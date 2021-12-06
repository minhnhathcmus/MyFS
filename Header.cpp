#include "Header.h"

Header::Header()
{
	password = "";
	entrySize = 0;
	dataSize = 0;
	volumeSize = (unsigned long long)sizeof(Header) + (unsigned long long)entrySize + dataSize;
}
Header::Header(string _password)
{
	password = _password;
	entrySize = 0;
	dataSize = 0;
	volumeSize = (unsigned long long)sizeof(Header) + (unsigned long long)entrySize + dataSize;
}
Header::~Header()
{

}
string Header::getPassword()
{
	return password;
}
unsigned int Header::getEntrySize()
{
	return entrySize;
}
unsigned long long Header::getDataSize()
{
	return dataSize;
}
unsigned long long Header::getVolumeSize()
{
	return volumeSize;
}
void Header::setPassword(string _password)
{
	password = _password;
}
void Header::setEntrySize(unsigned int _entrySize)
{
	entrySize = _entrySize;
}
void Header::setDataSize(unsigned long long _dataSize)
{
	dataSize = _dataSize;
}
void Header::setVolumeSize(unsigned long long _volumeSize)
{
	volumeSize = _volumeSize;
}