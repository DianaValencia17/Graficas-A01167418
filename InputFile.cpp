//Autor: Diana Laura Valencia Dominguez A01167418
//********************************************************* /
//
//  Tarea1 Diana Valencia.cpp
//  DianaValenciaTarea1
//
//  Created by Diana Valencia  on 2017-09-06.
//
//
#include <iostream>
#include <fstream>
#include <sstream>
#include "InputFile.h"


using namespace std;

bool InputFile::Read(std::string FileName)
{
	fstream inFile;
	std::string linea;
	inFile.open(FileName);
	if (!inFile) {
		cout << "Unable to open file";
		return false; // terminate with error
	}

	while (getline(inFile, linea)) {
		_contents += " " + linea + "\n";
	}
	inFile.close();
	return true;

	
}

std::string InputFile::GetContents()
{
	return _contents;
}


