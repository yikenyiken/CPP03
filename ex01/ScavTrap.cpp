#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	name = "defaultName";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << "'s default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << "'s String constructor called\n";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap" << "'s Copy constructor called\n";
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed\n";
}


ScavTrap	&ScavTrap::operator = (const ScavTrap &rhs)
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;

	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (!energyPoints || !hitPoints)
	{
		std::cout << "ScavTrap " << name << " unable to attack " << target
			<< (!energyPoints ? ". Energy points: " : ". Hit points: ") << "0\n";
		return ;
	}

	--energyPoints;

	std::cout << "ScavTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!\n";
}

void	ScavTrap::guardGate()
{
	if (!energyPoints || !hitPoints)
	{
		std::cout << "ScavTrap " << name << " unable to guard the gate"
			<< (!energyPoints ? ". Energy points: " : ". Hit points: ") << "0\n";

		return ;
	}

	std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}