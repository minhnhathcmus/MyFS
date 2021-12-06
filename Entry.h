#pragma once
#include<string>

using namespace std;

struct Date
{
	unsigned char day;
	unsigned char month;
	unsigned short year;
};
struct Time
{
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
};

class Entry
{
private:
	Date date; //Ngay chinh sua lan cuoi
	Time time; //Gio chinh sua lan cuoi
	unsigned int dataSize;
	unsigned short fileNameLength;
	unsigned short passwordLength;
	unsigned long long offsetOfData; //Vi tri cua du lieu tinh tu dau volume
	string fileName;
	string password;
public:
	Entry();
	Entry(Date _date, Time _time, unsigned int _dataSize, unsigned short _fileNameLength, 
		unsigned short _passwordLength, unsigned long long _offsetOfData, string _fileName, string _password);
	~Entry();
	Date getDate();
	Time getTime();
	unsigned int getDataSize();
	unsigned short getFileNameLength();
	unsigned short getPasswordLength();
	unsigned long long getOffsetOfData();
	string getFileName();
	string getPassword();
	void setDate(Date _date);
	void setTime(Time _time);
	void setDataSize(unsigned int _dataSize);
	void setFileNameLength(unsigned short _fileNameLength);
	void setPasswordLength(unsigned short _passwordLength);
	void setOffsetOfData(unsigned int _offsetOfData);
	void setFileName(string _fileName);
	void setPassword(string _password);
};
