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
	void setConfigData(INIData data);

	INIData getConfigData();

	INIData getINIDataFromFile();
	
	void writeINIDataToFile();

	string getFilePath();
	
	void setFilePath(string path);
	
private: 
	vector<string>readFile();
	
	string matchSection(string str);

	string matchKey(string str);

	string matchKeyValue(string str);

	INIData formatConfigDataStructure(vector<string>bufferedData);

	string formatConfigDataName();
	
};