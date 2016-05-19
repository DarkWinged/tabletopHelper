#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QString>
#include <QtMath>

class Attribute
{
public:
    Attribute();
    Attribute(QString name, QString sName, int attr);
    ~Attribute();

    int getMod();
    int attr;
    QString name;
    QString sName;

private:
    int mod;
};

#endif // ATTRIBUTE_H
