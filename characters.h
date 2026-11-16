#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>
#include <vector>
#include "item.h"


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
        unsigned short count_boost_of(enum Stat stat);
    public:
        Character(/* args */);
        unsigned short get_attack();
};

class Player : Character{
    private:
        unsigned long money;
};

#endif