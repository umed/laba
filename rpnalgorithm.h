#ifndef RPNALGORITHM_H
#define RPNALGORITHM_H

#include "algorithm.h"
#include <QStack>

class RpnAlgorithm : public Algorithm
{
public:
    RpnAlgorithm();

    double calculate() override;

private:
    // данный алгоритм обрабатывает скобок в... забыл название нотации (4 3 +)
    // эта штука формирует корректную строку для выполнения алгоритма
    void buildOutputItemSequence();
    // эта штука считает приоритет операций
    int operationPriority(QString item);
    // обработка (кладёт в стек или считает выражение)
    void processing(QString item);

private:
    // стек для подсчёта результата
    QStack<QString> stack;
    // переделанное отображение выражения
    QStringList output;
};

#endif // RPNALGORITHM_H
