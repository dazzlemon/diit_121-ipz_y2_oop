/// @file gazetteer.h
#ifndef GAZETTEER_H
#define GAZETTEER_H

#include <map>
#include <string>

/**
 * std::map wrapper to represent Gazetteer.
 */
class Gazetteer {
	std::map<std::string, std::string> dict;
public:
	/**
	 * @brief Returns info about country.
	 * @param[in] country Country to get info about
	 * @return String with info about country
	 * @details
	 * Returns "No info about this country." if no info about this country.
	 */
	[[nodiscard]] auto getInfo(const std::string& country) const -> std::string {
		auto val = this->dict.find(country);
		if (val == this->dict.end()) {
			return "No info about this country.";
		}
		return val->second;
	}

	/**
	 * @brief Inserts info about country.
	 * @param[in] country Country to insert info about
	 * @param[in] info Info about country
	 * @return true in case of success(see details)
	 * @details
	 * Inserts info about country if there is none, returns true.
	 * If info already exists returns false.
	 */
	auto insert(const std::string& country, const std::string info) -> bool {
		bool ret = !this->dict.contains(country);
		this->dict.insert({country, info});
		return ret;
	}

	/**
	 * @brief Inserts info about country.
	 * @param[in] country Country to insert info about
	 * @param[in] info Info about country
	 * @return true in case of insertion, false in case of replacement
	 * Inserts info about country if there is none, returns true.
	 * If info already exists, replaces it returns false.
	 */
	auto insert_force(const std::string& country, const std::string info) -> bool {
		return this->dict.insert_or_assign(country, info).second;
	}
};

#endif
