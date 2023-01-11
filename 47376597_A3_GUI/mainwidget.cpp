#include "mainwidget.h"
#include "containerfactory.h"
#include "tcpconnection.h"
#include "xmlwriter.h"

#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QTextEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QSize>
#include <QThread>

MainWidget::MainWidget(QWidget *parent)
           :QWidget(parent),
            new_job                      (new ContainerFactory),
            container_list               (new ContainerList),
            pallet_list                  (new PalletList),
            tab_widget                   (new QTabWidget(this)),
            box_breadth_QSpinBox         (new QSpinBox()),
            box_length_QSpinBox          (new QSpinBox()),
            box_height_QSpinBox          (new QSpinBox()),
            box_weight_QSpinBox          (new QSpinBox()),
            cylinder_diameter_QSpinBox   (new QSpinBox()),
            cylinder_height_QSpinBox     (new QSpinBox()),
            cylinder_weight_QSpinBox     (new QSpinBox()),
            add_box_QPushButton          (new QPushButton("Add box")),
            add_cyl_QPushButton          (new QPushButton("Add cylinder")),
            unallocated_list_QListWidget (new QListWidget()),
            pallet_number_QSpinBox       (new QSpinBox()),
            move_to_pallet_QPushButton   (new QPushButton("Move to pallet")),
            clear_selection_QPushButton  (new QPushButton("Clear selection")),
            backup_QPushButton           (new QPushButton("Backup")),
            post_xml_QPushButton         (new QPushButton("Post XML to network")),
            pallet_xml_display_QTextEdit (new QTextEdit)
{
    connect(box_breadth_QSpinBox,         &QSpinBox::textChanged,   this, &MainWidget::check_box_inputs);
    connect(box_length_QSpinBox,          &QSpinBox::textChanged,   this, &MainWidget::check_box_inputs);
    connect(box_height_QSpinBox,          &QSpinBox::textChanged,   this, &MainWidget::check_box_inputs);
    connect(box_weight_QSpinBox,          &QSpinBox::textChanged,   this, &MainWidget::check_box_inputs);

    connect(cylinder_diameter_QSpinBox,   &QSpinBox::textChanged,   this, &MainWidget::check_cyl_inputs);
    connect(cylinder_height_QSpinBox,     &QSpinBox::textChanged,   this, &MainWidget::check_cyl_inputs);
    connect(cylinder_weight_QSpinBox,     &QSpinBox::textChanged,   this, &MainWidget::check_cyl_inputs);

    connect(unallocated_list_QListWidget, &QListWidget::itemClicked,this, &MainWidget::check_unalocated_list_selected);
    connect(clear_selection_QPushButton,  &QPushButton::clicked,    this, &MainWidget::clear_container_selection);

    connect(add_box_QPushButton,          &QPushButton::clicked,    this, &MainWidget::create_container);
    connect(add_cyl_QPushButton,          &QPushButton::clicked,    this, &MainWidget::create_container);

    connect(backup_QPushButton,           &QPushButton::clicked,    this, &MainWidget::add_memento_signal);
    connect(move_to_pallet_QPushButton,   &QPushButton::clicked,    this, &MainWidget::move_container_to_pallet);
    connect(post_xml_QPushButton,         &QPushButton::clicked,    this, &MainWidget::xml_thread_slot);

    create_tab_1();
    create_tab_2();

    set_input_limits();
}

