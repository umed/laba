#include "rpnalgorithm.h"

RpnAlgorithm::RpnAlgorithm()
{

}

void RpnAlgorithm::processing(QString item)
{
    if(item == ")")
    {
        while(stack.top() != "(")
            output.append(stack.pop());
        stack.pop();
    }
    else if(isNumber(item))
    {
        output.append(item);
    }
    else if(item == "(")
    {
        stack.push(item);
    }
    else
    {
        if(stack.empty())
        {
            stack.push(item);
        }
        else if(operationPriority(item) > operationPriority(stack.top()))
        {
            stack.push(item);
        }
        else
        {
            while(operationPriority(item) >= operationPriority(stack.top()))
                output.append(stack.pop());

            stack.push(item);
        }
    }
}

void RpnAlgorithm::buildOutputItemSequence()
{
    foreach(QString item, items)
    {
        processing(item);
    }

    while(!stack.empty())
        output.append(stack.pop());
}

double RpnAlgorithm::calculate()
{
    buildOutputItemSequence();

    while(output.size() != 1)
    {
        QString first, second, action;

        if(!isNumber(output[0]))
            throw std::invalid_argument("Неверное выражение");

        first = output[0];
        if(isNumber(output[1]))
        {
            second = output[1];
            action = output[2];

            output.removeAt(2);
            output.removeAt(1);
        }
        else
        {
            action = output[1];
            output.removeAt(1);
        }

        output[0] = QString::number(executeAction(first, second, action));
    }

    return output.last().toDouble();
}

bool RpnAlgorithm::isNumber(QString item)
{
    return !dictionary.contains(item);
}

int RpnAlgorithm::operationPriority(QString item)
{
    if(item == "(")
        return 0;
    else if(item == ")")
        return 1;
    else if(item == "+" || item == "-")
        return 2;
    else if(item == "*" || item == "/")
        return 3;
    else if("^")
        return 4;

    throw std::invalid_argument("Операция не существует");
}

