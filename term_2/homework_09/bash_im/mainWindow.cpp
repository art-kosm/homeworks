#include <QNetworkAccessManager>
#include <QtXml/QDomDocument>
#include <QGridLayout>

#include "mainWindow.h"
#include "ui_mainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(fileIsReady(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://bash.im/rss/")));

    ui->setupUi(this);
    setWindowTitle("bash.im");
    resize(600, 300);

    quoteNumber = new QLabel;
    quoteNumber->setAlignment(Qt::AlignHCenter);
    nextQuote = new QPushButton("Next quote");
    quote = new QPlainTextEdit;
    quote->setReadOnly(true);

    currentQuote = 0;

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(quoteNumber, 0, 0);
    layout->addWidget(nextQuote, 0, 1);
    layout->addWidget(quote, 1, 0, 2, 2);
    ui->centralWidget->setLayout(layout);

    connect(nextQuote, SIGNAL(clicked()), this, SLOT(showNextQuote()));
}

MainWindow::~MainWindow()
{
    delete numbers;
    delete ui;
}

void MainWindow::fileIsReady(QNetworkReply *reply)
{
    const int size = 100;
    numbers = new int[size];
    quotes = new QString*[size];

    QTemporaryFile file;

    file.open();
    file.write(reply->readAll());
    file.close();
    parse(file, quotes, numbers);

    setInitialWidgetText();
}

void MainWindow::setInitialWidgetText()
{
    quoteNumber->setText(QString::number(numbers[0]));
    quote->setPlainText(*quotes[0]);
}

void MainWindow::showNextQuote()
{
    if (currentQuote < 99)
    {
        currentQuote++;
        quoteNumber->setText(QString::number(numbers[currentQuote]));
        quote->setPlainText(*quotes[currentQuote]);
    }
}

void MainWindow::parse(QTemporaryFile &file, QString **quotes, int *numbers)
{
    int counter = 0;
    file.open();

    QDomDocument doc;
    doc.setContent(&file);
    QDomNodeList items = doc.elementsByTagName("item");
    for (int i = 0; i < items.size(); i++)
    {
        QDomNode node = items.item(i);
        QDomElement title = node.firstChildElement("title");
        QDomElement description = node.firstChildElement("description");
        numbers[counter] = title.text().split('#')[1].toInt();
        quotes[counter] = new QString(description.text());
        decode(quotes[counter]);
        counter++;
    }

    file.close();
}

void MainWindow::decode(QString *string)
{
    string->replace("<br>", "\n");
    string->replace("&#039;", "\'");
    string->replace("&quot;", "\"");
    string->replace("&lt", "<");
    string->replace("&gt;", ">");
}
