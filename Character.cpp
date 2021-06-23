#include <stdexcept>
#include <iostream>
#include "Character.h"

namespace mbs {
    Character::Character()
    {
        std::vector<std::string> inventory = {};
    
        setID(getLastID());
        setName("Default Character");
        setPosX(0);
        setPosY(0);
        setHealth(100);
        setStamina(100);
        setInventory(inventory);

        ++lastID_;
    }

    Character::Character(std::string name, double& x, double& y, unsigned int health, unsigned int stamina, std::vector<std::string>& inventory)
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

    Character::~Character()
    {
    }

    void Character::setID(unsigned int id)
    {
        id_ = id;
    }

    void Character::setName(std::string name)
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

    void Character::setPosX(double x)
    {
        posX_ = x;
    }

    void Character::setPosY(double y)
    {
        posY_ = y;
    }

    void Character::setHealth(unsigned int health)
    {
        health_ = health;
    }

    void Character::setStamina(unsigned int stamina)
    {
        stamina_ = stamina;
    }

    void Character::setInventory(std::vector<std::string>& inventory)
    {
        inventory_.clear();
        for (unsigned int i = 0; i < inventory.size(); ++i)
        {
            inventory_.push_back(inventory[i]);
        }
    }

    // Compares the stamina of the two objects
    bool Character::operator==(const Character& ch) const
    {
        return (getStamina() == ch.getStamina());
    }

    // Compares the stamina of the two objects
    bool Character::operator!=(const Character& ch) const
    {
        return (getStamina() != ch.getStamina());
    }

    // Compares the stamina of the two objects
    bool Character::operator<(const Character& ch) const
    {
        return (getStamina() < ch.getStamina());
    }

    // Compares the stamina of the two objects
    bool Character::operator<=(const Character& ch) const
    {
        return (getStamina() <= ch.getStamina());
    }

    // Compares the stamina of the two objects
    bool Character::operator>(const Character& ch) const
    {
        return (getStamina() > ch.getStamina());
    }

    // Compares the stamina of the two objects
    bool Character::operator>=(const Character& ch) const
    {
        return (getStamina() >= ch.getStamina());
    }

    Character& Character::operator++()
    {
        ++this->stamina_;
        return *this;
    }

    Character Character::operator++(int rhs)
    {
        Character tmp = *this;
        this->stamina_++;
        return tmp;
    }

    std::string Character::toString()
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

    std::ostream& operator<<(std::ostream& output, Character& ch)
    {
        output << ch.toString();
        return output;
    }

    // std::string name, double& x, double& y, unsigned int health, unsigned int stamina
    std::istream& operator>>(std::istream& input, Character& ch)
    {
        Character tmp;
    
        input >> tmp.name_ >> tmp.posX_ >> tmp.posY_ >> tmp.health_ >> tmp.stamina_; // wasted about 2 hours being stuck with >> not having enough overloads because I haven't included iostream...
                                                                                     // I know... *AMAZING*... I feel retarded rn... And just generally blind...
        if (input.fail())
        {
            // May throw an exception but the program state won't change because of that, aka strong exception guarantee
            throw std::runtime_error("Reading input failed. One of the value types might be wrong... Or something else... Idk... Stop being a monke on the keyboard...");
        }
        else
        {
            ch = tmp;
        }

        return input;
    }

}

