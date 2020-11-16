#ifndef CREATABLE_H
#define CREATABLE_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

// Header only virtual class for items that can be
class creatable : public sf::Sprite {
public:
	creatable(sf::Texture texture) {
		this->setTexture(texture);
		this->setTextureRect(sf::IntRect(10, 10, 50, 30));
		this->setColor(sf::Color(255, 255, 255, 200));
		this->setPosition(100, 25);
	};

	// Called once it's shown
	virtual void onShow() = 0;
protected:
	std::string get_file_contents(const std::string filename) {
		std::ifstream in(filename, std::ios::in | std::ios::binary);
		if (in) {
		    std::string contents;
		    in.seekg(0, std::ios::end);
		    contents.resize(in.tellg());
		    in.seekg(0, std::ios::beg);
		    in.read(&contents[0], contents.size());
		    in.close();
		    return(contents);
  		}
		return "";
	}
};

#endif
