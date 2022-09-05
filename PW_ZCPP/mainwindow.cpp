#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <game.h>

struct Pos { int row = -1, col = -1; };

Pos gridPosition(QWidget * widget) {
  if (! widget->parentWidget()) return {};
  auto layout = qobject_cast<QGridLayout*>(widget->parentWidget()->layout());
  if (! layout) return {};
  int index = layout->indexOf(widget);
  Q_ASSERT(index >= 0);
  int _;
  Pos pos;
  layout->getItemPosition(index, &pos.row, &pos.col, &_, &_);
  return pos;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sizerEdit->setText(QString::number(3));
    setupGame(3);
    connect(ui->startButton, SIGNAL(released()), this, SLOT(startPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
}

void MainWindow::startPressed() {
    const int newSize = ui->sizerEdit->text().toInt();
    setupGame(newSize);
}

void MainWindow::setupGame(const int size) {

    if (game != nullptr) {
        delete game;
    }
    game = new Game(size);
    const auto end = game->getElementsEnd();

    int row = 0, col = 0;

    if (ui->mainGrid->layout() != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->mainGrid->layout()->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        //delete ui->mainGrid->layout();
    }

    for(auto it = game->getElementsBegin(); it != end; it++)
    {
        const auto element = *it;
        if (!element->isEmpty()){

            const int sequenceNumber = element->getSequence();
            QPushButton *button = new QPushButton(QString::number(sequenceNumber));
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->mainGrid->addWidget(button, row, col);
            connect(button, SIGNAL(released()), this, SLOT(tilePressed()));
        }
        if (++col == size) {
            col = 0;
            row++;
        }
    }
}

void MainWindow::tilePressed(){
    // QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open File"),"/path/to/file/",tr("Mp3 Files (*.png)"));
    QPushButton *button = (QPushButton *)sender();
    Pos p = gridPosition(button);

    const int emptyTileRow = game->getEmptyTileRow();
    const int emptyTileCol = game->getEmptyTileCol();
    if (game->move(p.row, p.col)) {
        const int idx = ui->mainGrid->indexOf(button);
        delete ui->mainGrid->takeAt(idx);
        ui->mainGrid->addWidget(button, emptyTileRow, emptyTileCol);

        if (game->getIsFinished()) {
            QMessageBox::information(this, "Congrats", "You win!");
        }
    }
}















