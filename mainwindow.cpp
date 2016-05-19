#include <QtWidgets>

#include "mainwindow.h"
#include "charactertab.h"

MainWindow::MainWindow()
{
    QTabWidget *tabWidget = new QTabWidget;

    this->title = "Tabletop Helper";
    this->minSizeWidth = 160;
    this->minSizeHeight = 160;
    this->width = 480;
    this->height = 320;

    QWidget *widget = new QWidget;
    this->setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to"
                              "invoke a context menu</i>"));
    this->infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    this->infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //tabWidget->addTab(bottomFiller,"Overview");

    CharacterTab *tab = new CharacterTab();

    tabWidget->addTab(tab, "Character");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(tabWidget);
    layout->addWidget(this->infoLabel);
    //layout->addWidget(tabWidget);
    widget->setLayout(layout);

    this->createActions();
    this->createMenus();

    QString message = tr("A context menu is available by right-clicking");
    this->statusBar()->showMessage(message);

    this->setWindowTitle(tr(this->title.c_str()));
    this->setMinimumSize(this->minSizeWidth, this->minSizeHeight);
    this->resize(this->width, this->height);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(this->cutAct);
    menu.addAction(this->copyAct);
    menu.addAction(this->pasteAct);
    menu.exec(event->globalPos());
}

void MainWindow::newFile()
{
    this->infoLabel->setText(tr("Invoked <b>File|New</b?"));
}

void MainWindow::open()
{
    //this->infoLabel->setText(tr("Invoked <b>File|Open</b?"));
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
            tr("Tabletop Helper File (*.tthc)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        //ui->textEdit->setText(in.readAll());
        file.close();
    }
}

void MainWindow::save()
{
    this->infoLabel->setText(tr("Invoked <b>File|Save</b?"));
}

void MainWindow::print()
{
    this->infoLabel->setText(tr("Invoked <b>File|Print</b?"));
}

void MainWindow::undo()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Undo</b?"));
}

void MainWindow::redo()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Redo</b?"));
}

void MainWindow::cut()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Cut</b?"));
}

void MainWindow::copy()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Copy</b?"));
}

void MainWindow::paste()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Paste</b?"));
}

void MainWindow::bold()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Format|Bold</b?"));
}

void MainWindow::italic()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Format|Italic</b?"));
}

void MainWindow::leftAlign()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Format|Left Align</b?"));
}

void MainWindow::rightAlign()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Format|Right Align</b?"));
}

void MainWindow::justify()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Format|Justify</b?"));
}

void MainWindow::center()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Format|Center</b?"));
}

void MainWindow::setLineSpacing()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Format|Set Line Spacing</b?"));
}

void MainWindow::setParagraphSpacing()
{
    this->infoLabel->setText(tr("Invoked <b>Edit|Format|Set Paragraph Spacing</b?"));
}

void MainWindow::about()
{
    this->infoLabel->setText(tr("Invoked <b>Help|About</b?"));
    QMessageBox::about(this, tr("About Menu"), tr("The <b>Menu</b> example shows how to create "
                                                  "menu-bar menus and context menus."));
}

void MainWindow::aboutQt()
{
    this->infoLabel->setText(tr("Invoked <b>Help|About QT</b?"));
}

