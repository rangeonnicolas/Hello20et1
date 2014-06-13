

#include "dataBaseA.h"



QList<UV*>* DATABASE::UnpersistentDataBaseA::getAllUVs() const{
    QList<UV*>* ret = new QList<UV*>;

    *ret<< new UV("AA01"  ,   "",true,true);          // ,"");
    *ret<< new UV("AP"    ,   "Atelier Projet",true,true);          // ,"");
    *ret<< new UV("AP51"  ,   "",true,true);          // ,"");
    *ret<< new UV("AP52"  ,   "",true,true);          // ,"");
    *ret<< new UV("AP53"  ,   "",true,true);          // ,"");
    *ret<< new UV("API01" ,   "",true,true);          // ,"");
    *ret<< new UV("API02" ,   "",true,true);          // ,"");
    *ret<< new UV("API03" ,   "",true,true);          // ,"");
    *ret<< new UV("API04" ,   "",true,true);          // ,"");
    *ret<< new UV("API05" ,   "",true,true);          // ,"");
    *ret<< new UV("API06" ,   "Analyse De Donnees Et Data Mining (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("API07" ,   "Architecture Des Applications Internet, Programmation Web Et Securite (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("API08" ,   "Ihm Et Multimédia (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("API09" ,   "Méthodes Et Outils Pour L Optimisation Et La Simulation (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("API10" ,   "Méthodes De Vérification Et Validation De Logiciel Et Programmation Sous Linux (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("AR03"  ,   "Art et technologies contemporaines",true,true);
    *ret<< new UV("AR04"  ,   "Art, ville, architecture",true,false);          // ,"A");
    *ret<< new UV("AS01"  ,   "Analyse des Situations de l’ingénieur ",true,true);
    *ret<< new UV("AS02"  ,   "Accompagnement pour l’Analyse des Situations de l’ingénieur ",true,true);          // ,"A_P");
    *ret<< new UV("ASP03" ,   "",true,true);          // ,"");
    *ret<< new UV("ASP04" ,   "",true,true);          // ,"");
    *ret<< new UV("ASP06" ,   "",true,true);          // ,"");
    *ret<< new UV("AV01"  ,   "Initiation à l’analyse et à la réalisation audiovisuelle",true,true);          // ,"A_P");
    *ret<< new UV("BA01"  ,   "Equipements Techniques Du Batiment",true,true);          // ,"");
    *ret<< new UV("BA02"  ,   "Gestion Technique Du Patrimoine Immobilier",true,true);          // ,"");
    *ret<< new UV("BA03"  ,   "MATÉRIAUX DE CONSTRUCTION",true,false);          // ,"A");
    *ret<< new UV("BA04"  ,   "Conversion Et Gestion Des Energies Renouvelables",true,true);          // ,"");
    *ret<< new UV("BA05"  ,   "",true,true);          // ,"");
    *ret<< new UV("BA06"  ,   "",true,true);          // ,"");
    *ret<< new UV("BA07"  ,   "MODES OPÉRATOIRES DE LA CONSTRUCTION",false,true);          // ,"P");
    *ret<< new UV("BA09"  ,   "Introduction Au Calcul Des Structures Du Batiment",true,true);          // ,"");
    *ret<< new UV("BC01"  ,   "",true,true);          // ,"");
    *ret<< new UV("BI01"  ,   "MODELES POUR LA BIOINFORMATIQUE",false,true);          // ,"P");
    *ret<< new UV("BL01"  ,   "SCIENCES BIOLOGIQUES POUR L INGÉNIEUR",true,true);          // ,"A_P");
    *ret<< new UV("BL09"  ,   "BIOPHYSIQUE DES SYSTÈMES BIOLOGIQUES",false,true);          // ,"P");
    *ret<< new UV("BL10"  ,   "STRUCTURES ET PHYSICOCHIMIE DES MOLÉCULES BIOLOGIQUES",true,true);          // ,"A_P");
    *ret<< new UV("BL16"  ,   "",true,true);          // ,"");
    *ret<< new UV("BL17"  ,   "",true,true);          // ,"");
    *ret<< new UV("BL20"  ,   "MÉTABOLISME ET PHYSIOLOGIE CELLULAIRE",true,false);          // ,"A");
    *ret<< new UV("BL22"  ,   "Microbiologie Et Biologie Moléculaire",true,true);          // ,"");
    *ret<< new UV("BL30"  ,   "Physiologie Des Systèmes Intégrés",true,true);          // ,"");
    *ret<< new UV("BL40"  ,   "Génie Cellulaire",true,true);          // ,"");
    *ret<< new UV("BM01"  ,   "INTRODUCTION À L INSTRUMENTATION BIOMÉDICALE",false,true);          // ,"P");
    *ret<< new UV("BM02"  ,   "Organes Artificiels Et Biorheologie",true,true);          // ,"");
    *ret<< new UV("BM04"  ,   "",true,true);          // ,"");
    *ret<< new UV("BM05"  ,   "",true,true);          // ,"");
    *ret<< new UV("BM06"  ,   "",true,true);          // ,"");
    *ret<< new UV("BM07"  ,   "",true,true);          // ,"");
    *ret<< new UV("BM08"  ,   "Modélisation Des Systèmes Biomécaniques",true,true);          // ,"");
    *ret<< new UV("BT02"  ,   "Opérations Agro-Industrielles",true,true);          // ,"");
    *ret<< new UV("BT03"  ,   "",true,true);          // ,"");
    *ret<< new UV("BT06"  ,   "Analyse Des Produits Biologiques Et Alimentaires",true,true);          // ,"");
    *ret<< new UV("BT07"  ,   "",true,true);          // ,"");
    *ret<< new UV("BT09"  ,   "INDUSTRIES AGRO-ALIMENTAIRES - QUALITES DE L ALIMENT",true,false);          // ,"A");
    *ret<< new UV("BT10"  ,   "Risques Biologiques Et Sécurité Alimentaire",true,true);          // ,"");
    *ret<< new UV("BT21"  ,   "Biotechnologies Moleculaires Et Genie Genetique",true,true);          // ,"");
    *ret<< new UV("BT22"  ,   "Les Agroressources",true,true);          // ,"");
    *ret<< new UV("C2I1"  ,   "CERTIFICAT INFORMATIQUE ET INTERNET NIVEAU 1",true,true);          // ,"A_P");
    *ret<< new UV("CM01"  ,   "PHYSIQUE DE LA MATIÈRE",false,true);          // ,"P");
    *ret<< new UV("CM04"  ,   "PROCÉDÉS INDUSTRIELS",true,false);          // ,"A");
    *ret<< new UV("CM05"  ,   "THERMODYNAMIQUE CHIMIQUE",true,true);          // ,"A");
    *ret<< new UV("CM06"  ,   "CALCUL D UNE OPÉRATION INDUSTRIELLE",true,true);          // ,"A_P");
    *ret<< new UV("CM07"  ,   "TRAVAUX PRATIQUES DE GÉNIE CHIMIQUE",true,true);          // ,"A_P");
    *ret<< new UV("CM11"  ,   "CHIMIE GÉNÉRALE",true,true);          // ,"A_P");
    *ret<< new UV("CM12"  ,   "CHIMIE PHYSIQUE MINÉRALE",true,false);          // ,"A");
    *ret<< new UV("CM13"  ,   "CHIMIE DES SUBSTANCES ORGANIQUES ET BIOLOGIQUES",true,true);          // ,"A_P");
    *ret<< new UV("CM15"  ,   "SYSTEMES COLLOIDAUX - APPLICATIONS AGROALIMENTAIRES",false,true);          // ,"P");
    *ret<< new UV("CM40"  ,   "Catalyse Heterogene",true,true);          // ,"");
    *ret<< new UV("CM70"  ,   "TRAVAUX PRATIQUES DE GP (1)",false,true);          // ,"P");
    *ret<< new UV("CT02"  ,   "Maitrise Statistique Des Processus",true,true);          // ,"");
    *ret<< new UV("CT04"  ,   "Controles Non Destructifs",true,true);          // ,"");
    *ret<< new UV("DD01"  ,   "Séminaire Développement Durable ",true,true);          // ,"A_P");
    *ret<< new UV("DD02"  ,   "Introduction A L Eco-Conception Et A L Analyse De Cycle De Vie",true,true);          // ,"");
    *ret<< new UV("DI01"  ,   "Initiation au design industriel",true,true);          // ,"A_P");
    *ret<< new UV("DI02"  ,   "Initiation au design graphique",true,true);          // ,"A_P");
    *ret<< new UV("DI03"  ,   "Conception Formelle Des Produits",true,true);          // ,"");
    *ret<< new UV("DI05"  ,   "Methodologie Et Analyse De La Valeur",true,true);          // ,"");
    *ret<< new UV("DI06"  ,   "Analyse Des Produits De Consommation",true,true);          // ,"");
    *ret<< new UV("DI07"  ,   "",true,true);          // ,"");
    *ret<< new UV("DI08"  ,   "",true,true);          // ,"");
    *ret<< new UV("EG01"  ,   "Ergonomie",true,true);          // ,"");
    *ret<< new UV("EI03"  ,   "Communication interculturelle",true,true);          // ,"A_P");
    *ret<< new UV("EI04"  ,   "Intelligence économique : stratégie d’entreprise et outils",true,true);          // ,"A_P");
    *ret<< new UV("EI05"  ,   "Science, technologie et société dans l’UE",true,true);          // ,"A_P");
    *ret<< new UV("EL01"  ,   "PHÉNOMÈNES ELECTROMAGNÉTIQUES",false,true);          // ,"P");
    *ret<< new UV("EL02"  ,   "ÉLECTRICITÉ INDUSTRIELLE APPLIQUÉE",false,true);          // ,"P");
    *ret<< new UV("EN14"  ,   "Fonctions Électroniques Pour L Ingénieur",true,true);          // ,"");
    *ret<< new UV("EN21"  ,   "BASES DE L ÉLECTRONIQUE ANALOGIQUE",true,true);          // ,"A_P");
    *ret<< new UV("EN90"  ,   "ELECTRONIQUE NUMÉRIQUE",true,false);          // ,"A");
    *ret<< new UV("EV01"  ,   "Procédés De Traitement Des Déchets",true,true);          // ,"");
    *ret<< new UV("EV02"  ,   "",true,true);          // ,"");
    *ret<< new UV("FPP01" ,   "",true,true);          // ,"");
    *ret<< new UV("FPP02" ,   "Fiabilite Et Ingenierie Robuste De Produits (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("FPP03" ,   "",true,true);          // ,"");
    *ret<< new UV("FQ01"  ,   "ÉCONOMIE GLOBALE ET MAITRISE DE LA QUALITÉ",true,true);          // ,"A_P");
    *ret<< new UV("FQ03"  ,   "",true,true);          // ,"");
    *ret<< new UV("FQ04"  ,   "",true,true);          // ,"");
    *ret<< new UV("FQ05"  ,   "",true,true);          // ,"");
    *ret<< new UV("FQ07"  ,   "La Qualité Des Services A L Industrie",true,true);          // ,"");
    *ret<< new UV("GE10"  ,   "Economie politique",true,true);          // ,"A_P");
    *ret<< new UV("GE12"  ,   "Géographie et économie des territoires",true,true);          // ,"A_P");
    *ret<< new UV("GE13"  ,   "Les risques entre technique et société",true,true);          // ,"A_P");
    *ret<< new UV("GE15"  ,   "Initiation à la création et gestion d’entreprise",true,true);          // ,"A_P");
    *ret<< new UV("GE20"  ,   "Economie industrielle",true,true);          // ,"A_P");
    *ret<< new UV("GE21"  ,   "Economie et gestion de l’innovation et du numérique",true,true);          // ,"A_P");
    *ret<< new UV("GE22"  ,   "Economie internationale",true,true);          // ,"A_P");
    *ret<< new UV("GE23"  ,   "Transferts de technologie et développement",true,true);          // ,"A_P");
    *ret<< new UV("GE24"  ,   "Recherche & développement : ingénieurs et investisseurs",true,true);          // ,"P");
    *ret<< new UV("GE25"  ,   "Gestion et organisation de la production",true,true);          // ,"A_P");
    *ret<< new UV("GE26"  ,   "Management stratégique des ressources humaines",true,true);          // ,"A_P");
    *ret<< new UV("GE27"  ,   "Gestion financière de l’entreprise",true,false);          // ,"A");
    *ret<< new UV("GE28"  ,   "Economie et droit de la propriété intellectuelle",true,true);          // ,"A_P");
    *ret<< new UV("GE29"  ,   "Management d’entreprise internationale",true,true);          // ,"A_P");
    *ret<< new UV("GE36"  ,   "Marketing",true,true);          // ,"A_P");
    *ret<< new UV("GE37"  ,   "GESTION DE PROJET",true,true);          // ,"A_P");
    *ret<< new UV("GE38"  ,   "MANAGEMENT ET OUTILS D AIDE À LA CRÉATIVITÉ INDUSTRIELLE ET À L INNOVATION",true,true);          // ,"A_P");
    *ret<< new UV("GE39"  ,   "MANAGEMENT ET MARKETING DE L INNOVATION",true,true);          // ,"A_P");
    *ret<< new UV("GE40"  ,   "MANAGEMENT DE PROJETS",true,false);          // ,"A");
    *ret<< new UV("GE90"  ,   "Organisations, innovations et international ",true,true);          // ,"A_P");
    *ret<< new UV("GPL01" ,   "Gestion De Production Et Erp (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("GPL02" ,   "",true,true);          // ,"");
    *ret<< new UV("GPL03" ,   "",true,true);          // ,"");
    *ret<< new UV("HE01"  ,   "Epistémologie et histoire des sciences",true,true);          // ,"A_P");
    *ret<< new UV("HE03"  ,   "Logique, histoire et formalisme",true,true);          // ,"A_P");
    *ret<< new UV("HE04"  ,   "Epistémologie et pratiques des modèles ",true,true);          // ,"A_P");
    *ret<< new UV("HE05"  ,   "Culture Technique",true,true);          // ,"A_P");
    *ret<< new UV("HT02"  ,   "",true,true);          // ,"");
    *ret<< new UV("IA01"  ,   "INTELLIGENCE ARTIFICIELLE : REPRÉSENTATION",true,false);          // ,"A");
    *ret<< new UV("IA02"  ,   "RÉSOLUTION DE PROBLÈMES ET PROGRAMMATION LOGIQUE",false,true);          // ,"P");
    *ret<< new UV("IA03"  ,   "TECHNIQUES DE MODÉLISATION, CAPITALISATION ET GESTION DES CONNAISSANCES",true,false);          // ,"A");
    *ret<< new UV("IA04"  ,   "SYSTÈMES MULTIAGENTS",false,true);          // ,"P");
    *ret<< new UV("IC01"  ,   "Histoire et prospective des industries culturelles",false,true);          // ,"P");
    *ret<< new UV("IC03"  ,   "Le numérique : des formats aux chaînes de production",true,true);          // ,"A_P");
    *ret<< new UV("IC05"  ,   "Technologies pour la documentique et l’indexation hypermédia",true,true);          // ,"A_P");
    *ret<< new UV("IC06"  ,   "Conception et industrie des jeux vidéo",true,true);          // ,"A_P");
    *ret<< new UV("IC07"  ,   "Techniques et technologies du musical et du sonore",true,true);          // ,"A_P");
    *ret<< new UV("IR00"  ,   "Initiation à la recherche",true,true);          // ,"A_P");
    *ret<< new UV("LA00"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA01"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA02"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA03"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA04"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA11"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA12"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA13"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA14"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA15"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA20"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA21"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA22"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA23"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA24"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA91"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA92"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA93"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LA94"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LB04"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LB14"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LB24"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LC14"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG30"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG31"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG32"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG40"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG41"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG42"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG50"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG51"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG52"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG53"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG60"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG61"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG62"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LG63"  ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LNG01" ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LNG02" ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LNG03" ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LNG04" ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LNG05" ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LNG14" ,   "''",true,true);          // ,"A_P");
    *ret<< new UV("LO01"  ,   "BASES DE LA PROGRAMMATION",true,true);          // ,"A_P");
    *ret<< new UV("LO12"  ,   "INFOGRAPHIE ET IMAGES DE SYNTHÈSE",true,false);          // ,"A");
    *ret<< new UV("LO17"  ,   "INDEXATION ET RECHERCHE D INFORMATION",true,true);          // ,"A_P");
    *ret<< new UV("LO18"  ,   "PROJETS MULTIMÉDIA POUR LA FORMATION",false,true);          // ,"P");
    *ret<< new UV("LO21"  ,   "PROGRAMMATION ET CONCEPTION ORIENTEES OBJET",false,true);          // ,"P");
    *ret<< new UV("LO22"  ,   "GENIE LOGICIEL",false,true);          // ,"P");
    *ret<< new UV("LO23"  ,   "CONDUITE DE PROJET INFORMATIQUE",true,false);          // ,"A");
    *ret<< new UV("MA11"  ,   "RÉVISION D ANALYSE ET D ALGÈBRE (GM, GSM, GP)",true,true);          // ,"A_P");
    *ret<< new UV("MAT01" ,   "",true,true);          // ,"");
    *ret<< new UV("MAT02" ,   "",true,true);          // ,"");
    *ret<< new UV("MAT03" ,   "Mecanique Des Materiaux (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("MB11"  ,   "RÉVISION D ANALYSE ET D ALGÈBRE (GB, GI, GSU)",true,true);          // ,"A_P");
    *ret<< new UV("MC01"  ,   "Machines Électriques",true,true);          // ,"");
    *ret<< new UV("MC02"  ,   "",true,true);          // ,"");
    *ret<< new UV("MC05"  ,   "Machines De Transfert De Fluides",true,true);          // ,"");
    *ret<< new UV("MC06"  ,   "",true,true);          // ,"");
    *ret<< new UV("MC07"  ,   "Électronique De Puissance",true,true);          // ,"");
    *ret<< new UV("MC08"  ,   "",true,true);          // ,"");
    *ret<< new UV("MEQ01" ,   "",true,true);          // ,"");
    *ret<< new UV("MEQ02" ,   "",true,true);          // ,"");
    *ret<< new UV("MEQ03" ,   "Dynamique Des Solides (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("MEQ04" ,   "",true,true);          // ,"");
    *ret<< new UV("MEQ05" ,   "",true,true);          // ,"");
    *ret<< new UV("MG01"  ,   "Management en entreprise : styles de management, construction d’équipe et techniques de travail en groupe (P)",true,true);          // ,"A_P");
    *ret<< new UV("MG02"  ,   "",true,true);          // ,"");
    *ret<< new UV("MI01"  ,   "STRUCTURE D UN CALCULATEUR",true,false);          // ,"A");
    *ret<< new UV("MI03"  ,   "SYSTÈMES TEMPS RÉEL",false,true);          // ,"P");
    *ret<< new UV("MP02"  ,   "INTRODUCTION AUX MÉTHODES DE LA GPAO",false,true);          // ,"P");
    *ret<< new UV("MP03"  ,   "SUPPLY CHAIN MANAGEMENT",true,false);          // ,"A");
    *ret<< new UV("MQ01"  ,   "ÉLÉMENTS DE RESISTANCE DES MATÉRIAUX",true,true);          // ,"A_P");
    *ret<< new UV("MQ02"  ,   "Mécanique Des Solides Déformables",true,true);          // ,"");
    *ret<< new UV("MQ03"  ,   "MÉCANIQUE DES VIBRATIONS I",true,true);          // ,"A_P");
    *ret<< new UV("MQ04"  ,   "Polymères",true,true);          // ,"");
    *ret<< new UV("MQ05"  ,   "",true,true);          // ,"");
    *ret<< new UV("MQ06"  ,   "Modélisation Des Structures Par Éléments Finis",true,true);          // ,"");
    *ret<< new UV("MQ07"  ,   "",true,true);          // ,"");
    *ret<< new UV("MQ08"  ,   "Elaboration Et Proprietes D Usage Des Metaux",true,true);          // ,"");
    *ret<< new UV("MQ09"  ,   "Mécanique Des Vibrations II",true,true);          // ,"");
    *ret<< new UV("MQ10"  ,   "Comportement Mécanique Des Matériaux",true,true);          // ,"");
    *ret<< new UV("MQ11"  ,   "Mise En Oeuvre Des Matériaux",true,true);          // ,"");
    *ret<< new UV("MQ12"  ,   "",true,true);          // ,"");
    *ret<< new UV("MQ13"  ,   "",true,true);          // ,"");
    *ret<< new UV("MQ14"  ,   "Optimisation En Mécanique",true,true);          // ,"");
    *ret<< new UV("MQ16"  ,   "",true,true);          // ,"");
    *ret<< new UV("MQ17"  ,   "INTRODUCTION AUX PROPRIÉTÉS MÉCANIQUES ET À L INGÉNIERIE DES MATÉRIAUX",true,true);          // ,"A_P");
    *ret<< new UV("MQ18"  ,   "Cinématique Et Dynamique Des Systèmes",true,true);          // ,"");
    *ret<< new UV("MQ19"  ,   "Dynamique Des Structures",true,true);          // ,"");
    *ret<< new UV("MQ20"  ,   "INTRODUCTION A LA MÉCANIQUE DES SOLIDES ET DES FLUIDES",true,false);          // ,"A");
    *ret<< new UV("MS01"  ,   "MÉTHODES D ANALYSE PHYSICO-CHIMIQUE",true,true);          // ,"A_P");
    *ret<< new UV("MS02"  ,   "Principes Physiques Des Capteurs Et Instrumentation",true,true);          // ,"");
    *ret<< new UV("MS03"  ,   "Pratique Expérimentale En Acoustique Et Vibrations",true,true);          // ,"");
    *ret<< new UV("MT09"  ,   "ANALYSE NUMÉRIQUE",true,false);          // ,"A");
    *ret<< new UV("MT10"  ,   "STRUCTURES,CALCUL FORMEL ET ALGORITHMES",false,true);          // ,"P");
    *ret<< new UV("MT12"  ,   "METHODES MATHEMATIQUES POUR L ANALYSE DU SIGNAL ET DE L IMAGE",true,true);          // ,"A_P");
    *ret<< new UV("MT22"  ,   "FONCTIONS DE PLUSIEURS VARIABLES RÉELLES ET APPLICATIONS",true,true);          // ,"A_P");
    *ret<< new UV("MT23"  ,   "ALGÈBRE LINÉAIRE ET APPLICATIONS",true,true);          // ,"A_P");
    *ret<< new UV("MT31"  ,   "",true,true);          // ,"");
    *ret<< new UV("MT32"  ,   "",true,true);          // ,"");
    *ret<< new UV("MT33"  ,   "",true,true);          // ,"");
    *ret<< new UV("MT34"  ,   "Analyse 2 : Mesures, Intégrations, Probabilités",true,true);          // ,"");
    *ret<< new UV("MT35"  ,   "",true,true);          // ,"");
    *ret<< new UV("MT36"  ,   "",true,true);          // ,"");
    *ret<< new UV("MT37"  ,   "Logiques, Quelques Approfondissements Mathématiques Et Philosophiques",true,true);          // ,"");
    *ret<< new UV("MT38"  ,   "Probabilités",true,true);          // ,"");
    *ret<< new UV("MT90"  ,   "FONCTIONS D UNE VARIABLE REELLE 1",true,true);          // ,"A_P");
    *ret<< new UV("MT91"  ,   "FONCTIONS D UNE VARIABLE REELLE 2",true,true);          // ,"A_P");
    *ret<< new UV("MT94"  ,   "INTRODUCTION AUX MATHEMATIQUES APPLIQUÉES",false,true);          // ,"P");
    *ret<< new UV("MU01"  ,   "Pratique instrumentale d’ensemble",true,true);          // ,"A_P");
    *ret<< new UV("MU02"  ,   "Pratique instrumentale de haut niveau",true,true);          // ,"A_P");
    *ret<< new UV("MU03"  ,   "Pratique collective de musiques contemporaines",true,true);          // ,"A_P");
    *ret<< new UV("NF01"  ,   "ALGORITHMIQUE ET PROGRAMMATION",true,true);          // ,"A_P");
    *ret<< new UV("NF02"  ,   "DU CIRCUIT INTÉGRÉ AU MICROPROCESSEUR",true,true);          // ,"A_P");
    *ret<< new UV("NF04"  ,   "MODÉLISATION NUMÉRIQUE DES PROBLÈMES DE L INGÉNIEUR",true,true);          // ,"A_P");
    *ret<< new UV("NF11"  ,   "THÉORIE DES LANGAGES DE PROGRAMMATION",false,true);          // ,"P");
    *ret<< new UV("NF15"  ,   "MICROPROCESSEURS, INTERFACES ET LOGICIELS DE BASES",false,true);          // ,"P");
    *ret<< new UV("NF16"  ,   "ALGORITHMIQUE ET STRUCTURES DE DONNÉES",true,true);          // ,"A_P");
    *ret<< new UV("NF17"  ,   "CONCEPTION DE BASES DE DONNÉES",false,true);          // ,"P");
    *ret<< new UV("NF22"  ,   "MICRO-ORDINATEURS ET APPLICATIONS",true,true);          // ,"A_P");
    *ret<< new UV("NF24"  ,   "Modelisation Et Simulation Des Procedes",false,true);          // ,"");
    *ret<< new UV("NF26"  ,   "DATA WAREHOUSE ET OUTILS DÉCISIONNELS",false,true);          // ,"P");
    *ret<< new UV("NF28"  ,   "INGÉNIERIE DES SYSTÈMES INTÉRACTIFS",false,true);          // ,"P");
    *ret<< new UV("NF29"  ,   "INGÉNIERIE DOCUMENTAIRE ET SUPPORTS D INFORMATION",true,false);          // ,"A");
    *ret<< new UV("NF33"  ,   "CONCEPTION ET ARCHITECTURE DE SYSTÈMES NUMÉRIQUES INFORMATIQUES",false,true);          // ,"P");
    *ret<< new UV("NF92"  ,   "TRAITEMENT AUTOMATIQUE DE L INFORMATION",true,true);          // ,"A_P");
    *ret<< new UV("NF93"  ,   "SCIENCES DE L INFORMATIQUE",true,false);          // ,"A");
    *ret<< new UV("NP90"  ,   "NANO-PROJETS",true,true);          // ,"A_P");
    *ret<< new UV("NP94"  ,   "PREPARATION SCIENTIFIQUE A UN SUJET CHALLENGE DE TN04",true,false);          // ,"A");
    *ret<< new UV("NX17"  ,   "INTRODUCTION AUX BASES DE DONNEES",false,true);          // ,"P");
    *ret<< new UV("PAE01" ,   "",true,true);          // ,"");
    *ret<< new UV("PAE02" ,   "",true,true);          // ,"");
    *ret<< new UV("PAE03" ,   "",true,true);          // ,"");
    *ret<< new UV("PH01"  ,   "Introduction à la philosophie",true,true);          // ,"A_P");
    *ret<< new UV("PH02"  ,   "L’ingénieur, le philosophe et le scientifique",true,true);          // ,"A_P");
    *ret<< new UV("PH03"  ,   "Penser la technique aujourd’hui",true,true);          // ,"A_P");
    *ret<< new UV("PH09"  ,   "Ethique : une approche pluridisciplinaire ?",true,true);          // ,"A_P");
    *ret<< new UV("PH10"  ,   "Analyse phénoménologique des objets audiovisuels",true,false);          // ,"A");
    *ret<< new UV("PH11"  ,   "",true,true);          // ,"");
    *ret<< new UV("PH12"  ,   "",true,true);          // ,"");
    *ret<< new UV("PR"    ,   "RÉALISATION DE PROJET",true,true);          // ,"A_P");
    *ret<< new UV("PS04"  ,   "THERMODYNAMIQUE",true,true);          // ,"A_P");
    *ret<< new UV("PS05"  ,   "Fondements De L Acoustique Et Modélisations",true,true);          // ,"");
    *ret<< new UV("PS09"  ,   "ACOUSTIQUE APPLIQUÉE",false,true);          // ,"P");
    *ret<< new UV("PS10"  ,   "",true,true);          // ,"");
    *ret<< new UV("PS12"  ,   "",true,true);          // ,"");
    *ret<< new UV("PS13"  ,   "",true,true);          // ,"");
    *ret<< new UV("PS15"  ,   "THERMODYNAMIQUE PHYSIQUE",true,false);          // ,"A");
    *ret<< new UV("PS90"  ,   "INTRODUCTION A LA MESURE",true,true);          // ,"A_P");
    *ret<< new UV("PS91"  ,   "MECANIQUE PHYSIQUE",true,true);          // ,"A_P");
    *ret<< new UV("PS92"  ,   "DYNAMIQUE DES SYSTEMES ET DES SOLIDES",false,true);          // ,"P");
    *ret<< new UV("PS93"  ,   "OPTIQUE GEOMETRIQUE",true,true);          // ,"A_P");
    *ret<< new UV("PS94"  ,   "ELECTRICITE",true,true);          // ,"A_P");
    *ret<< new UV("PS95"  ,   "ONDES ET ELECTROMAGNETISME 1",true,false);          // ,"A");
    *ret<< new UV("PS96"  ,   "ONDES ET ELECTROMAGNETISME 2",true,false);          // ,"A");
    *ret<< new UV("RO03"  ,   "RECHERCHE OPÉRATIONNELLE, OPTIMISATION COMBINATOIRE",false,true);          // ,"P");
    *ret<< new UV("RO04"  ,   "OPTIMISATION ET RECHERCHE OPÉRATIONNELLE",false,true);          // ,"P");
    *ret<< new UV("RO05"  ,   "MODÉLISATION DE PHÉNOMÈNES ALÉATOIRES",true,false);          // ,"A");
    *ret<< new UV("RO06"  ,   "SIMULATION ET TECHNIQUES D OPTIMISATION",true,false);          // ,"A");
    *ret<< new UV("RR01"  ,   "CINÉTIQUE CHIMIQUE ET RÉACTEURS HOMOGÈNES",false,true);          // ,"P");
    *ret<< new UV("RR02"  ,   "CALCULS DES RÉACTEURS INDUSTRIELS",true,false);          // ,"A");
    *ret<< new UV("RV01"  ,   "RÉALITÉ VIRTUELLE",true,false);          // ,"A");
    *ret<< new UV("SA11"  ,   "Pratiques théâtrales",true,true);          // ,"A_P");
    *ret<< new UV("SC01"  ,   "Séminaire PHITECO ",true,true);          // ,"A_P");
    *ret<< new UV("SC11"  ,   "Théorie des sciences cognitives",true,true);          // ,"A_P");
    *ret<< new UV("SC12"  ,   "Technologie et cognition",true,true);          // ,"A_P");
    *ret<< new UV("SC21"  ,   "Linguistique(s) et philosophie(s) du langage",true,true);          // ,"A_P");
    *ret<< new UV("SC22"  ,   "Sociologie cognitive, lien social et techniques",true,true);          // ,"A_P");
    *ret<< new UV("SC23"  ,   "Analyse des usages",true,true);          // ,"A_P");
    *ret<< new UV("SC24"  ,   "Apprentissage et perception",true,true);          // ,"A_P");
    *ret<< new UV("SCI08" ,   "Introduction A L Ingenierie Systeme",true,true);          // ,"");
    *ret<< new UV("SI01"  ,   "Science et débat public",true,true);          // ,"A_P");
    *ret<< new UV("SI02"  ,   "Communication professionnelle de l’ingénieur",true,true);          // ,"A_P");
    *ret<< new UV("SI05"  ,   "Théories de la communication",true,true);          // ,"A_P");
    *ret<< new UV("SI06"  ,   "La documentation technique",true,true);          // ,"A_P");
    *ret<< new UV("SI07"  ,   "Médias et Industries culturelles",true,true);          // ,"A_P");
    *ret<< new UV("SI11"  ,   "Expression orale, parole publique",true,true);          // ,"A_P");
    *ret<< new UV("SI14"  ,   "Parole publique en anglais",true,true);          // ,"A_P");
    *ret<< new UV("SI20"  ,   "Rhétorique et arts du discours",true,true);          // ,"A_P");
    *ret<< new UV("SI22"  ,   "Signes et contenus numériques",true,true);          // ,"A_P");
    *ret<< new UV("SI24"  ,   "Ecritures numériques ordinaires    ",true,true);          // ,"A_P");
    *ret<< new UV("SI28"  ,   "Ecriture interactive et multimédia ",true,true);          // ,"A_P");
    *ret<< new UV("SI90"  ,   "Communication des Connaissances Technologiques     ",true,true);          // ,"A_P");
    *ret<< new UV("SL"    ,   "Suivi Linguistique",true,true);          // ,"");
    *ret<< new UV("SL0A"  ,   "",true,true);          // ,"");
    *ret<< new UV("SO04"  ,   "Initiation au Droit",true,true);          // ,"A_P");
    *ret<< new UV("SO05"  ,   "Sociologie, organisations et dynamiques des collectifs",true,true);          // ,"A_P");
    *ret<< new UV("SO06"  ,   "Organisation des systèmes de santé",true,true);          // ,"A_P");
    *ret<< new UV("SP01"  ,   "Un corps pour apprendre et comprendre",true,true);          // ,"A_P");
    *ret<< new UV("SP02"  ,   "Conduire un projet sportif",true,true);          // ,"A_P");
    *ret<< new UV("SP11"  ,   "Physiologie de l’effort sportif",false,true);          // ,"P");
    *ret<< new UV("SP22"  ,   "S’apprendre pour mieux gérer",true,true);          // ,"A_P");
    *ret<< new UV("SR01"  ,   "MAITRISE DES SYSTÈMES INFORMATIQUES",true,false);          // ,"A");
    *ret<< new UV("SR02"  ,   "SYSTÈMES D EXPLOITATION : DES CONCEPTS À LA PROGRAMMATION",false,true);          // ,"P");
    *ret<< new UV("SR03"  ,   "ARCHITECTURE DES APPLICATIONS INTERNET",false,true);          // ,"P");
    *ret<< new UV("SR04"  ,   "RÉSEAUX INFORMATIQUES",true,false);          // ,"A");
    *ret<< new UV("SR05"  ,   "ALGORITHMES ET SYSTÈMES RÉPARTIS",true,false);          // ,"A");
    *ret<< new UV("SR06"  ,   "SÉCURITÉ SYSTÈMES ET RÉSEAUX",true,false);          // ,"A");
    *ret<< new UV("SSA03" ,   "",true,true);          // ,"");
    *ret<< new UV("SSA04" ,   "",true,true);          // ,"");
    *ret<< new UV("SSA06" ,   "",true,true);          // ,"");
    *ret<< new UV("SY01"  ,   "ÉLÉMENTS DE PROBABILITÉS",true,true);          // ,"A_P");
    *ret<< new UV("SY02"  ,   "MÉTHODES STATISTIQUES POUR L INGÉNIEUR",true,true);          // ,"A_P");
    *ret<< new UV("SY03"  ,   "INTRODUCTION AUX SYSTEMES D ENTRAINEMENTS ELECTRIQUES",true,false);          // ,"A");
    *ret<< new UV("SY04"  ,   "SYSTÈMES ASSERVIS LINÉAIRES : ANALYSE ET COMMANDE",false,true);          // ,"P");
    *ret<< new UV("SY05"  ,   "CONDUITE DES PROCÉDÉS",false,true);          // ,"P");
    *ret<< new UV("SY06"  ,   "ANALYSE ET TRAITEMENT DU SIGNAL",false,true);          // ,"P");
    *ret<< new UV("SY08"  ,   "MODÉLISATION DES SYSTÈMES A ÉVÈNEMENTS DISCRETS",true,false);          // ,"A");
    *ret<< new UV("SY09"  ,   "ANALYSE DES DONNÉES ET DATA MINING",false,true);          // ,"P");
    *ret<< new UV("SY10"  ,   "",true,true);          // ,"");
    *ret<< new UV("SY12"  ,   "Modélisation Et Performance Des Systèmes De Production",true,true);          // ,"");
    *ret<< new UV("SY14"  ,   "ÉLÉMENTS D AUTOMATIQUE",false,true);          // ,"P");
    *ret<< new UV("SY15"  ,   "AUTOMATIQUE AVANCÉE",false,true);          // ,"P");
    *ret<< new UV("SY16"  ,   "",true,true);          // ,"");
    *ret<< new UV("SY19"  ,   "DECISION ET APPRENTISSAGE AUTOMATIQUE",true,false);          // ,"A");
    *ret<< new UV("SY23"  ,   "VISION ET IMAGE",false,true);          // ,"P");
    *ret<< new UV("SY26"  ,   "TÉLÉCOMMUNICATIONS",false,true);          // ,"P");
    *ret<< new UV("SY27"  ,   "MACHINES INTELLIGENTES",true,false);          // ,"A");
    *ret<< new UV("SY31"  ,   "CAPTEURS POUR LES SYSTEMES INTELLIGENTS",true,false);          // ,"A");
    *ret<< new UV("TA02"  ,   "ÉVALUATION ÉCONOMIQUE DES PROCÉDÉS",false,true);          // ,"P");
    *ret<< new UV("TEST"  ,   "",true,true);          // ,"");
    *ret<< new UV("TF01"  ,   "MÉCANIQUE DES FLUIDES INCOMPRESSIBLES",true,true);          // ,"A_P");
    *ret<< new UV("TF06"  ,   "TRANSFERT DE CHALEUR",false,true);          // ,"P");
    *ret<< new UV("TF07"  ,   "Calcul Des Échangeurs Thermiques Industriels",true,true);          // ,"");
    *ret<< new UV("TF08"  ,   "HYDRODYNAMIQUE DES SYSTÈMES DISPERSÉS",false,true);          // ,"P");
    *ret<< new UV("TF11"  ,   "INTRODUCTION AUX PHÉNOMÈNES DE TRANSFERT",true,false);          // ,"A");
    *ret<< new UV("TF14"  ,   "LES OPÉRATIONS DE TRANSFERT DE MATIÈRE",false,true);          // ,"P");
    *ret<< new UV("TF15"  ,   "",true,true);          // ,"");
    *ret<< new UV("TH02"  ,   "",true,true);          // ,"");
    *ret<< new UV("TH04"  ,   "",true,true);          // ,"");
    *ret<< new UV("TMI01" ,   "Conception Niveau 2 (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("TMI02" ,   "",true,true);          // ,"");
    *ret<< new UV("TMI03" ,   "",true,true);          // ,"");
    *ret<< new UV("TMI04" ,   "",true,true);          // ,"");
    *ret<< new UV("TMI05" ,   "Fabrication Assistee Par Ordinateur Et Machines A Commande Numerique (Apprentissage)",true,true);          // ,"");
    *ret<< new UV("TMI07" ,   "",true,true);          // ,"");
    *ret<< new UV("TMI08" ,   "",true,true);          // ,"");
    *ret<< new UV("TMI09" ,   "",true,true);          // ,"");
    *ret<< new UV("TN01"  ,   "ÉLÉMENTS DE DESSIN TECHNIQUE",true,true);          // ,"A_P");
    *ret<< new UV("TN02"  ,   "INTRODUCTION A LA CONCEPTION MÉCANIQUE",true,true);          // ,"A_P");
    *ret<< new UV("TN03"  ,   "FABRICATION MÉCANIQUE",true,true);          // ,"A_P");
    *ret<< new UV("TN04"  ,   "RÉALISATION",true,true);          // ,"A_P");
    *ret<< new UV("TN05"  ,   "",true,true);          // ,"");
    *ret<< new UV("TN06"  ,   "TRANSMISSION DES EFFORTS EN MÉCANIQUE",true,true);          // ,"A_P");
    *ret<< new UV("TN07"  ,   "",true,true);          // ,"");
    *ret<< new UV("TN08"  ,   "Dessin De Communication",true,true);          // ,"");
    *ret<< new UV("TN09"  ,   "Stage assistant ingénieur",true,true);          // ,"");
    *ret<< new UV("TN10"  ,   "Stage de fin d études",true,true);          // ,"");
    *ret<< new UV("TN12"  ,   "Conception Mécanique",true,true);          // ,"");
    *ret<< new UV("TN13"  ,   "Dimensionnement Pour La Conception Des Systemes Mecaniques",true,true);          // ,"");
    *ret<< new UV("TN14"  ,   "",true,true);          // ,"");
    *ret<< new UV("TN15"  ,   "Création de produit, d’activité, d’entreprise (TM)",true,true);          // ,"A_P");
    *ret<< new UV("TN16"  ,   "Etude interculturelle",true,true);          // ,"A_P");
    *ret<< new UV("TN20"  ,   "CAO : MODÉLISATION GÉOMÉTRIQUE",true,true);          // ,"A_P");
    *ret<< new UV("TN21"  ,   "",true,true);          // ,"");
    *ret<< new UV("TN22"  ,   "éléments De Bureau D études",true,true);          // ,"");
    *ret<< new UV("TN23"  ,   "",true,true);          // ,"");
    *ret<< new UV("TN24"  ,   "Technologies De Fabrication Et Outils Méthodes",true,true);          // ,"");
    *ret<< new UV("TN29"  ,   "Outils De Definition Et De Developpement De Systemes",true,true);          // ,"");
    *ret<< new UV("TN30"  ,   "Xao En Milieu Professionnel",true,true);          // ,"");
    *ret<< new UV("TO01"  ,   "Module De Preparation Au Toeic ",true,true);          // ,"");
    *ret<< new UV("TO02"  ,   "",true,true);          // ,"");
    *ret<< new UV("TO0A"  ,   "",true,true);          // ,"");
    *ret<< new UV("TR91"  ,   "TECHNIQUES DE RECHERCHE D INFORMATION POUR L INGENIEUR",true,true);          // ,"A_P");
    *ret<< new UV("TS01"  ,   "MAITRISE DES RISQUES",false,true);          // ,"P");
    *ret<< new UV("TS02"  ,   "",true,true);          // ,"");
    *ret<< new UV("TX"    ,   "ÉTUDE EXPÉRIMENTALE",true,true);          // ,"A_P");
    *ret<< new UV("UB01"  ,   "COMPOSANTES DES SYSTÈMES TECHNIQUES URBAINS",true,false);          // ,"A");
    *ret<< new UV("UB02"  ,   "Systemes De Transport Urbain",true,true);          // ,"");
    *ret<< new UV("UB04"  ,   "AMBIANCES ET ENVIRONNEMENT LUMINEUX",false,true);          // ,"P");
    *ret<< new UV("UB06"  ,   "Mises En Scènes Urbaines",true,true);          // ,"");
    *ret<< new UV("UB08"  ,   "Hydrologie Urbaine",true,true);          // ,"");
    *ret<< new UV("UB10"  ,   "THERMIQUE URBAINE",true,false);          // ,"A");
    *ret<< new UV("UR01"  ,   "Droit De L Urbanisme, De La Construction Et De L Environnement",true,true);          // ,"");
    *ret<< new UV("UR02"  ,   "THÉORIES ET PRATIQUES DE L URBANISME CONTEMPORAIN",true,false);          // ,"A");
    *ret<< new UV("UR03"  ,   "CARTOGRAPHIE SÉMIOLOGIE GRAPHIQUE ET CAO/DAO",true,true);          // ,"A_P");
    *ret<< new UV("UR04"  ,   "OUTILS POUR LE PROJET",true,false);          // ,"A");
    *ret<< new UV("UR05"  ,   "AMÉNAGEMENT ET ENVIRONNEMENT   TM",false,true);          // ,"P");
    *ret<< new UV("UR06"  ,   "GÉOMATIQUE",true,false);          // ,"A");
    *ret<< new UV("UXD01" ,   "Design D Experience",true,true);          // ,"");

    return ret;
}


QList<Credits*>* DATABASE::UnpersistentDataBaseA::returnCreditsOfAnUV(string codeUV, string portee) const{

    QList<Credits*>* res = new QList<Credits*>;

    if       ( codeUV == "LO21" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "GE37" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "NF17" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "LO22" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "SR03" && portee == "PCB_pour_etudiant_en_GI+FDD"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "TX" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("TM") ,5);

    } else if( codeUV == "IA01" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "NF16" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "SY02" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "IA02" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "RO03" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "RO04" && portee == "PCB_pour_etudiant_en_GI"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "BI01" && portee == "PCB_pour_etudiant_en_GI+FDD"){
        *res<< new Credits( new CreditType("CS") ,6);




    } else if( codeUV == "LA13" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SC24" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "LG51" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SC01" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SO04" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "IC07" && portee == "TSH_accessibles_aux_BRANCHES_uniquement"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "EI03" && portee == "TSH_accessibles_aux_BRANCHES_uniquement"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "LA02" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        *res<< new Credits( new CreditType("TSH") ,4);




    } else if( codeUV == "LA13" && portee == "TableauTSH-col1-ligne2"){
        *res<< new Credits( new CreditType("TSH") ,1);

    } else if( codeUV == "SC24" && portee == "TableauTSH-col2-ligne1"){
        *res<< new Credits( new CreditType("TSH") ,1);

    } else if( codeUV == "LG51" && portee == "TableauTSH-col1-ligne2"){
        *res<< new Credits( new CreditType("TSH") ,1);

    } else if( codeUV == "SC01" && portee == "TableauTSH-col2-ligne1"){
        *res<< new Credits( new CreditType("TSH") ,1);

    } else if( codeUV == "SO04" && portee == "TableauTSH-col2-ligne3"){
        *res<< new Credits( new CreditType("TSH") ,1);

    } else if( codeUV == "IC07" && portee == "TableauTSH-col2-ligne1"){
        *res<< new Credits( new CreditType("TSH") ,1);

    } else if( codeUV == "EI03" && portee == "TableauTSH-col1-ligne3"){
        *res<< new Credits( new CreditType("TSH") ,1);

    } else if( codeUV == "LA02" && portee == "TableauTSH-col1-ligne2"){
        *res<< new Credits( new CreditType("TSH") ,1);



    } else if( codeUV == "GE37" && portee == "TableauTSH-col1-ligne3"){
        *res<< new Credits( new CreditType("TSH") ,1);












///////// "Tous_Cursus_Confondus"




    } else if( codeUV == "LO21" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "GE37" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "NF17" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "LO22" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "SR03" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "TX"   && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TM") ,5);

    } else if( codeUV == "IA01" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "NF16" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "SY02" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "IA02" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "RO03" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "RO04" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "BI01" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "TN09" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("SP") ,30);

    } else if( codeUV == "TN10" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("SP") ,30);

    } else if( codeUV == "LA13" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SC24" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "LG51" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SC01" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SO04" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "IC07" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "EI03" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "LA02" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SY09" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "NF26" && portee == "Tous_Cursus_Confondus"){
        *res<< new Credits( new CreditType("TM") ,6);


///////// "Toutes_Branches_Confondues"




    } else if( codeUV == "LO21" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "GE37" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "NF17" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "LO22" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "SR03" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TM") ,6);

    } else if( codeUV == "TX"   && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TM") ,5);

    } else if( codeUV == "IA01" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "NF16" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "SY02" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "IA02" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "RO03" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "RO04" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "BI01" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "TN09" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("SP") ,30);

    } else if( codeUV == "TN10" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("SP") ,30);

    } else if( codeUV == "LA13" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SC24" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "LG51" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SC01" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SO04" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "IC07" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "EI03" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "LA02" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TSH") ,4);

    } else if( codeUV == "SY09" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("CS") ,6);

    } else if( codeUV == "NF26" && portee == "Toutes_Branches_Confondues"){
        *res<< new Credits( new CreditType("TM") ,6);
    }






    return res;
}





