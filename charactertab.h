#ifndef CHARACTERTAB_H
#define CHARACTERTAB_H

#include <QWidget>

class QPushButton;
class QLabel;
class QLineEdit;
class QGridLayout;

class CharacterTab : public QWidget
{
    Q_OBJECT
public:
    CharacterTab();
    ~CharacterTab();

private slots:
    void handleEditButton();
    void handleSaveButton();
    void handleResetButton();

private:
    void createLayouts();

    void setEditable();
    void setUnEditable();

    bool isEditing = false;
    bool isSaved = true;

    QLineEdit *charNameEdit;
    QString *charName;
    QLineEdit *charAlignEdit;
    QString *charAlign;
    QLineEdit *charLvlEdit;
    qint8 *charLvl;
    QLineEdit *charDietyEdit;
    QString *charDiety;
    QLineEdit *charRaceEdit;
    QString *charRace;
    QLineEdit *charSizeEdit;
    QChar *charSize;
    QLineEdit *charGenderEdit;
    QString *charGender;
    QLineEdit *charAgeEdit;
    qint8 *charAge;

    QLineEdit *charSTREdit;
    qint8 *charSTR;
    QLineEdit *charDEXEdit;
    qint8 *charDEX;
    QLineEdit *charCONEdit;
    qint8 *charCON;
    QLineEdit *charINTEdit;
    qint8 *charINT;
    QLineEdit *charWISEdit;
    qint8 *charWIS;
    QLineEdit *charCHAEdit;
    qint8 *charCHA;

    QPushButton *editButton;
    QPushButton *saveButton;
    QPushButton *resetButton;

    QGridLayout *mainLayout;
};

#endif // CHARACTERTAB_H
