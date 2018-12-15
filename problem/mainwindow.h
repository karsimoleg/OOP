#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "program.h"
#include "user.h"
#include "problem.h"
#include "program.h"
#include "user.h"
#include "user1.h"
#include "user2.h"
#include "user3.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_programsList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_usersList_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_startTime_valueChanged(int arg1);

    void on_endTime_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    void showProgramInfo(Program* program);
    void hideProgramInfo();
    void showUserInfo(User* user);
    void hideUserInfo();
    User* getCurrentUser();
};

#endif // MAINWINDOW_H
