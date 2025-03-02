#include "ScavTrap.hpp"
#include <iostream>

void	getScavTrapGoing()
{
	std::cout << "# SCAVTRAP #\n";
	ScavTrap	dummy("Dummy");
	ScavTrap	ghost("zombie");
	ScavTrap	zombie = ghost;

	std::cout << std::endl;

	dummy.attack("Zombie");
	zombie.takeDamage(190);

	std::cout << std::endl;

	zombie.attack("Dummy"); // shouldn't be able to do anything
	zombie.beRepaired(5);

	std::cout << std::endl;

	ghost.attack("Dummy");
	dummy.takeDamage(90); 
	dummy.beRepaired(10);
	dummy.guardGate();

	std::cout << std::endl;

	dummy.takeDamage(20);
	dummy.guardGate();
	dummy.beRepaired(3); // shouldn't be able to do anything
	std::cout << std::endl;
}

void	getClapTrapGoing()
{
	std::cout << "# ClapTrap #\n";

	ClapTrap	dummy("Dummy");
	ClapTrap	ghost("zombie");
	ClapTrap	zombie = ghost;

	std::cout << std::endl;

	dummy.attack("Zombie");
	zombie.takeDamage(19);

	std::cout << std::endl;

	zombie.attack("Dummy"); // shouldn't be able to do anything
	zombie.beRepaired(5);

	std::cout << std::endl;

	ghost.attack("Dummy");
	dummy.takeDamage(9); 
	dummy.beRepaired(1);

	std::cout << std::endl;

	dummy.takeDamage(2);
	dummy.beRepaired(3); // shouldn't be able to do anything

	std::cout << std::endl;

	ghost.attack("innocent");
	ghost.attack("innocent");
	ghost.attack("innocent");
	ghost.attack("innocent");
	ghost.attack("innocent");
	ghost.attack("innocent");
	ghost.attack("innocent");
	ghost.attack("innocent");
	ghost.attack("innocent");

	std::cout << std::endl;

	ghost.attack("innocent"); // shouldn't be able to do anything
	ghost.beRepaired(5);
	std::cout << std::endl;
}

int main()
{
	getClapTrapGoing();
	getScavTrapGoing();
}