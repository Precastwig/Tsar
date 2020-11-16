#ifndef ROBOT_H
#define ROBOT_H

#include <SFML/Graphics.hpp>
#include <creatable.hpp>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

class robot : public creatable {
public:
	robot(sf::Texture texture, const std::string propertiesfile) : creatable(texture) {
		const char* properties_string = get_file_contents(propertiesfile).c_str();
		rapidjson::Document document;
		document.Parse(properties_string);
	};

	virtual void onShow() override;

private:
	int attack_distance;
	std::vector<std::vector<bool>> attack_pattern;
	int max_health;
	int current_health;
};

#endif
