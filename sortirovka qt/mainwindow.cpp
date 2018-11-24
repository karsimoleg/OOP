#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QUndoCommand>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 200;i++)
        arr[i] = 0;
    QIntValidator *pass = new QIntValidator(1,1000);
    ui->_elemCount->setValidator(pass);

    //вимикаємо кнопки
    ui->_bubbleSortBtn->setEnabled(false);
    ui->_clrBtn->setEnabled(false);
    ui->_insertSortBtn->setEnabled(false);
    ui->_mergeSortBtn->setEnabled(false);
    ui->_rndBtn->setEnabled(false);
    ui->_goButt->setEnabled(false);
    ui->_undo_btn->setEnabled(false);
    ui->_redo_btn->setEnabled(false);
    ui->_sortNoSteps_btn->setEnabled(false);

    //підрахунок короків
    stepCounter_insertSort=0;
    stepCounter_mergeSort=0;
    stepCounter_bubbleSort=0;

    colomnAmount=1;//количество рядків
}

MainWindow::~MainWindow()
{
    delete ui;
}

//функция зміни в рядку воду кількості елементів
void MainWindow::on__elemCount_textChanged()
{
    if (firstElemCountEnter)
    {
        firstElemCountEnter = false;
    }
    ui->_goButt->setEnabled(true);
}


void MainWindow::on__arrWindow_cellChanged(int row, int column)
{
    arr[column] = ui->_arrWindow->item(row,column)->text().toDouble();
    ui->_bubbleSortBtn->setEnabled(true);
    ui->_clrBtn->setEnabled(true);
    ui->_insertSortBtn->setEnabled(true);
    ui->_mergeSortBtn->setEnabled(true);
}

//зібрати
void MainWindow::on__goButt_clicked()
{
    ui->_goButt->setEnabled(false);
    ui->_goButt->setText("Перезібрати таблицю");
    if (ui->_elemCount->text().toInt() != 0)
    {
        Elements = ui->_elemCount->text().toInt();
//        if (ui->_elemCount->text().toInt() < Elements)
//            Array.Clear(arr, 0, arr.1000)
    }
    else
    {
        QMessageBox::critical(this,"помилка","");
        Elements = 5;
    }
    ui->_arrWindow->setColumnCount(Elements);
    ui->_arrWindow->setRowCount(colomnAmount);
    for (int i = 0; i < Elements; i++)
        ui->_arrWindow->setColumnWidth(i,75);
    ui->_rndBtn->setEnabled(true);
}

//функция яка заповнює зміни
void MainWindow::Fill()
{
    for (int i = 0; i < Elements; i ++)
    {
        QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(arr[i]));
        ui->_arrWindow->setItem(0,i,itm);
    }
}

//сортування  вставкою
void MainWindow::on__insertSortBtn_clicked()
{
    typeSort=0;
    ui->_sortNoSteps_btn->setEnabled(true);
    ui->_bubbleSortBtn->setEnabled(false);
    ui->_insertSortBtn->setEnabled(false);
    ui->_mergeSortBtn->setEnabled(false);
    ui->_undo_btn->setEnabled(true);
    ui->_redo_btn->setEnabled(true);
}

void MainWindow::insertSort()
{
    int i = 1;
    double Temp;
    if(!withSteps)
        while(i < Elements)
        {
            if(i == 0 || arr[i - 1] <= arr[i])
                ++i;
            else
            {
                Temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = Temp;
                --i;
            }
        }
    else
    {
        while(exit == false)
        {
            if(stepCounter_insertSort == 0 || arr[stepCounter_insertSort - 1] <= arr[stepCounter_insertSort])
                ++stepCounter_insertSort;
            else
            {
                Temp = arr[stepCounter_insertSort];
                arr[stepCounter_insertSort] = arr[stepCounter_insertSort - 1];
                arr[stepCounter_insertSort - 1] = Temp;
                --stepCounter_insertSort;
                exit = true;
            }
            if (stepCounter_insertSort == Elements)
            {
                exit = true;
                stepCounter_insertSort=0;
                ui->_redo_btn->setEnabled(false);
            }
        }
    }
}
void MainWindow::on__mergeSortBtn_clicked()
{

    typeSort=1;
    ui->_sortNoSteps_btn->setEnabled(true);
    ui->_bubbleSortBtn->setEnabled(false);
    ui->_insertSortBtn->setEnabled(false);
    ui->_mergeSortBtn->setEnabled(false);
    ui->_undo_btn->setEnabled(false);
    ui->_redo_btn->setEnabled(false);
}

void MainWindow::MergeSort(double* arr,int first, int last)
{
    if (first<last)
    {
        MergeSort(arr, first, (first+last)/2);
        MergeSort(arr,(first+last)/2+1,last);
        Merge(arr, first, last);
    }
}

using namespace std;
void MainWindow::Merge(double* arr,int first, int last)
{
   int middle, start, final, j;
    double *mas=new double[200];
    middle=(first+last)/2;
    start=first;
    final=middle+1;

    for(j=first; j<=last; j++)
        if ((start<=middle) && ((final>last) || (arr[start]<arr[final])))
        {
            mas[j]=arr[start];
            start++;
        }
        else
        {
            mas[j]=arr[final];
            final++;
        }

    for (j=first; j<=last; j++) arr[j]=mas[j];
    delete[]mas;
}

