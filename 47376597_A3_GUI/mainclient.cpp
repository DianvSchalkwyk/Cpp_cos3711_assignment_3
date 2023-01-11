#include "mainclient.h"
#include "containercaretaker.h"

#include <QThread>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QLayout>
#include <QStatusBar>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTabWidget>

MainClient::MainClient(QWidget *parent)
           :QMainWindow(parent),
            container_widget(new MainWidget),
            caretaker(new ContainerCaretaker)
{
    setWindowTitle("Container");
    setWindowIcon(QIcon(":/COS3711_A3/Resources/Images/box_icon.ico"));

    setCentralWidget(container_widget);

    setMaximumSize(500,530);
    setMinimumSize(500,530);

    setup_actions();
    setup_menus();
    setup_toolbar();

    connect(about_QAction,    &QAction::triggered, this,             &MainClient::show_about);
    connect(help_QAction,     &QAction::triggered, this,             &MainClient::show_help);
    connect(backup_QAction,   &QAction::triggered, this,             &MainClient::add_memento);
    connect(restore_QAction,  &QAction::triggered, this,             &MainClient::restore_memento);
    connect(post_xml_QAction, &QAction::triggered, container_widget, &MainWidget::xml_thread_slot);
    connect(exit_QAction,     &QAction::triggered, this,             &QWidget   ::close);

    connect(container_widget, &MainWidget::update_statusBar_signal, this, &MainClient::update_statusBar_slot);
    connect(container_widget, &MainWidget::add_memento_signal,      this, &MainClient::add_memento);

    statusBar()->showMessage("Ready", 3000);
}

MainClient::~MainClient(){}

void MainClient::show_about()
{
    statusBar()->showMessage("About", 3000);

    new_about_view = new AboutView;
}

void MainClient::show_help()
{
    statusBar()->showMessage("Help", 3000);

    new_help_view = new HelpView;
    new_help_view->show();
}

void MainClient::add_memento()
{
    caretaker->request_memento(container_widget->create_memento());

    statusBar()->showMessage("New memento created", 3000);

    restore_QAction->setEnabled(true);
}

void MainClient::restore_memento()
{
    container_widget->set_memento(caretaker->restore_memento());
}

void MainClient::setup_actions()
{
    exit_QAction    = new QAction(QIcon(":/COS3711_A3/Resources/Images/exit.png"   ), "Exit"    );
    backup_QAction  = new QAction(QIcon(":/COS3711_A3/Resources/Images/backup.png" ), "Backup"  );
    restore_QAction = new QAction(QIcon(":/COS3711_A3/Resources/Images/restore.png"), "Restore" );
    post_xml_QAction= new QAction(QIcon(":/COS3711_A3/Resources/Images/xml.png"    ), "Post XML");
    help_QAction    = new QAction(QIcon(":/COS3711_A3/Resources/Images/help.png"   ), "Help"    );
    about_QAction   = new QAction(QIcon(":/COS3711_A3/Resources/Images/info.png"   ), "About"   );
}

void MainClient::setup_menus()
{
    file_QMenu = menuBar()->addMenu("File");
    file_QMenu->addSeparator();
    file_QMenu->addAction(exit_QAction);

    backup_QMenu = menuBar()->addMenu("Backup");
    backup_QMenu->addSeparator();
    backup_QMenu->addAction(backup_QAction);
    backup_QMenu->addAction(restore_QAction);

    post_xml_QMenu = menuBar()->addMenu("Post XML");
    post_xml_QMenu->addSeparator();
    post_xml_QMenu->addAction(post_xml_QAction);

    help_QMenu = menuBar()->addMenu("Help");
    help_QMenu->addAction(about_QAction);
    help_QMenu->addAction(help_QAction);
}

void MainClient::setup_toolbar()
{
    toolbar = addToolBar("Main toolbar");
    toolbar->layout()->setSpacing(20);
    toolbar->addAction(backup_QAction);
    toolbar->addAction(restore_QAction);
    toolbar->addAction(post_xml_QAction);

    backup_QAction  ->setToolTip(backup_tooltip);
    restore_QAction ->setToolTip(restore_tooltip);
    post_xml_QAction->setToolTip(post_xml_tooltip);

    restore_QAction->setEnabled(false);
}

void MainClient::closeEvent(QCloseEvent *event)
{
    statusBar()->showMessage("Close?", 3000);

    int response;

    response = QMessageBox::warning(this, "Exit", "Are you sure you want to Exit ?", QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        statusBar()->showMessage("Ready", 3000);
        event->ignore();
    }
}

void MainClient::update_statusBar_slot(QString text, int time)
{
    statusBar()->showMessage(text, time);
}
