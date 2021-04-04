#include "INIFile.h"
#include <fstream>
#include <vector>
#include <regex>
#include "MyExceptions.h"

INIData INIFile::getINIDataFromFile() {
	vector<string> loadedData = readFile();
	this->configData = formatConfigDataStructure(loadedData);
	this->configData.setName(formatConfigDataName());
	return this->configData;
}

void INIFile::writeINIDataToFile() {
	try {
		ofstream fWStream(this->filePath, ofstream::binary);
		if (!fWStream.is_open()) {
			throw FileOperationException(string("Failed to write to the file"));
		}
		fWStream << this->configData;
		fWStream.close();
	}
	catch (ofstream::failure& e) {
		throw FileOperationException(string("Failed to write to the file"));
	}
}



vector<string> INIFile::readFile() {
	vector<string> listOfData;
	string text;
	try {
		ifstream fRStream(this->filePath, ios::binary);
		if (!fRStream.is_open()) {
			throw FileOperationException(string("Failed to read file"));
		}
		while (getline(fRStream, text)) {
			listOfData.push_back(text);
		}
		fRStream.close();
	}
	catch (const ifstream::failure& e) {
		throw FileOperationException(string("Failed to read file"));
	}
	return listOfData;
}

string  INIFile::matchSection(string str) {
	smatch matched_group; 
	regex regexPattern("\\[(.*?)\\]");
	if (regex_search(str, matched_group, regexPattern)) {
		if(matched_group.size()!=2) throw WrongLineInConfig("too many groups found, innapropriate format");
		return matched_group[1].str();
	}
	else {
		throw MatchNotFound();
	}
}

string  INIFile::matchKey(string str) {
	smatch matched_group;
	regex regexPattern("^[\\t ]*(.*?)\\s*=[\\t ]*(.*?)(#.*)?$");
	if (regex_search(str, matched_group, regexPattern)) {
		if (matched_group.size() != 4) throw WrongLineInConfig("too many groups found, innapropriate format");
		return matched_group[1].str();
	}
	else {
		throw MatchNotFound();
	}
}

string  INIFile::matchKeyValue(string str) {
	smatch matched_group;
	regex regexPattern("^[\\t ]*(.*?)\\s*=[\\t ]*(.*?)(#.*)?$");
	if (regex_search(str, matched_group, regexPattern)) {
		if (matched_group.size() != 4) throw WrongLineInConfig("too many groups found, innapropriate format");
		return matched_group[2].str();
	}
	else {
		throw MatchNotFound();
	}
}

INIData INIFile::formatConfigDataStructure(vector<string>bufferedData) {
	INIData data; 
	string lastSection;
	for (string& s : bufferedData)
	{
		try {
			matchLines(data, s, lastSection);
		}
		catch (WrongLineInConfig& e) {
			cout << e.what() << endl;
		}

	}

	return data;
}

string INIFile::formatConfigDataName() {
	string delimiter = "\\";
	try {
		string s = this->filePath.substr(this->filePath.find_last_of(delimiter) + 1, this->filePath.length() - 1);
		return s;
	}
	catch (exception& e) {
		cout << "Failed to format name for INIData from path";
	}
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


void INIFile::matchLines(INIData& data, string& s, string& lastSection) {
	int errs = 0;
	try {
		string matchedSection = matchSection(s);

		data.createSection(matchedSection);

		lastSection = matchedSection;
		return;
	}
	catch (MatchNotFound& ex) {
		errs++;
	}
	try {
		string matchedKey = matchKey(s);
		string matchedKeyValue = matchKeyValue(s);
		data.createKeyInSection(matchedKey, lastSection);
		data.setKeyValueInSection(matchedKey, lastSection, matchedKeyValue);
	}
	catch (MatchNotFound& ex) {
		errs++;
	}
	if (errs > 2) {
		throw WrongLineInConfig(s);
	}
}