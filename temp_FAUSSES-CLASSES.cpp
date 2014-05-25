#include "temp_FAUSSES-CLASSES.h"

using namespace FOOO;

QList<Credits> dataBase::returnCreditsOfAnUV(string codeUV, string portee) const{

    QList<Credits> res = QList<Credits>();

    if       ( codeUV == "LO21" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("TM") ,6);

	} else if( codeUV == "GE37" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("TM") ,6);

	} else if( codeUV == "NF17" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("TM") ,6);

	} else if( codeUV == "LO22" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("TM") ,6);

	} else if( codeUV == "SR03" && portee == "PCB_pour_etudiant_en_GI+FDD"){
        res<<Credits( new CreditType("TM") ,6);

	} else if( codeUV == "TX" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("TM") ,5);

	} else if( codeUV == "IA01" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("CS") ,6);

	} else if( codeUV == "NF16" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("CS") ,6);

	} else if( codeUV == "SY02" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("CS") ,6);

	} else if( codeUV == "IA02" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("CS") ,6);

	} else if( codeUV == "RO03" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("CS") ,6);

	} else if( codeUV == "RO04" && portee == "PCB_pour_etudiant_en_GI"){
        res<<Credits( new CreditType("CS") ,6);

	} else if( codeUV == "BI01" && portee == "PCB_pour_etudiant_en_GI+FDD"){
        res<<Credits( new CreditType("CS") ,6);

	} else if( codeUV == "TN09" && portee == "Toutes_Branches_Confondues"){
        res<<Credits( new CreditType("SP") ,30);

	} else if( codeUV == "TN10" && portee == "Toutes_Branches_Confondues"){
        res<<Credits( new CreditType("SP") ,30);





	} else if( codeUV == "LA13" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        res<<Credits( new CreditType("TSH") ,4);

	} else if( codeUV == "SC24" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        res<<Credits( new CreditType("TSH") ,4);

	} else if( codeUV == "LG51" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        res<<Credits( new CreditType("TSH") ,4);

	} else if( codeUV == "SC01" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        res<<Credits( new CreditType("TSH") ,4);

	} else if( codeUV == "SO04" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        res<<Credits( new CreditType("TSH") ,4);

	} else if( codeUV == "IC07" && portee == "TSH_accessibles_aux_BRANCHES_uniquement"){
        res<<Credits( new CreditType("TSH") ,4);

	} else if( codeUV == "EI03" && portee == "TSH_accessibles_aux_BRANCHES_uniquement"){
        res<<Credits( new CreditType("TSH") ,4);

	} else if( codeUV == "LA02" && portee == "TSH_accessibles_aux_TC_et_BRANCHES"){
        res<<Credits( new CreditType("TSH") ,4);




	} else if( codeUV == "LA13" && portee == "TSH-demarchespratiques-communiquer"){
        res<<Credits( new CreditType("TSH") ,1);

	} else if( codeUV == "SC24" && portee == "TSH-connaissances-concevoir"){
        res<<Credits( new CreditType("TSH") ,1);

	} else if( codeUV == "LG51" && portee == "TSH-demarchespratiques-communiquer"){
        res<<Credits( new CreditType("TSH") ,1);

	} else if( codeUV == "SC01" && portee == "TSH-connaissances-concevoir"){
        res<<Credits( new CreditType("TSH") ,1);

	} else if( codeUV == "SO04" && portee == "TSH-connaissances-organisermanager"){
        res<<Credits( new CreditType("TSH") ,1);

	} else if( codeUV == "IC07" && portee == "TSH-demarchespratiques-concevoir"){
        res<<Credits( new CreditType("TSH") ,1);

	} else if( codeUV == "EI03" && portee == "TSH-demarchespratiques-organisermanager"){
        res<<Credits( new CreditType("TSH") ,1);

	} else if( codeUV == "LA02" && portee == "TSH-demarchespratiques-communiquer"){
        res<<Credits( new CreditType("TSH") ,1);




	} else if( codeUV == "GE37" && portee == "TSH-demarchespratiques-organisermanager"){
        res<<Credits( new CreditType("TSH") ,1);



     }
    return res;
}
