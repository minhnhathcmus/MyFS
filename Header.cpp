#include "Header.h"

Header::Header()
{
	entrySize = 0;
	dataSize = 0;
	volumeSize = sizeof(Header) + entrySize + dataSize;
}
Header::~Header()
{

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