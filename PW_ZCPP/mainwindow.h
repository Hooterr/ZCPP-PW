#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <algorithm>
#include <game.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QMenuBar;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Game* game = nullptr;
    void setupGame(const int size);

private slots:

    void tilePressed();
    void startPressed();
    void loadImage();
};
#endif // MAINWINDOW_H
