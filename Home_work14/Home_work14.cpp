#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Veapon; class Player; class Team;
enum class Role {
	Assault,
	Support,
	Sniper,
	Medic
};
class Rectangle {
private:
	float lenght{}, hight{};
public:
	
	const float getArea() {
		return lenght * hight;
	}
	const float getPerimeter() {
		return 2 * (lenght + hight);
	}
	Rectangle(float leght, float hight) : lenght{ leght }, hight{ hight } {}
	Rectangle() {
		lenght = 0;
		hight = 0;
	}
};
class Weapon {
	
private:
	friend Player;
	std::string name;

	float damage{};
	float range{};
public:
	
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
private:
	static const int bag = 2;
	std::vector<Weapon *> weapons;
	//Weapon weapons[bag];
	//int weapon_counter = 0;
	std::string name {};
	Role role = Role::Assault;
	float health = 50;
	std::string team_name;
public:

	void addWeapon(Weapon & weapon) {
		if (weapons.size() < bag) {
			weapons.emplace_back(&weapon);
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
		if (weapons.size() == 0) std::cout << "\nNo weapon\n";
		else {
			std::cout << "\nWeapon:\n";
			for (auto weapon: weapons) {
				std::cout << weapon->name << " damage: " << weapon->damage << " range: " << weapon->range << std::endl;
			}
		}

		std::cout << "Team: " << team_name << std::endl;
	}
	Player(std::string name, float health, Role role) {
		this->name = name;
		this->health = health;
		this->role = role;
	}
	
	Player & operator = (const Player & player) {
		name = player.name;
		health = player.health;
		role = player.role;

		return *this;
	}
	bool operator == (Player & player) {
		if (this == &player) {
			return true;
		}
		return false;
	};
	friend Team;
};
class Team {
	friend Player;
private:
	std::string name;
	static const int team_size = 4;
	std::vector<Player *> members;
public:
	
	void addPlayer(Player & player) {
		if (members.size() < team_size) {
			members.emplace_back(&player);
			player.team_name = name;
		}
		
	}
	void removePlayer(Player & player) {
		members.erase(std::remove_if(members.begin(), members.end(), [&](Player * member) {
			return (member == &player);
		}), members.end());
		player.team_name = "NONE";
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
	red.addPlayer(p);
	p.printPlayerInfo();
	p.addWeapon(w);
	red.removePlayer(p);
	p.printPlayerInfo();
}