#include "FileReader.h"



/**
* \brief <h2><b><i>Parametre ile default Constructor</i></b></h2>
*
* <p>&emsp;&emsp;Nesne yaratilirken dosya ismini alir.</p>
*
* \param filePath: Dosya ismi
*/
FileReader::FileReader(const string& fileName) {
	setFilePath(fileName);
}




/**
* \brief <h2><b><i>fileName icin setter</i></b></h2>
*
* <p>&emsp;&emsp;filePath degerini set eder.</p>
*
* \param filePath: Dosya ismi
*/
void FileReader::setFilePath(const string& fileName) {
	if (theFile.is_open()) {
		theFile.close();
	}

	try {
		this->fileName = fileName;
		theFile.open(fileName);

		if (!theFile.is_open()) {
			throw errorReadFile();
		}
	}
	catch (errorReadFile error) {
		error.message(fileName);
	}
}

/**
* \brief <h2><b><i>filePath icin getter</i></b></h2>
*
* <p>&emsp;&emsp;filePath degerini dondurur.</p>
*
* \return filePath
*/
string FileReader::getFilePath() const {
	return this->fileName;
}




/**
* \brief <h2><b><i>Dosya sonu icin getter</i></b></h2>
*
* <p>&emsp;&emsp;Dosya sonunda ise true degerini dondurur.</p>
*
* \return true/false
*/
bool FileReader::endOfFile() { 
	return theFile.eof();
}




/**
* \brief <h2><b><i>Dosyadan okuma yapar</i></b></h2>
*
* <p>&emsp;&emsp;Dosyadan her bir satiri tek tek okur ve dondurur. Dosya sonunda ise dosyayi kapatir. Kaldigi yeri hatirlar.</p>
*
* \return line
*/
string FileReader::readLine() {
	string line;

	while (getline(theFile, line)) {
		return line;
	}

	if (theFile.eof()) {
		theFile.close();
	}
}