void MainWindow::on__bubbleSortBtn_clicked()
{
    typeSort=2;
    ui->_sortNoSteps_btn->setEnabled(true);
    ui->_insertSortBtn->setEnabled(false);
    ui->_mergeSortBtn->setEnabled(false);
    ui->_bubbleSortBtn->setEnabled(false);
    ui->_undo_btn->setEnabled(true);
    ui->_redo_btn->setEnabled(true);
}

void MainWindow::BubbleSort()
{
    double temp;
    if(!withSteps)
    {
        for (int i = 0; i < Elements - 1; i++)
            for (int j = 0; j < Elements - i - 1; j++)
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
    }
    else
    {
        int i;
        while(exit == false)
        {
        for (i = 0; i < Elements - 1; i++)
            for (stepCounter_bubbleSort = 0; stepCounter_bubbleSort < Elements - i - 1; stepCounter_bubbleSort++)
                if (arr[stepCounter_bubbleSort] > arr[stepCounter_bubbleSort + 1])
                {
                    temp = arr[stepCounter_bubbleSort];
                    arr[stepCounter_bubbleSort] = arr[stepCounter_bubbleSort + 1];
                    arr[stepCounter_bubbleSort + 1] = temp;
                    i = Elements;
                }
if (i==Elements-1)
   ui->_redo_btn->setEnabled(false);
    exit = true;
}
    }
}

void MainWindow::on__clrBtn_clicked()
{
    colomnAmount=1;
    ui->_arrWindow->setRowCount(colomnAmount);
    for (int i = 0; i < Elements; i++)
        arr[i] = 0;
    ui->_rndBtn->setEnabled(true);
    ui->_arrWindow->clearContents();
    ui->_bubbleSortBtn->setEnabled(false);
    ui->_clrBtn->setEnabled(false);
    ui->_insertSortBtn->setEnabled(false);
    ui->_mergeSortBtn->setEnabled(false);
    ui->_undo_btn->setEnabled(false);
    ui->_redo_btn->setEnabled(false);
}

void MainWindow::on__rndBtn_clicked()
{
    Randomize();
    Fill();
    ui->_rndBtn->setEnabled(false);
    ui->_undo_btn->setEnabled(false);
    ui->_redo_btn->setEnabled(false);
}

void MainWindow::Randomize()
{
    for (int i = 0; i < Elements; i++)
        arr[i] = qrand();
}

void MainWindow::on__undo_btn_clicked()
{
    copyItem();
    colomnAmount++;
    ui->_undo_btn->setEnabled(false);
    switch (typeSort)
    {
    case 0:
    {
        double Temp;
        Temp = arr[stepCounter_insertSort];
        arr[stepCounter_insertSort] = arr[stepCounter_insertSort + 1];
        arr[stepCounter_insertSort + 1] = Temp;
        --stepCounter_insertSort;
        stepCounter_insertSort++;
        Fill();
        ui->_arrWindow->item(0,stepCounter_insertSort)->setBackground( Qt::green);
        break;
    }
    case 2:
    {
        double temp;
        temp = arr[stepCounter_bubbleSort];
        arr[stepCounter_bubbleSort] = arr[stepCounter_bubbleSort - 1];
        arr[stepCounter_bubbleSort - 1] = temp;
        stepCounter_bubbleSort--;
        Fill();
        if(stepCounter_bubbleSort<=Elements-1)
        ui->_arrWindow->item(0,stepCounter_bubbleSort)->setBackground( Qt::green);
        break;
    }
    }

}

void MainWindow::on__redo_btn_clicked()
{
    copyItem();
    colomnAmount++;
    ui->_undo_btn->setEnabled(true);
    withSteps = true;
    switch (typeSort)
    {
    case 0:
    {
        insertSort();
        Fill();
        ui->_arrWindow->item(0,stepCounter_insertSort)->setBackground( Qt::green);
        exit = false;
        break;
    }
    case 1:
    {
        stepCounter_mergeSort++;
        MergeSort(arr, 0, Elements-1);
        break;
    }
    case 2:
    {
        BubbleSort();
        Fill();
            ui->_arrWindow->item(0,stepCounter_bubbleSort)->setBackground( Qt::green);
         exit = false;
        break;
    }
    }
}

void MainWindow::on__sortNoSteps_btn_clicked()
{
    ui->_sortNoSteps_btn->setEnabled(false);
    withSteps = false;
    switch (typeSort)
    {
    case 0:
    {
        insertSort();
        Fill();
        break;
    }
    case 1:
    {
        MergeSort(arr, 0, Elements-1);
        Fill();
        break;
    }
    case 2:
    {
        BubbleSort();
        Fill();
        break;
    }
    }
}

void MainWindow::copyItem()
{
    ui->_arrWindow->setRowCount(colomnAmount+1);
    ui->_arrWindow->setColumnCount(Elements);
    for (int j =colomnAmount; j > 0; j--)
        for (int i = 0; i < Elements; i ++)
        {
            ui->_arrWindow->setItem(j,i, ui->_arrWindow->item(j-1, i)->clone());
        }
}

