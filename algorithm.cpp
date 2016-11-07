#include "algorithm.h"

Algorithm::Algorithm()
{
    dictionary.append("+");
    dictionary.append("-");
    dictionary.append("*");
    dictionary.append("/");
    dictionary.append("(");
    dictionary.append(")");
    dictionary.append("^");
    dictionary.append("cos");
    dictionary.append("sin");
    dictionary.append("tg");
    dictionary.append("ln");
}

bool Algorithm::check()
{
    split();

    int braces = 0;
    foreach(QString item, items)
    {
        if(item == "(")
            braces++;
        else if(item == ")")
            braces--;
    }
    return braces == 0;
}

Algorithm::~Algorithm(){}

double Algorithm::executeAction(QString first, QString second, QString action)
{
    if(action == "sin")
        return sin(first.toDouble());
    else if(action == "cos")
        return cos(first.toDouble());
    else if(action == "tg")
        return tan(first.toDouble());
    else if(action == "ln")
        return log(first.toDouble());
    else if(action == "+")
        return first.toDouble() + second.toDouble();
    else if(action == "-")
        return first.toDouble() - second.toDouble();
    else if(action == "*")
        return first.toDouble() * second.toDouble();
    else if(action == "/")
        return first.toDouble() / second.toDouble();
    else if(action == "^")
        return  qPow(first.toDouble(), second.toDouble());

    throw std::invalid_argument("Операция недоступна");
}

QVector<Algorithm::Entry> Algorithm::getEntries()
{
    QVector<Entry> entries;
    for(int i = 0; i < dictionary.size(); i++)
    {
        int position = expression.indexOf(dictionary[i], 0);

        while(position > -1 && position < expression.size())
        {
            Entry entry;
            entry.value = dictionary[i];
            entry.startIndex = position;

            entries.push_back(entry);

            position += dictionary[i].size();
            position = expression.indexOf(dictionary[i], position);
        }
    }

    qSort(entries.begin(), entries.end(), [](const Entry& first, const Entry& second){ return first.startIndex < second.startIndex; });

    return entries;
}

QStringList Algorithm::split()
{
    QVector<Entry> entries = getEntries();

    QStringList result;


    if(entries[0].startIndex > 0)
        result.append(expression.mid(0, entries[0].startIndex));
    result.append(entries[0].value);

    for(int i = 1; i < entries.size(); i++)
    {
        int position = entries[i - 1].startIndex + entries[i - 1].value.size();

        if(position != entries[i].startIndex)
        {
            int size = entries[i].startIndex - position;
            result.append(expression.mid(position, size));
        }

        result.append(entries[i].value);
    }

    int lastEntry = entries.size() - 1;
    int position = entries[lastEntry].startIndex + entries[lastEntry].value.size();

    if(position < expression.size())
        result.append(expression.mid(position, expression.size() - position));

    items = result;
    return result;
}
