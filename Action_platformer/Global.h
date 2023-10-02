#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

sf::RenderWindow window(sf::VideoMode(1024, 1024), "Game" );


class SpriteSheet {
public:
	std::map<std::string, sf::IntRect> frame;
	SpriteSheet() = default;
	SpriteSheet(std::string path, auto && ... args) {
		texture.loadFromFile(path);
		([&] {frame[std::string{args.first}] = args.second; }(), ...);
	}

	SpriteSheet(std::string path, sf::IntRect rect) {
		texture.loadFromFile(path);
		frame[path] = rect;
	}

	SpriteSheet(std::string path) {
		texture.loadFromFile(path);
		frame[path] = sf::IntRect{ 0, 0, (int)texture.getSize().x, (int)texture.getSize().y };
	}
	sf::Texture texture;
};

struct TexturePack {
	std::map<std::string, SpriteSheet> pack;
	TexturePack() {
		pack["player"] = {
			"images/PlayerList.png",
			std::pair{"walk0", sf::IntRect{0, 0, 64, 128}},
			std::pair{"walk1", sf::IntRect{64, 0, 64, 128}},
			std::pair{"walk2", sf::IntRect{128, 0, 64, 128}},
			std::pair{"walk3", sf::IntRect{192, 0, 64, 128}},
			std::pair{"jump", sf::IntRect{256, 0, 64, 128}},
		};
		pack["enemy"] = {
			"images/EnemyList.png",
			std::pair{"walk0", sf::IntRect{0, 0, 64, 128}},
			std::pair{"walk1", sf::IntRect{64, 0, 64, 128}},
			std::pair{"walk2", sf::IntRect{128, 0, 64, 128}},
			std::pair{"walk3", sf::IntRect{192, 0, 64, 128}},
			std::pair{"jump", sf::IntRect{256, 0, 64, 128}},
		};
		pack["block0"] = { "images/block0.png" };
		pack["bullet0"] = { "images/bullet.png" };
		pack["medkit"] = { "images/medkit.png" };
		pack["background"] = { "images/background.png" };
		pack["win"] = { "images/picture.png" };
	}

	SpriteSheet& operator[](std::string name) {
		return pack[name];
	}

} texture_pack {};


class Out {
private:
	sf::Font font{};
	sf::Text text{};
public:
	Out() {
		font.loadFromFile("Marlboro.ttf");
		text.setFont(font);
	}
	sf::Text& operator ()(sf::String out, int size, float x, float y) {
		text.setString(out);
		text.setCharacterSize(size);
		text.setPosition(x,y);
		return text;
	}
} out{};

namespace global {
	static int id = 0;
	bool gameOver = false;

}