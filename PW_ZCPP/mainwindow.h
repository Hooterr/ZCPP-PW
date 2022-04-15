#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <algorithm>


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
const int NumGridRows = 5;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel *labels[NumGridRows];
    QLineEdit *lineEdits[NumGridRows];
    QGroupBox *gridGroupBox;
};
#endif // MAINWINDOW_H
