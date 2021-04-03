#pragma once
#include <stdio.h>
#include <iostream>
#include <stdlib.h>   
#include <ostream>
#include <map>
#include <string>
using namespace std;

class INIData {

private:
	map<string, map<string, string>> dataConfig;
	string name;

public:
	INIData() {
	}

	INIData(string name) {
		this->name = name;

	}

	INIData(const INIData& data) {
		this->name = data.name;
		this->dataConfig = map<string, map<string, string>>(data.dataConfig);
	}

	~INIData() {
		this->dataConfig.clear();
	}

	bool empty() const {
		return this->name.empty() && dataConfig.size() == 0;
	}
	string getName() {
		return this->name;
	}

	void setName(string name) {
		this->name = name;
	}

	map<string, map<string, string>> getConfig() {
		return this->dataConfig;
	}

	void setConfig(map<string, map<string, string>> data) {
		this->dataConfig = data;
	}

	map<string, string> operator[](string name) {
		return getSection(name);
	}

	void createSection(string sectionName);

	void createKeyInSection(string key, string sectionName);

	void setKeyValueInSection(string key, string sectionName, string keyValue);

	map<string, string> getSection(string sectionName);

	string getKeyValue(string key, string sectionName);

	friend INIData operator+(const INIData& operand1, const INIData& operand2);

	friend ostream& operator<< (ostream& out, INIData& iniData);

};





