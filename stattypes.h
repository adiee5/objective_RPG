#pragma once

#include <string>

enum Stat{
    MAXITEMS,
    HEALTH,
    MAXHEALTH,
    ATTACK,
    DEFENSE,
    SPEED
};

void stat_display(enum Stat stat);
std::string stat_to_string(enum Stat stat);