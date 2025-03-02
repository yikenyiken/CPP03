#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	name = "defaultName";
	energyPoints = 50;

	std::cout << "DiamondTrap " << name << "'s default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	energyPoints = 50;
	std::cout << "DiamondTrap " << name << "'s String constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :
	ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap's Copy constructor called\n";
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " has been destroyed\n";
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &rhs)
{
	name = rhs.name;
	hitPoints = rhs.hitPoints;
	energyPoints = rhs.energyPoints;
	attackDamage = rhs.attackDamage;

	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << name << " has ClapTrap " << ClapTrap::name << std::endl;
}