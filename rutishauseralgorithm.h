#ifndef RUTISHAUSERALGORITHM_H
#define RUTISHAUSERALGORITHM_H

#include "algorithm.h"
#include <QVector>

class RutishauserAlgorithm : public Algorithm
{
public:
    RutishauserAlgorithm();

    bool check() override;
    double calculate() override;

private:
    int calcLevel(QString value, int current);
    int getMaxLevel();
    bool inBraces(QStringList& items, int first, int second);
    void getLevelExpression(int level, int &indexFirst, int &indexSecond, int &indexAction);
    void buildLevels();
    void removeExpression(QStringList &items, int first, int second);

private:
    QVector<int> levels;
};

#endif // RUTISHAUSERALGORITHM_H
