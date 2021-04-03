// ProjektSCP_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "INIData.h"
#include "INIFile.h"
int main()
{
    INIData testINIConfig("Meno");
    testINIConfig.createSection("Section1");
    testINIConfig.createKeyInSection("key1", "Section1");
    testINIConfig.setKeyValueInSection("key1", "Section1", "keyValue");
    

    testINIConfig.createSection("Section2");
    testINIConfig.createKeyInSection("key2", "Section2");
    testINIConfig.setKeyValueInSection("key2", "Section2", "keyValue");
    testINIConfig.createKeyInSection("key3", "Section2");
    testINIConfig.createKeyInSection("key4", "Section2");
    testINIConfig.setKeyValueInSection("key3", "Section2", "keyValue");
    testINIConfig.setKeyValueInSection("key2", "Section2", "keyValueNew");

    testINIConfig.createSection("Section3");
    testINIConfig.createKeyInSection("key3", "Section3");
    testINIConfig.setKeyValueInSection("key3", "Section3", "keyValue");


    testINIConfig.getKeyValue("key3", "Section3");
    testINIConfig.getSection("Section2");

    map<string, string> bla = testINIConfig["Section3"];
    string value = testINIConfig["Section1"]["key1"];

    std::cout << testINIConfig;
    INIFile file("C:\\Users\\erik.chovanec\\source\\repos\\ProjektSCP_3\\ProjektSCP_3\\new.ini");

    //file.writeINIDataToFile();

    INIData iniData = file.getINIDataFromFile();

    std::cout << iniData;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
