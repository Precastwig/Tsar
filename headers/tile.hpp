#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <creatable.hpp>
#include <memory>

// A light wrapper for our quadrefs on the board
// Encompassing some functionality and eventually game logic
class tile {
public:
	tile(int texture, const sf::Texture& tileset, const sf::Vector2u& tilesize)
		: m_texturepos(texture), m_tileset(tileset), m_tilesize(tilesize) {};

	void addContained(std::shared_ptr<creatable> thing);
	void drawContained(sf::RenderTarget& target);

	void setQuadPosition(const unsigned int& x, const unsigned int& y);
	void updateQuadRef(sf::Vertex* ref);
	void updateQuadTexture();
	
protected:
	void getTexturePositioninTileset(int& tu, int& tv);
	int m_texturepos;
	const sf::Texture& m_tileset;
	const sf::Vector2u& m_tilesize;
	std::vector<std::shared_ptr<creatable>> m_contained;

private:
	sf::Vertex* quad_ref;
};

#endif
