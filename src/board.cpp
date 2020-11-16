#include <board.hpp>

#include <tile.hpp>

#include <assert.h>
#include <stdlib.h>
#include <memory>

board::board(
	sf::Vector2u tileSize,
	std::vector<std::vector<std::shared_ptr<tile>>> tiles,
	const sf::Texture& tileset
)
	: m_tiles(tiles), m_tileset(tileset), m_width(tiles.size()), m_height(tiles[0].size()), m_tileSize(tileSize)
{
    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(m_width * m_height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < m_width; ++i) {
        for (unsigned int j = 0; j < m_height; ++j) {
            // get the current tile number
            auto tile = m_tiles[i][j];

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];
						tile->updateQuadRef(quad);

            // define its 4 corners
            tile->setQuadPosition(i,j);

						tile->updateQuadTexture();
        }
	}
}

void board::onClick(
	sf::Vector2i position
)
{
	// find position relative to our square
	auto topLeftPos = getPosition();
	float relativePosX = position.x - topLeftPos.x;
	float relativePosY = position.y - topLeftPos.y;

	int map_width = m_tileSize.x * m_width;
	int map_height = m_tileSize.y * m_height;

	if (relativePosX > 0 && relativePosY > 0 &&
		relativePosX < map_width && relativePosY < map_height) {
		int Xtile = (relativePosX / map_width) * m_width;
		int Ytile = (relativePosY / map_height) * m_height;
		assert(Xtile >= 0 && Xtile < m_width);
		assert(Ytile >= 0 && Ytile < m_height);

		m_tiles[Xtile][Ytile]->updateQuadTexture();
	}
}

board::~board()
{
}

void board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);

	for(unsigned int i = 0; i < m_width; i++) {
		for (unsigned int j = 0; j < m_height; j++) {
			// m_tiles[i][j]->drawContained(target);
		}
	}
}
