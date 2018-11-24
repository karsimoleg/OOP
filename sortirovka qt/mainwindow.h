#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

namespace Ui {
class MainWindow;
}

using std::vector;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double arr[200];
    int Elements;
    bool firstElemCountEnter = true;
    void Fill();
    void Randomize();
    bool exit = false;
    void insertSort();
    void BubbleSort();
    void MergeSort(double[200],int,int);
    void Merge(double[200],int,int);
    int typeSort;
    bool withSteps;
    int stepCounter_insertSort;
    int stepCounter_mergeSort;
    int stepCounter_bubbleSort;
    int colomnAmount;
    void copyItem();
private slots:

    void on__goButt_clicked();

    void on__clrBtn_clicked();

    void on__insertSortBtn_clicked();

    void on__bubbleSortBtn_clicked();

    void on__arrWindow_cellChanged(int row, int column);

    void on__rndBtn_clicked();

    void on__elemCount_textChanged();

    //void on__elemCount_cursorPositionChanged(int arg1, int arg2);

    void on__mergeSortBtn_clicked();

    void on__undo_btn_clicked();

    void on__redo_btn_clicked();

    void on__sortNoSteps_btn_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
