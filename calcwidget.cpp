#include "calcwidget.h"
#include "ui_calcwidget.h"

CalcWidget::CalcWidget(std::shared_ptr<Algorithm> algorithm, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalcWidget),
    algorithm(algorithm)
{
    ui->setupUi(this);

    connect(ui->check, SIGNAL(clicked(bool)), this, SLOT(check()));
    connect(ui->calculate, SIGNAL(clicked(bool)), this, SLOT(calc()));
}

CalcWidget::~CalcWidget()
{
    delete ui;
}

void CalcWidget::check()
{
    algorithm->setExpression(ui->lineEdit->text());
    algorithm->check();
}

void CalcWidget::calc()
{
    algorithm->setExpression(ui->lineEdit->text());

    if(algorithm->check())
    {
        try
        {
            double result = 0.0;
            result = algorithm->calculate();
            ui->lineEdit_2->setText(QString::number(result));
        }
        catch(std::invalid_argument e)
        {
            ui->lineEdit_2->setText(e.what());
        }
        catch(...)
        {
            ui->lineEdit_2->setText("Не удалось посчитать");
        }
    }
    else
    {
        ui->lineEdit_2->setText("Количество скобок не совпало.");
    }

}
