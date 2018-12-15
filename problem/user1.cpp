#include "user1.h"

User1::User1(string name, map<Program *, int> programs) : User(name, programs) {}

double User1::getProbability(Program *program, Problem *problem)
{
    return 0.1;
}
