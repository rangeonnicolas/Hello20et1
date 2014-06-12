

#include "dataBaseA.h"

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





