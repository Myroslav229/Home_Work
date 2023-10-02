#pragma once
#include <variant>
#include <vector>
#include <tuple>
#include "Systems.h"
#include "Entities.h"
#include "Global.h"
#include "World.h"


class Game {

public:
	Game() {
		float grid = 64;
		
		for (int i = 0; i < world.map.size(); ++i) {
			for (int j = 0; j < world.map[i].size(); ++j ) {
				if (i % 16 == 0 && j % 16 == 0) {
					entities[global::id] = (Background{ {j * grid, i * grid} });
					++global::id;
				}
				
			}
		}
		
		for (int i = 0; i < world.map.size(); ++i) {
			for (int j = 0; j < world.map[i].size(); ++j) {
				
				switch (world.map[i][j]){
				case ' ': continue;
				case 'a': entities[global::id] = (Tile{ {j * grid, i * grid} }); ++global::id; continue;
				case 'p': entities[global::id] = (Player{ {j * grid, i * grid} }); ++global::id;  continue;
				case 'e': entities[global::id] = (Enemy{ {j * grid, i * grid} }); ++global::id;  continue;
				case 'b': entities[global::id] = (Bullet{ {j * grid, i * grid} }); ++global::id;  continue;
				case 'm': entities[global::id] = (MedicalKit{ {j * grid, i * grid} }); ++global::id;  continue;
				case 'w':entities[global::id] = (Win{ {j * grid, i * grid} }); ++global::id;  continue;
				}
			}
		}
	}

	void start() {
		sf::Clock clock;
		float elapsed{};

		const float frame_time = (float)1 / 60;
		while (window.isOpen()) {
			sf::Time dt = clock.restart();
			elapsed += dt.asSeconds();
			if (elapsed >= frame_time) {
				sf::Event event;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed) { window.close(); }
				}
				window.clear();

				systems.update(elapsed);
				window.display();
				elapsed = 0;
			}
			
		}
	}

	World world;
	Entities entities;
	Systems systems{entities};
};
