#include "Entry.h"

Entry::Entry()
{
	date = 0;
	time = 0;
	dataSize = 0;
	fileNameLength = 0;
	passwordLength = 0;
	offsetOfData = 0;
	fileName = "";
	password = "";
}
Entry::~Entry()
{

}
unsigned short Entry::getDate()
{
	return date;
}
unsigned short Entry::getTime()
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
unsigned int Entry::getOffsetOfData()
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
void Entry::setDate(unsigned short _date)
{
	date = _date;
}
void Entry::setTime(unsigned short _time)
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