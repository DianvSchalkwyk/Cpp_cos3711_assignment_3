#include "helpview.h"

#include <QIcon>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>

HelpView::HelpView(QWidget *parent)
         :QWidget{parent},
          close_QPushButton             (new QPushButton("Close")),
          display_help_info_QTextBrowser(new QTextBrowser)
{
    setWindowIcon(QIcon(":/COS3711_A3/Resources/Images/help.png"));
    setWindowTitle("Help");

    setMaximumSize(500,530);
    setMinimumSize(500,530);

    connect(close_QPushButton, &QPushButton::clicked, this, &QWidget::close);

    setup_help_window();
}

void HelpView::setup_help_window()
{
    QFile help_html_file(":/COS3711_A3/Resources/help_html.html");

    help_html_file.open(QIODevice::ReadOnly);

    display_help_info_QTextBrowser->setHtml(help_html_file.readAll());

    QVBoxLayout *help_window_QVBoxLayout(new QVBoxLayout());

    help_window_QVBoxLayout->addWidget(display_help_info_QTextBrowser);
    help_window_QVBoxLayout->addWidget(close_QPushButton);

    this->setLayout(help_window_QVBoxLayout);

    help_html_file.close();
}
