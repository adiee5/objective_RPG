#include "characters.h"
#include "item.h"
#include "itemtypes.h"
#include <iostream>

unsigned short Character::count_boost_of(enum Stat stat){
    unsigned short s=0;
    for(auto i : items){
        auto item= (Statboost*)i;
        if(!i->is_a_statboost())continue;
        if(item->get_stat()==stat)s+=item->get_boost();
    }
    return s;
}

unsigned short Character::get_attack(){
    return attack+count_boost_of(Stat::ATTACK);
}

unsigned short Character::get_defense(){
    return defense+count_boost_of(Stat::DEFENSE);
}

unsigned short Character::get_maxhealth(){
    return maxhealth+count_boost_of(Stat::MAXHEALTH);
}

unsigned short Character::get_speed(){
    return speed+count_boost_of(Stat::SPEED);
}

unsigned int Character::get_maxitems(){
    return maxitems+count_boost_of(Stat::MAXITEMS);
}

void Character::give_item(Item *i){
    if (items.size()>=get_maxitems()) return;
    items.push_back(i);
}

unsigned short Character::get_health(){
    return health;
}

void Character::take_damage(unsigned short damage){
    if (shield!=nullptr){
        shield->take_damage(new CharAction(shield, ActionTarget::PLAYER, Stat::HEALTH, -((short)damage)));
        if (!shield->can_be_used()){
            auto it = items.begin();
            while (it!=items.end()&&*it!=shield) it++;
            items.erase(it);
            shield=nullptr;
        }
    }
    else{
        if (damage>health) health=0;
        else health-=damage;
    }
}

void Character::print_items(){
    std::cout<<"=====\n"
    <<name<<
    "\n-----\n"
    "Przedmioty:\n";
    unsigned short c=1;
    for(auto i : items){
        std::cout<<c++<<"- "<<i->get_name()<<"\n";
    }
    std::cout<<"=====\n";
}

bool Character::use_item(unsigned short item_index, Character *enemy, bool player_pov){
    if (item_index==0 || item_index>items.size()) return false;
    Item *i=items[item_index-1];
    if (i==nullptr) return false;
    if (!i->is_a_usable()) return false;
    auto u=(Usable*)i;
    u->use(player_pov, this, enemy);
    return true;
}