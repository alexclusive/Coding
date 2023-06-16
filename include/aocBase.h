#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

#ifndef aocBase

/*
	Replaces each item in string that matches remove with replace.
	e.g. replaceAll("test:test,test", {":", ","}, " ") -> "test test test"
	@return the altered string
	@param line - the string to work with
	@param remove - a list of strings to remove
	@param replace - the string to replace removed items with
*/
std::string replaceAll(std::string line, std::vector<std::string> replace, std::string with) {
	for (auto rem : replace) {
		line = std::regex_replace(line, std::regex(rem), with);
	}
	return line;
}

/*
	Removes the spaces at the start of a string
	@return the altered string
	@param str - the string to work with
*/
std::string removeBeginingSpaces(std::string str) {
	size_t begin = str.find_first_not_of(" ");
	return str.substr(begin);
}

/*
	Splits a string by delim into a vector.
	@return the altered string - now a vector of strings
	@param str - the string to work with
	@param delim - the char delimiter to split str on
*/
std::vector<std::string> split(std::string str, char delim) {
	std::vector<std::string> line;
	std::string word = "";
	for (auto x : str) {
		if (x == delim) {
			line.push_back(word);
			word = "";
		} else {
			word += x;
		}
	}
	line.push_back(word);
	return line;
}

/*
	Does replacements, removes begining whitespace, and splits string.
	@return the altered string - now a vector of strings
	@param line - the string to alter
	@param splitOn - the char delimiter to split on
	@param removeFrontSpaces - true if we want to remove spaces at the start of the line
	@param replace - a vector of strings to replace (or remove if `with` is not set)
	@param with - string to replace matches of replace strings
*/
std::vector<std::string> fixLine(	std::string line,
									char splitOn=' ',
									bool removeFrontSpaces=false,
									std::vector<std::string> replace={}, 
									std::string with="") {
	std::vector<std::string> ret;
	if (line.size() > 0) {
		if (replace.size() > 0) {
			line = replaceAll(line, replace, with);
		}
		if (removeFrontSpaces) {
			line = removeBeginingSpaces(line);
		}
		ret = split(line, splitOn);
	}
	return ret;
}

/*
	Reads in a file and converts each line to a string that has been broken up into words.
	@return a vector of a vector of strings from each line in the file (outer=line, inner=word)
	@param in - The file to read from
	@param splitOn - the char delimiter to split on
	@param removeFrontSpaces - true if we want to remove spaces at the start of the line
	@param replace - a vector of strings to replace (or remove if `with` is not set)
	@param with - string to replace matches of replace strings
*/
std::vector<std::vector<std::string>> readFileVector(	std::string name,
														char splitOn=' ',
														bool removeFrontSpaces=false,
														std::vector<std::string> replace={}, 
														std::string with="") {
	std::ifstream in (name);
	if (in.is_open()) {
		std::vector<std::vector<std::string>> fileLines;

		std::string buffer = "";
		while (getline(in, buffer)) {
			std::vector<std::string> row = fixLine(buffer, splitOn, removeFrontSpaces, replace, with);
			fileLines.push_back(row);
		}
		
		return fileLines;
	}
	std::vector<std::vector<std::string>> empty;
	return empty;
}

/*
	Reads in a file and converts each line to a string.
	@return a vector of strings from each line in the file
	@param name - the filename to read
*/
std::vector<std::string> readFile(std::string name) {
	std::ifstream in (name);
	if (in.is_open()) {
		std::vector<std::string> fileLines;

		std::string buffer = "";
		while (getline(in, buffer)) {
			fileLines.push_back(buffer);
		}

		return fileLines;
	}
	std::vector<std::string> empty;
	return empty;
}

#endif // aocBase

// int main() {
// 	std::string filename = "example";
// 	bool vector = true;
// 	if (vector) {
// 		std::vector<std::vector<std::string>> fileVector = openAndReadVector(filename, ' ');
// 		std::cout << "fileVector" << std::endl;
// 			for (auto row : fileVector) {
// 				for (auto word : row) {
// 					std::cout << word << ", ";
// 				}
// 				std::cout << std::endl;
// 			}
// 	} else {
// 		std::vector<std::string> file = openAndRead(filename);
// 		std::cout << "file" << std::endl;
// 			for (auto line : file) {
// 				std::cout << line << std::endl;
// 			}
// 	}
// }