void MainWidget::create_tab_1()
{
    // Tab 1 - Containers
    // Box

    QGroupBox   *boxGroup   (new QGroupBox("Box"));
    QGridLayout *boxlayout  (new QGridLayout);

    boxGroup->setLayout(boxlayout);

    QLabel  *labelBBreadth(new QLabel("Breadth"));

    boxlayout->addWidget(labelBBreadth,         0, 0);
    boxlayout->addWidget(box_breadth_QSpinBox,  0, 1);

    QLabel  *labelBLength(new QLabel("Length"));

    boxlayout->addWidget(labelBLength,          1, 0);
    boxlayout->addWidget(box_length_QSpinBox,   1, 1);

    QLabel *labelBHeight(new QLabel("Height"));

    boxlayout->addWidget(labelBHeight,          2, 0);
    boxlayout->addWidget(box_height_QSpinBox,   2, 1);

    QLabel *labelBWeight(new QLabel("Weight"));

    boxlayout->addWidget(labelBWeight,          3, 0);
    boxlayout->addWidget(box_weight_QSpinBox,   3, 1);
    boxlayout->addWidget(add_box_QPushButton,   4, 0, 1, 2);

    add_box_QPushButton->setObjectName("BoxButton");
    add_box_QPushButton->setToolTip(add_box_tooltip);
    add_box_QPushButton->setDisabled(true);

    // Cylinder

    QGroupBox   *cylinderGroup  (new QGroupBox("Cylinder"));
    QGridLayout *cylinderlayout (new QGridLayout);

    cylinderGroup->setLayout(cylinderlayout);

    QLabel *labelCDiameter(new QLabel("Diameter"));

    cylinderlayout->addWidget(labelCDiameter,               0, 0);
    cylinderlayout->addWidget(cylinder_diameter_QSpinBox,   0, 1);

    QLabel *labelCHeight(new QLabel("Height"));

    cylinderlayout->addWidget(labelCHeight,             1, 0);
    cylinderlayout->addWidget(cylinder_height_QSpinBox, 1, 1);

    QLabel *labelCWeight(new QLabel("Weight"));

    cylinderlayout->addWidget(labelCWeight,             2, 0);
    cylinderlayout->addWidget(cylinder_weight_QSpinBox, 2, 1);

    QLabel *labelBlank1(new QLabel(""));

    cylinderlayout->addWidget(labelBlank1,              4, 0);
    cylinderlayout->addWidget(add_cyl_QPushButton, 3, 0, 1, 2);

    add_cyl_QPushButton->setObjectName("CylinderButton");
    add_cyl_QPushButton->setToolTip(add_cyl_tooltip);
    add_cyl_QPushButton->setDisabled(true);

    QWidget     *bottomWidget(new QWidget);
    QGridLayout *bottomLayout(new QGridLayout);

    bottomWidget->setLayout(bottomLayout);

    QLabel *labelListOf(new QLabel("List of unallocated containers"));

    bottomLayout->addWidget(labelListOf, 0, 0);

    QLabel *labelClickOn(new QLabel("Click on item in list, choose a pallet number, and move container to that pallet"));

    labelClickOn->setWordWrap(true);

    bottomLayout->addWidget(unallocated_list_QListWidget, 1, 0, 5, 1);
    bottomLayout->addWidget(labelClickOn,                1, 1);
    bottomLayout->addWidget(pallet_number_QSpinBox,      2, 1);

    pallet_number_QSpinBox->setMinimum(1);

    bottomLayout->addWidget(move_to_pallet_QPushButton,  3, 1);
    bottomLayout->addWidget(clear_selection_QPushButton, 4, 1);

    move_to_pallet_QPushButton->setToolTip(move_to_pallet_tooltip);
    move_to_pallet_QPushButton->setDisabled(true);

    QLabel *labelBlank2(new QLabel);

    cylinderlayout->addWidget(labelBlank2, 4, 1);

    bottomLayout->addWidget(backup_QPushButton, 5, 1);

    backup_QPushButton->setToolTip(backup_tooltip);

    QWidget     *containerWidget    (new QWidget);
    QGridLayout *tabLayoutContainer (new QGridLayout);

    tabLayoutContainer->addWidget(boxGroup,      0, 0);
    tabLayoutContainer->addWidget(cylinderGroup, 0, 1);
    tabLayoutContainer->addWidget(bottomWidget,  1, 0, 1, 2);

    containerWidget->setLayout(tabLayoutContainer);

    tab_widget->addTab(containerWidget, "Containers");
}

void MainWidget::create_tab_2()
{
    // Tab 2 - Post XML

    pallet_xml_display_QTextEdit->setReadOnly(true);

    QWidget     *postWidget(new QWidget);
    QVBoxLayout *postLayout(new QVBoxLayout);

    postWidget->setLayout(postLayout);

    postLayout->addWidget(post_xml_QPushButton);
    postLayout->addWidget(pallet_xml_display_QTextEdit);

    post_xml_QPushButton->setToolTip(post_xml_tooltip);

    tab_widget->addTab(postWidget, "Post XML");
}

void MainWidget::set_input_limits()
{
    box_breadth_QSpinBox       ->setMaximum(9999);
    box_length_QSpinBox        ->setMaximum(9999);
    box_height_QSpinBox        ->setMaximum(9999);
    box_weight_QSpinBox        ->setMaximum(9999);
    cylinder_diameter_QSpinBox ->setMaximum(9999);
    cylinder_height_QSpinBox   ->setMaximum(9999);
    cylinder_weight_QSpinBox   ->setMaximum(9999);
    pallet_number_QSpinBox     ->setMaximum(9999);
}

void MainWidget::clear_inputs()
{
    box_breadth_QSpinBox       ->setValue(0);
    box_length_QSpinBox        ->setValue(0);
    box_height_QSpinBox        ->setValue(0);
    box_weight_QSpinBox        ->setValue(0);
    cylinder_diameter_QSpinBox ->setValue(0);
    cylinder_height_QSpinBox   ->setValue(0);
    cylinder_weight_QSpinBox   ->setValue(0);
    pallet_number_QSpinBox     ->setValue(0);
}

ContainerMemento *MainWidget::create_memento()
{
    ContainerMemento *new_memento = new ContainerMemento;

    new_memento->set_state(container_list);

    return new_memento;
}

