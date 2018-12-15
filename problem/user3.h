#pragma once
#ifndef USER3_H
#define USER3_H

#endif // USER3_H

#include "user.h"


class User3 : public User
{
private:
    map<Program*, int> programsUsed;
public:
    User3(string name, map<Program*, int> programs);

    double getProbability(Program* program, Problem* problem);

    void useProgram(Program* program);

    void startProgramUsing(Program* program);

    void finishProgramUsing(Program* program);
};
