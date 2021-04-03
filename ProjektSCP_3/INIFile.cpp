#include "INIFile.h"
#include <fstream>
#include <vector>
#include <regex>

INIData INIFile::getINIDataFromFile() {
	vector<string> loadedData = readFile();
	this->configData = formatConfigDataStructure(loadedData);
	this->configData.setName(formatConfigDataName());
	return this->configData;
}

void INIFile::writeINIDataToFile() {
	ofstream fWStream(this->filePath, ofstream::binary);
	if(!fWStream.is_open()) {
		throw "File is not open for writing";
	}
	fWStream << this->configData;
	fWStream.close();
}



vector<string> INIFile::readFile() {
	vector<string> listOfData;
	string text;
	ifstream fRStream(this->filePath, ios::binary);
	if (!fRStream.is_open()) {
		throw "Failed to read file";
	}
	while (getline(fRStream, text)) {
		listOfData.push_back(text);
	}
	fRStream.close();
	return listOfData;
}

string  INIFile::matchSection(string str) {
	smatch matched_group; 
	regex regexPattern("\\[(.*?)\\]");
	if (regex_search(str, matched_group, regexPattern)) {
		return matched_group[0].str();
	}
	else {
		throw("Match not found");
	}
}

string  INIFile::matchKey(string str) {
	smatch matched_group;
	regex regexPattern("(\\w+)\\s+=\\s{0,}([^\\+]+(?!\\+{3}))");
	if (regex_search(str, matched_group, regexPattern)) {
		if (matched_group.size() != 2) throw("Matching key failed");
		return matched_group[0].str();
	}
	else {
		throw("Match not found");
	}
}

string  INIFile::matchKeyValue(string str) {
	smatch matched_group;
	regex regexPattern("(\\w+)\\s+=\\s{0,}([^\\+]+(?!\\+{3}))");
	if (regex_search(str, matched_group, regexPattern)) {
		if (matched_group.size() != 2) throw("Matching key value failed");
		return matched_group[1].str();
	}
	else {
		throw("Match not found");
	}
}

INIData INIFile::formatConfigDataStructure(vector<string>bufferedData) {
	INIData data; 
	string lastSection;
	for (string& s : bufferedData)
	{
		if (regex_match(s, regex("\\[(.*)\\]"))) {
			string matchedSection = matchSection(s);

			data.createSection(matchedSection);

			lastSection = matchedSection;
			
		}
		else if (regex_match(s, regex("(\\w+)\\s+=\\s{0,}([^\\+]+(?!\\+{3}))"))) {
			string matchedKey = matchKey(s);
			string matchedKeyValue = matchKeyValue(s);

			data.createKeyInSection(matchedKey, lastSection);

			data.setKeyValueInSection(matchedKey, lastSection, matchedKeyValue);

		}
	}

	return data;
}

string INIFile::formatConfigDataName() {
	string delimiter = "//";
	string s = this->filePath.substr(this->filePath.find_last_of(delimiter), this->filePath.length());
	return s;
}

string INIFile::getFilePath() {
	return this->filePath;
}
void INIFile::setFilePath(string path) {
	this->filePath = path;
}

void INIFile::setConfigData(INIData data) {
	this->configData = data;
}

INIData INIFile::getConfigData() {
	if (this->configData.empty()) {
		throw "attempt to retriew empty config";
	}
	return this->configData;
}

