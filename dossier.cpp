#include "dossier.h"
#include "dataBaseA.h"

#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include <QTreeWidget>
//#include <ctime>

using namespace INSCRIPTIONS;
using namespace UV_credits_types;

float XUVParmi::completion_percentage (QList<Inscription> *ti) const{

    unsigned int cpt=0;
    string a,b;

    // copare dans chacune des deux listes le nombres d'UVs en commun et place le résultat dans cpt
    if(ti->length() > 0){
        for(    int i=0 ; i<   ti->length() ; i++){
            for(int j=0 ; j<UVlist.length() ; j++){
                a = ti->at(i).getUV().getCode().toStdString();
                b = UVlist.at(j)->getCode().toStdString();
                if( strcmp(a.c_str(),b.c_str())==0 ){  // comparaison des deux codes d'UV
                    cpt++;
                    j = UVlist.length();
                }
            }
        }
    }

    if(cpt>nb) return 1; // si l'étudiant à plus d'UV que nécessaire, le pourcentage de completion est de 100.
    return (float)((float)cpt/(float)nb);
    // TODO NICO :gerer le fx
}


void XUVParmi::copyIntoQtRuleView(QStandardItem * item)const{
    testNullPtr(false,false);
    item->setText(string(this->toString()+" ("+this->getName()+")").c_str());
};

void XCreditsParmi::copyIntoQtRuleView(QStandardItem * item)const{
    testNullPtr(false,false);
    item->setText(string(this->toString()+" ("+this->getName()+")").c_str());
};

float XCreditsParmi::completion_percentage (QList<Inscription> *ti) const{

    unsigned int cpt=0;
    QList<Credits*>* allCredits=0;

//TODO 2
DATABASE::UnpersistentDataBaseA db1 = DATABASE::UnpersistentDataBaseA();//TODO NICO : supprimer cette ligne a la fin!!!


    // parcours toutes les UVs de l'étudiant, et va chercher (et stocke dans "allCredits") pour chacune d'elle le nombre de crédits qu'elle rapport dans chaque type (ex: l'UV LO21 rapporte 6 crédits de type TM)
    if(ti->length() > 0){
        for( int i=0 ; i <ti->length() ; i++){ // parcours de toutes les UVs de l'étudiant
            for (int j = 0 ; j<porteeList.length() ; j++){ //^parcours des portees definies pour la présente règle de validation
              *allCredits << *db1.returnCreditsOfAnUV( ti->at(i).getUV().getCode().toStdString() , porteeList.at(j)->getLibelle().toStdString() ) ; // TODO NICO: utiliser le DP visitor
            }
        }
    }

    if(allCredits->length()>0) // On dépouille tous les crédits accumulés lors de l'analyse pour en faire la somme.
        for(int k=0; k<allCredits->length(); k++)
            cpt = cpt + allCredits->at(k)->getNbCredits();

    if(cpt>nb) return 1; // si l'étudiant à plus de crédits que nécessaire, le pourcentage de completion est de 100.
    return (float)((float)cpt/(float)nb);
}




float FonctionOU::completion_percentage (QList<Inscription> *ti) const{
    // on renvoie le maximum de tous les pourcentages des règles contenues dans la liste de règles
    float max = 0;
    float a;

    if(VRlist.length() > 0){
        for(int i=0; i<VRlist.length() ; i++){
            if(max < (a=VRlist.at(i)->completion_percentage(ti)) ){
                max = a;
            }
        }
    }
    return(max);
}

void FonctionOU::copyIntoQtRuleView(QStandardItem * item)const{
    testNullPtr(false,false);
    ValidationRule* vr;
    QList<QStandardItem*> subItem;
    item->setText((string("Fonction OU (")+string(this->getName())+string(")")).c_str());
    if(VRlist.length() >0){
        for(int j=0; j<VRlist.length() ; j++){
            vr = VRlist.at(j);
            subItem << new QStandardItem();
            vr->copyIntoQtRuleView(subItem.at(j));
            item -> appendRow(subItem.at(j));
        }
    }
};



float FonctionET::completion_percentage (QList<Inscription> *ti) const{

    float produit=0;
    int cpt=0;

    //parcours de toutes les regles de validation.
    //Le pourcentage total est le produit des pourcentages respectifs de toutes ces règles.
    if( VRlist.length() >= 1){
        for( int i=0 ; i <VRlist.length() ; i++){ // parcours de toutes les UVs de l'étudiant
            cpt++;
            produit +=  VRlist.at(i)->completion_percentage(ti);
        }
    }

    if(cpt){
        return (float)((float)produit/(float)cpt); // on fait ici la moyenne de tous les pourcentages
    }else{
        return 1;
    }

}

