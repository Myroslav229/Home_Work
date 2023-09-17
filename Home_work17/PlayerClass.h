#pragma once

class PlayerClass
{
	//FEEL free to add other unique properties
public:
	virtual float getHealthMultiplier() const = 0;
	virtual float getMeleeDamageMultiplier() const = 0;
	virtual float getRangedDamageMultiplier() const = 0;
	virtual float getDefenseMultiplier() const = 0;
};

class DefaultClass : public PlayerClass{
	virtual float getHealthMultiplier() const override { return 1.0f; }
	virtual float getMeleeDamageMultiplier() const override { return 1.0f; }
	virtual float getRangedDamageMultiplier() const override { return 1.0f; }
	virtual float getDefenseMultiplier() const override { return 1.0f; }
};

class DefenderClass : public DefaultClass{
public:
	//Leave damage multiplier as is
	virtual float getHealthMultiplier() const override { return 1.2f; }
	virtual float getDefenseMultiplier() const override { return 1.5f; }
};

class DamagerClass : public DefaultClass {
public:
	virtual float getRangedDamageMultiplier() const override { return 1.2f; }
	virtual float getMeleeDamageMultiplier() const override { return 1.2f; }
};

class WorkerClass : public DefaultClass {
	virtual float getRangedDamageMultiplier() const override { return 0.7f; }
	virtual float getMeleeDamageMultiplier() const override { return 1.9f; }
	virtual float getHealthMultiplier() const override { return 1.5f; }
};
//TODO: Implement other PlayerClasses with other properties