#pragma once
#include<exception>
using namespace std;


class MatchNotFound : public exception
{
	const char* what() const throw()
	{
		return "Regex match not found";
	}
};

class WrongLineInConfig : public exception
{
	string s;
public:
	WrongLineInConfig(string s) {
		this->s = s;
	}
	const char* what() const throw()
	{
		return ("Line in config has wrong format, line: $s", s.c_str());
	}
};


class FileOperationException : public exception
{
	string s;
public:
	FileOperationException() {
		this->s = string("There was error in operation");
	}

	FileOperationException(string s) {
		this->s = s;
	}
	const char* what() const throw()
	{
		return s.c_str();
	}
};



class INIDataException : public exception
{
	string s;
public:
	INIDataException() {
		this->s = string("Exception occured in ini data structure");
	}
	INIDataException(string s) {
		this->s = s;
	}
	const char* what() const throw()
	{
		return s.c_str();
	}
};


