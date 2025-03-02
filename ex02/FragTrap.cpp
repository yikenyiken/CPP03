#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	name = "defaultName";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << "'s default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << "'s String constructor called\n";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap" << "'s Copy constructor called\n";
	*this = other;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed\n";
}


FragTrap	&FragTrap::operator = (const FragTrap &rhs)
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;

	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (!energyPoints || !hitPoints)
	{
		std::cout << "FragTrap " << name << " unable to attack " << target
			<< (!energyPoints ? ". Energy points: " : ". Hit points: ") << "0\n";
		return ;
	}

	--energyPoints;

	std::cout << "FragTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!\n";
}

void	FragTrap::highFivesGuys()
{
	if (!energyPoints || !hitPoints)
	{
		if (!energyPoints || !hitPoints)
		{
			std::cout << "FragTrap " << name << " unable to request High fives"
				<< (!energyPoints ? ". Energy points: " : ". Hit points: ") << "0\n";

			return ;
		}
	}

	std::cout << "FragTrap " << name << ": High fives, anyone?\n";
}