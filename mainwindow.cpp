#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calcwidget.h"
#include <memory>
#include "rutishauseralgorithm.h"
#include "baurzamelzonalgorithm.h"
#include "rpnalgorithm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->addTab(new CalcWidget(std::make_shared<RutishauserAlgorithm>(), this), "Рутисхаузер");
    ui->tabWidget->addTab(new CalcWidget(std::make_shared<BaurZamelzonAlgorithm>(), this), "Баур-Замельзон");
    ui->tabWidget->addTab(new CalcWidget(std::make_shared<RpnAlgorithm>(), this), "Обратная польска нотация");
}

MainWindow::~MainWindow()
{
    delete ui;
}
