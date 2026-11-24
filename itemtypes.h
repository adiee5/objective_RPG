#pragma once

#include "action.h"
#include "item.h"

class Statboost;
class Action;

class Potion : public Usable{
private:
    enum Stat stat;
    unsigned short value;
    Action use_action();
public:
    Potion(std::string name, enum Stat stat, unsigned short value, unsigned long worth=150);
    Potion(enum Stat stat, unsigned short value, unsigned long worth=150) 
        : Potion("Potka na "+stat_to_string(stat), stat, value, worth){}
    bool is_volatile() override;
    void print_stats() override;
    std::string get_type() override;

};

class Shield : public Usable
{
private:
    unsigned short health;
    Action use_action();
public:
    Shield(std::string name, unsigned short health, unsigned long worth=150);
    Shield(unsigned short health, unsigned long worth=150)
        : Shield("Tarcza", health, worth){}
    Shield()
        : Shield(15){}
    bool can_be_used() override;
    bool is_volatile() override;
    std::string get_type() override;
    void print_stats() override;
    void take_damage(Action *a);
};

class Sword : public Statboost{
    public:
        Sword(std::string name, unsigned short damage, unsigned int health=10, unsigned long worth=200)
            : Statboost(name, Stat::ATTACK, damage, health, worth) {}
        Sword(unsigned short damage, unsigned int health=10, unsigned long worth=200)
            : Sword("Miecz", damage, health, worth) {}
        Sword()
            : Sword(5) {}
        std::string get_type() override;
        void print_stats() override;
};

class Wand : public Usable{
private:
    unsigned int max_uses;
    unsigned short damage;
    Action use_action();
public:
    Wand(std::string name, unsigned int uses, unsigned short damage, unsigned long worth=500);
    Wand(unsigned int uses, unsigned short damage, unsigned long worth=500) : Wand("Różdżka", uses, damage, worth){}
    Wand() : Wand(3, 20){}
    bool is_volatile() override;
    std::string get_type() override;
    void print_stats() override;
};

class WandRefill : public Usable{
    private:
        Action use_action();
    public:
        WandRefill() : Usable("Wkład do różdżki", 100){}
        bool is_volatile() override;
        std::string get_type() override;
        void print_stats() override;
};