void MainWidget::set_memento(ContainerMemento *memento)
{
    unallocated_list_QListWidget->clear();
    container_list->clear_container_list();

    container_list->set_container_list(memento->get_state());

    for(int i = 0; i < container_list->get_size(); i++)
    {
        unallocated_list_QListWidget->addItem(container_list->get_container(i)->get_code());
    }
}

void MainWidget::xml_thread_slot()
{
    pallet_xml_display_QTextEdit->clear();

    QThread   *new_thread = new QThread;
    XmlWriter *xml_writer = new XmlWriter;

    xml_writer->moveToThread(new_thread);

    connect(new_thread, &QThread::started, xml_writer, [this, xml_writer]{xml_writer->get_xml_list(pallet_list);});

    connect(new_thread, &QThread::finished, new_thread, &QThread::quit);
    connect(new_thread, &QThread::finished, new_thread, &QThread::deleteLater);

    connect(xml_writer, &XmlWriter::xml_list_completed, xml_writer, &QObject::deleteLater);
    connect(xml_writer, &XmlWriter::xml_list_completed, this,       &MainWidget::send_xml_slot);

    new_thread->start();
}

void MainWidget::send_xml_slot(QString xml_list_QString)
{
    pallet_xml_display_QTextEdit->append(xml_list_QString);

    QByteArray xml_data = QString(xml_list_QString).toUtf8();

    TcpConnection *new_tcp_connection = new TcpConnection();

    new_tcp_connection->send_xml(xml_data);
}

void MainWidget::check_box_inputs()
{
    if
    (
        box_breadth_QSpinBox->value() == 0 ||
        box_length_QSpinBox ->value() == 0 ||
        box_height_QSpinBox ->value() == 0 ||
        box_weight_QSpinBox ->value() == 0
    )
    {
        add_box_QPushButton->setDisabled(true);
    }
    else
    {
        add_box_QPushButton->setEnabled(true);
    }
}

void MainWidget::check_cyl_inputs()
{
    if
    (
        cylinder_diameter_QSpinBox  ->value() == 0 ||
        cylinder_height_QSpinBox    ->value() == 0 ||
        cylinder_weight_QSpinBox    ->value() == 0
    )
    {
        add_cyl_QPushButton->setDisabled(true);
    }
    else
    {
        add_cyl_QPushButton->setEnabled(true);
    }
}

void MainWidget::check_unalocated_list_selected()
{
    if(unallocated_list_QListWidget->selectedItems().count() == 0)
    {
        move_to_pallet_QPushButton->setDisabled(true);
    }
    else
    {
        move_to_pallet_QPushButton->setDisabled(false);
        pallet_number_QSpinBox->setFocus();
    }
}

void MainWidget::clear_container_selection()
{
    unallocated_list_QListWidget->clearSelection();
    move_to_pallet_QPushButton  ->setDisabled(true);

    emit update_statusBar_signal("List selection cleared", 3000);
}

void MainWidget::create_container()
{
    new_container = new_job->create_container(QString(sender()           ->objectName()),
                                              box_breadth_QSpinBox       ->value(),
                                              box_length_QSpinBox        ->value(),
                                              box_height_QSpinBox        ->value(),
                                              box_weight_QSpinBox        ->value(),
                                              cylinder_diameter_QSpinBox ->value(),
                                              cylinder_height_QSpinBox   ->value(),
                                              cylinder_weight_QSpinBox   ->value());

    if(new_container != nullptr)
    {
        container_list->add_container(new_container);

        unallocated_list_QListWidget->addItem(new_container->get_code());

        clear_inputs();

        emit update_statusBar_signal("Container "+new_container->get_code()+" added to unallocated list", 3000);
    }
    else
    {
        emit update_statusBar_signal("Error creating new container", 3000);
    }
}

void MainWidget::move_container_to_pallet()
{
    bool pallet_exists = false;

    int index = unallocated_list_QListWidget->currentRow();

    for(int i = 0; i < pallet_list->get_size(); i++)
    {
        if(pallet_list->get_pallet(i)->get_pallet_number() == pallet_number_QSpinBox->value())
        {
            pallet_exists = true;
        }
    }

    if(!pallet_exists)
    {
        Pallet *pallet = new Pallet(pallet_number_QSpinBox->value());
        pallet_list->add_pallet(pallet);
    }

    for(int i = 0; i < pallet_list->get_size(); i++)
    {
        if(pallet_list->get_pallet(i)->get_pallet_number() == pallet_number_QSpinBox->value())
        {
            pallet_list->get_pallet(i)->add_container(container_list->get_container(index));

            emit update_statusBar_signal("Container "        + container_list->get_container(index)->get_code() +
                                         " added to pallet " + QVariant(pallet_number_QSpinBox->value()).toString(), 5000);

            container_list->remove_container(index);

            qDeleteAll(unallocated_list_QListWidget->selectedItems());

            move_to_pallet_QPushButton->setDisabled(true);

            unallocated_list_QListWidget->clearSelection();
        }
    }
}

MainWidget::~MainWidget(){}
