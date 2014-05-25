#include "Cursus.h"
using namespace CURSUS;
using namespace UV_credits_types;

float CURSUS::XUVParmi::completion_percentage (QList<FOOO::Inscription> *ti) const{

	unsigned int cpt=0;
    string a,b;

    // copare dans chacune des deux listes le nombres d'UVs en commun et place le résultat dans cpt
    if(ti->length() > 0){
	    for(    int i=0 ; i<   ti->length() ; i++){
	        for(int j=0 ; j<UVlist.length() ; j++){
	            a = ti->at(i).getUV()->getCode();
	            b = UVlist.at(j)->getCode();
	            //std::cout<<a<<" et "<<b<<" :"<<strcmp(a.c_str(),b.c_str()) <<"\n";
	 			if( strcmp(a.c_str(),b.c_str())==0 ){  // comparaison des deux codes d'UV
	 				cpt++; 	
	 				j = UVlist.length();
	 			}
	 			// TODO NICO : ettention ici on ne gere pas les doublons d'UV!! Ni les listes nulles
	    	}
	    	//std::cout<<"_________________"<<cpt<<"____________________________\n";
		}
	}

	if(cpt>nb) return 100; // si l'étudiant à plus d'UV que nécessaire, le pourcentage de completion est de 100.
	return 100*cpt/nb;
	// TODO NICO :gerer le fx
}

float CURSUS::XCreditsParmi::completion_percentage (unsigned int x, QList<CreditType*> typeList,const Portee& portee) const{

	//Ici c'est pas fini. A vrai dire, ce n'est même pas commencé.

}