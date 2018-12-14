#include "program.h"
#include <iostream>

Program::Program(string name) : name(name) {}

Program::Program(string name, vector<Problem *> problems) : name(name), problems(problems) {}

string Program::getName()
{
    return name;
}

vector<Problem *> Program::getProblems()
{
    return problems;
}

void Program::addProblem(Problem *problem)
{
    problems.push_back(problem);
}
