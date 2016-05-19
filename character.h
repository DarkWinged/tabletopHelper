#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "skills.h"
#include "attributes.h"


class Character
{
public:
    Character();
    Character(QString loadFile);
    ~Character();

    QString name;
    QString align;
    QString deity;
    QString race;
    QString height;
    QString weight;
    QString hair;
    QString eyes;
    QChar size;
    QChar gender;
    int cl;
    int age;

    Skills skills;
    Attributes attrs;
};

#endif // CHARACTER_H
