#include "FileReader.h"
#include "deviceFactory.h"
#include "functions.h"
#include "menuManager.h"
#include "userInterface.h"


int main(const int argc, const char* argv[])
{
	int datFileCount = argc-1; // .exe haricindeki argüman sayýsýný alýr. (.dat dosya sayýsý)
	string *datFileNames = new string[datFileCount]; // argümandan gelecek .dat dosylarýnýn isimlerini tutar.

	for (int i = 0; i < datFileCount; i++) { // .dat dosya isimleri için argümanlar hafýzaya alýnýyor.
		datFileNames[i] = argv[i+1];
	}


	vector <Device*> allDevices;
	Device* deviceTMP;

	string message;
	string wrongs;
	vector<string> wrongDats;


	try {
		if (datFileCount < 1) {
			throw errorZeroFile();
		}

		checkDatFileName(datFileCount, datFileNames, wrongDats);

		if (wrongDats.size() > 0) {
			throw errorWrongFileName();
		}


		deviceFactory factory;
		for (int i = 0; i < datFileCount; i++) { // .dat dosyalarý tek tek okunuyor ve satýlarýna ayrýlarak geri döndürülüyor.
			FileReader fileReader(datFileNames[i]);
			while (!fileReader.endOfFile()) {
				deviceTMP = factory.create(fileReader.readLine());
				allDevices.push_back(deviceTMP);
			}
		}

	}
	catch(errorZeroFile error){
		message = "Attempted to run without giving file to read.";
		Logger::writeLine(message);

		error.message();
	}
	catch (errorWrongFileName error) {
		for (int i = 0; i < wrongDats.size(); i++) {
			wrongs += "'" + wrongDats[i] + "'";
			if (i != (wrongDats.size() - 1)) { wrongs += " "; }
		}
		message = "Attempt to run with the incorrect extension or without an extension: " + wrongs;
		Logger::writeLine(message);

		error.message(wrongs);
	}


	menuManager myDeviceMenu;
	myDeviceMenu.createMenu(allDevices);

	return 0;
}