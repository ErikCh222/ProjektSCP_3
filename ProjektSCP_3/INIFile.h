#pragma once
#include "INIData.h"
#include <vector>
using namespace std;

class INIFile{
	string filePath;
	INIData configData;
public:
	INIFile() {}
	INIFile(string filePath) {
		this->filePath = filePath;
	}
	INIFile(string filePath, INIData configData) {
		this->filePath = filePath;
		this->configData = configData;
	}

	INIData getINIDataFromFile();
	void writeINIDataToFile();
	
	void setConfigData(INIData data, bool rewrite = true);
	

private: 
	vector<string>readFile();
	
	string strpWhiteSpaces(string str);

	INIData formatConfigDataStructure(vector<string>bufferedData);

	
};