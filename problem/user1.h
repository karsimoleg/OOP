#pragma once
#ifndef USER1_H
#define USER1_H

#endif

#include "user.h"


class User1: public User
{
public:
    User1(string name, map<Program*, int> programs);

    double getProbability(Program* program, Problem* problem);
};
