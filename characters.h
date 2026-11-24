class Character;

#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <string>
#include <vector>
#include "item.h"
#include "action.h"

class CharAction;
class Shield;

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
        friend void ShieldAction::affect(Character* c);
    public:
        
        Character(std::string name, unsigned short health, unsigned short attack, unsigned short defense, unsigned short speed, unsigned int maxitems=5, unsigned long money=0)
            : name(name), health(health), maxhealth(health), attack(attack), defense(defense), speed(speed), maxitems(maxitems), money(money){};
        unsigned short get_attack();
        unsigned short get_defense();
        unsigned short get_health();
        unsigned short get_maxhealth();
        unsigned short get_speed();
        unsigned int get_maxitems();
        void give_item(Item *i);
        void take_damage(unsigned short damage);
        void print_items();
        bool use_item(unsigned short item_index, Character *enemy=nullptr, bool player_pov=true);
};

// Maybe there'll still be a use for this subclass
//class Player : Character{
//    private:
        
//};

#endif