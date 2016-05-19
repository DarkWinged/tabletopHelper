#include "attribute.h"

Attribute::Attribute()
{
    this->name = "";
    this->sName = "";
    this->attr = 0;
}

Attribute::Attribute(QString name, QString sName, int attr)
{
    this->name = name;
    this->sName = sName;
    this->attr = attr;
}

Attribute::setAttr(int attr)
{
    this->attr = attr;
    this->mod = this->calcMod(attr);
}

Attribute::getAttr()
{
    return this->attr;
}

Attribute::getMod()
{
    return this->mod;
}

Attrivute::calcMod(int attr)
{
    return qFloor(attr / 2);
}

Attribute::~Attribute()
{

}
