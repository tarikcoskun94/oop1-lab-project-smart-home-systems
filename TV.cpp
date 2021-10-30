#include "TV.h"
userInterface* TVMenuGUI = userInterface::getGUI();

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
TV::TV(int a, string c, int d) : Device(a, c, d) {

	state = false;
	activeChannel = 1;
	standByMode = false;
	
	
}
/**
* \brief <h2><b><i>TV state durumunu kapatma</i></b></h2>
*
* <p>&emsp;&emsp;Tv nin state durumunu 0 durumuna getirir.</p>
*
*
*/
void TV::off() {
	state = false;
	standByMode = false;

}
/**
* \brief <h2><b><i>Kanal secici fonksiyon</i></b></h2>
*
* <p>&emsp;&emsp;Verilen channelValue degerine gore o sayiya ait kanali acar.</p>
*
* \param channelValue: Acilmak istenilen kanalin sira numarasi.
*
*/
void TV::selectChannel(int channelValue) {

	activeChannel = channelValue;

}
/**
* \brief <h2><b><i>StandBy fonksiyonu</i></b></h2>
*
* <p>&emsp;&emsp;TV yi StandBy moda alir.</p>
*
*
*/
void TV::standBy() {
	
	if (standByMode == false) {
		standByMode = true;
	}
	else
		standByMode = false;

}

/**
* \brief <h2><b><i>TV ye ozel displayMenu</i></b></h2>
*
* <p>&emsp;&emsp;TV nin kendi ozelliklerine ait menusu cagirilir.</p>
*
*
*/

void TV::displayMenu() {

	int answer;
	string channelMemory;

	do{
		system("cls");


		if (state == false) {
			channelMemory = "[Off]";
		}
		else if(standByMode == true) {
			channelMemory = "[Standby]";
		}else{
			channelMemory = "[" + channelList[activeChannel - 1] + "]";
		}

		string TVGUI = "Pick from choices 1 for ON, 2 for OFF, or 3 for Check or, 4 for Channel Menu, 5 for Stand By ,6 for Exit , depending on what you want from the menu.\n\n1) On\n2) Off\n3) Check\n4) Channel Menu " + channelMemory + "\n5) Stand By Mode\n6) Exit\n\n\tPlease make your choice: ";
		TVMenuGUI->display(TVGUI);


		answer = TVMenuGUI->input();
		string logMsg = "";
		string checkStateMsg;

		try {
			switch (answer)
			{
			case 1:
				on();
				standByMode = false;
				logMsg = "TV - " + deviceName + " was enabled";
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);

				break;

			case 2:
				off();
				logMsg = "TV - " + deviceName + " was disabled";
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);

				break;

			case 3:
				if (standByMode == true) {
					checkStateMsg = "Standby";
				}
				else if (state == true) {
					checkStateMsg = "On";
				}
				else {
					checkStateMsg = "Off";
				}
				logMsg = "TV - " + deviceName + " was checked: " + checkStateMsg;
				Logger::writeLine(logMsg);

				delayWithMsg("\n\t" + logMsg, 1500);

				break;

			case 4:

				if (checkState() == true) {

					if (activeChannel >= 0 && standByMode == false)
					{
						TVGUI = "\n\tActive Channel is " + channelList[activeChannel - 1] + "\n\n";
						TVMenuGUI->display(TVGUI);


						int channelValue;
						TVGUI = "\n\n\t---Channel List---\n\n";
						TVMenuGUI->display(TVGUI);

						for (int i = 0; i < channelList.size(); i++)
						{
							TVGUI = "";
							TVGUI = "\t" + to_string(i + 1) + " -) " + channelList[i] + "\n";
							TVMenuGUI->display(TVGUI);
							delayWithMsg("", 150);

						}

						TVGUI = "\n\n\tSelect a channel: ";
						TVMenuGUI->display(TVGUI);

						channelValue = TVMenuGUI->input();
						if (channelValue <= channelList.size() && channelValue > 0)
						{
							selectChannel(channelValue);
							logMsg = "TV - " + deviceName + " is changed the channel to " + channelList[activeChannel - 1];
							Logger::writeLine(logMsg);
							delayWithMsg("", 150);
						}
						else
						{
							TVGUI = "";
							TVGUI = "\n\tYour selection is " + to_string(channelValue) + ". Your selection must be 1 to " + to_string(channelList.size());
							TVMenuGUI->display(TVGUI);
							delayWithMsg("", 3000);
						}

					}

					else if (standByMode == true) {
						TVGUI = "\n\tYou cant change the channel when the StandBy mode is off.\n\tFirst please change the StandBy mode";
						TVMenuGUI->display(TVGUI);
						delayWithMsg("", 5000);


					}

					//cout << activeChannel;
					//cout << channelList[activeChannel];

				}
				else
				{
					TVGUI = "\n\tYou cant change the channel when the TV is off.\n\tFirst please turn on the TV";
					TVMenuGUI->display(TVGUI);
					delayWithMsg("", 5000);

				}
				break;

			case 5:
				if (checkState() == 1) {

					standBy();

					if (standByMode == true) {
						TVGUI = "\n\tStandBy mode is active";
						TVMenuGUI->display(TVGUI);
						delayWithMsg("", 1500);
					}
					else
					{
						TVGUI = "\n\tStandBy mode is inactive";
						TVMenuGUI->display(TVGUI);
						delayWithMsg("", 1500);
					}


					logMsg = "TV - " + deviceName + " was changed to Stand By mode is " + ((standByMode == true) ? "On" : "Off");
					Logger::writeLine(logMsg);
				}
				else
				{
					TVGUI = "\n\tYou cant change the StandBy mode when the TV is off.\n\tFirst please open the TV";
					TVMenuGUI->display(TVGUI);
					delayWithMsg("", 5000);
				}

				break;



			case 6:
				TVGUI = "\n\tController is being shut down";
				TVMenuGUI->display(TVGUI);

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

	} while (answer != 6);
}


	