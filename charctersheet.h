#ifndef CHARCTERSHEET_H
#define CHARCTERSHEET_H
class CharacterSheet
{
public:
    CharacterSheet();
    ~CharacterSheet(){ this->destroy(); }

    void read(QFile f);
    void write(QFile f);
    void write(QString f);
};

#endif // CHARCTERSHEET_H
