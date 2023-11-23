#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculate);
}

float getPercent (float point, int percent) {
    return (point / 100) * percent;
}

void MainWindow::calculate() {
    float sem1 = ui->sem1->text().toFloat();
    float sem2 = ui->sem2->text().toFloat();
    float sem3 = ui->sem3->text().toFloat();
    float sem4 = ui->sem4->text().toFloat();
    float sem5 = ui->sem5->text().toFloat();
    float sem6 = ui->sem6->text().toFloat();
    float sem7 = ui->sem7->text().toFloat();
    float sem8 = ui->sem8->text().toFloat();

    qDebug() << sem1 << sem2;

    float gradePoints = (
        getPercent(sem1, 5) +
        getPercent(sem2, 5) +
        getPercent(sem3, 10) +
        getPercent(sem4, 10) +
        getPercent(sem5, 20) +
        getPercent(sem6, 20) +
        getPercent(sem7, 20) +
        getPercent(sem8, 10)
    );

    QString resultString = QString::number(gradePoints, 'f', 2);

    ui->result->setText(resultString);
}

MainWindow::~MainWindow()
{
    delete ui;
}

