/// @file gazetteer_dynamic.h
#ifndef GAZETTEER_DYNAMIC_H
#define GAZETTEER_DYNAMIC_H

#include <map>
#include <string>
#include <vector>

class GazetteerDynamic {
	std::multimap<std::string, std::string> multidict;
public:
	void insertInfo(const std::string& country, const std::string data) {
		this->multidict.insert({country, data});
	}

	auto getInfo(const std::string& country) -> std::vector<std::string> {
		auto [first, last] = multidict.equal_range(country);
		auto info = std::vector<std::string>();
		for (; first != last; first++) {
			info.push_back(first->second);
		}
		return info;
	}

	void removeCountry(const std::string& country) {
		multidict.erase(country);
	}
};

#endif
