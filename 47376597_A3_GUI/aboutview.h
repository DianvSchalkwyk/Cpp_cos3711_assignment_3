#ifndef ABOUTVIEW_H
#define ABOUTVIEW_H

#include <QWidget>

class QPushButton;
class QTextBrowser;

class AboutView : public QWidget
{
    Q_OBJECT

public:

    explicit AboutView(QWidget *parent = nullptr);

private:

    void setup_about_window();

    QPushButton *close_QPushButton;

    QTextBrowser *display_about_info_QTextBrowser;

    QString about_content = QString("%1\n%2\n%3\n%4 %5\n%6")
                               .arg("Author: Dian van Schalkwyk",
                                    "Container client - v1.00)",
                                    "Date: August 2022",
                                    "Qt version: ", qVersion(),
                                    "Student no: 47376597");
};

#endif // ABOUTVIEW_H
