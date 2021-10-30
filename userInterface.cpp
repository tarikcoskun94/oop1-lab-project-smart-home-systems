#include "userInterface.h"
userInterface* userInterface::instance = NULL;

/**
* \brief <h2><b><i>Arayuz icin nesne yaratilmasi icin singleton yapinin kontrolu</i></b></h2>
*
* <p>&emsp;&emsp;Daha once bu classtan nesne yaratilip yaratilmadigini kontrol eder. Yaratilmadiysa yaratir ve kendi tipinden bir pointer dondurur. Yaratildiysa zaten bellekte var olani dondurur. </p>
*
* \return instance
*/

userInterface* userInterface::getGUI() {
	if (userInterface::instance == NULL ) {
		userInterface::instance = new userInterface();
		//cout << "BURADA............." << endl; system("pause");
	}
	return userInterface::instance;
}

/**
* \brief <h2><b><i>Arayuzdeki gosterimler</i></b></h2>
*
* <p>&emsp;&emsp;Arayuze bastiralacaklar buradan yapilir. Boylece herhengi bir degisiklikte sadece buraya mudahele edilir ve ortak bir degisim saglanýr.</p>
*
* \param datLine: 
*/
void userInterface::display(string text) {
	cout << text;
}


int userInterface::input() {
	int input = 0;
	cin >> input;

	if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n'))
	{
		return input;
	}
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return 0;
	}
}