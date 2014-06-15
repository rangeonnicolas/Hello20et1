#include "dossierXMLreader.h"

using namespace INSCRIPTIONS;

XmlStreamReader::XmlStreamReader(Dossier* doss,Cursus* rootCursus):rootCursus(rootCursus){

    dossierAremplir = doss;

}


bool XmlStreamReader::readFile(const QString &fileName){
    QFile xml_doc(fileName);// On choisit le fichier contenant les informations XML.
    if(!xml_doc.open(QIODevice::ReadOnly | QIODevice::Text))// Si l'on n'arrive pas à ouvrir le fichier XML.
    {
        QMessageBox::warning(0,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert.");
        return false;
    }
    reader.setDevice(&xml_doc);
    QMessageBox::information(0,"   ", "entrée readFile");



    // We'll parse the XML until we reach end of it.
    while(!reader.atEnd() && !reader.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = reader.readNext();

        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named dossier, we'll dig the information from there.
            if(reader.name() == "dossier") {
                readDossier();
            }
            else
                reader.readNext();
        }
    }
    // Error handling.
    if(reader.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier dossier, parser xml");
    }
    xml_doc.close(); // Dans tous les cas, on doit fermer le document XML : on n'en a plus besoin, tout est compris dans l'objet
    return true;
}

void XmlStreamReader::readDossier(){
    reader.readNextStartElement();

    unsigned int i=0;
    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "dossier")) {

        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            // We've found login.
            if(reader.name() == "login") {
                reader.readNext();
                QString l=reader.text().toString();
                dossierAremplir->setLogin_etudiant(l);
            }

            if(reader.name() == "cursus") {

                reader.readNext();
                Cursus_Etudiant* ce= new Cursus_Etudiant(rootCursus);
                readRecursiveCursus(ce);
                dossierAremplir->setCursus(ce);



            }
            // We've found inscription.
            if(reader.name() == "inscription") {
                reader.readNext();
                Inscription in;
                dossierAremplir->setInscr(readInscription(in));
            }

            // We've found equivalence.
            if(reader.name() == "equivalence") {
                reader.readNext();
                Equivalence equi;
                dossierAremplir->setEqui(readEquivalence(equi));
            }


            // We've found solution.
            if(reader.name() == "solution") {
                reader.readNext();
                QList<Inscription> lP=readSolution();
                dossierAremplir->setMapSolutions(i,lP);
                i++;


            }

        }
        reader.readNext();
    }

}


void  XmlStreamReader::readRecursiveCursus(Cursus_Etudiant* parent){


    //QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    //item->setText(0, reader.attributes().value("term").toString());

//fonction pour recopier le cursus (voir feuolle)
//    for (int j=0; j<parent->getCursusReference()->getSOUSCursusList().length(); j++){
//        if(!strcmp(parent->getCursusReference()->getSOUSCursusList().at(j)->getName(),cursus)){
//            QMessageBox::information(0," ","");
//            Cursus* selected=parent->getCursusReference()->getSOUSCursusList().at(j);
//            Cursus_Etudiant* sous_cursus=new Cursus_Etudiant(selected);
//            parent->addSousCursus(sous_cursus);
//        }
//     }
//        reader.readNext();
//        while (!reader.atEnd()) {
//            if (reader.isEndElement()) {
//                reader.readNext();
//                break;
//            }

//            if (reader.isStartElement()) {
//                if (reader.name() == "cursus") {
//                    readRecursiveCursus(sous_cursus);

//                } else {
//                    skipUnknownElement();
//                }
//            } else {
//                reader.readNext();
//            }
//        }




}

Inscription& XmlStreamReader::readInscription(Inscription& inscri){

    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "inscription")){

        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="semestreI"){
                reader.readNext();
                Semestre sem;
                inscri.setSemestre(readSemestre(sem));



            }
            if(reader.name()=="resultat"){
                reader.readNext();
                inscri.setResultat(StringToNote(reader.text().toString()));
            }
            if(reader.name()=="uvI"){
                reader.readNext();
                inscri.setUv(readUv());
            }

         }
         reader.readNext();
    }

   return inscri;
}

Semestre& XmlStreamReader::readSemestre(Semestre& sem){



    while(!(reader.tokenType() == QXmlStreamReader::EndElement && (reader.name() == "semestreI" ||reader.name() == "semestreP"))) {

        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="saison"){
                reader.readNext();
                sem.setSaison(INSCRIPTIONS::StringToSaison(reader.text().toString()));
            }
            if(reader.name()=="annee"){
                reader.readNext();
                sem.setAnnee(reader.text().toString().toUInt());
            }

        }
        reader.readNext();
    }

    return sem;
}


UV* XmlStreamReader::readUv(){
   // A decommenter quand UVManager sera implémentée
    QString code;
    //lire le code dans fichier xml
    code=reader.text().toString();
    //le chercher dans UVManager

    //retourner le pointeur
    return &(UVManager::getInstance().getUV(code));

}

Equivalence& XmlStreamReader::readEquivalence(Equivalence& equi){

    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "equivalence")){
        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="portee"){
                reader.readNext();
                equi.setPortee(reader.text().toString());
            }
            if(reader.name()=="credits"){
                reader.readNext();
                Credits cred;
                readCredits(cred);
            }

        }
        reader.readNext();
    }
    return equi;
}



Credits& XmlStreamReader::readCredits(Credits &cred){

    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "credits")) {
        if(reader.tokenType() == QXmlStreamReader::StartElement) {

            if(reader.name()=="nb"){
                reader.readNext();
                cred.setNbCredits(reader.text().toString().toUInt());
                }
            if(reader.name()=="typeCredit"){
                reader.readNext();
                /*QString credTy=reader.text().toString()
                if(credTy nexiste pas encore)//chercher dans la QList de CreditType Manager
                    CreditType* CT=new CreditType(credTy);
                else
                    CreditType* CT=&de ce type qui existe déjà//chercher dans CreditType Manager
                cred.setType(CT);
                */
            }

        }
        reader.readNext();
    }
    return cred;
}



QList<Inscription> XmlStreamReader::readSolution(){

   QList<Inscription> solution;
    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "solution")){
        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="prevision"){
                reader.readNext();
                Inscription prev;
                solution.push_back(readPrevision(prev));
            }

        }
        reader.readNext();
    }
    return solution;
}


Inscription& XmlStreamReader::readPrevision(Inscription& prev){

    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "prevision")){
        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="semestreP"){
                reader.readNext();
                Semestre sem;
                prev.setSemestre(readSemestre(sem));
            }
            if(reader.name()=="uvP"){
                reader.readNext();
                prev.setUv(readUv());
            }

        }
        reader.readNext();
    }
    return prev;
}

void XmlStreamReader::skipUnknownElement(){

}
