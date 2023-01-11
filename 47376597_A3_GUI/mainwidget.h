#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "container.h"
#include "containerfactory.h"
#include "container.h"
#include "containerlist.h"
#include "containermemento.h"
#include "palletlist.h"

#include <QWidget>

class QSpinBox;
class QPushButton;
class QListWidget;
class QTextEdit;
class QTabWidget;

class MainWidget : public QWidget
{
    Q_OBJECT

public:

    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void create_tab_1();
    void create_tab_2();

    void set_input_limits();
    void clear_inputs();

    ContainerMemento *create_memento();
    void set_memento(ContainerMemento *memento);

signals:

    void update_statusBar_signal(QString text, int time);
    void add_memento_signal();

public slots:

    void xml_thread_slot();
    void send_xml_slot(QString xml_list_QString);

private slots:

    void check_box_inputs();
    void check_cyl_inputs();
    void check_unalocated_list_selected();
    void clear_container_selection();
    void create_container();
    void move_container_to_pallet();

private:

    ContainerFactory *new_job;
    Container        *new_container;
    ContainerList    *container_list;
    PalletList       *pallet_list;

    QTabWidget *tab_widget;

    QSpinBox *box_breadth_QSpinBox;
    QSpinBox *box_length_QSpinBox;
    QSpinBox *box_height_QSpinBox;
    QSpinBox *box_weight_QSpinBox;

    QSpinBox *cylinder_diameter_QSpinBox;
    QSpinBox *cylinder_height_QSpinBox;
    QSpinBox *cylinder_weight_QSpinBox;

    QPushButton *add_box_QPushButton;
    QPushButton *add_cyl_QPushButton;

    QListWidget *unallocated_list_QListWidget;

    QSpinBox    *pallet_number_QSpinBox;

    QPushButton *move_to_pallet_QPushButton;
    QPushButton *clear_selection_QPushButton;

    QPushButton *backup_QPushButton;

    QPushButton *post_xml_QPushButton;

    QTextEdit   *pallet_xml_display_QTextEdit;

    QString add_box_tooltip         = "Add a new box container to the list";
    QString add_cyl_tooltip         = "Add a new cylinder container to the list";
    QString move_to_pallet_tooltip  = "Move selected container to the selected pallet number";
    QString backup_tooltip          = "Backup current list of unallocated containers";
    QString post_xml_tooltip        = "Post XML list of the pallets with containers";
};

#endif // MAINWIDGET_H
