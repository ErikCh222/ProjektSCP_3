#include "INIData.h"


void INIData::createSection(string sectionName) {
	map<string, string> newEmptyMap;
	this->dataConfig.emplace(sectionName, newEmptyMap); 
}


void INIData::createKeyInSection(string key, string sectionName) {

	this->dataConfig[sectionName].emplace(key, ""); 
}


void INIData::setKeyValueInSection(string key, string sectionName, string keyValue) {
	this->dataConfig[sectionName][key] = keyValue; 
}

map<string, string> INIData::getSection(string sectionName) {
	return this->dataConfig[sectionName];
}

string INIData::getKeyValue(string key, string sectionName) {
	return this->dataConfig[sectionName][key]; 
}



INIData operator+(const INIData& operand1, const INIData& operand2) {
	INIData newMergedINIConfigs;
	newMergedINIConfigs.dataConfig.insert(operand1.dataConfig.begin(), operand1.dataConfig.end());
	newMergedINIConfigs.dataConfig.insert(operand2.dataConfig.begin(), operand2.dataConfig.end());
	return newMergedINIConfigs;
}


ostream& operator<< (ostream& out, INIData& iniData) {
	string resOp = "=";
	for (
		map<string, map<string, string>>::iterator it = iniData.dataConfig.begin();
		it != iniData.dataConfig.end(); it++
		) {
		out << "[" << it->first << "] "<< endl;
		for (
			map<string, string>::iterator it2 = it->second.begin();
			it2 != it->second.end(); it2++
			) {
			out << it2->first << resOp << it2->second << endl;
		}
	}
	return out;
}