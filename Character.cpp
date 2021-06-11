#include <stdexcept>
#include "Character.h"

mbs::Character::Character(std::string name, double x, double y, unsigned int health, unsigned int stamina, std::vector<std::string>& inventory)
{
    setID(getLastID());
    setName(name);
    setPosX(x);
    setPosY(y);
    setHealth(health);
    setStamina(stamina);
    setInventory(inventory);

    ++lastID_;
}

mbs::Character::~Character()
{
}

void mbs::Character::setID(unsigned int id)
{
    id_ = id;
}

void mbs::Character::setName(std::string name)
{
    if (name.length() > 0)
    {
        name_ = name;
    }
    else
    {
        throw std::invalid_argument("Character name cannot be empty.");
    }
}

void mbs::Character::setPosX(double x)
{
    posX_ = x;
}

void mbs::Character::setPosY(double y)
{
    posY_ = y;
}

void mbs::Character::setHealth(unsigned int health)
{
    health_ = health;
}

void mbs::Character::setStamina(unsigned int stamina)
{
    stamina_ = stamina;
}

void mbs::Character::setInventory(std::vector<std::string>& inventory)
{
    inventory_.clear();
    for (unsigned int i = 0; i < inventory.size(); ++i)
    {
        inventory_.push_back(inventory[i]);
    }
}

std::string mbs::Character::toString()
{
    std::string output = "";

    output += getName() + "'s ID: " + std::to_string(getID()) + "\n";
    output += getName() + "'s position: (" + std::to_string(getPosX()) + "; " + std::to_string(getPosY()) + ")\n";
    output += getName() + "'s health and stamina: " + std::to_string(getHealth()) + " hp and " + std::to_string(getStamina()) + " sp\n";

    output += getName() + "'s inventory:";
    for (unsigned int i = 0; i < getInventory().size(); ++i)
    {
        output += " " + getInventory()[i];
        if (i < getInventory().size() - 1)
        {
            output += ',';
        }
    }

    return output;
}