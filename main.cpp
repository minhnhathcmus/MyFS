<<<<<<< Updated upstream
#include "Volume.h"

int main()
{
	Volume volume;
	volume.create();
	//volume.format();
	volume.list(volume.getEntryTable());
	volume.importFile();
	return 0;
=======
#include "Volume.h"

int main()
{
	Volume volume;
	int option;
	do
	{
		option = showMainMenu();
		switch (option)
		{
		case 0:
			break;
		case 1:
		{
			volume.create();
			cout << "\nNhan phim bat ky de tiep tuc";
			getchar();
			break;
		}
		case 2:
		{
			volume.format();
			cin.ignore();
			cout << "\nNhan phim bat ky de tiep tuc";
			getchar();
			break;
		}
		case 3:
		{
			//Them method o day
			cout << "\nNhan phim bat ky de tiep tuc";
			getchar();
			break;
		}
		case 4:
		{
			//Them method o day
			cout << "\nNhan phim bat ky de tiep tuc";
			getchar();
			break;
		}
		case 5:
		{
			volume.list(volume.getEntryTable());
			cin.ignore();
			cout << "\nNhan phim bat ky de tiep tuc";
			getchar();
			break;
		}
		default:
		{
			cout << "Loi khong xac dinh!\n";
			cout << "\nNhan phim bat ky de tiep tuc";
			getchar();
			break;
		}
		}
	} while (option != 0);
	cout << "Da thoat chuong trinh.";
	return 0;
>>>>>>> Stashed changes
}