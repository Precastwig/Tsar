#ifndef BOARD_H
#define BOARD_H

#include <tile.hpp>
#include <memory>

class board : public sf::Drawable, public sf::Transformable {
public:
	board(
		sf::Vector2u tileSize,
		std::vector<std::vector<std::shared_ptr<tile>>> tiles,
		const sf::Texture& tileset
	);

	void onClick(
		sf::Vector2i position
	);

	~board();
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	std::vector<std::vector<std::shared_ptr<tile>>> m_tiles;
	const sf::Texture& m_tileset;
	int m_width;
	int m_height;
	sf::Vector2u m_tileSize;
};

#endif
