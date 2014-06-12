

#include "dataBaseA.h"



QList<UV*>* DATABASE::UnpersistentDataBaseA::getAllUVs() const{
    QList<UV*>* ret = new QList<UV*>;

    *ret<< new UV("AA01"  ,   "");          // ,"");
    *ret<< new UV("AP"    ,   "Atelier Projet");          // ,"");
    *ret<< new UV("AP51"  ,   "");          // ,"");
    *ret<< new UV("AP52"  ,   "");          // ,"");
    *ret<< new UV("AP53"  ,   "");          // ,"");
    *ret<< new UV("API01" ,   "");          // ,"");
    *ret<< new UV("API02" ,   "");          // ,"");
    *ret<< new UV("API03" ,   "");          // ,"");
    *ret<< new UV("API04" ,   "");          // ,"");
    *ret<< new UV("API05" ,   "");          // ,"");
    *ret<< new UV("API06" ,   "Analyse De Donnees Et Data Mining (Apprentissage)");          // ,"");
    *ret<< new UV("API07" ,   "Architecture Des Applications Internet, Programmation Web Et Securite (Apprentissage)");          // ,"");
    *ret<< new UV("API08" ,   "Ihm Et Multimédia (Apprentissage)");          // ,"");
    *ret<< new UV("API09" ,   "Méthodes Et Outils Pour L Optimisation Et La Simulation (Apprentissage)");          // ,"");
    *ret<< new UV("API10" ,   "Méthodes De Vérification Et Validation De Logiciel Et Programmation Sous Linux (Apprentissage)");          // ,"");
    *ret<< new UV("AR03"  ,   "Art et technologies contemporaines");          // ,"A_P");
    *ret<< new UV("AR04"  ,   "Art, ville, architecture");          // ,"A");
    *ret<< new UV("AS01"  ,   "Analyse des Situations de l’ingénieur ");          // ,"A_P");
    *ret<< new UV("AS02"  ,   "Accompagnement pour l’Analyse des Situations de l’ingénieur ");          // ,"A_P");
    *ret<< new UV("ASP03" ,   "");          // ,"");
    *ret<< new UV("ASP04" ,   "");          // ,"");
    *ret<< new UV("ASP06" ,   "");          // ,"");
    *ret<< new UV("AV01"  ,   "Initiation à l’analyse et à la réalisation audiovisuelle");          // ,"A_P");
    *ret<< new UV("BA01"  ,   "Equipements Techniques Du Batiment");          // ,"");
    *ret<< new UV("BA02"  ,   "Gestion Technique Du Patrimoine Immobilier");          // ,"");
    *ret<< new UV("BA03"  ,   "MATÉRIAUX DE CONSTRUCTION");          // ,"A");
    *ret<< new UV("BA04"  ,   "Conversion Et Gestion Des Energies Renouvelables");          // ,"");
    *ret<< new UV("BA05"  ,   "");          // ,"");
    *ret<< new UV("BA06"  ,   "");          // ,"");
    *ret<< new UV("BA07"  ,   "MODES OPÉRATOIRES DE LA CONSTRUCTION");          // ,"P");
    *ret<< new UV("BA09"  ,   "Introduction Au Calcul Des Structures Du Batiment");          // ,"");
    *ret<< new UV("BC01"  ,   "");          // ,"");
    *ret<< new UV("BI01"  ,   "MODELES POUR LA BIOINFORMATIQUE");          // ,"P");
    *ret<< new UV("BL01"  ,   "SCIENCES BIOLOGIQUES POUR L INGÉNIEUR");          // ,"A_P");
    *ret<< new UV("BL09"  ,   "BIOPHYSIQUE DES SYSTÈMES BIOLOGIQUES");          // ,"P");
    *ret<< new UV("BL10"  ,   "STRUCTURES ET PHYSICOCHIMIE DES MOLÉCULES BIOLOGIQUES");          // ,"A_P");
    *ret<< new UV("BL16"  ,   "");          // ,"");
    *ret<< new UV("BL17"  ,   "");          // ,"");
    *ret<< new UV("BL20"  ,   "MÉTABOLISME ET PHYSIOLOGIE CELLULAIRE");          // ,"A");
    *ret<< new UV("BL22"  ,   "Microbiologie Et Biologie Moléculaire");          // ,"");
    *ret<< new UV("BL30"  ,   "Physiologie Des Systèmes Intégrés");          // ,"");
    *ret<< new UV("BL40"  ,   "Génie Cellulaire");          // ,"");
    *ret<< new UV("BM01"  ,   "INTRODUCTION À L INSTRUMENTATION BIOMÉDICALE");          // ,"P");
    *ret<< new UV("BM02"  ,   "Organes Artificiels Et Biorheologie");          // ,"");
    *ret<< new UV("BM04"  ,   "");          // ,"");
    *ret<< new UV("BM05"  ,   "");          // ,"");
    *ret<< new UV("BM06"  ,   "");          // ,"");
    *ret<< new UV("BM07"  ,   "");          // ,"");
    *ret<< new UV("BM08"  ,   "Modélisation Des Systèmes Biomécaniques");          // ,"");
    *ret<< new UV("BT02"  ,   "Opérations Agro-Industrielles");          // ,"");
    *ret<< new UV("BT03"  ,   "");          // ,"");
    *ret<< new UV("BT06"  ,   "Analyse Des Produits Biologiques Et Alimentaires");          // ,"");
    *ret<< new UV("BT07"  ,   "");          // ,"");
    *ret<< new UV("BT09"  ,   "INDUSTRIES AGRO-ALIMENTAIRES - QUALITES DE L ALIMENT");          // ,"A");
    *ret<< new UV("BT10"  ,   "Risques Biologiques Et Sécurité Alimentaire");          // ,"");
    *ret<< new UV("BT21"  ,   "Biotechnologies Moleculaires Et Genie Genetique");          // ,"");
    *ret<< new UV("BT22"  ,   "Les Agroressources");          // ,"");
    *ret<< new UV("C2I1"  ,   "CERTIFICAT INFORMATIQUE ET INTERNET NIVEAU 1");          // ,"A_P");
    *ret<< new UV("CM01"  ,   "PHYSIQUE DE LA MATIÈRE");          // ,"P");
    *ret<< new UV("CM04"  ,   "PROCÉDÉS INDUSTRIELS");          // ,"A");
    *ret<< new UV("CM05"  ,   "THERMODYNAMIQUE CHIMIQUE");          // ,"A");
    *ret<< new UV("CM06"  ,   "CALCUL D UNE OPÉRATION INDUSTRIELLE");          // ,"A_P");
    *ret<< new UV("CM07"  ,   "TRAVAUX PRATIQUES DE GÉNIE CHIMIQUE");          // ,"A_P");
    *ret<< new UV("CM11"  ,   "CHIMIE GÉNÉRALE");          // ,"A_P");
    *ret<< new UV("CM12"  ,   "CHIMIE PHYSIQUE MINÉRALE");          // ,"A");
    *ret<< new UV("CM13"  ,   "CHIMIE DES SUBSTANCES ORGANIQUES ET BIOLOGIQUES");          // ,"A_P");
    *ret<< new UV("CM15"  ,   "SYSTEMES COLLOIDAUX - APPLICATIONS AGROALIMENTAIRES");          // ,"P");
    *ret<< new UV("CM40"  ,   "Catalyse Heterogene");          // ,"");
    *ret<< new UV("CM70"  ,   "TRAVAUX PRATIQUES DE GP (1)");          // ,"P");
    *ret<< new UV("CT02"  ,   "Maitrise Statistique Des Processus");          // ,"");
    *ret<< new UV("CT04"  ,   "Controles Non Destructifs");          // ,"");
    *ret<< new UV("DD01"  ,   "Séminaire Développement Durable ");          // ,"A_P");
    *ret<< new UV("DD02"  ,   "Introduction A L Eco-Conception Et A L Analyse De Cycle De Vie");          // ,"");
    *ret<< new UV("DI01"  ,   "Initiation au design industriel");          // ,"A_P");
    *ret<< new UV("DI02"  ,   "Initiation au design graphique");          // ,"A_P");
    *ret<< new UV("DI03"  ,   "Conception Formelle Des Produits");          // ,"");
    *ret<< new UV("DI05"  ,   "Methodologie Et Analyse De La Valeur");          // ,"");
    *ret<< new UV("DI06"  ,   "Analyse Des Produits De Consommation");          // ,"");
    *ret<< new UV("DI07"  ,   "");          // ,"");
    *ret<< new UV("DI08"  ,   "");          // ,"");
    *ret<< new UV("EG01"  ,   "Ergonomie");          // ,"");
    *ret<< new UV("EI03"  ,   "Communication interculturelle");          // ,"A_P");
    *ret<< new UV("EI04"  ,   "Intelligence économique : stratégie d’entreprise et outils");          // ,"A_P");
    *ret<< new UV("EI05"  ,   "Science, technologie et société dans l’UE");          // ,"A_P");
    *ret<< new UV("EL01"  ,   "PHÉNOMÈNES ELECTROMAGNÉTIQUES");          // ,"P");
    *ret<< new UV("EL02"  ,   "ÉLECTRICITÉ INDUSTRIELLE APPLIQUÉE");          // ,"P");
    *ret<< new UV("EN14"  ,   "Fonctions Électroniques Pour L Ingénieur");          // ,"");
    *ret<< new UV("EN21"  ,   "BASES DE L ÉLECTRONIQUE ANALOGIQUE");          // ,"A_P");
    *ret<< new UV("EN90"  ,   "ELECTRONIQUE NUMÉRIQUE");          // ,"A");
    *ret<< new UV("EV01"  ,   "Procédés De Traitement Des Déchets");          // ,"");
    *ret<< new UV("EV02"  ,   "");          // ,"");
    *ret<< new UV("FPP01" ,   "");          // ,"");
    *ret<< new UV("FPP02" ,   "Fiabilite Et Ingenierie Robuste De Produits (Apprentissage)");          // ,"");
    *ret<< new UV("FPP03" ,   "");          // ,"");
    *ret<< new UV("FQ01"  ,   "ÉCONOMIE GLOBALE ET MAITRISE DE LA QUALITÉ");          // ,"A_P");
    *ret<< new UV("FQ03"  ,   "");          // ,"");
    *ret<< new UV("FQ04"  ,   "");          // ,"");
    *ret<< new UV("FQ05"  ,   "");          // ,"");
    *ret<< new UV("FQ07"  ,   "La Qualité Des Services A L Industrie");          // ,"");
    *ret<< new UV("GE10"  ,   "Economie politique");          // ,"A_P");
    *ret<< new UV("GE12"  ,   "Géographie et économie des territoires");          // ,"A_P");
    *ret<< new UV("GE13"  ,   "Les risques entre technique et société");          // ,"A_P");
    *ret<< new UV("GE15"  ,   "Initiation à la création et gestion d’entreprise");          // ,"A_P");
    *ret<< new UV("GE20"  ,   "Economie industrielle");          // ,"A_P");
    *ret<< new UV("GE21"  ,   "Economie et gestion de l’innovation et du numérique");          // ,"A_P");
    *ret<< new UV("GE22"  ,   "Economie internationale");          // ,"A_P");
    *ret<< new UV("GE23"  ,   "Transferts de technologie et développement");          // ,"A_P");
    *ret<< new UV("GE24"  ,   "Recherche & développement : ingénieurs et investisseurs");          // ,"P");
    *ret<< new UV("GE25"  ,   "Gestion et organisation de la production");          // ,"A_P");
    *ret<< new UV("GE26"  ,   "Management stratégique des ressources humaines");          // ,"A_P");
    *ret<< new UV("GE27"  ,   "Gestion financière de l’entreprise");          // ,"A");
    *ret<< new UV("GE28"  ,   "Economie et droit de la propriété intellectuelle");          // ,"A_P");
    *ret<< new UV("GE29"  ,   "Management d’entreprise internationale");          // ,"A_P");
    *ret<< new UV("GE36"  ,   "Marketing");          // ,"A_P");
    *ret<< new UV("GE37"  ,   "GESTION DE PROJET");          // ,"A_P");
    *ret<< new UV("GE38"  ,   "MANAGEMENT ET OUTILS D AIDE À LA CRÉATIVITÉ INDUSTRIELLE ET À L INNOVATION");          // ,"A_P");
    *ret<< new UV("GE39"  ,   "MANAGEMENT ET MARKETING DE L INNOVATION");          // ,"A_P");
    *ret<< new UV("GE40"  ,   "MANAGEMENT DE PROJETS");          // ,"A");
    *ret<< new UV("GE90"  ,   "Organisations, innovations et international ");          // ,"A_P");
    *ret<< new UV("GPL01" ,   "Gestion De Production Et Erp (Apprentissage)");          // ,"");
    *ret<< new UV("GPL02" ,   "");          // ,"");
    *ret<< new UV("GPL03" ,   "");          // ,"");
    *ret<< new UV("HE01"  ,   "Epistémologie et histoire des sciences");          // ,"A_P");
    *ret<< new UV("HE03"  ,   "Logique, histoire et formalisme");          // ,"A_P");
    *ret<< new UV("HE04"  ,   "Epistémologie et pratiques des modèles ");          // ,"A_P");
    *ret<< new UV("HE05"  ,   "Culture Technique");          // ,"A_P");
    *ret<< new UV("HT02"  ,   "");          // ,"");
    *ret<< new UV("IA01"  ,   "INTELLIGENCE ARTIFICIELLE : REPRÉSENTATION");          // ,"A");
    *ret<< new UV("IA02"  ,   "RÉSOLUTION DE PROBLÈMES ET PROGRAMMATION LOGIQUE");          // ,"P");
    *ret<< new UV("IA03"  ,   "TECHNIQUES DE MODÉLISATION, CAPITALISATION ET GESTION DES CONNAISSANCES");          // ,"A");
    *ret<< new UV("IA04"  ,   "SYSTÈMES MULTIAGENTS");          // ,"P");
    *ret<< new UV("IC01"  ,   "Histoire et prospective des industries culturelles");          // ,"P");
    *ret<< new UV("IC03"  ,   "Le numérique : des formats aux chaînes de production");          // ,"A_P");
    *ret<< new UV("IC05"  ,   "Technologies pour la documentique et l’indexation hypermédia");          // ,"A_P");
    *ret<< new UV("IC06"  ,   "Conception et industrie des jeux vidéo");          // ,"A_P");
    *ret<< new UV("IC07"  ,   "Techniques et technologies du musical et du sonore");          // ,"A_P");
    *ret<< new UV("IR00"  ,   "Initiation à la recherche");          // ,"A_P");
    *ret<< new UV("LA00"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA01"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA02"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA03"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA04"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA11"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA12"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA13"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA14"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA15"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA20"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA21"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA22"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA23"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA24"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA91"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA92"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA93"  ,   "''");          // ,"A_P");
    *ret<< new UV("LA94"  ,   "''");          // ,"A_P");
    *ret<< new UV("LB04"  ,   "''");          // ,"A_P");
    *ret<< new UV("LB14"  ,   "''");          // ,"A_P");
    *ret<< new UV("LB24"  ,   "''");          // ,"A_P");
    *ret<< new UV("LC14"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG30"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG31"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG32"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG40"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG41"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG42"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG50"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG51"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG52"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG53"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG60"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG61"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG62"  ,   "''");          // ,"A_P");
    *ret<< new UV("LG63"  ,   "''");          // ,"A_P");
    *ret<< new UV("LNG01" ,   "''");          // ,"A_P");
    *ret<< new UV("LNG02" ,   "''");          // ,"A_P");
    *ret<< new UV("LNG03" ,   "''");          // ,"A_P");
    *ret<< new UV("LNG04" ,   "''");          // ,"A_P");
    *ret<< new UV("LNG05" ,   "''");          // ,"A_P");
    *ret<< new UV("LNG14" ,   "''");          // ,"A_P");
    *ret<< new UV("LO01"  ,   "BASES DE LA PROGRAMMATION");          // ,"A_P");
    *ret<< new UV("LO12"  ,   "INFOGRAPHIE ET IMAGES DE SYNTHÈSE");          // ,"A");
    *ret<< new UV("LO17"  ,   "INDEXATION ET RECHERCHE D INFORMATION");          // ,"A_P");
    *ret<< new UV("LO18"  ,   "PROJETS MULTIMÉDIA POUR LA FORMATION");          // ,"P");
    *ret<< new UV("LO21"  ,   "PROGRAMMATION ET CONCEPTION ORIENTEES OBJET");          // ,"P");
    *ret<< new UV("LO22"  ,   "GENIE LOGICIEL");          // ,"P");
    *ret<< new UV("LO23"  ,   "CONDUITE DE PROJET INFORMATIQUE");          // ,"A");
    *ret<< new UV("MA11"  ,   "RÉVISION D ANALYSE ET D ALGÈBRE (GM, GSM, GP)");          // ,"A_P");
    *ret<< new UV("MAT01" ,   "");          // ,"");
    *ret<< new UV("MAT02" ,   "");          // ,"");
    *ret<< new UV("MAT03" ,   "Mecanique Des Materiaux (Apprentissage)");          // ,"");
    *ret<< new UV("MB11"  ,   "RÉVISION D ANALYSE ET D ALGÈBRE (GB, GI, GSU)");          // ,"A_P");
    *ret<< new UV("MC01"  ,   "Machines Électriques");          // ,"");
    *ret<< new UV("MC02"  ,   "");          // ,"");
    *ret<< new UV("MC05"  ,   "Machines De Transfert De Fluides");          // ,"");
    *ret<< new UV("MC06"  ,   "");          // ,"");
    *ret<< new UV("MC07"  ,   "Électronique De Puissance");          // ,"");
    *ret<< new UV("MC08"  ,   "");          // ,"");
    *ret<< new UV("MEQ01" ,   "");          // ,"");
    *ret<< new UV("MEQ02" ,   "");          // ,"");
    *ret<< new UV("MEQ03" ,   "Dynamique Des Solides (Apprentissage)");          // ,"");
    *ret<< new UV("MEQ04" ,   "");          // ,"");
    *ret<< new UV("MEQ05" ,   "");          // ,"");
    *ret<< new UV("MG01"  ,   "Management en entreprise : styles de management, construction d’équipe et techniques de travail en groupe (P)");          // ,"A_P");
    *ret<< new UV("MG02"  ,   "");          // ,"");
    *ret<< new UV("MI01"  ,   "STRUCTURE D UN CALCULATEUR");          // ,"A");
    *ret<< new UV("MI03"  ,   "SYSTÈMES TEMPS RÉEL");          // ,"P");
    *ret<< new UV("MP02"  ,   "INTRODUCTION AUX MÉTHODES DE LA GPAO");          // ,"P");
    *ret<< new UV("MP03"  ,   "SUPPLY CHAIN MANAGEMENT");          // ,"A");
    *ret<< new UV("MQ01"  ,   "ÉLÉMENTS DE RESISTANCE DES MATÉRIAUX");          // ,"A_P");
    *ret<< new UV("MQ02"  ,   "Mécanique Des Solides Déformables");          // ,"");
    *ret<< new UV("MQ03"  ,   "MÉCANIQUE DES VIBRATIONS I");          // ,"A_P");
    *ret<< new UV("MQ04"  ,   "Polymères");          // ,"");
    *ret<< new UV("MQ05"  ,   "");          // ,"");
    *ret<< new UV("MQ06"  ,   "Modélisation Des Structures Par Éléments Finis");          // ,"");
    *ret<< new UV("MQ07"  ,   "");          // ,"");
    *ret<< new UV("MQ08"  ,   "Elaboration Et Proprietes D Usage Des Metaux");          // ,"");
    *ret<< new UV("MQ09"  ,   "Mécanique Des Vibrations II");          // ,"");
    *ret<< new UV("MQ10"  ,   "Comportement Mécanique Des Matériaux");          // ,"");
    *ret<< new UV("MQ11"  ,   "Mise En Oeuvre Des Matériaux");          // ,"");
    *ret<< new UV("MQ12"  ,   "");          // ,"");
    *ret<< new UV("MQ13"  ,   "");          // ,"");
    *ret<< new UV("MQ14"  ,   "Optimisation En Mécanique");          // ,"");
    *ret<< new UV("MQ16"  ,   "");          // ,"");
    *ret<< new UV("MQ17"  ,   "INTRODUCTION AUX PROPRIÉTÉS MÉCANIQUES ET À L INGÉNIERIE DES MATÉRIAUX");          // ,"A_P");
    *ret<< new UV("MQ18"  ,   "Cinématique Et Dynamique Des Systèmes");          // ,"");
    *ret<< new UV("MQ19"  ,   "Dynamique Des Structures");          // ,"");
    *ret<< new UV("MQ20"  ,   "INTRODUCTION A LA MÉCANIQUE DES SOLIDES ET DES FLUIDES");          // ,"A");
    *ret<< new UV("MS01"  ,   "MÉTHODES D ANALYSE PHYSICO-CHIMIQUE");          // ,"A_P");
    *ret<< new UV("MS02"  ,   "Principes Physiques Des Capteurs Et Instrumentation");          // ,"");
    *ret<< new UV("MS03"  ,   "Pratique Expérimentale En Acoustique Et Vibrations");          // ,"");
    *ret<< new UV("MT09"  ,   "ANALYSE NUMÉRIQUE");          // ,"A");
    *ret<< new UV("MT10"  ,   "STRUCTURES,CALCUL FORMEL ET ALGORITHMES");          // ,"P");
    *ret<< new UV("MT12"  ,   "METHODES MATHEMATIQUES POUR L ANALYSE DU SIGNAL ET DE L IMAGE");          // ,"A_P");
    *ret<< new UV("MT22"  ,   "FONCTIONS DE PLUSIEURS VARIABLES RÉELLES ET APPLICATIONS");          // ,"A_P");
    *ret<< new UV("MT23"  ,   "ALGÈBRE LINÉAIRE ET APPLICATIONS");          // ,"A_P");
    *ret<< new UV("MT31"  ,   "");          // ,"");
    *ret<< new UV("MT32"  ,   "");          // ,"");
    *ret<< new UV("MT33"  ,   "");          // ,"");
    *ret<< new UV("MT34"  ,   "Analyse 2 : Mesures, Intégrations, Probabilités");          // ,"");
    *ret<< new UV("MT35"  ,   "");          // ,"");
    *ret<< new UV("MT36"  ,   "");          // ,"");
    *ret<< new UV("MT37"  ,   "Logiques, Quelques Approfondissements Mathématiques Et Philosophiques");          // ,"");
    *ret<< new UV("MT38"  ,   "Probabilités");          // ,"");
    *ret<< new UV("MT90"  ,   "FONCTIONS D UNE VARIABLE REELLE 1");          // ,"A_P");
    *ret<< new UV("MT91"  ,   "FONCTIONS D UNE VARIABLE REELLE 2");          // ,"A_P");
    *ret<< new UV("MT94"  ,   "INTRODUCTION AUX MATHEMATIQUES APPLIQUÉES");          // ,"P");
    *ret<< new UV("MU01"  ,   "Pratique instrumentale d’ensemble");          // ,"A_P");
    *ret<< new UV("MU02"  ,   "Pratique instrumentale de haut niveau");          // ,"A_P");
    *ret<< new UV("MU03"  ,   "Pratique collective de musiques contemporaines");          // ,"A_P");
    *ret<< new UV("NF01"  ,   "ALGORITHMIQUE ET PROGRAMMATION");          // ,"A_P");
    *ret<< new UV("NF02"  ,   "DU CIRCUIT INTÉGRÉ AU MICROPROCESSEUR");          // ,"A_P");
    *ret<< new UV("NF04"  ,   "MODÉLISATION NUMÉRIQUE DES PROBLÈMES DE L INGÉNIEUR");          // ,"A_P");
    *ret<< new UV("NF11"  ,   "THÉORIE DES LANGAGES DE PROGRAMMATION");          // ,"P");
    *ret<< new UV("NF15"  ,   "MICROPROCESSEURS, INTERFACES ET LOGICIELS DE BASES");          // ,"P");
    *ret<< new UV("NF16"  ,   "ALGORITHMIQUE ET STRUCTURES DE DONNÉES");          // ,"A_P");
    *ret<< new UV("NF17"  ,   "CONCEPTION DE BASES DE DONNÉES");          // ,"P");
    *ret<< new UV("NF22"  ,   "MICRO-ORDINATEURS ET APPLICATIONS");          // ,"A_P");
    *ret<< new UV("NF24"  ,   "Modelisation Et Simulation Des Procedes");          // ,"");
    *ret<< new UV("NF26"  ,   "DATA WAREHOUSE ET OUTILS DÉCISIONNELS");          // ,"P");
    *ret<< new UV("NF28"  ,   "INGÉNIERIE DES SYSTÈMES INTÉRACTIFS");          // ,"P");
    *ret<< new UV("NF29"  ,   "INGÉNIERIE DOCUMENTAIRE ET SUPPORTS D INFORMATION");          // ,"A");
    *ret<< new UV("NF33"  ,   "CONCEPTION ET ARCHITECTURE DE SYSTÈMES NUMÉRIQUES INFORMATIQUES");          // ,"P");
    *ret<< new UV("NF92"  ,   "TRAITEMENT AUTOMATIQUE DE L INFORMATION");          // ,"A_P");
    *ret<< new UV("NF93"  ,   "SCIENCES DE L INFORMATIQUE");          // ,"A");
    *ret<< new UV("NP90"  ,   "NANO-PROJETS");          // ,"A_P");
    *ret<< new UV("NP94"  ,   "PREPARATION SCIENTIFIQUE A UN SUJET CHALLENGE DE TN04");          // ,"A");
    *ret<< new UV("NX17"  ,   "INTRODUCTION AUX BASES DE DONNEES");          // ,"P");
    *ret<< new UV("PAE01" ,   "");          // ,"");
    *ret<< new UV("PAE02" ,   "");          // ,"");
    *ret<< new UV("PAE03" ,   "");          // ,"");
    *ret<< new UV("PH01"  ,   "Introduction à la philosophie");          // ,"A_P");
    *ret<< new UV("PH02"  ,   "L’ingénieur, le philosophe et le scientifique");          // ,"A_P");
    *ret<< new UV("PH03"  ,   "Penser la technique aujourd’hui");          // ,"A_P");
    *ret<< new UV("PH09"  ,   "Ethique : une approche pluridisciplinaire ?");          // ,"A_P");
    *ret<< new UV("PH10"  ,   "Analyse phénoménologique des objets audiovisuels");          // ,"A");
    *ret<< new UV("PH11"  ,   "");          // ,"");
    *ret<< new UV("PH12"  ,   "");          // ,"");
    *ret<< new UV("PR"    ,   "RÉALISATION DE PROJET");          // ,"A_P");
    *ret<< new UV("PS04"  ,   "THERMODYNAMIQUE");          // ,"A_P");
    *ret<< new UV("PS05"  ,   "Fondements De L Acoustique Et Modélisations");          // ,"");
    *ret<< new UV("PS09"  ,   "ACOUSTIQUE APPLIQUÉE");          // ,"P");
    *ret<< new UV("PS10"  ,   "");          // ,"");
    *ret<< new UV("PS12"  ,   "");          // ,"");
    *ret<< new UV("PS13"  ,   "");          // ,"");
    *ret<< new UV("PS15"  ,   "THERMODYNAMIQUE PHYSIQUE");          // ,"A");
    *ret<< new UV("PS90"  ,   "INTRODUCTION A LA MESURE");          // ,"A_P");
    *ret<< new UV("PS91"  ,   "MECANIQUE PHYSIQUE");          // ,"A_P");
    *ret<< new UV("PS92"  ,   "DYNAMIQUE DES SYSTEMES ET DES SOLIDES");          // ,"P");
    *ret<< new UV("PS93"  ,   "OPTIQUE GEOMETRIQUE");          // ,"A_P");
    *ret<< new UV("PS94"  ,   "ELECTRICITE");          // ,"A_P");
    *ret<< new UV("PS95"  ,   "ONDES ET ELECTROMAGNETISME 1");          // ,"A");
    *ret<< new UV("PS96"  ,   "ONDES ET ELECTROMAGNETISME 2");          // ,"A");
    *ret<< new UV("RO03"  ,   "RECHERCHE OPÉRATIONNELLE, OPTIMISATION COMBINATOIRE");          // ,"P");
    *ret<< new UV("RO04"  ,   "OPTIMISATION ET RECHERCHE OPÉRATIONNELLE");          // ,"P");
    *ret<< new UV("RO05"  ,   "MODÉLISATION DE PHÉNOMÈNES ALÉATOIRES");          // ,"A");
    *ret<< new UV("RO06"  ,   "SIMULATION ET TECHNIQUES D OPTIMISATION");          // ,"A");
    *ret<< new UV("RR01"  ,   "CINÉTIQUE CHIMIQUE ET RÉACTEURS HOMOGÈNES");          // ,"P");
    *ret<< new UV("RR02"  ,   "CALCULS DES RÉACTEURS INDUSTRIELS");          // ,"A");
    *ret<< new UV("RV01"  ,   "RÉALITÉ VIRTUELLE");          // ,"A");
    *ret<< new UV("SA11"  ,   "Pratiques théâtrales");          // ,"A_P");
    *ret<< new UV("SC01"  ,   "Séminaire PHITECO ");          // ,"A_P");
    *ret<< new UV("SC11"  ,   "Théorie des sciences cognitives");          // ,"A_P");
    *ret<< new UV("SC12"  ,   "Technologie et cognition");          // ,"A_P");
    *ret<< new UV("SC21"  ,   "Linguistique(s) et philosophie(s) du langage");          // ,"A_P");
    *ret<< new UV("SC22"  ,   "Sociologie cognitive, lien social et techniques");          // ,"A_P");
    *ret<< new UV("SC23"  ,   "Analyse des usages");          // ,"A_P");
    *ret<< new UV("SC24"  ,   "Apprentissage et perception");          // ,"A_P");
    *ret<< new UV("SCI08" ,   "Introduction A L Ingenierie Systeme");          // ,"");
    *ret<< new UV("SI01"  ,   "Science et débat public");          // ,"A_P");
    *ret<< new UV("SI02"  ,   "Communication professionnelle de l’ingénieur");          // ,"A_P");
    *ret<< new UV("SI05"  ,   "Théories de la communication");          // ,"A_P");
    *ret<< new UV("SI06"  ,   "La documentation technique");          // ,"A_P");
    *ret<< new UV("SI07"  ,   "Médias et Industries culturelles");          // ,"A_P");
    *ret<< new UV("SI11"  ,   "Expression orale, parole publique");          // ,"A_P");
    *ret<< new UV("SI14"  ,   "Parole publique en anglais");          // ,"A_P");
    *ret<< new UV("SI20"  ,   "Rhétorique et arts du discours");          // ,"A_P");
    *ret<< new UV("SI22"  ,   "Signes et contenus numériques");          // ,"A_P");
    *ret<< new UV("SI24"  ,   "Ecritures numériques ordinaires    ");          // ,"A_P");
    *ret<< new UV("SI28"  ,   "Ecriture interactive et multimédia ");          // ,"A_P");
    *ret<< new UV("SI90"  ,   "Communication des Connaissances Technologiques     ");          // ,"A_P");
    *ret<< new UV("SL"    ,   "Suivi Linguistique");          // ,"");
    *ret<< new UV("SL0A"  ,   "");          // ,"");
    *ret<< new UV("SO04"  ,   "Initiation au Droit");          // ,"A_P");
    *ret<< new UV("SO05"  ,   "Sociologie, organisations et dynamiques des collectifs");          // ,"A_P");
    *ret<< new UV("SO06"  ,   "Organisation des systèmes de santé");          // ,"A_P");
    *ret<< new UV("SP01"  ,   "Un corps pour apprendre et comprendre");          // ,"A_P");
    *ret<< new UV("SP02"  ,   "Conduire un projet sportif");          // ,"A_P");
    *ret<< new UV("SP11"  ,   "Physiologie de l’effort sportif");          // ,"P");
    *ret<< new UV("SP22"  ,   "S’apprendre pour mieux gérer");          // ,"A_P");
    *ret<< new UV("SR01"  ,   "MAITRISE DES SYSTÈMES INFORMATIQUES");          // ,"A");
    *ret<< new UV("SR02"  ,   "SYSTÈMES D EXPLOITATION : DES CONCEPTS À LA PROGRAMMATION");          // ,"P");
    *ret<< new UV("SR03"  ,   "ARCHITECTURE DES APPLICATIONS INTERNET");          // ,"P");
    *ret<< new UV("SR04"  ,   "RÉSEAUX INFORMATIQUES");          // ,"A");
    *ret<< new UV("SR05"  ,   "ALGORITHMES ET SYSTÈMES RÉPARTIS");          // ,"A");
    *ret<< new UV("SR06"  ,   "SÉCURITÉ SYSTÈMES ET RÉSEAUX");          // ,"A");
    *ret<< new UV("SSA03" ,   "");          // ,"");
    *ret<< new UV("SSA04" ,   "");          // ,"");
    *ret<< new UV("SSA06" ,   "");          // ,"");
    *ret<< new UV("SY01"  ,   "ÉLÉMENTS DE PROBABILITÉS");          // ,"A_P");
    *ret<< new UV("SY02"  ,   "MÉTHODES STATISTIQUES POUR L INGÉNIEUR");          // ,"A_P");
    *ret<< new UV("SY03"  ,   "INTRODUCTION AUX SYSTEMES D ENTRAINEMENTS ELECTRIQUES");          // ,"A");
    *ret<< new UV("SY04"  ,   "SYSTÈMES ASSERVIS LINÉAIRES : ANALYSE ET COMMANDE");          // ,"P");
    *ret<< new UV("SY05"  ,   "CONDUITE DES PROCÉDÉS");          // ,"P");
    *ret<< new UV("SY06"  ,   "ANALYSE ET TRAITEMENT DU SIGNAL");          // ,"P");
    *ret<< new UV("SY08"  ,   "MODÉLISATION DES SYSTÈMES A ÉVÈNEMENTS DISCRETS");          // ,"A");
    *ret<< new UV("SY09"  ,   "ANALYSE DES DONNÉES ET DATA MINING");          // ,"P");
    *ret<< new UV("SY10"  ,   "");          // ,"");
    *ret<< new UV("SY12"  ,   "Modélisation Et Performance Des Systèmes De Production");          // ,"");
    *ret<< new UV("SY14"  ,   "ÉLÉMENTS D AUTOMATIQUE");          // ,"P");
    *ret<< new UV("SY15"  ,   "AUTOMATIQUE AVANCÉE");          // ,"P");
    *ret<< new UV("SY16"  ,   "");          // ,"");
    *ret<< new UV("SY19"  ,   "DECISION ET APPRENTISSAGE AUTOMATIQUE");          // ,"A");
    *ret<< new UV("SY23"  ,   "VISION ET IMAGE");          // ,"P");
    *ret<< new UV("SY26"  ,   "TÉLÉCOMMUNICATIONS");          // ,"P");
    *ret<< new UV("SY27"  ,   "MACHINES INTELLIGENTES");          // ,"A");
    *ret<< new UV("SY31"  ,   "CAPTEURS POUR LES SYSTEMES INTELLIGENTS");          // ,"A");
    *ret<< new UV("TA02"  ,   "ÉVALUATION ÉCONOMIQUE DES PROCÉDÉS");          // ,"P");
    *ret<< new UV("TEST"  ,   "");          // ,"");
    *ret<< new UV("TF01"  ,   "MÉCANIQUE DES FLUIDES INCOMPRESSIBLES");          // ,"A_P");
    *ret<< new UV("TF06"  ,   "TRANSFERT DE CHALEUR");          // ,"P");
    *ret<< new UV("TF07"  ,   "Calcul Des Échangeurs Thermiques Industriels");          // ,"");
    *ret<< new UV("TF08"  ,   "HYDRODYNAMIQUE DES SYSTÈMES DISPERSÉS");          // ,"P");
    *ret<< new UV("TF11"  ,   "INTRODUCTION AUX PHÉNOMÈNES DE TRANSFERT");          // ,"A");
    *ret<< new UV("TF14"  ,   "LES OPÉRATIONS DE TRANSFERT DE MATIÈRE");          // ,"P");
    *ret<< new UV("TF15"  ,   "");          // ,"");
    *ret<< new UV("TH02"  ,   "");          // ,"");
    *ret<< new UV("TH04"  ,   "");          // ,"");
    *ret<< new UV("TMI01" ,   "Conception Niveau 2 (Apprentissage)");          // ,"");
    *ret<< new UV("TMI02" ,   "");          // ,"");
    *ret<< new UV("TMI03" ,   "");          // ,"");
    *ret<< new UV("TMI04" ,   "");          // ,"");
    *ret<< new UV("TMI05" ,   "Fabrication Assistee Par Ordinateur Et Machines A Commande Numerique (Apprentissage)");          // ,"");
    *ret<< new UV("TMI07" ,   "");          // ,"");
    *ret<< new UV("TMI08" ,   "");          // ,"");
    *ret<< new UV("TMI09" ,   "");          // ,"");
    *ret<< new UV("TN01"  ,   "ÉLÉMENTS DE DESSIN TECHNIQUE");          // ,"A_P");
    *ret<< new UV("TN02"  ,   "INTRODUCTION A LA CONCEPTION MÉCANIQUE");          // ,"A_P");
    *ret<< new UV("TN03"  ,   "FABRICATION MÉCANIQUE");          // ,"A_P");
    *ret<< new UV("TN04"  ,   "RÉALISATION");          // ,"A_P");
    *ret<< new UV("TN05"  ,   "");          // ,"");
    *ret<< new UV("TN06"  ,   "TRANSMISSION DES EFFORTS EN MÉCANIQUE");          // ,"A_P");
    *ret<< new UV("TN07"  ,   "");          // ,"");
    *ret<< new UV("TN08"  ,   "Dessin De Communication");          // ,"");
    *ret<< new UV("TN09"  ,   "Stage assistant ingénieur");          // ,"");
    *ret<< new UV("TN10"  ,   "Stage de fin d études");          // ,"");
    *ret<< new UV("TN12"  ,   "Conception Mécanique");          // ,"");
    *ret<< new UV("TN13"  ,   "Dimensionnement Pour La Conception Des Systemes Mecaniques");          // ,"");
    *ret<< new UV("TN14"  ,   "");          // ,"");
    *ret<< new UV("TN15"  ,   "Création de produit, d’activité, d’entreprise (TM)");          // ,"A_P");
    *ret<< new UV("TN16"  ,   "Etude interculturelle");          // ,"A_P");
    *ret<< new UV("TN20"  ,   "CAO : MODÉLISATION GÉOMÉTRIQUE");          // ,"A_P");
    *ret<< new UV("TN21"  ,   "");          // ,"");
    *ret<< new UV("TN22"  ,   "éléments De Bureau D études");          // ,"");
    *ret<< new UV("TN23"  ,   "");          // ,"");
    *ret<< new UV("TN24"  ,   "Technologies De Fabrication Et Outils Méthodes");          // ,"");
    *ret<< new UV("TN29"  ,   "Outils De Definition Et De Developpement De Systemes");          // ,"");
    *ret<< new UV("TN30"  ,   "Xao En Milieu Professionnel");          // ,"");
    *ret<< new UV("TO01"  ,   "Module De Preparation Au Toeic ");          // ,"");
    *ret<< new UV("TO02"  ,   "");          // ,"");
    *ret<< new UV("TO0A"  ,   "");          // ,"");
    *ret<< new UV("TR91"  ,   "TECHNIQUES DE RECHERCHE D INFORMATION POUR L INGENIEUR");          // ,"A_P");
    *ret<< new UV("TS01"  ,   "MAITRISE DES RISQUES");          // ,"P");
    *ret<< new UV("TS02"  ,   "");          // ,"");
    *ret<< new UV("TX"    ,   "ÉTUDE EXPÉRIMENTALE");          // ,"A_P");
    *ret<< new UV("UB01"  ,   "COMPOSANTES DES SYSTÈMES TECHNIQUES URBAINS");          // ,"A");
    *ret<< new UV("UB02"  ,   "Systemes De Transport Urbain");          // ,"");
    *ret<< new UV("UB04"  ,   "AMBIANCES ET ENVIRONNEMENT LUMINEUX");          // ,"P");
    *ret<< new UV("UB06"  ,   "Mises En Scènes Urbaines");          // ,"");
    *ret<< new UV("UB08"  ,   "Hydrologie Urbaine");          // ,"");
    *ret<< new UV("UB10"  ,   "THERMIQUE URBAINE");          // ,"A");
    *ret<< new UV("UR01"  ,   "Droit De L Urbanisme, De La Construction Et De L Environnement");          // ,"");
    *ret<< new UV("UR02"  ,   "THÉORIES ET PRATIQUES DE L URBANISME CONTEMPORAIN");          // ,"A");
    *ret<< new UV("UR03"  ,   "CARTOGRAPHIE SÉMIOLOGIE GRAPHIQUE ET CAO/DAO");          // ,"A_P");
    *ret<< new UV("UR04"  ,   "OUTILS POUR LE PROJET");          // ,"A");
    *ret<< new UV("UR05"  ,   "AMÉNAGEMENT ET ENVIRONNEMENT   TM");          // ,"P");
    *ret<< new UV("UR06"  ,   "GÉOMATIQUE");          // ,"A");
    *ret<< new UV("UXD01" ,   "Design D Experience");          // ,"");

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





