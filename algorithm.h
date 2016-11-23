#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QVector>
#include <QString>
#include <QtMath>
#include <QDebug>

class Algorithm
{
protected:
    // эта структура используется для поиска отдельно взятого выражения
    // в входной строке (плюсик, число или прочее)
    struct Entry
    {
        Entry() : value(""), startIndex(0)
        {
        }

        QString value;
        int startIndex;
    };

public:
    Algorithm();

    // устанавливает строку с выражением
    virtual void setExpression(const QString& expression);

    // проверяет соответствие открытых/закрытых скобок
    virtual bool check();

    // функция подсчёта, потомки данного класса должны реализовать её
    virtual double calculate() = 0;

    virtual ~Algorithm();

protected:
    // выполняет операцию (сложение, перемножение и т.д.)
    double executeAction(QString first, QString second, QString action = QString());

    // получает все числа из входной строки
    QVector<Entry> getEntries();

    bool isNumber(QString item);

    // получает из выражения всех действия
    // и объединяет числа и действия,
    // результат записывает в items
    QStringList split();

    // проверка, является ли операция унарной
    bool isUnaryOperations(const QString& operation);

    void showItems();
protected:
    // исходная строка выражения
    QString expression;
    // список действий (плюс, минус и т.д.)
    QStringList operations;
    // унарные операции (cos, sin, tg, ln)
    QStringList unaryOperations;
    // список чисел и действий по порядку
    QStringList items;
};

#endif // ALGORITHM_H
