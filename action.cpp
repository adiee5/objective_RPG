#include "action.h"
#include "itemtypes.h"
#include "characters.h"

enum ActionTarget Action::get_target(){
    return target;
}

short Action::get_value(){
    return value;
}

void CharAction::affect(Character *c){
    switch (stat)
    {
    case Stat::MAXHEALTH:
        c->maxhealth=((value<0&&value+c->maxhealth>c->maxhealth)
            ||(value>0&&value+c->maxhealth<c->maxhealth))?c->maxhealth+value:0;
        break;
    case Stat::HEALTH:
        if (value<0 && c->shield!=nullptr){
            c->shield->take_damage(this);
            if (!c->shield->can_be_used()){
                auto it = c->items.begin();
                while (it!=c->items.end()&&*it!=c->shield) it++;
                c->items.erase(it);
            }
            c->shield=nullptr;
        }else{
            c->health=((value<0&&value+c->health>c->health)
                ||(value>0&&value+c->health<c->health))?c->health+value:0;
        }
        break;
    case Stat::ATTACK:
        c->attack=((value<0&&value+c->attack>c->attack)
            ||(value>0&&value+c->attack<c->attack))?c->attack+value:0;
        break;
    case Stat::DEFENSE:
        c->defense=((value<0&&value+c->defense>c->defense)
            ||(value>0&&value+c->defense<c->defense))?c->defense+value:0;
        break;
    case Stat::MAXITEMS:
        c->maxitems=((value<0&&value+c->maxitems>c->maxitems)
            ||(value>0&&value+c->maxitems<c->maxitems))?c->maxitems+value:0;
        break;
    case Stat::SPEED:
        c->speed=((value<0&&value+c->speed>c->speed)
            ||(value>0&&value+c->speed<c->speed))?c->speed+value:0;
        break;
    default:
        throw "Wrong Stat value in the action";
    }
}

void ShieldAction::affect(Character *c){
    c->shield=(Shield*)item;
}