#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDoubleSpinBox>
#include <QObject>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDoubleSpinBox *spins=ui->doubleSpinBox;     // widget 선언시 포인터 선언
    connect(spins,SIGNAL(valueChanged(double)) ,this ,SLOT(value_changed(double))); // spins가 valuechage(double) signal을 this로 보내면 slot 함수를 실행하겠다.
    spins->setValue(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::value_changed(double arg)
{
    qDebug()<<arg; // 변경된값 20 출력
}

