#include "skill.h"

Skill::Skill(QString name, QString mod, bool trained, int rank)
{
    this->name = name;
    this->mod = mod;
    this->trained = trained;
    this->rank = rank;
}

Skill::Skill()
{
    this->name = QString("");
    this->mod = QString("");
    this->trained = false;
    this->rank = 0;
}
