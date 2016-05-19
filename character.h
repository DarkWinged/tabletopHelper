#ifndef CHARACTER_H
#define CHARACTER_H

class QFile;
class QChar;
class QString;
class qint8;

class Character
{
public:
    Character();
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
    qint8 cl;
    qint8 age;

};

#endif // CHARACTER_H
