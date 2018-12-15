#pragma once
#ifndef USER2_H
#define USER2_H

#endif

#include "User.h"


class User2: public User
{
public:
    User2(string name, map<Program*, int> programs);

    double getProbability(Program* program, Problem* problem);
};
