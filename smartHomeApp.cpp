#include "FileReader.h"
#include "deviceFactory.h"
#include "functions.h"
#include "menuManager.h"
#include "userInterface.h"


int main(const int argc, const char* argv[])
{
	int datFileCount = argc-1; // .exe haricindeki arg�man say�s�n� al�r. (.dat dosya say�s�)
	string *datFileNames = new string[datFileCount]; // arg�mandan gelecek .dat dosylar�n�n isimlerini tutar.

	for (int i = 0; i < datFileCount; i++) { // .dat dosya isimleri i�in arg�manlar haf�zaya al�n�yor.
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
		for (int i = 0; i < datFileCount; i++) { // .dat dosyalar� tek tek okunuyor ve sat�lar�na ayr�larak geri d�nd�r�l�yor.
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