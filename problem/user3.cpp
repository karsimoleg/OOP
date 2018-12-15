#include "user3.h"

User3::User3(string name, map<Program *, int> programs) : User(name, programs) {}

double User3::getProbability(Program *program, Problem *problem)
{
    int usingTime = 0;
    map<Program*, int>::iterator p = programsUsed.find(program);
    if (p != programsUsed.end())
    {
        usingTime = p->second;
    }
    double probability = 0.2 - usingTime * 0.01;
    if (probability < 0) probability = 0;
    return probability;
}

void User3::useProgram(Program *program)
{
    map<Program*, int>::iterator p = programsUsed.find(program);
    if (p == programsUsed.end())
    {
        programsUsed.insert(make_pair(program, 1));
    }
    else
    {
        p->second++;
    }
}

void User3::startProgramUsing(Program *program)
{
    state = programUsing;
    currentProgram = program;
    useProgram(program);
}

void User3::finishProgramUsing(Program *program)
{
    state = waiting;
    useProgram(program);
}
