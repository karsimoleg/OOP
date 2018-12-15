#pragma once
#ifndef PROBLEM_H
#define PROBLEM_H

#endif // PROBLEM_H
#include <string>
#include <vector>

using namespace std;

class Problem
{
private:
    string name;
    string type;
    int solvingTime;

public:
    Problem (string name, string type, int solvingTime);

    string getName();

    string getType();

    int getSolvingTime();
};
