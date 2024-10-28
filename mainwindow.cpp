#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // call appendtoinput when each button is pressed
    connect(ui->btn0, &QPushButton::clicked, this, [=]() { appendToInput("0"); });
    connect(ui->btn1, &QPushButton::clicked, this, [=]() { appendToInput("1"); });
    connect(ui->btn2, &QPushButton::clicked, this, [=]() { appendToInput("2"); });
    connect(ui->btn3, &QPushButton::clicked, this, [=]() { appendToInput("3"); });
    connect(ui->btn4, &QPushButton::clicked, this, [=]() { appendToInput("4"); });
    connect(ui->btn5, &QPushButton::clicked, this, [=]() { appendToInput("5"); });
    connect(ui->btn6, &QPushButton::clicked, this, [=]() { appendToInput("6"); });
    connect(ui->btn7, &QPushButton::clicked, this, [=]() { appendToInput("7"); });
    connect(ui->btn8, &QPushButton::clicked, this, [=]() { appendToInput("8"); });
    connect(ui->btn9, &QPushButton::clicked, this, [=]() { appendToInput("9"); });
    connect(ui->btnDec, &QPushButton::clicked, this, [=]() { appendToInput("."); });

    //operations, clear, backspace, and enter button connections
    connect(ui->btnPlus, &QPushButton::clicked, this, [=]() { onOperationButtonClicked("+"); });
    connect(ui->btnMinus, &QPushButton::clicked, this, [=]() { onOperationButtonClicked("-"); });
    connect(ui->btnMult, &QPushButton::clicked, this, [=]() { onOperationButtonClicked("*"); });
    connect(ui->btnDiv, &QPushButton::clicked, this, [=]() { onOperationButtonClicked("/"); });
    connect(ui->btnEnter, &QPushButton::clicked, this, &MainWindow::onEnterButtonClicked);
    connect(ui->btnBackSpace, &QPushButton::clicked, this, &MainWindow::onBackspaceButtonClicked);
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::onClearButtonClicked);


}


void MainWindow::appendToInput(const QString &value){ //if number button is pressed, the button should appened to any existing text in input field

    QString currentText = ui->inputLine->text();


    if (value == "." && currentText.contains(".")) { // handle invalid double decimal
        return; // do nothing if there's already a decimal point
    }

    ui->inputLine->setText(ui->inputLine->text()+value);
}

void MainWindow::onOperationButtonClicked(const QString &operation) {
    bool ok; // input validation
    currentValue = ui->inputLine->text().toFloat(&ok);

    if (!ok) {
        // handle invalid input
        ui->outputLine->setText("Invalid input");
        ui->inputLine->clear(); // clear invalid input
        return;
    }

    pendingOperation = operation; //successful store
    ui->inputLine->clear(); //ready for second input
}

void MainWindow::onEnterButtonClicked() {
    float newValue = ui->inputLine->text().toFloat(); //new input
    float result = 0;

    if (pendingOperation == "+") {
        result = currentValue + newValue;
    } else if (pendingOperation == "-") {
        result = currentValue - newValue;
    } else if (pendingOperation == "*") {
        result = currentValue * newValue;
    } else if (pendingOperation == "/") {
        if (newValue != 0) {
            result = currentValue / newValue;
        } else {
            // division by zero
            ui->outputLine->setText("Error");
            return;
        }
    }
    currentValue = result; // current value becomes result for longer calulations
    ui->outputLine->setText(QString::number(result)); // result
    ui->inputLine->setText(QString::number(result));
}

void MainWindow::onBackspaceButtonClicked(){
    QString currentText = ui->inputLine->text();
    if (!currentText.isEmpty()) {// remove last character
        currentText.chop(1);
        ui->inputLine->setText(currentText); // update input line
    }
}

void MainWindow::onClearButtonClicked(){ // should clear on ongoing opeations and input line
    ui->inputLine->clear();
    currentValue = 0;
    pendingOperation.clear();
}


MainWindow::~MainWindow()
{
    delete ui;
}
