// ProjektSCP_3.cpp : Project for SCP INI config file 



#include <iostream>
#include "DemonstrationFunc.h"

int main()
{
 
    std::cout << "-------------------create and print demo--------------------"<<std::endl;
    demo::createNewAndPrintDataStructure();


    std::cout << "-------------------read file and print data content demo--------------------" << std::endl;
    demo::readFileAndPrintINIData(".\\testConfig.ini");


    std::cout << "-------------------create data and write data into file demo--------------------" << std::endl;
    demo::writeNewINIFile(".\\newFile.ini");
}



