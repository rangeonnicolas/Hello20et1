#ifndef CURSUS_CPP
#define CURSUS_CPP

#include "Cursus.h"
#include "temp2.h"

#include <QString>
//using namespace CURSUS;
using namespace UV_credits_types;
//using namespace FOOO; //TODO nico: supprimer cette ligne à la fin

float CURSUS::XUVParmi::completion_percentage (QList<FOOO::Inscription> *ti) const{

	unsigned int cpt=0;
    string a,b;

    // copare dans chacune des deux listes le nombres d'UVs en commun et place le résultat dans cpt
    if(ti->length() > 0){
	    for(    int i=0 ; i<   ti->length() ; i++){
	        for(int j=0 ; j<UVlist.length() ; j++){
                a = ti->at(i).getUV().getCode().toStdString();
                b = UVlist.at(j)->getCode().toStdString();
	            //std::cout+a+" et "+b+" :"+strcmp(a.c_str(),b.c_str()) +"\n";
	 			if( strcmp(a.c_str(),b.c_str())==0 ){  // comparaison des deux codes d'UV
	 				cpt++; 	
	 				j = UVlist.length();
	 			}
	 			// TODO NICO : ettention ici on ne gere pas les doublons d'UV!! Ni les listes nulles
	    	}
	    	//std::cout+"_________________"+cpt+"____________________________\n";
		}
	}

	if(cpt>nb) return 1; // si l'étudiant à plus d'UV que nécessaire, le pourcentage de completion est de 100.
	return (float)((float)cpt/(float)nb);
	// TODO NICO :gerer le fx
}

void CURSUS::XUVParmi::copyIntoQtRuleView(QStandardItem * item)const{
    item->setText(string(this->toString()+" ("+this->getName()+")").c_str());
};

void CURSUS::XCreditsParmi::copyIntoQtRuleView(QStandardItem * item)const{
    item->setText(string(this->toString()+" ("+this->getName()+")").c_str());
};

float CURSUS::XCreditsParmi::completion_percentage (QList<FOOO::Inscription> *ti) const{

	unsigned int cpt=0;
    QList<Credits> allCredits;

    dataBase db1 = dataBase();//TODO NICO : supprimer cette ligne a la fin!!!

	// parcours toutes les UVs de l'étudiant, et va chercher (et stocke dans "allCredits") pour chacune d'elle le nombre de crédits qu'elle rapport dans chaque type (ex: l'UV LO21 rapporte 6 crédits de type TM)
    if(ti->length() > 0){
	    for( int i=0 ; i <ti->length() ; i++){ // parcours de toutes les UVs de l'étudiant
	    	for (int j = 0 ; j<porteeList.length() ; j++){ //^parcours des portees definies pour la présente règle de validation
              allCredits << db1.returnCreditsOfAnUV( ti->at(i).getUV().getCode().toStdString() , porteeList.at(j)->getLibelle().toStdString() ) ; // TODO NICO: utiliser le DP visitor
	        }
		}
	}

	if(allCredits.length()>0) // On dépouille tous les crédits accumulés lors de l'analyse pour en faire la somme.
		for(int k=0; k<allCredits.length(); k++)
			cpt = cpt + allCredits.at(k).getNbCredits();

	if(cpt>nb) return 1; // si l'étudiant à plus de crédits que nécessaire, le pourcentage de completion est de 100.
	return (float)((float)cpt/(float)nb);
}





