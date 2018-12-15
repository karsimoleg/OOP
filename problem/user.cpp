#include "user.h"
#include <iostream>
User::User(string name, map<Program *, int> programs) : name(name), programs(programs){}

std::string User::getName()
{
    return name;
}

map<Program *, int> User::getPrograms()
{
    return programs;
}

vector<pair<Problem *, pair<int, int>>> User::getLog()
{
    return log;
}

User::State User::getState()
{
    return state;
}

Program *User::getCurrentProgram()
{
    return currentProgram;
}

Problem *User::getCurrentProblem()
{
    return currentProblem;
}

Program *User::getRandomProgram()
{
    int i = rand() % programs.size();
    int j = 0;

    for (auto program : programs)
    {
        if (i == j) {
            return program.first;
        }
        j++;
    }
}

Problem *User::getRandomProblem()
{
    vector<Problem*> problems = currentProgram->getProblems();
    vector<double> probabilities;
    for (int i = 0; i < problems.size(); i++)
    {
        double s = 0;
        if (i > 0) s = probabilities[i - 1];
        probabilities.push_back(getProbability(currentProgram, problems[i]) + s);
    }
    double rnd = (double)rand() / RAND_MAX;
    for (int i = 0; i < probabilities.size(); i++)
    {
        if (rnd < probabilities[i]) return problems[i];
    }
    return nullptr;
}

int User::getTime()
{
    return time;
}

void User::startProgramUsing(Program *program)
{
    state = programUsing;
    currentProgram = program;
}

void User::useProgram(Program *program)
{

}

void User::finishProgramUsing(Program *program)
{
    state = waiting;
}

void User::problemOccur(Problem *problem, int timeNow)
{
    state = problemSolving;
    currentProblem = problem;
    log.push_back(make_pair(problem, make_pair(timeNow, 0)));
}

void User::solveProblem(int timeNow)
{
    time++;
    if (time >= currentProblem->getSolvingTime())
    {
        problemSolved(currentProblem, timeNow);
        time = 0;
    }
}

void User::problemSolved(Problem *problem, int timeNow)
{
    state = programUsing;
    log[log.size() - 1].second.second = timeNow;
}
