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
    void buildOutputItemSequence();
    bool isNumber(QString item);
    int operationPriority(QString item);
    void processing(QString item);

private:
    QStack<QString> stack;
    QStringList output;
};

#endif // RPNALGORITHM_H