void FonctionET::copyIntoQtRuleView(QStandardItem * item)const{
    testNullPtr(false,false);
    ValidationRule* vr;
    QList<QStandardItem*> subItem;
    item->setText((string("Fonction ET (")+string(this->getName())+string(")")).c_str());
    if(VRlist.length() >0){
        for(int j=0; j<VRlist.length() ; j++){
            vr = VRlist.at(j);
            subItem << new QStandardItem();
            vr->copyIntoQtRuleView(subItem.at(j));
            item -> appendRow(subItem.at(j));
        }
    }
};




string XUVParmi::toString () const {

    string str = string("");

   if(UVlist.length()>0){
        int i;
          str = string("Obtenir ") + nb_str + string(" UV parmi : ") ;
       for(i=0; i<(UVlist.length()-1) ; i++)
            str =str + string(UVlist.at(i)->getCode().toStdString()) + "," ;
        i = UVlist.length()-1;
        str =str + UVlist.at(i)->getCode().toStdString() + "." ;

    }else{
        //str = "!!Règle incomplète";
    }

    return str;
}

string XCreditsParmi::toString () const {

    string str = string("");

    if(typeList.length()>0){
        int i;
        str = string("Obtenir ") + nb_str + string(" créd. (") ;
        for(i=0; i<(typeList.length()-1) ; i++){
            str = str + typeList.at(i)->getLibelle().toStdString() + " ou " ;    
        }
        i = typeList.length()-1;
        str = str + typeList.at(i)->getLibelle().toStdString() + ") parmi UV ayant une portée dans: (" ;
        for( i=0 ; i<(porteeList.length()-1) ; i++)
                str = str + porteeList.at(i)->getLibelle().toStdString() + ", " ;
            i = porteeList.length()-1;
            str = str + porteeList.at(i)->getLibelle().toStdString() + ")." ;
    }else{
        //str = "!!Règle incomplète";
    }

    return str;

}

string FonctionOU::toString () const {

    string str = string("");

    if(VRlist.length()>0){
        int i;
        str = str + " [ ";
        for(i=0; i<VRlist.length()-1 ; i++)
            str = str + VRlist.at(i)->toString() + " ]\nOU [ ";
        i = VRlist.length()-1 ;
        str = str + VRlist.at(i)->toString() + " ]";

    }else{
        str = "";
    }

    return str;
}

string FonctionET::toString () const {

    string str = string("");

    if(VRlist.length()>0){
        int i;
        str = str + " [ ";
        for(i=0; i<VRlist.length()-1 ; i++)
            str = str + VRlist.at(i)->toString() + " ] \nET [ ";
        i = VRlist.length()-1 ;
        str = str + VRlist.at(i)->toString() + " ]";

    }else{
        str = "";
    }

    return str;
}


float Profil::completion_percentage (QList<Inscription> *ti) const{

    float produit=0;
    int cpt=0;

    //parcours de toutes les regles de validation.
    //Le pourcentage total est le produit des pourcentages respectifs de toutes ces règles.
    if(VRlist.length() > 0){
        for( int i=0 ; i <VRlist.length() ; i++){ // parcours de toutes les UVs de l'étudiant
            produit = produit + VRlist.at(i)->completion_percentage(ti);
            cpt ++;
        }
    }

    if(cpt){
        return (float)((float)produit/(float)cpt);  // on fait la moyenne de tous les pourcentages
    }else{
        return 1;
    }

}

string Profil::toString(int k) const{

    string indentation=string("");
    for(int l=0;l<k;l++)
        indentation = indentation + "      ";
    string str = indentation;

    if(VRlist.length()>0){
        int i;
        for(i=0; i<VRlist.length() ; i++)
            str = str +"\n"+indentation+"règle de validation:" + VRlist.at(i)->toString();
    }else{
        str = "";
    }

    return str;
}

void Profil::copyIntoQtRuleView(QStandardItemModel *modeleRegl)const{
    testNullPtr(false,false);
    ValidationRule* vr;
    QList<QStandardItem*> subItem;
    if(VRlist.length() >0){
        for(int j=0; j<VRlist.length() ; j++){
            vr = VRlist.at(j);
            subItem << new QStandardItem();
            vr->copyIntoQtRuleView(subItem.at(j));
            modeleRegl->appendRow(subItem.at(j));
        }
    }
}



