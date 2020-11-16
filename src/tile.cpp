#include <tile.hpp>
#include <assert.h>
#include <creatable.hpp>

void tile::drawContained(sf::RenderTarget& target) {
	for(unsigned int i = 0; i < m_contained.size(); i++) {
		sf::Vector2f new_pos = quad_ref[0].position;
		new_pos = new_pos + sfVector2f(m_tileSize/4, m_tileSize/4);
		m_contained[i]->setPosition(new_pos);
		target.draw(*m_contained[i]);
	}
}

void tile::updateQuadRef(sf::Vertex* ref) {
	assert(ref);
	quad_ref = ref;
}

void tile::updateQuadTexture() {
	assert(quad_ref);
	int tu, tv;
	getTexturePositioninTileset(tu, tv);
	quad_ref[0].texCoords = sf::Vector2f(tu * m_tilesize.x, tv * m_tilesize.y);
	quad_ref[1].texCoords = sf::Vector2f((tu + 1) * m_tilesize.x, tv * m_tilesize.y);
	quad_ref[2].texCoords = sf::Vector2f((tu + 1) * m_tilesize.x, (tv + 1) * m_tilesize.y);
	quad_ref[3].texCoords = sf::Vector2f(tu * m_tilesize.x, (tv + 1) * m_tilesize.y);
}

void tile::getTexturePositioninTileset(int& tu, int& tv) {
	tu = m_texturepos % (m_tileset.getSize().x / m_tilesize.x);
	tv = m_texturepos / (m_tileset.getSize().x / m_tilesize.x);
}

void tile::setQuadPosition(const unsigned int& x, const unsigned int& y) {
	assert(quad_ref);
	quad_ref[0].position = sf::Vector2f(x * m_tilesize.x, y * m_tilesize.y);
	quad_ref[1].position = sf::Vector2f((x + 1) * m_tilesize.x, y * m_tilesize.y);
	quad_ref[2].position = sf::Vector2f((x + 1) * m_tilesize.x, (y + 1) * m_tilesize.y);
	quad_ref[3].position = sf::Vector2f(x * m_tilesize.x, (y + 1) * m_tilesize.y);
}
