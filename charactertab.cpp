#include <QtWidgets>
#include <QPushButton>

#include "charactertab.h"
#include "skills.h"
#include "skill.h"

CharacterTab::CharacterTab()
{
    this->setStyleSheet("QLineEdit { border: none }");





    this->createLayouts();
}

void CharacterTab::handleEditButton()
{
    this->setEditable();
    this->resetButton->show();
    this->editButton->hide();
    this->saveButton->show();
    this->setStyleSheet("QLineEdit { border: 1px solid black }");
}

void CharacterTab::handleSaveButton()
{
    this->setStyleSheet("QLineEdit { border: none }");
    this->resetButton->hide();
    this->editButton->show();
    this->saveButton->hide();
    this->setUnEditable();
}

void CharacterTab::handleResetButton()
{
    this->setStyleSheet("QLineEdit { border: none }");
    this->resetButton->hide();
    this->editButton->show();
    this->saveButton->hide();
    this->setUnEditable();
}

void CharacterTab::createLayouts()
{
    this->editButton = new QPushButton("Edit", this);
    this->saveButton = new QPushButton("Save", this);
    this->saveButton->hide();
    this->resetButton = new QPushButton("Reset", this);
    this->resetButton->hide();

    connect(this->editButton, SIGNAL(clicked()), this, SLOT(handleEditButton()));
    connect(this->saveButton, SIGNAL(clicked()), this, SLOT(handleSaveButton()));
    connect(this->resetButton, SIGNAL(clicked()), this, SLOT(handleSaveButton()));

    QLabel *charNameLabel = new QLabel(tr("Chracter Name:"));
    QLabel *charAlignLabel = new QLabel(tr("Alignment:"));
    QLabel *charLvlLabel = new QLabel(tr("CL:"));
    QLabel *charDietyLabel = new QLabel(tr("Diety:"));
    QLabel *charRaceLabel = new QLabel(tr("Race:"));
    QLabel *charSizeLabel = new QLabel(tr("Size:"));
    QLabel *charGenderLabel = new QLabel(tr("Gender:"));
    QLabel *charAgeLabel = new QLabel(tr("Age:"));

    QLabel *charSTRLabel = new QLabel(tr("STR:"));
    QLabel *charDEXLabel = new QLabel(tr("DEX:"));
    QLabel *charCONLabel = new QLabel(tr("CON:"));
    QLabel *charINTLabel = new QLabel(tr("INT:"));
    QLabel *charWISLabel = new QLabel(tr("WIS:"));
    QLabel *charCHALabel = new QLabel(tr("CHA:"));

    this->charNameEdit = new QLineEdit("Gaeth Ankou");
    this->charNameEdit->setReadOnly(true);
    this->charNameEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charAlignEdit = new QLineEdit("True Neutral");
    this->charAlignEdit->setReadOnly(true);
    this->charAlignEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charLvlEdit = new QLineEdit("20");
    this->charLvlEdit->setReadOnly(true);
    this->charLvlEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charDietyEdit = new QLineEdit("None");
    this->charDietyEdit->setReadOnly(true);
    this->charDietyEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charRaceEdit = new QLineEdit("Human");
    this->charRaceEdit->setReadOnly(true);
    this->charRaceEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charSizeEdit = new QLineEdit("M");
    this->charSizeEdit->setReadOnly(true);
    this->charSizeEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charGenderEdit = new QLineEdit("Male");
    this->charGenderEdit->setReadOnly(true);
    this->charGenderEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charAgeEdit = new QLineEdit("1000");
    this->charAgeEdit->setReadOnly(true);
    this->charAgeEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charSTREdit = new QLineEdit("20");
    this->charSTREdit->setReadOnly(true);
    this->charSTREdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charDEXEdit = new QLineEdit("20");
    this->charDEXEdit->setReadOnly(true);
    this->charDEXEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charCONEdit = new QLineEdit("20");
    this->charCONEdit->setReadOnly(true);
    this->charCONEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charINTEdit = new QLineEdit("20");
    this->charINTEdit->setReadOnly(true);
    this->charINTEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charWISEdit = new QLineEdit("20");
    this->charWISEdit->setReadOnly(true);
    this->charWISEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    this->charCHAEdit = new QLineEdit("20");
    this->charCHAEdit->setReadOnly(true);
    this->charCHAEdit->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    int def = 80;
    QPalette *palette = new QPalette();
    //palette->setColor(QPalette::Base,Qt::gray);
    palette->setColor(QPalette::Text,Qt::darkGray);
    this->charNameEdit->setPalette(*palette);
    this->charNameEdit->setMaximumWidth(def);

    this->charRaceEdit->setPalette(*palette);
    this->charRaceEdit->setMaximumWidth(50);

    this->charAlignEdit->setPalette(*palette);
    this->charAlignEdit->setMaximumWidth(def);

    this->charLvlEdit->setPalette(*palette);
    this->charLvlEdit->setMaximumWidth(20);

    this->charDietyEdit->setPalette(*palette);
    this->charDietyEdit->setMaximumWidth(def);

    this->charSizeEdit->setPalette(*palette);
    this->charSizeEdit->setMaximumWidth(15);

    this->charGenderEdit->setPalette(*palette);
    this->charGenderEdit->setMaximumWidth(50);

    this->charAgeEdit->setPalette(*palette);
    this->charAgeEdit->setMaximumWidth(30);

    int width = 30;
    this->charSTREdit->setPalette(*palette);
    this->charSTREdit->setMaximumWidth(width);
    this->charDEXEdit->setPalette(*palette);
    this->charDEXEdit->setMaximumWidth(width);
    this->charCONEdit->setPalette(*palette);
    this->charCONEdit->setMaximumWidth(width);
    this->charINTEdit->setPalette(*palette);
    this->charINTEdit->setMaximumWidth(width);
    this->charWISEdit->setPalette(*palette);
    this->charWISEdit->setMaximumWidth(width);
    this->charCHAEdit->setPalette(*palette);
    this->charCHAEdit->setMaximumWidth(width);

    this->mainLayout = new QGridLayout;

//    this->mainLayout->addWidget(this->editButton,0,0);
//    this->mainLayout->addWidget(this->saveButton,0,1);
//    this->mainLayout->addWidget(this->resetButton,0,2);


    this->mainLayout->addWidget(charNameLabel,1,0);
    this->mainLayout->addWidget(this->charNameEdit,1,1);
    this->mainLayout->addWidget(charAlignLabel,2,0);
    this->mainLayout->addWidget(this->charAlignEdit,2,1);
    this->mainLayout->addWidget(charLvlLabel,1,2);
    this->mainLayout->addWidget(this->charLvlEdit,1,3);
    this->mainLayout->addWidget(charDietyLabel,1,6);
    this->mainLayout->addWidget(this->charDietyEdit,1,7);
    this->mainLayout->addWidget(charRaceLabel,1,4);
    this->mainLayout->addWidget(this->charRaceEdit,1,5);
    this->mainLayout->addWidget(charSizeLabel,2,2);
    this->mainLayout->addWidget(this->charSizeEdit,2,3);
    this->mainLayout->addWidget(charGenderLabel,2,4);
    this->mainLayout->addWidget(this->charGenderEdit,2,5);
    this->mainLayout->addWidget(charAgeLabel,2,6);
    this->mainLayout->addWidget(this->charAgeEdit,2,7);

    QFormLayout *attributeLayout = new QFormLayout;
    attributeLayout->addRow(charSTRLabel,this->charSTREdit);
    attributeLayout->addRow(charDEXLabel,this->charDEXEdit);
    attributeLayout->addRow(charCONLabel,this->charCONEdit);
    attributeLayout->addRow(charINTLabel,this->charINTEdit);
    attributeLayout->addRow(charWISLabel,this->charWISEdit);
    attributeLayout->addRow(charCHALabel,this->charCHAEdit);
    attributeLayout->setHorizontalSpacing(0);
    this->mainLayout->addLayout(attributeLayout,3,0,5,2,Qt::AlignLeft);

    //++++++++++++++++++++++++++++++++++++++ADD SKILLS++++++++++++++++++++++++++++++++++++++
    Skills *skills = new Skills();
    //QGridLayout *skillsLayout = new QGridLayout;
    QFormLayout *skillsLayout = new QFormLayout;
    Skill **aSkills = skills->getSkills();

    for(int z = 0; z <= SKILLCOUNT; z++)
    {
        Skill *skill = aSkills[z];
        QCheckBox *checkbox = new QCheckBox(skill->name + ":");
        checkbox->setPalette(*palette);
        checkbox->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

        QLineEdit *skillValue = new QLineEdit(QString::number(skill->rank), this);
        skillValue->setPalette(*palette);
        skillValue->setReadOnly(true);
        skillValue->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
        skillValue->setMaximumWidth(20);

        skillsLayout->addRow(checkbox, skillValue);
    }
    skillsLayout->setHorizontalSpacing(0);
    this->mainLayout->addLayout(skillsLayout,3,3,SKILLCOUNT,3,Qt::AlignLeft);
    //++++++++++++++++++++++++++++++++++++++ADD SKILLS++++++++++++++++++++++++++++++++++++++

    QWidget *client = new QWidget;
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    client->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    scrollArea->setWidget(client);
    client->setLayout(this->mainLayout);

    QVBoxLayout *main = new QVBoxLayout;
    QHBoxLayout *temp = new QHBoxLayout;
    this->editButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    this->saveButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    this->resetButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    temp->addWidget(this->editButton);
    temp->addWidget(this->saveButton);
    temp->addWidget(this->resetButton);
    temp->setAlignment(Qt::AlignLeft);
    main->addLayout(temp);
    //temp->addWidget(scrollArea);
    this->setLayout(main);
    this->layout()->addWidget(scrollArea);
    //this->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Fixed);
}

void CharacterTab::setEditable()
{
    foreach(QLineEdit * ed, this->findChildren<QLineEdit*>())
    {
        ed->setReadOnly(false);
    }
}

void CharacterTab::setUnEditable()
{
    foreach(QLineEdit * ed, this->findChildren<QLineEdit*>())
    {
        ed->setReadOnly(true);
    }
}

CharacterTab::~CharacterTab()
{
    this->destroy();
}
