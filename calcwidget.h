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
    void check();
    void calc();
    bool tryCheck();

    void buttonPressed();

private:
    Ui::CalcWidget *ui;
    std::shared_ptr<Algorithm> algorithm;
};

#endif // CALCWIDGET_H
