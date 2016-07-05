#include "fstream"
#include "json.hpp"
#include "DebugHandler.h"

#ifdef COMPILE_MYLIBRARY
#define MYLIBRARY_EXPORT __declspec(dllexport)
#else
#define MYLIBRARY_EXPORT __declspec(dllimport)
#endif

using json = nlohmann::json;

#ifndef __JSONHANDLER_H_INCLUDED__
#define __JSONHANDLER_H_INCLUDED__
class MYLIBRARY_EXPORT JSONHandler
{
protected:
	std::string filePath;
	json data;
	DebugHandler debug;

	//Checks if the given file exists
	bool fileExists(const std::string& name);
	
	//Gets a json object from the given file
	json getJSON(std::string fileName);

	//Saves the given json object to the given file
	void saveJSON(std::string fileName, json data);
};
#endif