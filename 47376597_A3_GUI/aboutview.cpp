#include "aboutview.h"

#include <QIcon>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

AboutView::AboutView(QWidget *parent)
          :QWidget(parent),
           close_QPushButton(new QPushButton("Close")),
           display_about_info_QTextBrowser(new QTextBrowser)
{
    setWindowIcon(QIcon(":/COS3711_A3/Resources/Images/info.png"));
    setWindowTitle("About");

    connect(close_QPushButton, &QPushButton::clicked, this, &QWidget::close);

    setup_about_window();
}

void AboutView::setup_about_window()
{
    QPixmap about_QPixmap(":/COS3711_A3/Resources/Images/COS3711-Logistics-about.png");

    QMessageBox about;

    about.setWindowTitle("About");
    about.setWindowIcon(QIcon(":/COS3711_A3/Resources/Images/info.png"));
    about.setIconPixmap(about_QPixmap);
    about.setText(about_content);
    about.setStandardButtons(QMessageBox::Close);

    about.exec();
}
