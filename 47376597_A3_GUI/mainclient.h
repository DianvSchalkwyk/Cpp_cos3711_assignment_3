#ifndef MAINCLIENT_H
#define MAINCLIENT_H

#include "mainwidget.h"
#include "helpview.h"
#include "aboutview.h"

#include <QMainWindow>

class QAction;
class QMenu;
class QToolBar;
class ContainerCaretaker;

class MainClient : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainClient(QWidget *parent = nullptr);

    ~MainClient();

    void closeEvent(QCloseEvent *event);

public slots:

    void update_statusBar_slot(QString text, int time);

private slots:

    void show_about();
    void show_help();

    void add_memento();
    void restore_memento();

private:

    void setup_actions();
    void setup_menus();
    void setup_toolbar();

    MainWidget *container_widget;
    HelpView   *new_help_view;
    AboutView  *new_about_view;

    ContainerCaretaker *caretaker;

    QAction *exit_QAction;
    QAction *backup_QAction;
    QAction *restore_QAction;
    QAction *post_xml_QAction;
    QAction *about_QAction;
    QAction *help_QAction;

    QMenu *file_QMenu;
    QMenu *backup_QMenu;
    QMenu *post_xml_QMenu;
    QMenu *help_QMenu;

    QToolBar *toolbar;

    QString backup_tooltip      = "Backup current list of unallocated containers";
    QString restore_tooltip     = "Restore backup of list of unallocated containers";
    QString post_xml_tooltip    = "Post XML list of pallets with containers";
};

#endif // MAINCLIENT_H
