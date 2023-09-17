#include <string>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{

	//static_assert(std::is_base_of_v<Weapon, SniperRifle>);

	//Game cycle
	Player player1("OnePunchMan", new SniperRifle);
	Player player2("JohnCena", new Axe, new DefenderClass);
	Player player3("Joseph", new Spear, new WorkerClass);
	
	player1.attack(player2, 2);
	player1.attack(player2, 5);
	player1.attack(player1, 2);
	player2.attack(player3, 2);
	player3.attack(player2, 10);

	return 0;
}