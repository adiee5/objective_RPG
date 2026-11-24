#include "itemtypes.h"
#include "action.h"
#include <iostream>

#pragma region Potion

Action Potion::use_action(){
    return CharAction(this, ActionTarget::PLAYER, stat, value);
}

Potion::Potion(std::string name, enum Stat stat, unsigned short value, unsigned long worth) 
    : Usable(name, worth), stat(stat){
        if(value==0) throw "Potion value cannot be 0";
        this->value=value;
}

bool Potion::is_volatile(){
    return true;
}

void Potion::print_stats(){
    std::cout<<"=====\n"
    <<get_name()<<
    "\n-----\n"
    "Polepsza "; stat_display(stat);
    std::cout<<"o "<<value<<"pkt. po zażyciu\n"
    "\n=====\n";
}

std::string Potion::get_type(){
    return "Potion";
}

#pragma endregion

#pragma region Shield

Action Shield::use_action(){
    return ShieldAction(this, ActionTarget::PLAYER);
}

Shield::Shield(std::string name, unsigned short health, unsigned long worth) : Usable(name, worth, ~0U){
    if (health==0) throw "Shield health cannot be 0";
    this->health=health;
}

bool Shield::can_be_used(){
    return Usable::can_be_used() && health >0;
}

bool Shield::is_volatile(){
    return true;
}

void Shield::print_stats(){
    std::cout<<"=====\n"
    <<get_name()<<
    "\n-----\n"
    "Na pojedynczą rundę całkowicie blokuje atak przeciwnika\n"
    "Zdrowie Tarczy: "<<health<<
    "\n=====\n";
    
}
std::string Shield::get_type(){
    return "Shield";
}

void Shield::take_damage(Action *a){
    health =(health+a->get_value()>health)?0:health+a->get_value();
}

#pragma endregion

#pragma region Sword

std::string Sword::get_type(){
    return "Sword";
}

void Sword::print_stats(){
    std::cout<<"=====\n"
    <<get_name()<<
    "\n-----\n"
    "Zwiększa Atak o "<<boost<<"pkt." /*" i zwiększa szanse na atak krytyczny"*/
    "\nZdrowie Miecza: "<<health<<
    "\n=====\n";
}

#pragma endregion

#pragma region Wand

Action Wand::use_action(){
    return CharAction(this, ActionTarget::ENEMY, Stat::HEALTH, -((short)damage));
}

Wand::Wand(std::string name, unsigned int uses, unsigned short damage, unsigned long worth) 
    : Usable(name, worth, uses){
        max_uses=uses; //already checked by the parrent class constructor.
        if (damage==0) throw "damage cannot be 0";
        this->damage=damage;
}

bool Wand::is_volatile(){
    return false;
}

std::string Wand::get_type(){
    return "Wand";
}

void Wand::print_stats(){
    std::cout<<"=====\n"
    <<get_name()<<
    "\n-----\n"
    "Użyj, by zadać mocny atak przeciwnikowi.\n"
    "Obrażenia: "<<damage<<"\n"
    "Amunicja: "<<get_uses_left()<<'/'<<max_uses<<
    "\n=====\n";
}
#pragma endregion

#pragma region WandRefill

Action WandRefill::use_action(){
    // TODO
}

bool WandRefill::is_volatile(){
    return true;
}

std::string WandRefill::get_type(){
    return "WandRefill";
}

void WandRefill::print_stats(){
    std::cout<<"=====\n"
    <<get_name()<<
    "\n-----\n"
    "Doładuj tym różdżkę"
    "\n=====\n";
}
#pragma endregion