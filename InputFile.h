	//Autor: Diana Laura Valencia Dominguez A01167418
	//********************************************************* /
	//
	//  Tarea1 Diana Valencia.cpp
	//  DianaValenciaTarea1
	//
	//  Created by Diana Valencia  on 2017-09-06.
	//
	//
#pragma once
#include <string>
class InputFile
{
public:
	bool Read(std::string FileName);
	std::string GetContents();

private:
	std::string _contents;

};
