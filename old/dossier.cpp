#include "dossier.h"
#include "UV.h"
#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>

using namespace question3;
using namespace UV_credits_types;

Categorie question3::StringToCategorie(const QString& str){
    if (str=="CS") return CS;
    else
    if (str=="TM") return TM;
    else
    if (str=="SP") return SP;
    else
    if (str=="TSH") return TSH;
    else {
        throw UTProfilerException(QString("erreur, StringToCategorie, categorie ")+str+" inexistante");
    }
}

QString question3::CategorieToString(Categorie c){
    switch(c){
    case CS: return "CS";
    case TM: return "TM";
    case SP: return "SP";
    case TSH: return "TSH";
    default: throw UTProfilerException("erreur, categorie non traitee",__FILE__,__LINE__);
    }
}

Saison question3::StringToSaison(const QString str){
    if (str=="A") return Automne;
    else
    if (str=="P") return Printemps;
    else {
        throw UTProfilerException(QString("erreur, StringToSaison, saison ")+str+" inexistante");
    }
}

Note question3::StringToNote (const QString str){
    if (str=="A") return A;
    else
    if (str=="B") return B;
    else
    if (str=="C") return C;
    else
    if (str=="D") return D;
    else
    if (str=="E") return E;
    else
    if (str=="FX") return FX;
    else
    if (str=="F") return F;
    else
    if (str=="EC") return EC;
    else {
        throw UTProfilerException(QString("erreur, StringToNote, note ")+str+" inexistante");
    }

}

Dossier* Dossier::instance=0;//initialisation de la variable static


Dossier::Dossier():QWidget(),login_etudiant(""), modification(false){
    //création d'un nouveau dossier
}

Dossier& Dossier::getInstance(){
    if(!instance)
        instance=new Dossier;
    return * instance;
}

void Dossier::libererInstance(){
    if(instance){
        delete instance;
        instance=0;
    }
}

//!!!!!!!! A FAIRE!!!!!!!!
Dossier::~Dossier(){
    if(modification){
        //enregistrement du dossier



    }
}
XmlStreamReader::XmlStreamReader(QFile* f){
    file=f;
}


void Dossier::load(const QString f,Dossier* doss){
    if(file!=f) this->~Dossier();
    file=f;
    QFile xml_doc(f);// On choisit le fichier contenant les informations XML.
    if(!xml_doc.open(QIODevice::ReadOnly | QIODevice::Text))// Si l'on n'arrive pas à ouvrir le fichier XML.
    {
        QMessageBox::warning(this,"Erreur à l'ouverture du document XML","Le document XML n'a pas pu être ouvert.");
        return;
    }
    XmlStreamReader reader(&xml_doc);
    reader.readFile(doss);

    xml_doc.close(); // Dans tous les cas, on doit fermer le document XML : on n'en a plus besoin, tout est compris dans l'objet

}
bool XmlStreamReader::readFile(Dossier *doss){

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
                readDossier(doss);
            }
            else
                reader.readNext();
        }
    }
    // Error handling.
    if(reader.hasError()) {
        throw UTProfilerException("Erreur lecteur fichier dossier, parser xml");
    }
        return true;
}

void XmlStreamReader::readDossier(Dossier* doss){

    unsigned int i=0;
    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "dossier")) {
        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            // We've found login.
            if(reader.name() == "login") {
                reader.readNext();
                QString l=reader.text().toString();
                doss->setLogin_etudiant(l);
            }

            if(reader.name() == "cursus") {
                Cursus cur;
                doss->setCursus(readCursus(cur));
            }
            // We've found inscription.
            if(reader.name() == "inscription") {
                Inscription in;
                doss->setInscr(readInscription(in));
            }

            // We've found equivalence.
            if(reader.name() == "equivalence") {
                Equivalence equi;
                doss->setEqui(readEquivalence(equi));
            }


            // We've found solution.
            if(reader.name() == "solution") {
                QList<Prevision> lP=readSolution();
                doss->setMapSolutions(i,lP);
                i++;


            }
        }
    }

}

Cursus& XmlStreamReader::readCursus(Cursus& cur){
    //afaire selon le tuto sur les arbres:http://www.informit.com/articles/article.aspx?p=1405553
    return cur;
}

Inscription& XmlStreamReader::readInscription(Inscription& inscri){

    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "inscription")){
        if(reader.tokenType() == QXmlStreamReader::StartElement) {

            if(reader.name()=="semestre"){
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
    }

   return inscri;
}

Semestre& XmlStreamReader::readSemestre(Semestre& sem){
    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "semestre")) {
        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="saison"){
                reader.readNext();
                sem.setSaison(question3::StringToSaison(reader.text().toString()));
            }
            if(reader.name()=="annee"){
                reader.readNext();
                sem.setAnnee(reader.text().toString().toUInt());
            }
        }
    }
    return sem;
}


UV* XmlStreamReader::readUv(){
    //next
    //creer pointeur sur uv
    //creer uv (UVManager)
    //recuperer code
    //aller chercher titre,.. dans base de données
    //retourner uv

}

Equivalence& XmlStreamReader::readEquivalence(Equivalence& equi){

    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "equivalence")){
        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="portee"){
                reader.readNext();
                equi.setPortee(reader.text().toString());
            }
            if(reader.name()=="credits"){
                Credits cred;
                readCredits(cred);
            }
        }
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
    }
    return cred;
}



QList<Prevision> XmlStreamReader::readSolution(){
   QList<Prevision> solution;
    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "solution")){
        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="prevision"){
                Prevision prev;
                solution.push_back(readPrevision(prev));
            }
        }
    }
    return solution;
}


Prevision& XmlStreamReader::readPrevision(Prevision& prev){

    while(!(reader.tokenType() == QXmlStreamReader::EndElement && reader.name() == "prevision")){
        if(reader.tokenType() == QXmlStreamReader::StartElement) {
            if(reader.name()=="semestreP"){
                Semestre sem;
                prev.setSemestre(readSemestre(sem));
            }
            if(reader.name()=="uvP"){
                prev.setUv(readUv());
            }
        }
    }
    return prev;
}

void XmlStreamReader::skipUnknownElement(){

}

/*void Dossier::ajouter_inscription(Saison sais,unsigned int annee, Note res, QString code){
    QString titre="titreàallerchercher";
    const UV u=new UV(code,titre);
    Inscription* nouvInsc= new Inscription(u,s,res);
    add_inscription(nouvInsc);
    modification=true;
}

void Dossier::add_inscription(Inscription* inscrip){

    inscr.push_back(inscrip);

}
void Credits::ajouterCredits(CreditType type ,unsigned int nb){


}
*/

//methodes à implémenter
/*;

void save();

void add_cursus();
void delete_cursus();
void add_equivalence();
void delete_equivalence();

void delete_inscription();
void add_semestre_etranger();
void delete_semestre_etranger();
void save_solution();
*/

