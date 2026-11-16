#include "stattypes.h"
#include <iostream>

void stat_display(enum Stat stat){
    switch (stat)
    {
    case Stat::MAXHEALTH:
        std::cout<<"Max zdrowie";
        break;
    case Stat::ATTACK:
        std::cout<<"Atak";
        break;
    case Stat::DEFENSE:
        std::cout<<"Obrona";
        break;
    case Stat::MAXITEMS:
        std::cout<<"Pojemność Plecaka";
        break;
    case Stat::SPEED:
        std::cout<<"Szybkość";
        break;
    default:
        throw "Wrong Stat value for stat display function";
    }
}