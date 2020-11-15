#ifndef GRASS_H
#define GRASS_H

#include <tile.hpp>
#include <SFML/Graphics.hpp>

// A light wrapper for our quadrefs on the board
// Encompassing some functionality and eventually game logic
class grass : public tile {
public:
	grass(const sf::Texture& tileset, const sf::Vector2u& tilesize)
		: tile(0, tileset, tilesize) {};
};

#endif
