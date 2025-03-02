#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("defaultName"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << "'s default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10),
	energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << "'s String constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap" << "'s Copy constructor called\n";
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed\n";
}


ClapTrap	&ClapTrap::operator = (const ClapTrap &rhs)
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;

	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!energyPoints || !hitPoints)
	{
		std::cout << "ClapTrap " << name << " unable to attack " << target
			<< (!energyPoints ? ". Energy points: " : ". Hit points: ") << "0 \n";

		return ;
	}

	--energyPoints;

	std::cout << "ClapTrap " << name << " attacks " << target
		<< ", causing " << attackDamage << " points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!energyPoints || !hitPoints)
	{
		std::cout << "ClapTrap " << name << " unable to repair itself" 
			<< (!energyPoints ? ". Energy points: " : ". Hit points: ") << "0 \n";

		return ;
	}

	--energyPoints;
	hitPoints += amount;

	std::cout << "ClapTrap " << name << " repaired itself by "
		<< amount << " points\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints = (hitPoints < amount) ? 0 : (hitPoints - amount);
	
	std::cout << "ClapTrap " << name << " received a damage of " << amount << " points\n";
}