// Property of Rokas Vysniauskas, nes nuuu... taip tiesiog yra. Deal with it.

#include <iostream>
#include <vector>
#include <string>
#include "Character.h"

using namespace std;
using namespace mbs;

unsigned int Character::lastID_ = 0;

int main()
{
    try
    {
        double posX1, posY1, posX2, posY2;
        posX1 = 0;
        posY1 = 0;
        posX2 = 256;
        posY2 = -348;

        vector<string> inventory1 = { "Sword", "Shield", "Helmet", "Chestplate" };
        vector<string> inventory2 = { "Leggings", "Silver Ring", "Boots", "Cape", "Gold Ingot" };

        Character player("Player", posX1, posY1, 98, 87, inventory1);
        cout << player.toString() << endl << endl;

        Character* merchant = new Character("Merchant", posX2, posY2, 200, 200, inventory2);
        cout << merchant->toString() << endl << endl;

        Character* slave = new Character("Slave", posX2, posY2, 200, 200, inventory2);
        cout << slave->toString() << endl << endl;

        cout << "The program will now create two different vectors (consisting of 4 characters each)." << endl;
        cout << "After adding the first 2 characters, their positions (meaning location on the map) will get swapped and then the same two characters will get added additionally to the lists." << endl;
        cout << "--------------------------------------------------------" << endl << endl;

        vector<Character> listOfCharacters;
        vector<Character*> listOfCharactersPtrs;

        // Additions to the list of characters
        listOfCharacters.push_back(player);
        listOfCharacters.push_back(*merchant);

        // Swap of positions
        player.setPosX(posX2);
        player.setPosY(posY2);
        merchant->setPosX(posX1);
        merchant->setPosY(posY1);

        // Additions to the list of characters
        listOfCharacters.push_back(player);
        listOfCharacters.push_back(*merchant);

        // Reset of positions
        player.setPosX(posX1);
        player.setPosY(posY1);
        merchant->setPosX(posX2);
        merchant->setPosY(posY2);

        // Additions to the list of pointers to characters
        listOfCharactersPtrs.push_back(&player);
        listOfCharactersPtrs.push_back(merchant);

        // Swap of positions
        player.setPosX(posX2);
        player.setPosY(posY2);
        merchant->setPosX(posX1);
        merchant->setPosY(posY1);

        // Additions to the list of pointers to characters
        listOfCharactersPtrs.push_back(&player);
        listOfCharactersPtrs.push_back(merchant);

        // Testing of characters' positions' value changes
        cout << "List of characters:" << endl << endl;
        for (int i = 0; i < listOfCharacters.size(); ++i)
        {
            cout << listOfCharacters[i].toString() << endl << endl;
        }

        cout << "--------------------------------------------------------" << endl << endl;

        cout << "List of pointers to characters:" << endl << endl;
        for (int i = 0; i < listOfCharactersPtrs.size(); ++i)
        {
            cout << listOfCharactersPtrs[i]->toString() << endl << endl;
        }
        cout << endl;

        delete merchant;

        // Exception testing
        Character* dog = new Character("", posX2, posY2, 200, 200, inventory2);

        cout << "Exception test FAILED HAAAAAAAAA... Noob... XOXOXOX" << endl;
    }
    catch (const std::invalid_argument& ia)
    {
        cerr << "Invalid argument exception: " << ia.what() << endl;
    }
    catch (const std::out_of_range& oor)
    {
        cerr << "Out of range exception: " << oor.what() << endl;
    }
    catch (const std::exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    

    return 0;
}