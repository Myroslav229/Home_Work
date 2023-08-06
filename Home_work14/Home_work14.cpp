#include <iostream>
#include <string>
enum class Role {
	Assault,
	Support,
	Sniper,
	Medic
};
class Rectangle {
public:
	float leght{}, hight{};
	float getArea() {
		return leght * hight;
	}
	float getPerimeter() {
		return 2 * (leght + hight);
	}
	Rectangle(float leght, float hight) : leght{ leght }, hight{ hight } {}
	Rectangle() {
		leght = 10;
		hight = 8;
	}
};
class Weapon {
public:
	std::string name;

	float damage{};
	float range{};
	Weapon() {
		name = "Hand";
		damage = 1.25;
		range = 1.25;
	}
	Weapon(std::string name, float damage, float range) {
		this->name = name;
		this->damage = damage;
		this->range = range;
	}
};
class Player {
public:
	static const int bag = 2;
	Weapon weapons[bag];
	int weapon_counter = 0;
	std::string name {};
	Role role = Role::Assault;
	float health = 50;
	std::string team_name;
	void addWeapon(Weapon weapon) {
		if (weapon_counter < bag) {
			weapons[weapon_counter] = weapon;
			weapon_counter++;
		}

	}
	void printPlayerInfo() {
		std::cout << "Name: " << name << std::endl << "Health: " << health << std::endl << "Class: ";
		switch (role) {
		case Role::Assault:
			std::cout << "assault";
			break;
		case Role::Support:
			std::cout << "support";
			break;
		case Role::Sniper:
			std::cout << "sniper";
			break;
		case Role::Medic:
			std::cout << "medic";
			break;
		}
		if (weapon_counter == 0) std::cout << "\nNo weapon\n";
		else {
			std::cout << "\nWeapon:\n";
			for (int i = 0; i < weapon_counter; i++) {
				std::cout << weapons[i].name << " damage: " << weapons[i].damage << " range: " << weapons[i].range << std::endl;
			}
		}

		std::cout << "Team: " << team_name << std::endl;
	}
	Player(std::string name, float health, Role role) {
		this->name = name;
		this->health = health;
		this->role = role;
	}
};
class Team {
public:
	std::string name;
	int member_pointer = 0;
	static const int team_size = 4;
	Player* members[team_size];
	void addPlayer(Player* player) {
		if (member_pointer < team_size) {
			members[member_pointer] = player;
			player->team_name = name;
			member_pointer++;
		}
	}
	void removePlayer(Player* player) {
		for (int i = 0; i < member_pointer; i++) {
			if (members[i] == player) {
				members[i] = members[member_pointer];
				members[member_pointer] = NULL;
				member_pointer--;
			}
		}
	}
	Team(std::string name) {
		this->name = name;
	}
};
int main() {
	Rectangle r[4]{ {0,0}, {-5,1}, {13,5} };
	for (int i = 0; i < 4; i++) {
		std::cout << "Rectangle " << i << " area: " << r[i].getArea() << " perimeter:" << r[i].getPerimeter() << std::endl;
	}
	Player p("Antony", 100, Role::Assault);
	Weapon w("Glock", 100, 400);
	Team red("red");
	red.addPlayer(&p);
	p.printPlayerInfo();
	p.addWeapon(w);
	p.printPlayerInfo();
}