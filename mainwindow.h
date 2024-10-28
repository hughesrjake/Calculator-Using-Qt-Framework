#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *btn0; // all number buttons
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;

    QPushButton *btnPlus; // operation buttons
    QPushButton *btnMinus;
    QPushButton *btnMult;
    QPushButton *btnDiv;

    QPushButton *btnEnter;
    QPushButton *btnBackSpace;

    QLineEdit *inputLine; //in+out line
    QLineEdit *outputLine;

    float currentValue; // hold the current number
    QString pendingOperation; // hold the operation

    Ui::MainWindow *ui;

private slots:
    //functions (called slots in qt)
    void appendToInput(const QString &value);
    void onOperationButtonClicked(const QString &operation);
    void onEnterButtonClicked();
    void onBackspaceButtonClicked();
    void onClearButtonClicked();
};
#endif // MAINWINDOW_H
