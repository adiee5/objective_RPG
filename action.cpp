#include "action.h"

ActionTarget Action::get_target(){
    return target;
}

void CharAction::affect(Character *c){
    switch (stat)
    {
    case Stat::MAXHEALTH:
        c->maxhealth=((value<0&&value+c->maxhealth>c->maxhealth)
            ||(value>0&&value+c->maxhealth<c->maxhealth))?c->maxhealth+value:0;
    case Stat::HEALTH:
        return "Zdrowie";
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