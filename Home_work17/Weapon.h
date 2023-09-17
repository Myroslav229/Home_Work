#pragma once

class Weapon
{
protected:
	int range {};
	int damage{};


public:
	//TODO: Feel free to add other properties
	//Or use another approach for damage calculation:
	//health, stamina, weight, level, speed or whatever you have in mind.
	virtual int getDamageRate(int distance) const {
		if (distance < range) {
			return damage * (range - distance);
		}
		else return 0;
	}
};

class RangedWeapon : public Weapon
{
public:
	int getDamageRate(int distance) const override { 
		return static_cast<int>(damage * getPrecision(distance)); 
	}
	//protected means this method is not accessible from outside but is accessible by children classes
protected:
	float getPrecision(int distance) const {
		if (distance <= range) {
			return static_cast<float>(0.01*(range - (distance/2)));
		}
		else {
			return static_cast<float>(0.01*(range / (distance/2)));
		}
	}
};

class SniperRifle : public RangedWeapon
{
public:
	SniperRifle() { range = 100; damage = 40; }
};

//TODO
class Pistol : public RangedWeapon
{
	Pistol() { range = 30; damage = 45; }
};

//TODO
class AssaultRifle : public RangedWeapon
{
public:
	AssaultRifle( ) { range = 45; damage = 35; }
};

class MeleeWeapon : public Weapon
{
public:
	int getDamageRate(int distance) const override {
		if (distance < range) {
			return damage;
		}
		else return 0;
	}
};

class BareHand : public MeleeWeapon
{
public:
	BareHand() { range = 5; damage = 15; }
	//TODO
};

class Axe : public MeleeWeapon
{
public:
	Axe() { range = 6; damage = 65; }
	//TODO
};
class Spear : public MeleeWeapon
{
public:
	Spear() { range = 10; damage = 65; }
	int getDamageRate(int distance) const override {
		if (distance <= range) {
			return damage*(distance/range);
		}
		else return 0;
	}
	//TODO
};