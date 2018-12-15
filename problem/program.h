#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#endif // PROGRAM_H

#include <vector>
#include "problem.h"

class Program
{
    string name;
    vector<Problem*> problems;

public:
    Program(string name);
    Program(string name, vector<Problem*> problems);

    string getName();

    vector<Problem*> getProblems();

    void addProblem(Problem* problem);
};
