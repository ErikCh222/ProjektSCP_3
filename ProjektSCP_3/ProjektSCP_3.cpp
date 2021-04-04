// ProjektSCP_3.cpp : Project for SCP INI config file 

/*Expected functionality:
*   - create data structure for .INI file
*   - ability to create/update new sections, keys in data structure
*       - no duplicated sections
*       - no duplicated keys in section
*       - able to create single section or key
*       - able assing keyValue to given key and section
*       - using INIData.createKeyInsection/setKeyValueInSection - if section or key doesnt exist it will be created
*   - retrieving data from data structure
*       - if given section or key doesnt exit - return empty
*   - operator for redirecting data to output
*   - operator for meging to data structures
    - read .INI files - may throw FileOperationException
    - write .INI files - may throw FileOperationException - rewrite existing
*/

#include <iostream>
#include "INIData.h"
#include "INIFile.h"
int main()
{
    INIData testINIConfig("Meno");
    testINIConfig.createSection("Section5");
    testINIConfig.createKeyInSection("key6", "Section1");
    testINIConfig.setKeyValueInSection("key11add1", "Sectdadadion1", "keyValue");


    testINIConfig.getKeyValue("key3", "Section3");
    testINIConfig.getSection("Section2");

    map<string, string> bla = testINIConfig["Section3"];
    string value = testINIConfig["Section1"]["key1"];

    std::cout << testINIConfig;
    INIFile file("C:\\Users\\erik.chovanec\\source\\repos\\ProjektSCP_3\\ProjektSCP_3\\new.ini");

    //file.writeINIDataToFile();

    std::cout << "________________________"<<std::endl;
    INIData iniData = file.getINIDataFromFile();
    std::cout << iniData;


    std::cout << "________________________" << std::endl;
    INIData inssiData= iniData + testINIConfig;
    std::cout << inssiData;


    inssiData.getSection("haldhaldhaldhlad");
    inssiData.createKeyInSection("sjdhsldhsldhsd", "shdosdhosd");

    inssiData["dahoidlhada"];
    inssiData["dahoidlhada"]["shit"];
    std::cout << "SHUT";

    file.setConfigData(iniData);
    file.writeINIDataToFile();

}

