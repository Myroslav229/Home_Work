#pragma once
#include <string>
#include<iostream>
#include "PlayerClass.h"
#include "Weapon.h"


class Player
{
public:
	Player(const std::string& name = "Auto Generated NameId", Weapon* weapon = new BareHand, PlayerClass* playerClass = new DefaultClass)
		: m_name(name), m_weapon(weapon), m_class(playerClass) {
		setHealth(100 * playerClass->getHealthMultiplier());
	}
	~Player()
	{
		delete m_class;
		delete m_weapon;
	}


	std::string getName() const { return m_name; }
	int getBaseDamage(int distance) { return m_weapon->getDamageRate(distance); }

	void setWeapon(Weapon* weapon)
	{
		delete m_weapon;
		m_weapon = weapon;
	}
	void setPlayerClass(PlayerClass* playerClass) {
		{
			delete m_class;
			m_class = playerClass;
		}
	}
	int getHealth() { return m_health; }
	void setHealth(int health) { m_health = health; }
	bool isEliminated() const { return m_health <= 0; }

	void attack(Player& other, int distance)
	{
		if (&other == this)
		{
			std::cout << "\n-------FRIENDLY FIRE!-------\n";
		}

		if (other.isEliminated())
		{
			std::cout << "Player " << other.getName() << " has been already eliminated!\n";
			return;
		}

		//#TODO: Optional: Add your own damage-related modifier
		float multipler = 0.f;
		if (dynamic_cast<RangedWeapon *>(m_weapon) != nullptr) {
			//std::cout << " Ranged attack \n";
			multipler = m_class->getRangedDamageMultiplier();
		}
		else if (dynamic_cast<MeleeWeapon*>(m_weapon) != nullptr) {
			//std::cout << " Melee attack \n";
			multipler = m_class->getMeleeDamageMultiplier();
		}
		const int damage = (int)(m_weapon->getDamageRate(distance) * multipler / other.m_class->getDefenseMultiplier());
		//std::cout << other.getHealth() << std::endl;
		other.setHealth((other.getHealth() - damage));

		std::cout << "Player " << getName() << " attacked Player " << other.getName() <<" with damage " << damage << std::endl;

		std::cout << "Health left: " << other.getHealth() << std::endl;

		if (m_health <= 0)
		{
			m_health = 0;
			std::cout << "Player " << other.getName() << " was eliminated!\n";
		}
	}

private:
	int m_health = 100;
	std::string m_name;

	PlayerClass* m_class = nullptr;
	Weapon* m_weapon = nullptr;
};