#include "characters.h"

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