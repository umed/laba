#ifndef RUTISHAUSERALGORITHM_H
#define RUTISHAUSERALGORITHM_H

#include "algorithm.h"
#include <QVector>

class RutishauserAlgorithm : public Algorithm
{
public:
    RutishauserAlgorithm();

    double calculate() override;

private:
    // даёт уровень для выражение, относительно уровня current (текущего)
    int calcLevel(QString value, int current);
    // ищет максимальный уровень в выражении
    int getMaxLevel();
    // проверка, находится ли выражение внутри скобок
    // используется для подсчёта уровня результата выражения
    bool inBraces(QStringList& items, int first, int second);
    // выдаёт индексы выражения, которое нужно подсчитать по уровню
    void getExpressionIndexesByLevel(int level, int &indexFirst, int &indexSecond, int &indexAction);
    // выставляет уровни элементов во всём выражении
    void buildLevels();
    // удаляет элементы подсчитанного выражения
    void removeExpression(QStringList &items, int first, int second);

private:
    // хранит уровни элементов выражения
    QVector<int> levels;
};

#endif // RUTISHAUSERALGORITHM_H
