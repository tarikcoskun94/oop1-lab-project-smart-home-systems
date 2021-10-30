#include "Window.h"
userInterface* WindowMenuGUI = userInterface::getGUI();

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
Window::Window(int a, string c, int d) : Device(a, c, d) {

	state = false;

}
/**
* \brief <h2><b><i>Window state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Window nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void Window::off() {

	state = false;


}
/**
* \brief <h2><b><i>Window ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;Window nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/
void Window::displayMenu() {

	int answer;

	do{
		system("cls");

		string WindowsGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Exit depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Exit\n\n\tPlease make your choice: ";
		WindowMenuGUI->display(WindowsGUI);


		answer = WindowMenuGUI->input();
		string logMsg = "";

		try {
			switch (answer)
			{
			case 1:
				on();
				logMsg = "Window - " + deviceName + " was enabled";
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 2:
				off();
				logMsg = "Window - " + deviceName + " was disabled";
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 3:
				logMsg = "Window - " + deviceName + " was checked " + ((checkState() == true) ? "On" : "Off");
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);
				break;

			case 4:
				WindowsGUI = "\n\tController is being shut down";
				WindowMenuGUI->display(WindowsGUI);

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