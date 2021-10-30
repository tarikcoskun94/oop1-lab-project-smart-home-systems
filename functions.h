#ifndef SMART_HOME
#define SMART_HOME

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>

#include "userInterface.h"
#include "Logger.h"


using namespace std;



void delayWithMsg(string, int);

void checkDatFileName(int, string*, vector<string>&);

#endif /* SMART_HOME */