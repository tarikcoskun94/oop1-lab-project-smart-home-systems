#include "Logger.h"
string Logger::fileName = "events.log";
/**
* \brief <h2><b><i>writeLine fonksiyonu.</i></b></h2>
*
* <p>&emsp;&emsp;gonderilen bir stringe gore log dosyasini zamanla birlikte tutar.</p>
*
* \param logMsg: log dosyasina yazilacak mesaji tutar.
*
*/
void Logger::writeLine(string logMsg) {
	
	try {
		// Declaring argument for time() 
		time_t tt;

		// Declaring variable to store return value of 
		// localtime() 
		struct tm* ti;

		// Applying time() 
		time(&tt);

		// Using localtime() 
		ti = localtime(&tt);

		ofstream myfile; // MY File ad�nda yazd�rma verisi olu�turduk
		myfile.open(fileName, ios::app); // yazdir.txt ad�nda bir metin belgesi oldu�unu s�yl�yoruz ve bunu acmas�n� istiyoruz. (txt dosyas� yok ise kendisi olu�turuyor.)
		if (!myfile.is_open()) { throw errorWriteFile(); }
		myfile << logMsg << " - " << asctime(ti) << endl; // bu metnimizi txt yap��t�r�yoruz , farkl� uzant�larda bunu yapamaya biliriz.
		if (myfile.fail()) { throw errorWriteLine(); }
		myfile.close(); // Ac�l�p yazma i�lemi yap�lan txt dosyas� burda close komutu ile kapat�l�yor.
	}
	catch(errorWriteFile error){
		error.message(fileName);
	}
	catch (errorWriteLine error) {
		error.message();
	}

}

