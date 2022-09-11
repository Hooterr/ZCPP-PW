#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <game.h>
#include <stdlib.h>

struct Pos { int row = -1, col = -1; };

Pos gridPosition(QWidget * widget, QGridLayout *layout) {
  if (! widget->parentWidget()) return {};
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
    setFixedSize(1200,600);
    ui->setupUi(this);
    ui->sizerEdit->setText(QString::number(3));
    setupGame(3);
    connect(ui->startButton, SIGNAL(released()), this, SLOT(startPressed()));
    connect(ui->loadImageButton, SIGNAL(released()), this, SLOT(loadImage()));
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
    QString filePath = ui->imagePath->text();
    bool hasImage = filePath.length() > 0;

    ui->mainGrid->setHorizontalSpacing(hasImage ? 0 : 10);
    ui->mainGrid->setVerticalSpacing(hasImage ? 0 : 10);

    QPixmap pixmap(filePath);

    int layoutWidth = ui->imagePreview->width();
    int layoutHeight = ui->imagePreview->height();
    int buttonWidth = 1.0f / size * layoutWidth;
    int buttonHeight = 1.0f / size * layoutHeight;

    int offsetX = 0, offsetY = 0;

    if (hasImage) {
        pixmap = pixmap.scaled(layoutWidth, layoutHeight, Qt::KeepAspectRatioByExpanding);

        offsetX = std::abs(pixmap.width() - layoutWidth) / 2;
        offsetY = std::abs(pixmap.height() - layoutHeight) / 2;
    }

    for(auto it = game->getElementsBegin(); it != end; it++)
    {
        const auto element = *it;
        if (!element->isEmpty()){

            const int sequenceNumber = element->getSequence();
            QPushButton *button = new QPushButton();
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            if (hasImage) {
                QPalette palette;
                palette.setBrush(button->backgroundRole(),
                                 QBrush(pixmap.copy(((sequenceNumber - 1) % size) * buttonWidth + offsetX,
                                                    (sequenceNumber - 1)/ size * buttonHeight + offsetY, buttonWidth, buttonHeight)));
                button->setFlat(true);
                button->setAutoFillBackground(true);
                button->setPalette(palette);
            }
            else {
                button->setText(QString::number(sequenceNumber));
            }

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
    QPushButton *button = (QPushButton *)sender();
    Pos p = gridPosition(button, ui->mainGrid);

    const int emptyTileRow = game->getEmptyTileRow();
    const int emptyTileCol = game->getEmptyTileCol();
    if (game->move(p.row, p.col)) {
        const int idx = ui->mainGrid->indexOf(button);
        delete ui->mainGrid->takeAt(idx);
        ui->mainGrid->addWidget(button, emptyTileRow, emptyTileCol);


        if (game->getIsFinished()) {
            QMessageBox::information(this, "Congrats", "You win in " + QString::number(game->getNumberOfMoves()) + " moves.");
        }
    }
}


void MainWindow::loadImage() {
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open image file"),"/path/to/file/",tr("JPG Files (*.jpg)"));

    if (fileNames.length() <= 0 ){
        return;
    }

    ui->imagePath->setText(fileNames[0]);
    QString filePath = fileNames[0];
    QPixmap pixmap(filePath);
    pixmap = pixmap.scaled(ui->imagePreview->width(), ui->imagePreview->height(), Qt::KeepAspectRatioByExpanding);
    ui->imagePreview->setPixmap(pixmap);
}















