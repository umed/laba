#include "rutishauseralgorithm.h"

RutishauserAlgorithm::RutishauserAlgorithm()
{
}

int RutishauserAlgorithm::calcLevel(QString value, int current)
{
    bool result = false;
    value.toDouble(&result);

    if(result || value == "(")
        return current + 1;

    return current - 1;
}

void RutishauserAlgorithm::getLevelExpression(int level, int& indexFirst, int& indexSecond, int& indexAction)
{
    for(int i = 0; i < levels.size(); i++)
    {
        if(levels[i] == level)
        {
            indexFirst = i;
            indexAction = i + 1;
            indexSecond = i + 2;

            break;
        }
    }
}

int RutishauserAlgorithm::getMaxLevel()
{
    if(levels.size() == 1)
        return levels[0];

    int max = levels[0];
    for(int i=1;i<levels.size();i++)
    {
        if(max < levels[i])
            max = levels[i];
    }
    return max;
}

void RutishauserAlgorithm::buildLevels()
{
    levels.clear();
    int current = 0;

    for(int i = 0; i < items.size(); i++)
    {
        current = calcLevel(items[i], current);

        levels.append(current);
    }
}

bool RutishauserAlgorithm::inBraces(QStringList& items, int first, int second)
{
    bool result = (items.size() >= second + 1)
            && (first - 1 >= 0)
            && items[first - 1] == "("
            && items[second + 1] == ")";

    return result;
}

void RutishauserAlgorithm::removeExpression(QStringList& items, int first, int second)
{
    bool insideBraces = inBraces(items, first, second);
    if(insideBraces)
    {
        levels.removeAt(second + 1);   //will removed close brace
        items.removeAt(second + 1);
    }

    levels.removeAt(second);       //will removed right expression
    levels.removeAt(first);        //will removed left expression
    items.removeAt(second);
    items.removeAt(first);

    if(insideBraces)
    {
        levels.removeAt(first - 1);    //will removed open brace
        items.removeAt(first - 1);
    }
}

double RutishauserAlgorithm::calculate()
{
    buildLevels();

    QStringList items = this->items;

    while(levels.size() != 1)
    {
        int first, second, action;
        int maxLevel = getMaxLevel();

        getLevelExpression(maxLevel, first, second, action);

        double value = executeAction(items[first], items[second], items[action]);

        items[action] = QString::number(value);

        if(!inBraces(items, first, second))
            levels[action]++;

        removeExpression(items, first, second);
    }

    return items[0].toDouble();
}
