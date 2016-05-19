#include "skills.h"

Skills::Skills()
{
    //39
    this->skills[0] = new Skill("Acrobatics", "DEX", false, 0);
    this->skills[1] = new Skill("Appraise", "INT", false, 0);
    this->skills[2] = new Skill("Bluff", "CHA", false, 0);
    this->skills[3] = new Skill("Climb", "STR", false, 0);
    this->skills[4] = new Skill("Craft1", "INT", false, 0);
    this->skills[5] = new Skill("Craft2", "INT", false, 0);
    this->skills[6] = new Skill("Diplomacy", "CHA", false, 0);
    this->skills[7] = new Skill("Disable Device", "DEX", false, 0);
    this->skills[8] = new Skill("Disguise", "CHA", false, 0);
    this->skills[9] = new Skill("Escape Artist", "DEX", false, 0);
    this->skills[10] = new Skill("Fly", "DEX", false, 0);
    this->skills[11] = new Skill("Handle Animal", "CHA", false, 0);
    this->skills[12] = new Skill("Heal", "INT", false, 0);
    this->skills[13] = new Skill("Intimidate", "CHA", false, 0);
    this->skills[14] = new Skill("Kn. Arcana", "INT", false, 0);
    this->skills[15] = new Skill("Kn. Dungeoneering", "INT", false, 0);
    this->skills[16] = new Skill("Kn. Engineering", "INT", false, 0);
    this->skills[17] = new Skill("Kn. Geography", "INT", false, 0);
    this->skills[18] = new Skill("Kn. History", "INT", false, 0);
    this->skills[19] = new Skill("Kn. Local", "INT", false, 0);
    this->skills[20] = new Skill("Kn. Nature", "INT", false, 0);
    this->skills[21] = new Skill("Kn. Nobility", "INT", false, 0);
    this->skills[22] = new Skill("Kn. Planes", "INT", false, 0);
    this->skills[23] = new Skill("Kn. Religion", "INT", false, 0);
    this->skills[24] = new Skill("Linguistics", "INT", false, 0);
    this->skills[25] = new Skill("Perception", "WIS", false, 0);
    this->skills[26] = new Skill("Perform1", "CHA", false, 0);
    this->skills[27] = new Skill("Perform2", "CHA", false, 0);
    this->skills[28] = new Skill("Profession1", "WIS", false, 0);
    this->skills[29] = new Skill("Profession2", "WIS", false, 0);
    this->skills[30] = new Skill("Ride", "DEX", false, 0);
    this->skills[31] = new Skill("Sense Motive", "WIS", false, 0);
    this->skills[32] = new Skill("Sleight of Hand", "DEX", false, 0);
    this->skills[33] = new Skill("Spellcraft", "INT", false, 0);
    this->skills[34] = new Skill("Stealth", "DEX", false, 0);
    this->skills[35] = new Skill("Survival", "WIS", false, 0);
    this->skills[36] = new Skill("Swim", "STR", false, 0);
    this->skills[37] = new Skill("Use Magic Device", "CHA", false, 0);

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

void Skills::setSkillModName(QString name, QString mod)
{
    this->getSkill(name)->mod = mod;
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
