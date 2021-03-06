#include "Entry.h"

Entry::Entry()
{
	date.day = date.month = date.year = 0;
	time.hour = time.minute = time.second = 0;
	dataSize = 0;
	fileNameLength = 0;
	passwordLength = 0;
	offsetOfData = 0;
	fileName = "";
	password = "";
}
Entry::Entry(Date _date, Time _time, unsigned int _dataSize, unsigned short _fileNameLength,
	unsigned short _passwordLength, unsigned long long _offsetOfData, string _fileName, string _password)
{
	date = _date;
	time = _time;
	dataSize = _dataSize;
	fileNameLength = _fileNameLength;
	passwordLength = _passwordLength;
	offsetOfData = _offsetOfData;
	fileName = _fileName;
	password = _password;
}
Entry::~Entry()
{

}
Date Entry::getDate()
{
	return date;
}
Time Entry::getTime()
{
	return time;
}
unsigned int Entry::getDataSize()
{
	return dataSize;
}
unsigned short Entry::getFileNameLength()
{
	return fileNameLength;
}
unsigned short Entry::getPasswordLength()
{
	return passwordLength;
}
unsigned long long Entry::getOffsetOfData()
{
	return offsetOfData;
}
string Entry::getFileName()
{
	return fileName;
}
string Entry::getPassword()
{
	return password;
}
void Entry::setDate(Date _date)
{
	date = _date;
}
void Entry::setTime(Time _time)
{
	time = _time;
}
void Entry::setDataSize(unsigned int _dataSize)
{
	dataSize = _dataSize;
}
void Entry::setFileNameLength(unsigned short _fileNameLength)
{
	fileNameLength = _fileNameLength;
}
void Entry::setPasswordLength(unsigned short _passwordLength)
{
	passwordLength = _passwordLength;
}
void Entry::setOffsetOfData(unsigned int _offsetOfData)
{
	offsetOfData = _offsetOfData;
}
void Entry::setFileName(string _fileName)
{
	fileName = _fileName;
}
void Entry::setPassword(string _password)
{
	password = _password;
}