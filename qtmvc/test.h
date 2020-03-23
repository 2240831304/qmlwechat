#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>

#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
#include <QFileSystemModel>
#include <QStringListModel>

void modeltest()
{
    //新建一个QDirModel对象,为数据访问做准备,QDirModel的创建还可以设置过滤器
     //即只有符合条件的文件或目录才可被访问
     //QDirModel类继承自QAbstractItemModel类,为访问本地系统提供数据模型,它提供了如
     //新建,删除,创建目录等一系列与文件操作相关的函数
     QDirModel model;

     //新建三种不同的View对象,以便文件目录可以以三种不同的方式显示
     QTreeView tree;
     QListView list;
     QTableView table;

     //设置View对象的Model为QDirModel对象的model
     tree.setModel(&model);
     list.setModel(&model);
     table.setModel(&model);

     //设置QTreeView对象的选择方式为多选
     //QAbstractItemView提供了五种选择模式,QAbstractItem View::SingleSelection.
     //QAbstractItemView::NoSelection,QAbstractItemView::ContiguousSelection
     //QAbstractItemView::ExtendedSelection和QAbstractItemView::MultiSelection
     tree.setSelectionMode(QAbstractItemView::MultiSelection);
     //设置QTableView对象与QTreeView对象使用相同的选择模型
     list.setSelectionModel(tree.selectionModel());
     table.setSelectionMode(tree.selectionMode());

     //为了实现双击QTreeView对象中的某个目录时,QListView对象和QTableView对象显示此选定目录
     //下的所有文件和目录,需要连接QTreeView对象的doubleClicked()信号与QListView对象的
     //setRootIndex()槽函数
     QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&list,
                      SLOT(setRootIndex(QModelIndex)));
     QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&table,
                      SLOT(setRootIndex(QModelIndex)));

     QSplitter *splitter = new QSplitter;
     splitter->addWidget(&tree);
     splitter->addWidget(&list);
     splitter->addWidget(&table);
     splitter->setWindowTitle(QObject::tr("Model/view"));
     splitter->show();
}

void test11()
{
    QSplitter *splitter = new QSplitter;


    QFileSystemModel *model = new QFileSystemModel;

    model->setRootPath(QDir::currentPath());


    QTreeView *tree = new QTreeView(splitter);

    tree->setModel(model);

    tree->setRootIndex(model->index(QDir::currentPath()));


    QListView *list = new QListView(splitter);

    list->setModel(model);

    list->setRootIndex(model->index(QDir::currentPath()));


    splitter->setWindowTitle("Two views onto the same file system model");

    splitter->show();
}


QStringList numbers;
QAbstractItemModel *model;
QAbstractItemModel *model1;
QListView *view;
void Listmodel()
{
    numbers << "One" << "Two" << "Three" << "Four" << "Five";
    model = new QStringListModel(numbers);

    view = new QListView;

    view->setModel(model);
    view->show();
}

void changedata()
{
    numbers << "One" << "Two";
    model = new QStringListModel(numbers);
    view->reset();
    view->setModel(model);
}


