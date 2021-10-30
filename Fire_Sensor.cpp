#include "Fire_Sensor.h"
userInterface* FireMenuGUI = userInterface::getGUI();

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
Fire_Sensor::Fire_Sensor(int a, string c, int d) : Device::Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Fire_Sensor state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Fire_Sensor nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Fire_Sensor::off() {

	state = false;


}
/**
* \brief <h2><b><i>Fire_Sensor ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Fire_Sensor nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Fire_Sensor::displayMenu() {

	int answer;

	do{
		system("cls");

		string FireGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
		FireMenuGUI->display(FireGUI);


		answer = FireMenuGUI->input();
		string logMsg = "";

		try {
			switch (answer)
			{
			case 1:
				on();
				logMsg = "Fire_Sensor - " + deviceName + " was enabled";
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 2:
				off();
				logMsg = "Fire_Sensor - " + deviceName + " was disabled";
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 3:
				logMsg = "Fire_Sensor - " + deviceName + " was checked " + ((checkState() == true) ? "On" : "Off");
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 4:
				FireGUI = "\n\tController is being shut down";
				FireMenuGUI->display(FireGUI);

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