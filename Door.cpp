#include "Door.h"
userInterface* DoorMenuGUI = userInterface::getGUI();

/**
* \brief <h2><b><i>Constructor.</i></b></h2>
*
* <p>&emsp;&emsp;Verilen parametrelere gore yapilan constructor</p>
*
* \param a: id degiskeni.
* \param c: deviceName degiskeni.
* \param d: port degiskeni.
*
*/
Door::Door(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Door state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Door nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Door::off() {

	state = false;


}
/**
* \brief <h2><b><i>Door ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Door nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Door::displayMenu() {

	int answer;

	do{
		system("cls");

		string DoorGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
		DoorMenuGUI->display(DoorGUI);


		answer = DoorMenuGUI->input();
		string logMsg = "";

		try {
			switch (answer)
			{
			case 1:
				on();
				logMsg = "Door - " + deviceName + " was enabled";
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 2:
				off();
				logMsg = "Door - " + deviceName + " was disabled";
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 3:
				logMsg = "Door - " + deviceName + " was checked " + ((checkState() == true) ? "On" : "Off");
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 4:
				DoorGUI = "\n\tController is being shut down";
				DoorMenuGUI->display(DoorGUI);

				delayWithMsg("", 1500);
				break;

			default:
				throw errorWrongChoice();
			}
		}
		catch (errorWrongChoice error) {
			error.message(1);
			delayWithMsg("", 2000);
		}

	} while (answer != 4);
}