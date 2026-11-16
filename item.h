#pragma once

#include "stattypes.h"
#include <string>

class Item{
    private:
        std::string name;
        unsigned long worth;
    public:
        std::string get_name();
        const char virtual *get_type()=0; //classes name, I'll see if that's useful
        void virtual print_stats()=0;
        bool virtual is_a_statboost()=0;
        bool virtual is_a_usable()=0;
        unsigned long get_worth();
};

class Usable : public Item{
    private:
        unsigned int uses_left;
    public:
        bool can_be_used();
        bool virtual is_volatile()=0;
        void virtual use()=0; //void?
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
        bool drain();
        enum Stat get_stat();
        unsigned short get_boost();
        bool is_a_usable() override;
        bool is_a_statboost() override;
        void print_stats() override;
};