float Cursus::completion_percentage (QList<Inscription> *ti) const{

    float somme;
    int cpt=0;

    //parcours de toutes les regles de validation.
    //Le pourcentage total est le produit des pourcentages respectifs de toutes ces règles.
    if(PROlist.length() > 0){
        for( int i=0 ; i <PROlist.length() ; i++){ // parcours de toutes les UVs de l'étudiant
            somme = somme + PROlist.at(i)->completion_percentage(ti);
            cpt++;

        }
    }
    if(SOUS_cursus.length() > 0){
        for( int j=0 ; j <SOUS_cursus.length() ; j++){ // parcours de toutes les UVs de l'étudiant
            somme = somme + SOUS_cursus.at(j)->completion_percentage(ti);
            cpt++;

        }
    }

    if(cpt){
        return (float)((float)somme/(float)cpt); ; // On fait la moyenne du pourcentage de complétion des sous-cursus ainsi que la moyenne des pourcentages de complétion du profil du présent cursus.
    }else{
        return 1;
    }
}

string Cursus::toString(int k) const{

    string indentation=string("");
    for(int l=0;l<k;l++)
        indentation = indentation + "      ";
    string str = indentation;

    if(PROlist.length()>0){
        int i;
        for(i=0; i<PROlist.length() ; i++)
            str = str + "\n"+indentation+"Profil \""+PROlist.at(i)->getName()+"\": " + PROlist.at(i)->toString(k+1);

        if(SOUS_cursus.length() >0){
            str = str + "\n\n"+indentation+"Mais il faut également ";
        }
    }
    if(SOUS_cursus.length() >0){
        int j;
        str = str + "Valider les Sous-Cursus suivants : ";
        for(j=0; j<SOUS_cursus.length()-1 ; j++)
            str = str + SOUS_cursus.at(j)->getName() + ", ";
        j = SOUS_cursus.length()-1 ;
        str = str + SOUS_cursus.at(j)->getName() + ".";

        str = str + "\n"+indentation+"Voici donc les conditions de validation de ces sous-cursus:";
        for(j=0; j<SOUS_cursus.length() ; j++)
            str = str +"\n"+indentation+"sous-cursus \""+SOUS_cursus.at(j)->getName()+"\": "+ SOUS_cursus.at(j)->toString(k+1) + ",\n";

    }

    return str;
}


void Cursus::copyIntoQtProfilView(QStandardItemModel *modeleProfil,int begin)const{
    testNullPtr(false,false);
    for(int i=begin-1; i<PROlist.length() ; i++){
        //QMessageBox::warning(0," ","prolist.length passage\n");
        modeleProfil->appendRow(new QStandardItem_Profil(PROlist.at(i)->getName(),PROlist.at(i)));
    }

}


void Cursus::copyIntoQtCursusView(QStandardItem *itemCursus)const{
    testNullPtr(false,false);
    if(SOUS_cursus.length() >0){
        for(int j=0; j<SOUS_cursus.length() ; j++){
            Cursus* currentCurs = SOUS_cursus.at(j);
            QStandardItem *subItem = new QStandardItem_Cursus(currentCurs->getName(),SOUS_cursus.at(j));
            currentCurs->copyIntoQtCursusView(subItem);
            itemCursus -> appendRow(subItem);
        }
    }

}


const QList<Profil*> Cursus::getProfileList() const{
    if(PROlist.length() >0){
        return (const QList<Profil*>) PROlist;
    }else{
        QList<Profil*> ret;
        QList<const CreditType*> vide1;//= new QList<const CreditType*>;
        QList<const Portee*> vide2;// = new QList<const Portee*>;
        ValidationRule* foo = new XCreditsParmi(1,vide1,vide2,"(pas de règle de validation dans ce profil)",string("1"));
        Profil* foo2 = new Profil("(pas de profil dans ce cursus)");
        foo2->addValidationRule(foo);
        ret<<foo2;
        return((const QList<Profil*>)ret);
    }
}

const QList<Cursus*> Cursus::getSOUSCursusList() const{
    if(SOUS_cursus.length() >0){
        return (const QList<Cursus*>) SOUS_cursus;
    }else{
        QList<Cursus*> ret ;
        return ret;
    }
}

Cursus* Cursus::cloneRootElement() const{
    Cursus* ret = new Cursus(this->name);
    ret->PROlist = this->PROlist;
    return ret;
}



void XUVParmi::testNullPtr(bool recursiv,bool debug=false)const{
    QString type=QString("XUVParmi");
    QString att1=QString("UVlist");
    if(debug)QMessageBox::warning(0," ",(string("\n")+this->getName()+string("\n\ntype=")+type.toStdString()+string(" att=")+att1.toStdString()+string(" len=")).c_str());  

    for(int i=0;i<UVlist.length();i++){     
        if(UVlist.at(i)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att1);
    }
    if(recursiv){};
}

