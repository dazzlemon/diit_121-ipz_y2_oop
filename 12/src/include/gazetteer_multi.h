/// @file gazetteer_multi.h
#ifndef GAZETTEER_MULTI_H
#define GAZETTEER_MULTI_H

#include <map>
#include <string>
#include <vector>

/**
 * Wrapper for std::multimap to represent Gazetteer.
 */
class GazetteerMulti {
	std::multimap<std::string, std::string> multidict;
public:
	/**
	 * @brief Inserts new info about country.
	 * @param[in] country Country to insert info about
	 * @param[in] data Info about country
	 */
	void insertInfo(const std::string& country, const std::string data) {
		this->multidict.insert({country, data});
	}

	/**
	 * @brief Returns vector of inputs about country.
	 * @param[in] country Country to get info about
	 * @returns Vector of input about country(may be empty)
	 */
	auto getInfo(const std::string& country) -> std::vector<std::string> {
		auto [first, last] = multidict.equal_range(country);
		auto info = std::vector<std::string>();
		for (; first != last; first++) {
			info.push_back(first->second);
		}
		return info;
	}

	/**
	 * @brief Removes all inputs about country.
	 * @param[in] country Country to remove inputs about
	 */
	void removeCountry(const std::string& country) {
		multidict.erase(country);
	}
};

#endif
