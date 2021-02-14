/// @file gazetteer.h
#ifndef GAZETTEER_H
#define GAZETTEER_H

#include <map>
#include <string>

class Gazetteer {
	static const std::map<std::string, std::string> dict;
public:
	static auto getInfo(const std::string& country) -> std::string {
		if (Gazetteer::dict.contains(country)) {// try catch would prolly be more efficient but more verbose
			return Gazetteer::dict.at(country);
		}
		return "No info about this country.";
	}
};

#endif
