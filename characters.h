#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>
#include <vector>
#include "itemtypes.h"
#include "action.h"


class Character{
    private:
        std::string name;
        std::vector<Item*> items;
        unsigned int maxitems;
        unsigned short health;
        unsigned short maxhealth;
        unsigned short attack;
        unsigned short defense;
        unsigned short speed;
        unsigned long money;
        Shield *shield=nullptr;
        unsigned short count_boost_of(enum Stat stat);
        friend void CharAction::affect(Character* c);
    public:
        
        Character(/* args */);
        unsigned short get_attack();
};

// Maybe there'll still be a use for this subclass
//class Player : Character{
//    private:
        
//};

#endif