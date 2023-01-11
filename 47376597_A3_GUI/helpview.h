#ifndef HELPVIEW_H
#define HELPVIEW_H

#include <QWidget>

class QPushButton;
class QTextBrowser;

class HelpView : public QWidget
{
    Q_OBJECT

public:

    explicit HelpView(QWidget *parent = nullptr);

private:

    void setup_help_window();

    QPushButton *close_QPushButton;

    QTextBrowser *display_help_info_QTextBrowser;

};

#endif // HELPVIEW_H
