#pragma once

#include "INIData.h"
#include "INIFile.h"


namespace demo {
	INIData createNewDataStructure() {
		INIData newData("Test");
		
		newData.createSection("section1");//first option of creating sections
		newData.createKeyInSection("key1", "section1");
		newData.createKeyInSection("key2", "section1");
		newData.createKeyInSection("key3", "section1");
		newData.setKeyValueInSection("key1", "section1", "value1");
		newData.setKeyValueInSection("key2", "section1", "value2");
		newData.setKeyValueInSection("key3", "section1", "value3");

		
		
		newData["section2"];//second option of creating sections
		newData.createKeyInSection("key1", "section2");
		newData.createKeyInSection("key2", "section2");
		newData.createKeyInSection("key3", "section2");
		newData.setKeyValueInSection("key1", "section2", "1");
		newData.setKeyValueInSection("key2", "section2", "2");
		newData.setKeyValueInSection("key3", "section2", "3");


		//option of creating everything
		INIData newData2("MergeTest");
		newData2.setKeyValueInSection("key1", "section3", "value1");
		newData2.setKeyValueInSection("key2", "section3", "value2");
		newData2.setKeyValueInSection("key3", "section3", "value3");
		newData = newData+newData2; //merging 2 INIData structures
		return newData;
	}

	void createNewAndPrintDataStructure() 
	{
		INIData newDataStructure = createNewDataStructure();
		std::cout << newDataStructure;
	}	
	void readFileAndPrintINIData(string path) 
	{
		INIFile testConfig(path);
		testConfig.getINIDataFromFile();
		INIData testConfigData = testConfig.getConfigData();
		std::cout << testConfigData;
	}
	void writeNewINIFile(string path) 
	{
		INIData newIData = createNewDataStructure();
		INIFile newFile(path);
		newFile.setConfigData(newIData);
		newFile.writeINIDataToFile();
		std::cout << "Written successfuly";
	}


}