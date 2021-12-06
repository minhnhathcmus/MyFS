#include "Volume.h"

int main()
{
	Volume volume;
	volume.create();
	//volume.format();
	volume.list(volume.getEntryTable());
	volume.importFile();
	return 0;
}