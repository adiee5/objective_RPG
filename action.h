#include "stattypes.h"
#include "characters.h"

enum ActionTarget{
    PLAYER,
    ENEMY,
    ITEM
};

class Action{
    protected:
        Item *item;
        enum ActionTarget target;
        short value;
        Action(Item *item, enum ActionTarget target, unsigned short value) : item(item), target(target), value(value){}
    public:
        enum ActionTarget get_target();
};

class CharAction : public Action{
    private:
        Stat stat;
    public:
        CharAction(Item *item, enum ActionTarget target, enum Stat stat, short value) 
            : Action(item, target, value), stat(stat){}
        void virtual affect(Character* c);
};

class ShieldAction : public CharAction{
    public:
        ShieldAction(Item *item, enum ActionTarget target) 
            : CharAction(item, target, 0, 0){}
        void virtual affect(Character* c);

}