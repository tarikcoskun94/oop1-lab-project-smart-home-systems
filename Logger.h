#pragma once
//#include "Device.h"
#include<iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include "exceptions.h"
#pragma warning(disable : 4996)
using namespace std;
/**
* \brief <h2><b><i>Logger class.</i></b></h2>
*
* <p>&emsp;&emsp;Singleton Pattern ile olusturulmus Logger clasi</p>
*
*
*/
class Logger {
private:
	/**
	* \brief fileName attribute
	*/
	static string fileName;
	Logger() {};

public:
	
	static void writeLine(string);

};


