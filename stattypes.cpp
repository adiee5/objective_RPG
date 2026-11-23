#include "stattypes.h"
#include <iostream>

void stat_display(enum Stat stat){
    std::cout<<stat_to_string(stat);
}

std::string stat_to_string(enum Stat stat){
    switch (stat)
    {
    case Stat::MAXHEALTH:
        return "Max zdrowie";
    case Stat::ATTACK:
        return "Atak";
    case Stat::DEFENSE:
        return "Obronność";
    case Stat::MAXITEMS:
        return "Pojemność Plecaka";
    case Stat::SPEED:
        return "Szybkość";
    default:
        throw "Wrong Stat value for stat->string conversion";
    }
}