#include "menuManager.h"
#include "userInterface.h"
#include "functions.h"


/**
* \brief <h2><b><i>Ana menuyu yaratir</i></b></h2>
*
* <p>&emsp;&emsp;Device listesini okuyarak ana menuyu listeler ve secim icin girdi bekler. Gelen secimin uygunluguna gore istenen cihazin kendi menusu acilir.</p>
*
* \param deviceList: Device listesi
*/
void menuManager::createMenu(vector<Device*>& deviceList) {

	this->deviceList = deviceList;

	string theMenuElement; // menu ekran�nda g�r�necek her bir eleman� uygun bi�imde saklar.
	userInterface* myDeviceMenuGUI = userInterface::getGUI();
	
	do {
		myDeviceMenuGUI->display("\n");
		system("cls");
		for (int i = 0; i < this->deviceList.size(); i++) { // Device isimleri uygun bi�imde display fonksiyonuna at�l�yor.

			theMenuElement = to_string(i + 1) + ") " + this->deviceList[i]->getDeviceName() + "\n";
			myDeviceMenuGUI->display(theMenuElement);
			if (i + 1 == this->deviceList.size()) { // En sonuncu eleman�n alt�na "Shutdown all devices" se�e�ini basar.
				theMenuElement = "---" + to_string(i + 2) + ") " + "Shutdown all devices." + "\n";
				myDeviceMenuGUI->display(theMenuElement);
			}
		}


		int selection = 0;
		int selectionMAX = this->deviceList.size();
		myDeviceMenuGUI->display("\n\tPlease make your selection: ");
		selection = myDeviceMenuGUI->input();
		string logMsg = "";


		try {
			if (selection > 0 && selection <= selectionMAX) {
				this->deviceList[selection - 1]->displayMenu();
			}
			else if (selection == selectionMAX + 1) {
				for (int i = 0; i < this->deviceList.size(); i++) {
					this->deviceList[i]->off();
				}
				logMsg = "All devices were disabled.";
				Logger::writeLine(logMsg);
				delayWithMsg("\n\t" + logMsg, 1500);
			}
			else {
				throw errorWrongChoice();
			}
		}
		catch (errorWrongChoice error) {
			error.message(1);
			delayWithMsg("", 2000);
		}
	} while (true);
}