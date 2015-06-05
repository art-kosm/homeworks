#include <QVBoxLayout>
#include "mainWindow.h"
#include "ui_mainwindow.h"
#include "generalTab.h"
#include "statisticsTab.h"
#include "hashFunctionTab.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hashtable = new Hashtable();

    GeneralTab *generalTab = new GeneralTab(hashtable);
    StatisticsTab *statisticsTab = new StatisticsTab(hashtable);
    connect(generalTab, SIGNAL(valueAddedOrRemoved()), statisticsTab, SLOT(hashtableWasModified()));

    HashFunctionTab *hashFunctionTab = new HashFunctionTab(hashtable);
    connect(hashFunctionTab, SIGNAL(hashFunctionSet()), statisticsTab, SLOT(hashtableWasModified()));

    QTabWidget *tabWidget = new QTabWidget;
    tabWidget->addTab(generalTab, tr("General"));
    tabWidget->addTab(statisticsTab, tr("Statistics"));
    tabWidget->addTab(hashFunctionTab, tr("Hash function"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tabWidget);
    ui->centralWidget->setLayout(layout);

    setWindowTitle(tr("Hashtable"));
}

MainWindow::~MainWindow()
{
    delete hashtable;
    delete ui;
}
