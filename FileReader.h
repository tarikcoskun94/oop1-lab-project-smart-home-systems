#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "exceptions.h"


using namespace std;


/**
* \brief <h2><b><i>FileReader Nesnesi</i></b></h2>
*
* <p>&emsp;&emsp;Dosyanin nasil okunacagi burada tanimlanir.</p>
*/
class FileReader {
private:
	/**
	* \brief filePath attribute
	*/
	string fileName;
	/**
	* \brief theFile attribute
	*/
	ifstream theFile;

public:
	FileReader(){}
	FileReader(const string&);

	void setFilePath(const string&);
	string getFilePath() const;

	bool endOfFile();

	//vector <string> readLine();
	string readLine();

	~FileReader(){}

};