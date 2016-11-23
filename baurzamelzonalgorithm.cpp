#include "baurzamelzonalgorithm.h"

BaurZamelzonAlgorithm::BaurZamelzonAlgorithm()
{
}

void BaurZamelzonAlgorithm::executeLastOperation()
{
    if(translator.empty())
        return;

    QString first = interpretator.pop();
    QString second = interpretator.pop();
    QString action = translator.pop();

    double result = executeAction(first, second, action);

    interpretator.push(QString::number(result));
}

void BaurZamelzonAlgorithm::executeLastOperation(QString item)
{
    executeLastOperation();
    processing(item);
}

void BaurZamelzonAlgorithm::processing(QString item)
{
    if(item == "(")
    {
        translator.push(item);
    }
    else if(item == ")")
    {
        if(translator.empty())
            throw std::invalid_argument("Некорректная расстановка скобок");
        else if(translator.last() == "(")
            translator.pop();
        else
            executeLastOperation(item);
    }
    else
    {
        if(translator.empty() || translator.top() == "(")
        {
            translator.push(item);
        }
        else if(item == "+" || item == "-")
        {
            if(translator.top() == "+" || translator.top() == "-")
                executeLastOperation();
            else if(translator.top() == "*" || translator.top() == "/")
                executeLastOperation(item);
            else
                throw std::invalid_argument("Некорректная расстановка скобок");
        }
        else if(translator.top() == "*" || translator.top() == "/")
        {
            if(translator.top() == "+" || translator.top() == "-")
                translator.push(item);
            else if(translator.top() == "*" || translator.top() == "/")
                executeLastOperation();
            else
                executeLastOperation(item);
        }

    }
}

double BaurZamelzonAlgorithm::calculate()
{
    foreach(QString item, items)
    {
        if(isNumber(item))
            interpretator.push(item);
        else
            processing(item);
    }
    executeLastOperation();
    return interpretator.top().toDouble();
}

