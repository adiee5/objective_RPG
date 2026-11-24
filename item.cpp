#include "item.h"
#include "action.h"
#include <cstdlib>
#include <iostream>

std::string Item::get_name(){
    return name;
}

unsigned long Item::get_worth(){
    return worth;
}

#pragma region Usable

Usable::Usable(std::string name, unsigned long worth, unsigned int uses) 
            : Item(name, worth){
                if(!uses) throw "uses count cannot be 0";
                uses_left=uses;
            }

bool Usable::can_be_used(){
    return uses_left>0;
}

unsigned int Usable::get_uses_left(){
    return uses_left;
}

void Usable::use(bool player_pov, Character *player, Character* enemy){
    if (!can_be_used()) return;
    if (player==nullptr) throw "`player` cannot be null! (`player` variable is about a character who uses the item)";
    auto a=use_action();
    if (player_pov && enemy==nullptr && a.get_target()==ActionTarget::ENEMY){
        std::cout<<"Ten przedmiot możesz użyć jedynie w walce\n";
        return;
    }
    uses_left--;
    
}

bool Usable::is_a_usable(){
    return true;
}

bool Usable::is_a_statboost(){
    return false;
}

#pragma endregion

#pragma region Statboost

Statboost::Statboost(std::string name, enum Stat stat, unsigned short boost, unsigned int health, unsigned long worth)
            : Item(name, worth) {
                if(stat==Stat::HEALTH)
                    throw "Statboost cannot boost the `health` stat";
                this->stat=stat;

                if (boost==0)
                    throw "boost cannot be 0";
                this->boost=boost;

                if (health==0)
                    throw "health cannot be 0";
                this->health=health;
            }

bool Statboost::is_a_usable(){
    return false;
}

bool Statboost::is_a_statboost(){
    return true;
}

enum Stat Statboost::get_stat(){
    return stat;
}

unsigned short Statboost::get_boost(){
    return boost;
}

void Statboost::print_stats(){
    std::cout<<"=====\n"
    <<get_name()<<
    "\n-----\n"
    "Ulepsza: "; stat_display(stat);
    std::cout<<"\no "<<boost<<"pkt.\n"
    "Zdrowie Przedmiotu: "<<health<<
    "\n=====\n";
}
std::string Statboost::get_type(){
    return "Statboost";
}
bool Statboost::drain(){
    return (--health)>0;
}

#pragma endregion