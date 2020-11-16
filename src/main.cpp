#include <SFML/Graphics.hpp>
#include <board.hpp>
#include <iostream>
#include <memory>
#include <tile.hpp>
#include <grass.hpp>
#include <robot.hpp>

int main() {
    int window_width = 1200;
    int window_height = 1200;
    sf::ContextSettings context(0,0,8);
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "tsar", sf::Style::Default, context);
    int grid_size_x = 6;
    int grid_size_y = 6;

    sf::Texture tileset;
    if (!tileset.loadFromFile("textures/tileset.png")) {
        return -1;
    }
    sf::Vector2u tilesize(200,200);

    std::vector<std::vector<std::shared_ptr<tile>>> map_tiles;
    for (int i = 0; i < grid_size_x; i++) {
        std::vector<std::shared_ptr<tile>> temp;
        for (int j = 0; j < grid_size_y; j++) {
            auto new_tile = std::make_shared<grass>(tileset, tilesize);
            temp.push_back(new_tile);
        }
        map_tiles.push_back(temp);
    }

    sf::Texture trevor_texture;
    if (!trevor_texture.loadFromFile("textures/trevor.png")) {
      return -1;
    }
    auto trevor = std::make_shared<robot>(trevor_texture, "json/trevor.json");
    map_tiles[0][0]->addContained(trevor);
	  board map(
		    tilesize,
		    map_tiles,
        tileset
	  );
    int map_width = 6*50;
    // map.setPosition(window_width / 2 - map_width / 2, window_height / 2 - map_width / 2);
    map.setPosition(0,0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                map.onClick(
                    sf::Mouse::getPosition(window)
                );
            }
        }
        window.clear(sf::Color(240,233,194,255));
        window.draw(map);
        window.display();
    }



    return 0;
}
