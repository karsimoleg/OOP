#include "mainwindow.h"
#include "ui_mainwindow.h"




Problem* pr1 = new Problem("Прогррама не скомпилирована","Ошибка" ,2);
Problem* pr2= new Problem("Не правильно присвоена переменная ", "Ошибка", 1);
Problem* pr3= new Problem("Файл не найден", "Ошибка", 10);
Problem* pr4= new Problem("ошибка при открытии sln", "Ошибка", 3);
Problem* pr5= new Problem("В пути найдены русские символы", "Ошибка", 1);
Problem* pr6= new Problem("Компилятор не найден", "Ошибка", 2);
Problem* pr7= new Problem("Даный путь не найден", "Ошибка", 4);
Problem* pr8= new Problem("Библиотека не подключена", "Ошибка", 2);
Problem* pr9= new Problem("Ошибка установки", "Ошибка", 5);
Problem* pr10= new Problem("Не удалось открыть проэкт", "Ошибка", 5);

Program* MSVS = new Program("Visual C#",
                            vector<Problem*>{pr4,pr10});
Program* VSC = new Program("Visual Studio Code",
                            vector<Problem*>{pr1,pr2,pr4,pr8,pr10});
Program* QtCreator = new Program("Qt Creator",
                            vector<Problem*>{pr5,pr7,pr9,pr3});
Program* Python = new Program("PyDev",
                            vector<Problem*>{pr9,pr8,pr6});
//Program* JS = new Program("JS",
 //  = new User2("Пользователь JS", map<Program*, int>{ {JS, 6}});
vector<Program*> programs{MSVS, VSC, QtCreator, Python/*,JS*/};
vector<User*> users{userC1,userPython,userC2/*,userJS*/

    int time = 100;

   for (int i = 0; i < time; i++)
    {
        for (auto user: users)
        {
            User::State state = user->getState();
            if (state == User::State::waiting)
            {
               Program* program = user->getRandomProgram();
                user->startProgramUsing(program);
            }
            if (state == User::State::programUsing)
            {
                Problem* newProblem = user->getRandomProblem();
                if (newProblem == nullptr)
                {
                    user->useProgram(user->getCurrentProgram());
                }
                else
                {
                    user->problemOccur(newProblem, i);
                }
            }
            if (state == User::State::problemSolving)
            {
                user->solveProblem(i);
            }
        }
    }

   for (auto program: programs)
    {
        ui->programsList->addItem(QString::fromUtf8(program->getName().data()));
    }

   for (auto user: users)
    {
        ui->usersList->addItem(QString::fromUtf8(user->getName().data()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_programsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (current == nullptr)
    {
        hideProgramInfo();
    }
    else
    {
        string s = current->text().toUtf8().data();
        for (auto program: programs)
        {
            if (program->getName() == s)
            {
                showProgramInfo(program);
                return;
            }
        }
    }
}

void MainWindow::showProgramInfo(Program *program)
{
    ui->programProblemsList->clear();
    ui->programName->setText(QString::fromUtf8(program->getName().data()));
    for (auto i: program->getProblems())
    {
        ui->programProblemsList->addItem(QString::fromUtf8(i->getName().data()));
    }
}

void MainWindow::hideProgramInfo()
{
    ui->programName->clear();
    ui->programProblemsList->clear();
}

void MainWindow::showUserInfo(User *user)
{
    ui->userProgramsList->clear();
    ui->userName->setText(QString::fromUtf8(user->getName().data()));
    for (auto i: user->getPrograms())
    {
        ui->userProgramsList->addItem(QString::fromUtf8(i.first->getName().data()));
    }

    ui->userLog->clear();
    vector<pair<Problem*, pair<int, int>>> log = user->getLog();
    int sum = 0;
    for (auto i: log)
    {
        if (i.second.first < ui->startTime->value()) continue;
        if (i.second.second > ui->endTime->value() || i.second.second == 0) continue;
        sum += i.second.second - i.second.first;
        string s = i.first->getName() + "\nНачало: " + to_string(i.second.first) + "\nКонец: " + to_string(i.second.second);
        ui->userLog->addItem(QString::fromUtf8(s.data()));
    }
    ui->sumTime->setText(QString::fromUtf8(to_string(sum).data()));
}

void MainWindow::hideUserInfo()
{
    ui->userName->clear();
    ui->userProgramsList->clear();
}

User *MainWindow::getCurrentUser()
{
    string s = ui->usersList->currentItem()->text().toUtf8().data();
    for (auto user: users)
    {
        if (user->getName() == s)
        {
            return user;
        }
    }
}

void MainWindow::on_usersList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (current == nullptr)
    {
        hideUserInfo();
    }
    else
    {
       showUserInfo(getCurrentUser());
    }
}

void MainWindow::on_startTime_valueChanged(int arg1)
{
    showUserInfo(getCurrentUser());
}

void MainWindow::on_endTime_valueChanged(int arg1)
{
    showUserInfo(getCurrentUser());
}
