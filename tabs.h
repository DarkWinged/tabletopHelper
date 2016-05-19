#ifndef TABS_H
#define TABS_H

#include <QDialog>

class QDialogButtonBox;
class QFileInfo;
class QTabWidget;

class GeneralTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralTab(const QFileInfo &fileInfo);
};

class PermissionsTab : public QWidget
{
    Q_OBJECT

public:
    explicit PermissionsTab(const QFileInfo &fileInfo);
};

class ApplicationsTab : public QWidget
{
    Q_OBJECT

public:
    explicit ApplicationsTab(const QFileInfo &fileInfo);
};

class Tabs : public QDialog
{
    Q_OBJECT

public:
    explicit Tabs(const QString &fileName);

private:
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};
#endif // TABS_H
