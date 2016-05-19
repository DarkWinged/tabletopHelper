#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <QString>
#include "attribute.h"

#define ATTRCOUNT 6

class Attributes
{
public:
    Attributes();
    Attributes(QString loadFile);
    ~Attributes();

    void setAttrName(QString oldName, QString newName);
    void setAttrVal(QString name, int val);
    void setShortName(QString name, QString sName);

    Attribute ** getAttrs();
    Attribute * getAttr(QString name);

    QString saveAttrs();
    void resetAttrs();

private:
    Attribute *attrs[ATTRCOUNT];
    Attribute *oldAttrs[ATTRCOUNT];
};

#endif // ATTRIBUTES_H
