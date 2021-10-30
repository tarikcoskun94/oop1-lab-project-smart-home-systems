#include "functions.h"


/**
* \brief <h2><b><i>Mesaj opsiyonlu gecikme</i></b></h2>
*
* <p>&emsp;&emsp;Opsiyonel olarak mesaj yazdirarak, eklendigi yerde program akisini verilen milisaniye kadar duraklatir.</p>
*
* \param msg: Mesaj
* \param time: Zaman
*/
void delayWithMsg(string msg, int time) {

	userInterface::getGUI()->display(msg);
	chrono::duration<int, milli> timespan(time);
	this_thread::sleep_for(timespan);
}

/**
* \brief <h2><b><i>.dat dosyalari icin format kontrolu</i></b></h2>
*
* <p>&emsp;&emsp;.dat dosyalarinin formatini kontrol eder ve uygunsuz dosya isimlerini vektore depolar.</p>
*
* \param datFileCount: .dat dosyalarinin adedi
* \param datFileNames: .dat dosyalarinin ismi
* \param wrongDats: hatalý dosyalarin isimleri
*/
void checkDatFileName(int datFileCount, string* datFileNames, vector<string>& wrongDats) {
	//bool formatCheck = false;

	size_t index;

	for (int i = 0; i < datFileCount; i++) {
		index = datFileNames[i].find(".dat");

		if (index != string::npos) {
			if (datFileNames[i].size() > 4 && datFileNames[i].size() == index + 4) {}
				//formatCheck = true;
			else {
				//formatCheck = false;
				wrongDats.push_back(datFileNames[i]);
				//break;
			}
		}
		else {
			//formatCheck = false;
			wrongDats.push_back(datFileNames[i]);
			//break;
		}
	}

	//if (formatCheck)
	//	return true;
	//else
	//	return false;
}