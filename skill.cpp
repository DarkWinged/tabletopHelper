#include "skill.h"

Skill::Skill(QString name, bool trained, int rank)
{
    this->name = name;
    this->trained = trained;
    this->rank = rank;
}

Skill::Skill()
{
    this->name = QString("");
    this->trained = false;
    this->rank = 0;
}
