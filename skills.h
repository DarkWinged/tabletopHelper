#ifndef SKILLS_H
#define SKILLS_H

#include <QString>
#include <QtGlobal>

#include "skill.h"

#define SKILLCOUNT 37

class Skills
{
public:
    Skills();
    Skills(QString loadFile);
    ~Skills();

    void setSkillName(QString oldName, QString newName);
    void setSkillRank(QString name, int rank);
    void setSkillTrained(QString name, bool trained);
    void setSkillModName(QString name, QString mod);

    Skill ** getSkills();
    Skill * getSkill(QString name);

    QString saveSkills();
    void resetSkills();

private:
    Skill *skills[SKILLCOUNT];
    Skill *oldSkills[SKILLCOUNT];
};

#endif // SKILLS_H