void XCreditsParmi::testNullPtr(bool recursiv,bool debug=false)const{
    QString type=QString("XCreditsParmi");
    QString att1=QString("typelist");
    QString att2=QString("porteelist");
    if(debug)QMessageBox::warning(0," ",(string("\n")+this->getName()+string("\n\ntype=")+type.toStdString()+string(" att=")+att1.toStdString()+string(" len=")+string(" att2=")+att2.toStdString()+string(" len=")).c_str());    

    for(int i=0;i<typeList.length();i++){
        if(typeList.at(i)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att1);
    }
    for(int j=0;j<porteeList.length();j++){
        if(porteeList.at(j)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att2);
    }
    if(recursiv){};
}

void FonctionOU::testNullPtr(bool recursiv,bool debug=false)const{
    QString type=QString("FonctionOU");
    QString att1=QString("VRlist");
    
    if(debug)QMessageBox::warning(0," ",(string("\n")+this->getName()+string("\n\ntype=")+type.toStdString()+string(" att=")+att1.toStdString()+string(" len=")).c_str());    
    for(int i=0;i<VRlist.length();i++){
        if(VRlist.at(i)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att1);
        if(recursiv)
            VRlist.at(i)->testNullPtr(recursiv,debug);
    }
 }

 void FonctionET::testNullPtr(bool recursiv,bool debug=false)const{
    QString type=QString("FonctionET");
    QString att1=QString("VRlist");
    
    if(debug)QMessageBox::warning(0," ",(string("\n")+this->getName()+string("\n\ntype=")+type.toStdString()+string(" att=")+att1.toStdString()+string(" len=")).c_str());    
    for(int i=0;i<VRlist.length();i++){
        if(VRlist.at(i)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att1);
        if(recursiv)
            VRlist.at(i)->testNullPtr(recursiv,debug);
    }
 }

  void Profil::testNullPtr(bool recursiv,bool debug=false)const{
    QString type=QString("Profil");
    QString att1=QString("VRlist");
    
    if(debug)QMessageBox::warning(0," ",(string("\n")+this->getName()+string("\n\ntype=")+type.toStdString()+string(" att=")+att1.toStdString()+string(" len=")).c_str());    
    for(int i=0;i<VRlist.length();i++){
        if(VRlist.at(i)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att1);
        if(recursiv)
            VRlist.at(i)->testNullPtr(recursiv,debug);
    }
 }

 void Cursus::testNullPtr(bool recursiv,bool debug=false)const{
    QString type=QString("Cursus");
    QString att1=QString("PROlist");
    QString att2=QString("SOUS_cursus");
    if(debug)QMessageBox::warning(0," ",(string("\n")+this->getName()+string("\n\ntype=")+type.toStdString()+string(" att=")+att1.toStdString()+string(" len=")+string(" att2=")+att2.toStdString()+string(" len=")).c_str());    

    for(int i=0;i<PROlist.length();i++){
        if(PROlist.at(i)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att1);
        if(recursiv)
            PROlist.at(i)->testNullPtr(recursiv,debug);
    }
    for(int j=0;j<SOUS_cursus.length();j++){
        if(SOUS_cursus.at(j)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att2);
        if(recursiv)
            SOUS_cursus.at(j)->testNullPtr(recursiv,debug);
    }
}

 void Cursus_Etudiant::testNullPtr(bool recursiv,bool debug=false)const{
    QString type=QString("Cursus_Etudiant");
    QString att1=QString("PROlist");
    QString att2=QString("SOUS_cursus");
    if(debug)QMessageBox::warning(0," ",(string("\n")+this->getName()+string("\n\ntype=")+type.toStdString()+string(" att=")+att1.toStdString()+string(" len=")+string(" att2=")+att2.toStdString()+string(" len=")).c_str());    

    for(int i=0;i<PROlist.length();i++){
        if(PROlist.at(i)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att1);
        if(recursiv)
            PROlist.at(i)->testNullPtr(recursiv,debug);
    }
    for(int j=0;j<SOUS_cursus.length();j++){
        if(SOUS_cursus.at(j)==0)
            throw CursusNullPtrException(QString("!!Dans l'objet ")+QString(this->getName())+QString(" de type ")+type+QString(", il y a un pointeur nul dans l'attribut")+att2);
        if(recursiv)
            SOUS_cursus.at(j)->testNullPtr(recursiv,debug);
    }
}



Dossier* Dossier::instance=0; //initialisation de la variable statique

Dossier::Dossier():login_etudiant(""), modification(false){
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


