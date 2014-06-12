


#include "dataBaseB.h"

Cursus* UnpersistentDataBaseB::getSavedAdministrationCursusTree(){

    QList<UV*> luv ;
    QList<Inscription> nico ;

    PorteeManager pm = PorteeManager();
    pm.addPortee("PCB_pour_etudiant_en_GI");
    pm.addPortee("PCB_pour_etudiant_en_GI+FDD");
    pm.addPortee("TSH_accessibles_aux_TC_et_BRANCHES");
    pm.addPortee("TSH_accessibles_aux_BRANCHES");
    pm.addPortee("TableauTSH-col1-ligne1");
    pm.addPortee("TableauTSH-col1-ligne2");
    pm.addPortee("TableauTSH-col1-ligne3");
    pm.addPortee("TableauTSH-col2-ligne1");
    pm.addPortee("TableauTSH-col2-ligne2");
    pm.addPortee("TableauTSH-col2-ligne3");
    pm.addPortee("Tous_Cursus_Confondus");
    pm.addPortee("Toutes_Branches_Confondues");

    CreditTypeManager ctm = CreditTypeManager();
    ctm.addType("CS");
    ctm.addType("TM");
    ctm.addType("TSH");
    ctm.addType("SP");

    UV* uv1  = new UV("TX"  ,"UV_sans_description");
    UV* uv2  = new UV("LO21","UV_sans_description");
    UV* uv3  = new UV("GE37","UV_sans_description");
    UV* uv4  = new UV("NF17","UV_sans_description");
    UV* uv5  = new UV("LO22","UV_sans_description");
    UV* uv6  = new UV("SR03","UV_sans_description");
    UV* uv7  = new UV("IA01","UV_sans_description");
    UV* uv8  = new UV("NF16","UV_sans_description");
    UV* uv9  = new UV("SY02","UV_sans_description");
    UV* uv10 = new UV("IA02","UV_sans_description");
    UV* uv11 = new UV("RO03","UV_sans_description");
    UV* uv12 = new UV("RO04","UV_sans_description");
    UV* uv13 = new UV("BI01","UV_sans_description");
    UV* uv14 = new UV("TN09","UV_sans_description");
    UV* uv15 = new UV("TN10","UV_sans_description");
    UV* uv16 = new UV("LA13","UV_sans_description");
    UV* uv17 = new UV("SC24","UV_sans_description");
    UV* uv18 = new UV("LG51","UV_sans_description");
    UV* uv19 = new UV("SC01","UV_sans_description");
    UV* uv20 = new UV("SO04","UV_sans_description");
    UV* uv21 = new UV("IC07","UV_sans_description");
    UV* uv22 = new UV("EI03","UV_sans_description");
    UV* uv23 = new UV("LA02","UV_sans_description");
    UV* uv24 = new UV("NF26","UV_sans_description");
    UV* uv25 = new UV("SY09","UV_sans_description");


    nico <<
    Inscription( uv1  , EC) <<
    Inscription( uv2  , EC) <<
    Inscription( uv3  , A ) <<
    Inscription( uv4  , A ) <<
    Inscription( uv5  , A ) <<
    Inscription( uv6  , A ) <<
    Inscription( uv7  , A ) <<
    Inscription( uv8  , A ) <<
    Inscription( uv9  , FX) <<
    Inscription( uv10 , A ) <<
    Inscription( uv11 , A ) <<
    Inscription( uv12 , A ) <<
    Inscription( uv13 , EC) <<
    Inscription( uv14 , A ) <<
    //Inscription( uv15 , EC) <<
    Inscription( uv16 , A ) <<
    Inscription( uv17 , A ) <<
    Inscription( uv18 , A ) <<
    Inscription( uv19 , A ) <<
    Inscription( uv20 , A ) <<
    Inscription( uv21 , A ) <<
    Inscription( uv22 , EC) <<
    Inscription( uv23 , EC) <<
    Inscription( uv24 , A ) <<
    Inscription( uv25 , A );

    Cursus* ALL_CURSUS = new Cursus("Tous les Cursus");

    //  1. CURSUS INGENIEUR :

        Cursus* Inge = new Cursus("Cursus Ingénieur");
        ALL_CURSUS->addSousCursus(Inge);

    //      1.1 PROFIL INGENIEUR

            Profil* Profil_Inge = new Profil("Profil Ingénieur");
            Inge->addProfil( Profil_Inge);

    //          1.1.1 REGLES DE VALIDATION DU PROFIL INGENIEUR
    //              1.1.1.1 REGLE DE VALIDATION "Avoir fait TN09 et TN10"

                    QList<UV*>* l1= new QList<UV*>;
                    *l1 <<  uv15 << uv14 ;               // TODO NICO: code sale, prendre le UVmanager
                    ValidationRule* Stages = new XUVParmi(2, *l1 ,"");
                    Profil_Inge->addValidationRule(Stages);

    //      1.2 SOUS CURSUS DU CURSUS INGENIEUR
    //          1.2.1 CURSUS INGENIEUR POUR ETUDIANT ENTRE DIRECTEMENT EN BRANCHE

                Cursus* Inge_BR    = new Cursus("Curs.Ing. pour étudiant rentré en Branche");
                Inge->addSousCursus( Inge_BR);

    //              1.2.1.1 PROFIL INGENIEUR POUR ETUDIANT ENTRE DIRECTEMEENT EN BRANCHE

                    Profil* Profil_Inge_BR = new Profil("Total");
                    Inge_BR->addProfil( Profil_Inge_BR);

                    Profil* Profil_Inge_BR_TabTSH = new Profil("Tableau TSH");
                    Inge_BR->addProfil( Profil_Inge_BR_TabTSH);

    //                  1.2.1.1.1 REGLES DE VALIDATION du "PROFIL INGENIEUR POUR ETUDIANT ENTRE DIRECTEMEENT EN BRANCHE"
    //                      1.2.1.1.1.1 REGLE DE VALIDATION "Avoir obtenu au moins 120 crédits"

                            QList<const CreditType*>* l11= new QList<const CreditType*>; *l11 << ctm.getFromType("CS") << ctm.getFromType("TM") << ctm.getFromType("TSH") << ctm.getFromType("SP");
                            QList<const Portee*>*     l12= new QList<const Portee*>    ; *l12 << pm.getFromPortee("Tous_Cursus_Confondus");
                            ValidationRule* vr1 = new XCreditsParmi(120,*l11,*l12,"Au - 120 créd. (TSH,CS,SP,TM) parmi UV de portée \"Tous_Cursus_Confondus\"");
                            Profil_Inge_BR->addValidationRule(vr1);

    //                      1.2.1.1.1.2 REGLE DE VALIDATION "Avoir au moins 28 crédits TSH"

                            QList<const CreditType*> l21 ; l21 << ctm.getFromType("TSH") ;
                            QList<const Portee*>     l22 ; l22 << pm.getFromPortee("Tous_Cursus_Confondus");
                            ValidationRule* vr2 = new XCreditsParmi(120,l21,l22,"Au - 28   créd. (TSH)                  parmi UV de portée \"Tous_Cursus_Confondus\"");
                            Profil_Inge_BR->addValidationRule(vr2);

    //                      1.2.1.1.1.3 REGLE DE VALIDATION "Avoir au moins 2 lignes et 2 colonnes du tableau TSH"

                            QList<const CreditType*> ctTSH ; ctTSH << ctm.getFromType("TSH") ;
                            QList<const Portee*>     porteeC1L1 ; porteeC1L1 << pm.getFromPortee("TableauTSH-col1-ligne1");
                            QList<const Portee*>     porteeC1L2 ; porteeC1L2 << pm.getFromPortee("TableauTSH-col1-ligne2");
                            QList<const Portee*>     porteeC1L3 ; porteeC1L3 << pm.getFromPortee("TableauTSH-col1-ligne3");
                            QList<const Portee*>     porteeC2L1 ; porteeC2L1 << pm.getFromPortee("TableauTSH-col2-ligne1");
                            QList<const Portee*>     porteeC2L2 ; porteeC2L2 << pm.getFromPortee("TableauTSH-col2-ligne2");
                            QList<const Portee*>     porteeC2L3 ; porteeC2L3 << pm.getFromPortee("TableauTSH-col2-ligne3");

                            FonctionOU* ligne1 = new FonctionOU("ligne1");
                            ligne1->addRule(new XCreditsParmi(1,ctTSH,porteeC1L1,"Remplir la case [1;1]"));
                            ligne1->addRule(new XCreditsParmi(1,ctTSH,porteeC2L1,"Remplir la case [1;2]"));
                            FonctionOU* ligne2 = new FonctionOU("ligne2");
                            ligne2->addRule(new XCreditsParmi(1,ctTSH,porteeC1L2,"Remplir la case [2;1]"));
                            ligne2->addRule(new XCreditsParmi(1,ctTSH,porteeC2L2,"Remplir la case [2;2]"));
                            FonctionOU* ligne3 = new FonctionOU("ligne3");
                            ligne3->addRule(new XCreditsParmi(1,ctTSH,porteeC1L3,"Remplir la case [3;1]"));
                            ligne3->addRule(new XCreditsParmi(1,ctTSH,porteeC2L3,"Remplir la case [3;2]"));
                            FonctionOU* col1 = new FonctionOU("col1");
                            col1->addRule(new XCreditsParmi(1,ctTSH,porteeC1L1,"Remplir la case [1;1]"));
                            col1->addRule(new XCreditsParmi(1,ctTSH,porteeC1L2,"Remplir la case [2;1]"));
                            col1->addRule(new XCreditsParmi(1,ctTSH,porteeC1L3,"Remplir la case [3;1]"));
                            FonctionOU* col2 = new FonctionOU("col2");
                            col2->addRule(new XCreditsParmi(1,ctTSH,porteeC2L1,"Remplir la case [1;2]"));
                            col2->addRule(new XCreditsParmi(1,ctTSH,porteeC2L2,"Remplir la case [2;2]"));
                            col2->addRule(new XCreditsParmi(1,ctTSH,porteeC2L3,"Remplir la case [3;2]"));

                            FonctionET* lignes1et2 = new FonctionET("Remplir ligne1 ET ligne2");
                            lignes1et2->addRule(ligne1);
                            lignes1et2->addRule(ligne2);
                            FonctionET* lignes1et3 = new FonctionET("Remplir ligne1 ET ligne3");
                            lignes1et3->addRule(ligne1);
                            lignes1et3->addRule(ligne3);
                            FonctionET* lignes2et3 = new FonctionET("Remplir ligne2 ET ligne3");
                            lignes2et3->addRule(ligne2);
                            lignes2et3->addRule(ligne3);

                            FonctionOU* avoirdeuxlignes = new FonctionOU("Remplir lignes 1et2 OU 1et3 OU 2et3");
                            avoirdeuxlignes->addRule(lignes1et2);
                            avoirdeuxlignes->addRule(lignes1et3);
                            avoirdeuxlignes->addRule(lignes2et3);
                            FonctionET* avoirdeuxcolonnes = new FonctionET("Remplir col1 ET col2");
                            avoirdeuxcolonnes->addRule(col1);
                            avoirdeuxcolonnes->addRule(col2);

                            FonctionET* vr3 = new FonctionET("Remplir 2 lignes ET 2 colonnes");
                            vr3->addRule(avoirdeuxlignes);
                            vr3->addRule(avoirdeuxcolonnes);
                            Profil_Inge_BR_TabTSH->addValidationRule(vr3);

    //              1.2.1.2 SOUS-CURSUS du "CURSUS INGENIEUR POUR ETUDIANT ENTRE DIRECTEMENT EN BRANCHE"
    //                  1.2.1.2.1 CURSUS BRANCHE_GENERAL

                        Cursus* BRANCHEGEN = new Cursus("BRANCHE (concept général)");
                        Inge_BR->addSousCursus( BRANCHEGEN);

    //                      1.2.1.2.1.1 PROFIL BRANCHE_GENERAL

                            Profil* Profil_BRANCHEGEN = new Profil("BR");
                            BRANCHEGEN->addProfil( Profil_BRANCHEGEN);

    //                          1.2.1.2.1.1.1 REGLES DE VALIDATION DU PROFIL BRANCHE_GENERAL

                                QList<const CreditType*> l61 ; l61 << ctm.getFromType("CS") << ctm.getFromType("TM");
                                QList<const Portee*>     l62 ; l62 << pm.getFromPortee("Toutes_Branches_Confondues");
                                ValidationRule* vr6 = new XCreditsParmi(84,l61,l62,"Au - 84 créd. (CS,TM) parmi UV de portée \"Toutes_Branches_Confondues\"");
                                Profil_BRANCHEGEN->addValidationRule(vr6);

                                QList<const CreditType*> l71 ; l71 << ctm.getFromType("CS");
                                QList<const Portee*>     l72 ; l72 << pm.getFromPortee("Toutes_Branches_Confondues");
                                ValidationRule* vr7 = new XCreditsParmi(30,l71,l72,"Au - 30 créd. (CS)       parmi UV de portée \"Toutes_Branches_Confondues\"");
                                Profil_BRANCHEGEN->addValidationRule(vr7);

                                QList<const CreditType*> l81 ; l81 << ctm.getFromType("TM");
                                QList<const Portee*>     l82 ; l82 << pm.getFromPortee("Toutes_Branches_Confondues");
                                ValidationRule* vr8 = new XCreditsParmi(30,l81,l82,"Au - 30 créd. (TM)     parmi UV de portée \"Toutes_Branches_Confondues\"");
                                Profil_BRANCHEGEN->addValidationRule(vr8);

    //                      1.2.1.2.1.2 SOUS-CURSUS du "CURSUS BRANCHE_GENERAL
    //                          1.2.1.2.1.2.2 CURSUS BRANCHE_GP

                                Cursus* BRANCHE_GP = new Cursus("GP");
                                BRANCHEGEN->addSousCursus( BRANCHE_GP);
    //
    //                          1.2.1.2.1.2.3 CURSUS BRANCHE_GB

                                Cursus* BRANCHE_GB = new Cursus("GB");
                                BRANCHEGEN->addSousCursus( BRANCHE_GB);
    //
    //                          1.2.1.2.1.2.4 CURSUS BRANCHE_GSM

                                Cursus* BRANCHE_GSM =new  Cursus("GSM");
                                BRANCHEGEN->addSousCursus( BRANCHE_GSM);
    //
    //                          1.2.1.2.1.2.5 CURSUS BRANCHE_GM

                                Cursus* BRANCHE_GM = new Cursus("GM");
                                BRANCHEGEN->addSousCursus( BRANCHE_GM);
    //                          1.2.1.2.1.2.1 CURSUS BRANCHE_GI

                                Cursus* BRANCHE_GI = new Cursus("GI");
                                BRANCHEGEN->addSousCursus( BRANCHE_GI);

    //                              1.2.1.2.1.2.1.1 PROFILS du CURSUS BRANCHE_GI

    //                              1.2.1.2.1.2.1.2 SousCursus du CURSUS BRANCHE_GI
    //                                  1.2.1.2.1.2.1.2.1 FDD
                                        Cursus* FIL_FDD = new Cursus("FDD");
                                        BRANCHE_GI->addSousCursus( FIL_FDD);

    //                                  1.2.1.2.1.2.1.2.2 ADEL
                                        Cursus* FIL_ADEL = new Cursus("ADEL");
                                        BRANCHE_GI->addSousCursus( FIL_ADEL);

    //                                  1.2.1.2.1.2.1.2.3 ICSI
                                        Cursus* FIL_ICSI = new Cursus("ICSI");
                                        BRANCHE_GI->addSousCursus( FIL_ICSI);

    //                                  1.2.1.2.1.2.1.2.4 MPI
                                        Cursus* FIL_MPI = new Cursus("MPI");
                                        BRANCHE_GI->addSousCursus( FIL_MPI);

    //                                  1.2.1.2.1.2.1.2.5 SRI
                                        Cursus* FIL_SRI = new Cursus("SRI");
                                        BRANCHE_GI->addSousCursus( FIL_SRI);

    //                                  1.2.1.2.1.2.1.2.6 STRIE
                                        Cursus* FIL_STRIE = new Cursus("STRIE");
                                        BRANCHE_GI->addSousCursus( FIL_STRIE);


    //

    //          1.2.2 CURSUS INGENIEUR POUR ETUDIANT ENTRE EN TRONC COMMUN

                Cursus* Inge_BR_TC = new Cursus("Curs.Ing. pour étudiant rentré en TC"       );
                Inge->addSousCursus( Inge_BR_TC);

    //              1.2.2.1 PROFIL INGENIEUR POUR ETUDIANT ENTRE EN TRONC COMMUN

                    Profil* Profil_Inge_BR_TC = new Profil("Total");
                    Inge_BR_TC->addProfil( Profil_Inge_BR_TC);

                    Inge_BR_TC->addProfil( Profil_Inge_BR_TabTSH);

    //                  1.2.2.1.1 REGLES DE VALIDATION du "PROFIL INGENIEUR POUR ETUDIANT ENTRE EN TRONC COMMUN"
    //                      1.2.2.1.1.1 REGLE DE VALIDATION "Avoir obtenu au moins 240 crédits"

                            QList<const CreditType*> l41 ; l41 << ctm.getFromType("CS") << ctm.getFromType("TM") << ctm.getFromType("TSH") << ctm.getFromType("SP");
                            QList<const Portee*>     l42 ; l42 << pm.getFromPortee("Tous_Cursus_Confondus");
                            ValidationRule* vr4 = new XCreditsParmi(120,l41,l42,"Au - 240 créd. (TSH,CS,SP,TM) parmi UV de portée \"Tous_Cursus_Confondus\"");
                            Profil_Inge_BR_TC->addValidationRule(vr4);

    //                      1.2.2.1.1.2 REGLE DE VALIDATION "Avoir au moins 52 crédits TSH"

                            QList<const CreditType*> l51 ; l51 << ctm.getFromType("TSH") ;
                            QList<const Portee*>     l52 ; l52 << pm.getFromPortee("Tous_Cursus_Confondus");
                            ValidationRule* vr5 = new XCreditsParmi(120,l51,l52,"Au - 52   créd. (TSH)                  parmi UV de portée \"Tous_Cursus_Confondus\"");
                            Profil_Inge_BR_TC->addValidationRule(vr5);

    //                      1.2.2.1.1.3 REGLE DE VALIDATION "Avoir au moins 2 lignes et 2 colonnes du tableau TSH"

                            //Profil_Inge_BR_TC->addValidationRule(vr3);  // ici c'est bien VR3.

    //                      1.2.2.1.1.4 REGLE DE VALIDATION "Avoir au moins 1 lignes complète du tableau TSH"

                            //Profil_Inge_BR_TC->addValidationRule(vr7);

    //              1.2.2.2 Sous Cursus du CURSUS INGENIEUR POUR ETUDIANT ENTRE EN TRONC COMMUN

                    Cursus* TroncCommun = new Cursus("TRONC COMMUN");
                    Inge_BR_TC->addSousCursus( TroncCommun);

                    Inge_BR_TC->addSousCursus( BRANCHEGEN);

    //                  1.2.2.2.1 Profil TC

                        Profil* Profil_TroncCommun = new Profil("TC");
                        TroncCommun->addProfil( Profil_TroncCommun);

    //                      1.2.2.2.1.1 Regles de validation du profil TC



    return(ALL_CURSUS);
}


