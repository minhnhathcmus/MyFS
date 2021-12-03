#pragma once
#include "main.h"

class Entry
{
private:
	unsigned short date;
	unsigned short time;
	unsigned int dataSize;
	unsigned short fileNameLength;
	unsigned short passwordLength;
	unsigned int offsetOfData; //Vi tri cua du lieu tinh tu dau volume
	string fileName;
	string password;
public:
	Entry();
	~Entry();
	unsigned short getDate();
	unsigned short getTime();
	unsigned int getDataSize();
	unsigned short getFileNameLength();
	unsigned short getPasswordLength();
	unsigned int getOffsetOfData();
	string getFileName();
	string getPassword();
	void setDate(unsigned short _date);
	void setTime(unsigned short _time);
	void setDataSize(unsigned int _dataSize);
	void setFileNameLength(unsigned short _fileNameLength);
	void setPasswordLength(unsigned short _passwordLength);
	void setOffsetOfData(unsigned int _offsetOfData);
	void setFileName(string _fileName);
	void setPassword(string _password);
};
