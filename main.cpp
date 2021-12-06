#include "Volume.h"

int main()
{
	//launch();
	Volume volume;
	volume.create();
	//volume.format();
	volume.list(volume.getEntryTable().getEntryList(), NULL, volume.getPath());
	return 0;
}