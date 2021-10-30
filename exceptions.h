#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class errorWriteFile : public exception {
public:
	void message(string, int = 0);
};

class errorWriteLine : public exception {
public:
	void message(int = 0);
};

class errorReadFile : public exception {
public:
	void message(string, int = 0);
};

class errorLineFormat : public exception {
public:
	void message(int = 0);
};

class errorZeroFile : public exception {
public:
	void message(int = 0);
};

class errorWrongFileName : public exception {
public:
	void message(string, int = 0);
};

class errorWrongChoice : public exception {
public:
	void message(int = 0);
};