#include "problem.h"

Problem::Problem(string name, string type, int solvingTime) : name(name), type(type), solvingTime(solvingTime) {}

string Problem::getName()
{
    return name;
}

string Problem::getType()
{
    return type;
}

int Problem::getSolvingTime()
{
    return solvingTime;
}
