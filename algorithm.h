#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QVector>
#include <QString>
#include <QtMath>

class Algorithm
{
protected:
    struct Entry
    {
        QString value;
        int startIndex;
    };

public:
    Algorithm();

    virtual void setExpression(const QString& expression)
    {
        this->expression = expression;
        check();
    }

    virtual bool check();
    virtual double calculate() = 0;

    virtual ~Algorithm();

protected:
    double executeAction(QString first, QString second, QString action);

    QVector<Entry> getEntries();

    QStringList split();

protected:
    QString expression;
    QStringList dictionary;
    QStringList items;
};

#endif // ALGORITHM_H
