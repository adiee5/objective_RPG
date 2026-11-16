#include "item.h"
#include <cstdlib>
#include <iostream>

std::string Item::get_name(){
    return name;
}

unsigned long Item::get_worth(){
    return worth;
}

bool Usable::can_be_used(){
    return uses_left<=0;
}

bool Usable::is_a_usable(){
    return true;
}

bool Usable::is_a_statboost(){
    return false;
}

bool Statboost::is_a_usable(){
    return false;
}

bool Statboost::is_a_statboost(){
    return true;
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