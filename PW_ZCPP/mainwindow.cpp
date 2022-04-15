#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <game.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Game g(5);
    g.move(1,1);
    g.move(0,0);
    g.move(5,5);
    g.move(4,3);
    int count = 1;
    for (int i = 0; i < NumGridRows; i++) {

        for (int j = 0; j < NumGridRows; j++) {
            if (i == 2 && j == 2)
                continue;
            QPushButton *button = new QPushButton(QString::number(count));
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->mainGrid->addWidget(button, i + 1, j + 1);
            count++;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

