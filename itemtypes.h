#include "item.h"

class Potion : public Usable
{
private:
    enum Stat stat;
    unsigned short value;
    useaction_t use_action();
public:
    bool is_volatile() override;
    void print_stats() override;
    const char *get_type() override;

};

class Shield
{
private:
    unsigned short health;
    
public:

};

Shield::Shield()
{
}

Shield::~Shield()
{
}
