#include <iostream>

#include "UV.h"
#include "Cursus.h"
#include "temp_FAUSSES-CLASSES.h" //TODO NICO: supprimer cette ligne à la fin

#include "UV.cpp"
#include "Cursus.cpp"

using namespace UV_credits_types;
using namespace CURSUS;

int main(){

    QList<UV*> luv ;
    QList<Inscription> lins ;
    
    UV* uv1 = new UV("LO22","POO") ;
    UV* uv2 = new UV("LO23","POO");
    UV* uv3 = new UV("LO24","POO") ;
    UV* uv4 = new UV("LO25","POO") ;
    UV* uv5 = new UV("LO26","POO");
    UV* uv6 = new UV("LO27","POO");
    UV* uv7 = new UV("LO28","POO");
    UV* uv8 = new UV("LO29","POO");
    UV* uv9 = new UV("LO30","POO");

    Inscription i1 = Inscription(uv7,EC); //LO23
    Inscription i2 = Inscription(uv6,FX); //LO23
    Inscription i3 = Inscription(uv5,A);  //LO23
    Inscription i4 = Inscription(uv8,EC); //LO22
    Inscription i5 = Inscription(uv2,EC); //LO22
    Inscription i6 = Inscription(uv9,A);  //LO22
    Inscription i7 = Inscription(uv1,B);  //LO22
    Inscription i8 = Inscription(uv3,EC); //LO24

    luv << uv1 << uv2 << uv3 << uv4 << uv5 << uv6;
    lins<< i1 << i2 << i3 << i4 << i5 << i6 << i7 << i8;

    XUVParmi v1 = XUVParmi(4,luv);
    std::cout<<"A="<<v1.completion_percentage(&lins)<<"\n";
    std::cout<<"B="<<v1.is_completed(&lins)<<"\n";

    PorteeManager pm = PorteeManager();
    pm.addPortee("PCB_pour_etudiant_en_FDD");
    pm.addPortee("ENSEIGNEMENT_DIPLOMANT_TC");
    pm.addPortee("PCB_pour_n_importequel_GI");


    system("pause");
    return 0;
    //TODO NICO: FAIRE TOUS LES DESTRUCTEURS!!!!
    //TODO NICO: faudrait ptet mettre des exceptions... genre si une règle XUVPrmi a sa QList nulle...
}
