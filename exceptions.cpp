#include <iostream>
#include <iomanip>
#include "exceptions.h"

string tabMaker(int tabCount) {
	string tabs;
	for (int i = 0; i < tabCount; i++) {
		tabs += "\t";
	}
	return tabs;
}


void errorWriteFile::message(string filePath, int tabCount) {
	string tabs = tabMaker(tabCount);
	cout << tabs << "!!! ERROR !!! - The file could not be created or opened for writing: " << filePath << endl;
	cout << tabs << "The program will be terminated." << endl << endl;
	system("pause");
	exit(0);
}

void errorWriteLine::message(int tabCount) {
	string tabs = tabMaker(tabCount);
	cout << tabs << "!!! ERROR !!! - A line could not be saved." << endl;
	cout << tabs << "The program will be terminated." << endl << endl;
	system("pause");
	exit(0);
}

void errorReadFile::message(string filePath, int tabCount) {
	string tabs = tabMaker(tabCount);
	cout << tabs << "!!! ERROR !!! - The file could not be opened for reading: " << filePath << endl;
	cout << tabs << "The program will be terminated." << endl << endl;
	system("pause");
	exit(0);
}

void errorLineFormat::message(int tabCount) {
	string tabs = tabMaker(tabCount);
	cout << tabs << "!!! ERROR !!! - Please make sure the lines are in the correct format." << endl;
	cout << "The program will be terminated." << endl << endl;
	system("pause");
	exit(0);
}

void errorZeroFile::message(int tabCount) {
	string tabs = tabMaker(tabCount);
	cout << tabs << "!!! ERROR !!! - You must provide at least one '.dat' file extension." << endl;
	cout << tabs << "The program will be terminated." << endl << endl;
	system("pause");
	exit(0);
}

void errorWrongFileName::message(string wrongFiles, int tabCount) {
	string tabs = tabMaker(tabCount);
	cout << tabs << "!!! ERROR !!! - Some of your files have no extension or are not in the correct extension: " << wrongFiles << endl;
	cout << tabs << "The program will be terminated." << endl << endl;
	system("pause");
	exit(0);
}

void errorWrongChoice::message(int tabCount) {
	string tabs = tabMaker(tabCount);
	cout << endl;
	cout << tabs << "Wrong Choise." << endl;
	cout << tabs << "Please fix it and try again.";
}