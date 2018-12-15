#include "user2.h"

User2::User2(string name, map<Program *, int> programs) : User(name, programs) {}

double User2::getProbability(Program *program, Problem *problem)
{
    for (auto i: log)
    {
        if (i.first->getType() == problem->getType())
            return 0;
    }
    return 0.1;
}
