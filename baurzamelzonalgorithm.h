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
    void processing(QString item);
    void executeLastOperation();
    void executeLastOperation(QString item);

private:
    QStack<QString> translator;
    QStack<QString> interpretator;
};

#endif // BAURZAMELZONALGORITHM_H
