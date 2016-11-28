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
    if(items.size() == 0)
        return 0.0;
    if(items.size() == 1)
        return items[0].toDouble();

    buildOutputItemSequence();

    while(!output.empty())
    {
        if(isNumber(output.front()))
        {
            stack.push(output.front());
        }
        else if(isUnaryOperations(output.first()))
        {
            double result = executeAction(stack.pop(), output.first());
            stack.push(QString::number(result));
        }
        else
        {
            double result = executeAction(stack.pop(), output.first(), stack.pop());
            stack.push(QString::number(result));
        }
        output.removeFirst();
    }

    return stack.pop().toDouble();
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

