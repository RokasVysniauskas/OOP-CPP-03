#pragma once

#include <vector>
#include <string>

namespace mbs // motivation-block struggles
{
    class Character
    {
    private:
        static unsigned int lastID_;
        unsigned int id_;
        std::string name_;
        double posX_;
        double posY_;
        unsigned int health_;
        unsigned int stamina_; // having maxStamina and MaxHP would probably make sense, especially considering the use of overloaded operators
        std::vector<std::string> inventory_;

    public:
        Character();
        Character(std::string name, double& x, double& y, unsigned int health, unsigned int stamina, std::vector<std::string>& inventory);
        virtual ~Character();

        static unsigned int getLastID() { return lastID_; }
        unsigned int getID() { return id_; }

    private:
        void setID(unsigned int id);

    public:
        std::string getName() const { return name_; }
        void setName(std::string name);
        double getPosX() const { return posX_; }
        void setPosX(double x);
        double getPosY() const { return posY_; }
        void setPosY(double y);
        unsigned int getHealth() const { return health_; }
        void setHealth(unsigned int health);
        unsigned int getStamina() const { return stamina_; }
        void setStamina(unsigned int stamina);
        std::vector<std::string> getInventory() const { return inventory_; }
        void setInventory(std::vector<std::string>& inventory);

        bool operator==(const Character& ch) const;
        bool operator!=(const Character& ch) const;
        bool operator<(const Character& ch) const;
        bool operator<=(const Character& ch) const;
        bool operator>(const Character& ch) const;
        bool operator>=(const Character& ch) const;
        
        Character& operator++();
        Character operator++(int rhs);

        friend std::ostream& operator<<(std::ostream& output, Character& ch);
        friend std::istream& operator>>(std::istream& input, Character& ch);

        std::string toString();
    };
}