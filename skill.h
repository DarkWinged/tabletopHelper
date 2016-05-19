#ifndef SKILL_H
#define SKILL_H

#include <QString>
#include <QtGlobal>

class Skill
{
public:
    Skill();
    Skill(QString name, QString mod, bool trained, int rank);
    ~Skill();

    bool trained;
    int rank;
    QString name;
    QString mod;
};

#endif // SKILL_H
