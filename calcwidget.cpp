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

    connect(ui->button0, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button1, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button2, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button3, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button4, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button5, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button6, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button7, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button8, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->button9, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->cos, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->divide, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->dot, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->leftBrace, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->log, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->minus, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->muliply, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->plus, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->power, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->rightBrace, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->sin, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
    connect(ui->tan, SIGNAL(clicked(bool)), this, SLOT(buttonPressed()));
}

CalcWidget::~CalcWidget()
{
    delete ui;
}

bool CalcWidget::tryCheck()
{
    try
    {
        if(algorithm->check())
        {
            ui->result->setText("OK");
            return true;
        }
        else
        {
            ui->result->setText("Количество скобок не совпало.");
        }
    }
    catch(std::invalid_argument e)
    {
        ui->result->setText(e.what());
    }
    catch(...)
    {
        ui->result->setText("Не удалось посчитать");
    }
    return false;
}

void CalcWidget::buttonPressed()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    QString expression = ui->expression->text();
    ui->expression->setText(expression + button->text());
}

void CalcWidget::check()
{
    algorithm->setExpression(ui->expression->text());
    tryCheck();
}

void CalcWidget::calc()
{
    if(ui->expression->text().isEmpty())
    {
        ui->result->setText("Задайте выражение");
        return;
    }

    algorithm->setExpression(ui->expression->text());

    try
    {
        if(tryCheck())
        {
                double result = 0.0;
                result = algorithm->calculate();
                ui->result->setText(QString::number(result));
        }
        else
        {
            ui->result->setText("Количество скобок не совпало.");
        }
    }
    catch(std::invalid_argument e)
    {
        ui->result->setText(e.what());
    }
    catch(...)
    {
        ui->result->setText("Не удалось посчитать");
    }

}