void MainWindow::createActions()
{
    this->newAct = new QAction(tr("&New"), this);
    this->newAct->setShortcuts(QKeySequence::New);
    this->newAct->setStatusTip(tr("Create a new file"));
    this->connect(this->newAct, &QAction::triggered, this, &MainWindow::newFile);

    this->openAct = new QAction(tr("&Open..."), this);
    this->openAct->setShortcuts(QKeySequence::Open);
    this->openAct->setStatusTip(tr("Open an existing file"));
    this->connect(openAct, &QAction::triggered, this, &MainWindow::open);

    this->saveAct = new QAction(tr("&Save"), this);
    this->saveAct->setShortcuts(QKeySequence::Save);
    this->saveAct->setStatusTip(tr("Save the document to disk"));
    this->connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    this->printAct = new QAction(tr("&Print..."), this);
    this->printAct->setShortcuts(QKeySequence::Print);
    this->printAct->setStatusTip(tr("Print the document"));
    this->connect(printAct, &QAction::triggered, this, &MainWindow::print);

    this->exitAct = new QAction(tr("E&xit"), this);
    this->exitAct->setShortcuts(QKeySequence::Quit);
    this->exitAct->setStatusTip(tr("Exit the application"));
    this->connect(exitAct, &QAction::triggered, this, &QWidget::close);

    this->undoAct = new QAction(tr("&Undo"), this);
    this->undoAct->setShortcuts(QKeySequence::Undo);
    this->undoAct->setStatusTip(tr("Undo the last operation"));
    this->connect(undoAct, &QAction::triggered, this, &MainWindow::undo);

    this->redoAct = new QAction(tr("&Redo"), this);
    this->redoAct->setShortcuts(QKeySequence::Redo);
    this->redoAct->setStatusTip(tr("Redo the last operation"));
    this->connect(redoAct, &QAction::triggered, this, &MainWindow::redo);

    this->cutAct = new QAction(tr("Cu&t"), this);
    this->cutAct->setShortcuts(QKeySequence::Cut);
    this->cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                                  "clipboard"));
    this->connect(cutAct, &QAction::triggered, this, &MainWindow::cut);

    this->copyAct = new QAction(tr("&Copy"), this);
    this->copyAct->setShortcuts(QKeySequence::Copy);
    this->copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                                   "clipboard"));
    this->connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

    this->pasteAct = new QAction(tr("&Paste"), this);
    this->pasteAct->setShortcuts(QKeySequence::Paste);
    this->pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                                    "selection"));
    this->connect(pasteAct, &QAction::triggered, this, &MainWindow::paste);

    this->boldAct = new QAction(tr("&Bold"), this);
    this->boldAct->setCheckable(true);
    this->boldAct->setShortcut(QKeySequence::Bold);
    this->boldAct->setStatusTip(tr("Make the text bold"));
    this->connect(boldAct, &QAction::triggered, this, &MainWindow::bold);

    QFont boldFont = boldAct->font();
    boldFont.setBold(true);
    boldAct->setFont(boldFont);

    this->italicAct = new QAction(tr("&Italic"), this);
    this->italicAct->setCheckable(true);
    this->italicAct->setShortcut(QKeySequence::Italic);
    this->italicAct->setStatusTip(tr("Make the text italic"));
    this->connect(italicAct, &QAction::triggered, this, &MainWindow::italic);

    QFont italicFont = italicAct->font();
    italicFont.setItalic(true);
    italicAct->setFont(italicFont);

    this->setLineSpacingAct = new QAction(tr("Set &Line Spacing..."), this);
    this->setLineSpacingAct->setStatusTip(tr("Change the gap between the lines of a "
                                             "paragraph"));
    this->connect(setLineSpacingAct, &QAction::triggered, this, &MainWindow::setLineSpacing);

    this->setParagraphSpacingAct = new QAction(tr("Set &Paragraph Spacing..."), this);
    this->setParagraphSpacingAct->setStatusTip(tr("Change the gap between paragraphs"));
    this->connect(setParagraphSpacingAct, &QAction::triggered,
                  this, &MainWindow::setParagraphSpacing);

    this->aboutAct = new QAction(tr("&About"), this);
    this->aboutAct->setStatusTip(tr("Show the application's About box"));
    this->connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    this->aboutQtAct = new QAction(tr("About &Qt"), this);
    this->aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    this->connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    this->connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);

    this->leftAlignAct = new QAction(tr("&Left Align"), this);
    this->leftAlignAct->setCheckable(true);
    this->leftAlignAct->setShortcut(tr("Ctrl+L"));
    this->leftAlignAct->setStatusTip(tr("Left align the selected text"));
    this->connect(leftAlignAct, &QAction::triggered, this, &MainWindow::leftAlign);

    this->rightAlignAct = new QAction(tr("&Right Align"), this);
    this->rightAlignAct->setCheckable(true);
    this->rightAlignAct->setShortcut(tr("Ctrl+R"));
    this->rightAlignAct->setStatusTip(tr("Right align the selected text"));
    this->connect(rightAlignAct, &QAction::triggered, this, &MainWindow::rightAlign);

    this->justifyAct = new QAction(tr("&Justify"), this);
    this->justifyAct->setCheckable(true);
    this->justifyAct->setShortcut(tr("Ctrl+J"));
    this->justifyAct->setStatusTip(tr("Justify the selected text"));
    this->connect(justifyAct, &QAction::triggered, this, &MainWindow::justify);

    this->centerAct = new QAction(tr("&Center"), this);
    this->centerAct->setCheckable(true);
    this->centerAct->setShortcut(tr("Ctrl+E"));
    this->centerAct->setStatusTip(tr("Center the selected text"));
    this->connect(centerAct, &QAction::triggered, this, &MainWindow::center);

    this->alignmentGroup = new QActionGroup(this);
    this->alignmentGroup->addAction(leftAlignAct);
    this->alignmentGroup->addAction(rightAlignAct);
    this->alignmentGroup->addAction(justifyAct);
    this->alignmentGroup->addAction(centerAct);
    this->leftAlignAct->setChecked(true);
}

void MainWindow::createMenus()
{
    this->fileMenu = this->menuBar()->addMenu(tr("&File"));
    this->fileMenu->addAction(this->newAct);
    this->fileMenu->addAction(this->openAct);
    this->fileMenu->addAction(this->saveAct);
    this->fileMenu->addAction(this->printAct);
    this->fileMenu->addSeparator();
    this->fileMenu->addAction(this->exitAct);

    this->editMenu = this->menuBar()->addMenu(tr("&Edit"));
    this->editMenu->addAction(this->undoAct);
    this->editMenu->addAction(this->redoAct);
    this->editMenu->addSeparator();
    this->editMenu->addAction(this->cutAct);
    this->editMenu->addAction(this->copyAct);
    this->editMenu->addAction(this->pasteAct);
    this->editMenu->addSeparator();

    this->helpMenu = this->menuBar()->addMenu(tr("&Help"));
    this->helpMenu->addAction(this->aboutAct);
    this->helpMenu->addAction(this->aboutQtAct);

    this->formatMenu = this->editMenu->addMenu(tr("&Format"));
    this->formatMenu->addAction(this->boldAct);
    this->formatMenu->addAction(this->italicAct);
    this->formatMenu->addSeparator()->setText(tr("Alignment"));
    this->formatMenu->addAction(this->leftAlignAct);
    this->formatMenu->addAction(this->rightAlignAct);
    this->formatMenu->addAction(this->justifyAct);
    this->formatMenu->addAction(this->centerAct);
    this->formatMenu->addSeparator();
    this->formatMenu->addAction(this->setLineSpacingAct);
    this->formatMenu->addAction(this->setParagraphSpacingAct);
}

MainWindow::~MainWindow()
{
    this->destroy();
}
