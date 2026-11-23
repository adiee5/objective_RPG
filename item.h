#pragma once

#include "stattypes.h"
#include <string>

class Item{
    private:
        std::string name;
        unsigned long worth;
    protected:
        Item(std::string name, unsigned long worth) : name(name), worth(worth){}
    public:
        std::string get_name();
        std::string virtual get_type()=0; //classes name, I'll see if that's useful
        void virtual print_stats()=0;
        bool virtual is_a_statboost()=0;
        bool virtual is_a_usable()=0;
        unsigned long get_worth();
};

typedef void useaction_t;

class Usable : public Item{
    private:
        unsigned int uses_left;
    protected:
        useaction_t virtual use_action()=0;
        Usable(std::string name, unsigned long worth, unsigned int uses);
        Usable(std::string name, unsigned long worth) : Item(name, worth), uses_left(1){}
    public:
        bool virtual can_be_used();
        bool virtual is_volatile()=0;
        unsigned int get_uses_left();
        useaction_t use(); //void?
        bool is_a_usable() override;
        bool is_a_statboost() override;
};

// It boosts a stat when owned.
class Statboost : public Item{
    protected:
        enum Stat stat;
        unsigned short boost;
        unsigned int health;
    public:
        Statboost(std::string name, enum Stat stat, unsigned short boost,
            unsigned int health=10, unsigned long worth=100);
        bool drain();
        enum Stat get_stat();
        unsigned short get_boost();
        bool is_a_usable() override;
        bool is_a_statboost() override;
        void print_stats() override;
        std::string get_type() override;
};
