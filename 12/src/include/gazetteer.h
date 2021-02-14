/// @file gazetteer.h
#ifndef GAZETTEER_H
#define GAZETTEER_H

#include <map>
#include <string>

class Gazetteer {
	std::map<std::string, std::string> dict;
public:
	auto getInfo(const std::string& country) -> std::string {
		auto val = this->dict.find(country);
		if (val == this->dict.end()) {
			return "No info about this country.";
		}
		return val->second;
	}

	auto insert(const std::string& country, const std::string info) -> bool {
		bool ret = this->dict.contains(country);
		this->dict.insert({country, info});
		return ret;
	}

	auto insert_force(const std::string& country, const std::string info) -> bool {
		return this->dict.insert_or_assign(country, info).second;
	}
};

#endif
