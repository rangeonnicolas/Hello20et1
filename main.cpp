#include <iostream>

#include "UV.h"

using namespace UV_credits_types;

int main(){

    CreditTypeManager ctm = CreditTypeManager();
    ctm.addType("CS");
    ctm.addType("TSH");
    ctm.addType("TM");
    ctm.addType("SP");
    ctm.addType("TM");
    ctm.addType("TM");
    ctm.displayAll();

    std::cout<<"\nfin du test\n";
    system("pause");
    return 0;
}
