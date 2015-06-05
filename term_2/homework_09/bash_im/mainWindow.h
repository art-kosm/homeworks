#include <QMainWindow>

#include <QNetworkReply>
#include <QTemporaryFile>
#include <QLabel>
#include <QPushButton>
#include <QPlainTextEdit>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    /**
     * @brief fileIsReady slot
     *
     * Is called after the page has been successfully downloaded
     * Creates a temporary file with this page text
     */

    void fileIsReady(QNetworkReply*);
    void showNextQuote();

private:
    Ui::MainWindow *ui;
    QLabel *quoteNumber;
    QPushButton *nextQuote;
    QPlainTextEdit *quote;
    int currentQuote; /// Ranges from 0 to 99

    void setInitialWidgetText(); /// Is called after all quotes have been parsed

    int *numbers;
    QString **quotes;

    void parse(QTemporaryFile&, QString**, int*);
    void decode(QString*); /// Replaces some XML symbols
};
