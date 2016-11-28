#ifndef CALCWIDGET_H
#define CALCWIDGET_H

#include <QWidget>
#include <memory>
#include "algorithm.h"

namespace Ui {
class CalcWidget;
}

class CalcWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalcWidget(std::shared_ptr<Algorithm> algorithm, QWidget *parent = 0);
    ~CalcWidget();

protected slots:
    // событие, обрабатывающая кнопку check
    // проверяет соответствие количества скобок
    void check();
    // событие =
    // считает
    void calc();
    // проверяет, верно ли выражение и можно ли его посчитать
    bool tryCheck();

    // нажатие любой из кнопок с выражением (1, 2, sin, ln)
    void buttonPressed();

    // кнопка удаления
    void remove();
private:
    Ui::CalcWidget *ui;
    // указатель на нужный алгоритм
    std::shared_ptr<Algorithm> algorithm;
};

#endif // CALCWIDGET_H