float CURSUS::FonctionOU::completion_percentage (QList<FOOO::Inscription> *ti) const{
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

void CURSUS::FonctionOU::copyIntoQtRuleView(QStandardItem * item)const{
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




float CURSUS::FonctionET::completion_percentage (QList<FOOO::Inscription> *ti) const{

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

void CURSUS::FonctionET::copyIntoQtRuleView(QStandardItem * item)const{
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




string CURSUS::XUVParmi::toString () const {

	string str = string("");

    //std::ostringstream nbSTR= std::ostringstream();
    //nbSTR << nb;

   if(UVlist.length()>0){
        int i;
          str = string("Obtenir ") + string(" UV parmi : ") ; // TODO NICO: corriger ici
        //str = "Avoir obtenu " + nbSTR.str() +" UV parmi : " ;
       for(i=0; i<(UVlist.length()-1) ; i++)
            str =str + string(UVlist.at(i)->getCode().toStdString()) + "," ;
		i = UVlist.length()-1;
        str =str + UVlist.at(i)->getCode().toStdString() + "." ;

	}else{
		str = "!!Règle incomplète";
	}

	return str;
}

string CURSUS::XCreditsParmi::toString () const {

	string str = string("");

//	std::ostringstream oss;
//    nbSTR << nb;

    if(typeList.length()>0){
        int i;
        str = string("Obtenir ") + string(" créd. (") ;
        for(i=0; i<(typeList.length()-1) ; i++)
            str = str + typeList.at(i)->getLibelle().toStdString() + " ou " ;
		i = typeList.length()-1;
        str = str + typeList.at(i)->getLibelle().toStdString() + ") parmi UV ayant une portée dans: (" ;

		for( i=0 ; i<(porteeList.length()-1) ; i++)
                str = str + porteeList.at(i)->getLibelle().toStdString() + ", " ;
			i = porteeList.length()-1;
            str = str + porteeList.at(i)->getLibelle().toStdString() + ")." ;

	}else{
		str = "!!Règle incomplète";
	}

	return str;

}

string CURSUS::FonctionOU::toString () const {
	
    string str = string("");

    if(VRlist.length()>0){
        int i;
        str = str + " [ ";
        for(i=0; i<VRlist.length()-1 ; i++)
            str = str + VRlist.at(i)->toString() + " ] OU [ ";
		i = VRlist.length()-1 ;
        str = str + VRlist.at(i)->toString() + " ]";

	}else{
		str = "!!Règle incomplète";
	}

	return str;
}

string CURSUS::FonctionET::toString () const {
	
    string str = string("");

    if(VRlist.length()>0){
        int i;
        str = str + " [ ";
        for(i=0; i<VRlist.length()-1 ; i++)
            str = str + VRlist.at(i)->toString() + " ] ET [ ";
		i = VRlist.length()-1 ;
        str = str + VRlist.at(i)->toString() + " ]";

	}else{
		str = "!!Règle incomplète";
	}

	return str;
}


float CURSUS::Profil::completion_percentage (QList<Inscription> *ti) const{

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

string CURSUS::Profil::toString() const{

	string str = string("");

    if(VRlist.length()>0){
        int i;
        str = str + " [ ";
        for(i=0; i<VRlist.length()-1 ; i++)
            str = str + VRlist.at(i)->toString() + " ] ET [ ";
		i = VRlist.length()-1 ;
        str = str + VRlist.at(i)->toString() + " ]";

	}else{
		str = "!!Règle incomplète";
	}

	return str;
}      

void CURSUS::Profil::copyIntoQtRuleView(QStandardItemModel *modeleRegl)const{
	ValidationRule* vr;
	QList<QStandardItem*> subItem;
	if(VRlist.length() >0){
		for(int j=0; j<VRlist.length() ; j++){
			vr = VRlist.at(j);
            //subItem << new QStandardItem_Regle(vr->getName(),VRlist.at(j));
            subItem << new QStandardItem();
            vr->copyIntoQtRuleView(subItem.at(j));
			modeleRegl->appendRow(subItem.at(j));
		}
	}
}


#include <ctime>//TODO NICO

float CURSUS::Cursus::completion_percentage (QList<Inscription> *ti) const{

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

string CURSUS::Cursus::toString() const{

	string str = string("");

    if(PROlist.length()>0){
        int i;
        str = str + " [ ";
        for(i=0; i<PROlist.length()-1 ; i++)
            str = str + PROlist.at(i)->toString() + " ] ET [ ";
        i = PROlist.length()-1 ;
        str = str + PROlist.at(i)->toString() + " ].";

		if(SOUS_cursus.length() >0){
            str = str + " Mais il faut également ";
		}
	}
	if(SOUS_cursus.length() >0){
		int j;
        str = str + "Valider les Sous-Cursus suivants : ";
		for(j=0; j<SOUS_cursus.length()-1 ; j++)
			str = str + SOUS_cursus.at(j)->getName() + ", ";
        j = SOUS_cursus.length()-1 ;
		str = str + SOUS_cursus.at(j)->getName() + ".";
	}

	return str;
}      


void CURSUS::Cursus::copyIntoQtProfilView(QStandardItemModel *modeleProfil,int begin)const{
	//std::cout<<"\n\n--AA-- nb de sous cursus :"<<SOUS_cursus.length();

    for(int i=begin-1; i<PROlist.length() ; i++){
        modeleProfil->appendRow(new QStandardItem_Profil(PROlist.at(i)->getName(),PROlist.at(i)));
    }

}


void CURSUS::Cursus::copyIntoQtCursusView(QStandardItem *itemCursus)const{
	if(SOUS_cursus.length() >0){
		for(int j=0; j<SOUS_cursus.length() ; j++){
			Cursus* currentCurs = SOUS_cursus.at(j);
			QStandardItem *subItem = new QStandardItem_Cursus(currentCurs->getName(),SOUS_cursus.at(j));
            currentCurs->copyIntoQtCursusView(subItem);
			itemCursus -> appendRow(subItem);
		}
	}

}

/*void CURSUS::Cursus::copyIntoQtCursusView(QStandardItem *itemCursus)const{

	if(SOUS_cursus.length() >0){
		for(int j=0; j<SOUS_cursus.length() ; j++){
			Cursus* currentCurs = SOUS_cursus.at(j);
			//std::cout<<"\n\n--AA-- on traite ici le sc "<< currentCurs->getName();
			QStandardItem *subItem = new QStandardItem(currentCurs->getName());
			//std::cout<<"\n\n--AA-- Entree dans la fn rec";
            currentCurs->copyIntoQtCursusView(subItem);
            //std::cout<<"\n\n--AA-- Sortie de la fn rec";
			itemCursus -> appendRow(subItem);
		}
	}

}*/

const QList<Profil*> CURSUS::Cursus::getProfileList() const{
	if(PROlist.length() >0){
        return (const QList<Profil*>) PROlist;
    }else{
        QList<Profil*> ret;
        QList<const CreditType*> vide1;
        QList<const Portee*> vide2;
        ValidationRule* foo = new XCreditsParmi(1,vide1,vide2,"(pas de règle de validation dans ce profil)");
        Profil* foo2 = new Profil("(pas de profil dans ce cursus)");
        foo2->addValidationRule(foo);
        ret<<foo2;
        return((const QList<Profil*>)ret);
    }
}

const QList<Cursus*> CURSUS::Cursus::getSOUSCursusList() const{
    if(SOUS_cursus.length() >0){
        return (const QList<Cursus*>) SOUS_cursus;
    }else{
        QList<Cursus*> ret ;
        //ret<<new Cursus("Pas de sous cursus");
        return ret;
    }
}

Cursus* CURSUS::Cursus::cloneRootElement() const{
    Cursus* ret = new Cursus(this->name);
    //ret.SOUS_cursus = QList<Cursus*>;
    ret->PROlist = this->PROlist;
    return ret;
}

#endif
