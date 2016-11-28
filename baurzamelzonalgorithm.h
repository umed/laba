#ifndef BAURZAMELZONALGORITHM_H
#define BAURZAMELZONALGORITHM_H

#include "algorithm.h"
#include <QStack>

class BaurZamelzonAlgorithm : public Algorithm
{
public:
    BaurZamelzonAlgorithm();

    double calculate() override;

private:
    // обрабатываем один элемент (кладёт его в нужный стек)
    void processing(QString item);
    // выполняет верхную операцию со стека
    void executeLastOperation();
    // выполняет верхнюю операцию со стека для определённого
    //  элемента (например, когда встречается закрывающая скобка)
    void executeLastOperation(QString item);

private:
    // стек для хранения операций (+ или скобка и т.д.)
    QStack<QString> translator;
    // для хранения чисел
    QStack<QString> interpretator;
};

#endif // BAURZAMELZONALGORITHM_H
