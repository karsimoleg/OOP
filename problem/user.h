#pragma once
#ifndef USER_H
#define USER_H

#endif

#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include "program.h"

using namespace std;

class User
{
public:
    enum State {waiting, programUsing, problemSolving};

protected:
    string name;
    map<Program*, int> programs;
    State state = waiting;
    Program* currentProgram = nullptr;
    Problem* currentProblem = nullptr;
    int time = 0;
    vector<pair<Problem*, pair<int, int>>> log;
public:

    User(string name, map<Program*, int> programs);


    virtual double getProbability(Program* program, Problem* problem) = 0;

    string getName();

    map<Program*, int> getPrograms();

    vector<pair<Problem*, pair<int, int>>> getLog();

    State getState();

    Program* getCurrentProgram();

    Problem* getCurrentProblem();

    Program* getRandomProgram();

    Problem* getRandomProblem();

    int getTime();

    void startProgramUsing(Program* program);

    void useProgram(Program* program);

    void finishProgramUsing(Program* program);

    void problemOccur(Problem* problem, int timeNow);

    void solveProblem(int timeNow);

    void problemSolved(Problem* problem, int timeNow);

};
