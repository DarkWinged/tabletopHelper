#include "skills.h"

Skills::Skills()
{
    //39
    this->skills[0] = new Skill("Acrobatics", false, 0);
    this->skills[1] = new Skill("Appraise", false, 0);
    this->skills[2] = new Skill("Bluff", false, 0);
    this->skills[3] = new Skill("Climb", false, 0);
    this->skills[4] = new Skill("Craft1", false, 0);
    this->skills[5] = new Skill("Craft2", false, 0);
    this->skills[6] = new Skill("Diplomacy", false, 0);
    this->skills[7] = new Skill("Disable Device", false, 0);
    this->skills[8] = new Skill("Disguise", false, 0);
    this->skills[9] = new Skill("Escape Artist", false, 0);
    this->skills[10] = new Skill("Fly", false, 0);
    this->skills[11] = new Skill("Handle Animal", false, 0);
    this->skills[12] = new Skill("Heal", false, 0);
    this->skills[13] = new Skill("Intimidate", false, 0);
    this->skills[14] = new Skill("Kn. Arcana", false, 0);
    this->skills[15] = new Skill("Kn. Dungeoneering", false, 0);
    this->skills[16] = new Skill("Kn. Engineering", false, 0);
    this->skills[17] = new Skill("Kn. Geography", false, 0);
    this->skills[18] = new Skill("Kn. History", false, 0);
    this->skills[19] = new Skill("Kn. Local", false, 0);
    this->skills[20] = new Skill("Kn. Nature", false, 0);
    this->skills[21] = new Skill("Kn. Nobility", false, 0);
    this->skills[22] = new Skill("Kn. Planes", false, 0);
    this->skills[23] = new Skill("Kn. Religion", false, 0);
    this->skills[24] = new Skill("Linguistics", false, 0);
    this->skills[25] = new Skill("Perception", false, 0);
    this->skills[26] = new Skill("Perform1", false, 0);
    this->skills[27] = new Skill("Perform2", false, 0);
    this->skills[28] = new Skill("Profession1", false, 0);
    this->skills[29] = new Skill("Profession2", false, 0);
    this->skills[30] = new Skill("Ride", false, 0);
    this->skills[31] = new Skill("Sense Motive", false, 0);
    this->skills[32] = new Skill("Sleight of Hand", false, 0);
    this->skills[33] = new Skill("Spellcraft", false, 0);
    this->skills[34] = new Skill("Stealth", false, 0);
    this->skills[35] = new Skill("Survival", false, 0);
    this->skills[36] = new Skill("Swim", false, 0);
    this->skills[37] = new Skill("Use Magic Device", false, 0);

    for(int z = 0; z <= SKILLCOUNT ; z++)
    {
        this->oldSkills[z] = this->skills[z];
    }
}

Skills::Skills(QString loadFile)
{

}

Skill *Skills::getSkill(QString name)
{
    for(int z = 0; z <= SKILLCOUNT; z++)
        if(this->skills[z]->name == name)
            return this->skills[z];
    return new Skill();
}

Skill **Skills::getSkills()
{
    return this->skills;
}

void Skills::setSkillRank(QString name, int rank)
{
    this->getSkill(name)->rank = rank;
}

void Skills::setSkillTrained(QString name, bool trained)
{
    this->getSkill(name)->trained = trained;
}

void Skills::resetSkills()
{
    for(int z = 0; z <= SKILLCOUNT; z++)
        this->skills[z] = this->oldSkills[z];
}

QString Skills::saveSkills()
{
    QString temp = "#SKILLS";
    for(int z = 0; z <= SKILLCOUNT; z++)
    {
        this->oldSkills[z] = this->skills[z];
        temp = temp + "\n" + this->oldSkills[z]->name + "," + this->oldSkills[z]->rank +"," +this->oldSkills[z]->trained;
    }
    return temp;
}

Skills::~Skills()
{

}
