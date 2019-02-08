#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_List();
    ui->lineEdit->setText("vlc");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_List()
{
    QString name;
    foreach(name, streamers.streamerNameList)
    {
        ui->listWidget->addItem(name);
    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qint64 pid = 0;
    QString player = "-p=" + ui->lineEdit->text();
    QStringList args = { streamers.streamer.value(item->text()), "best", player};
    QProcess::startDetached("streamlink", args, QDir::currentPath(), &pid);
    ui->statusBar->showMessage(tr("Working, please wait..."));
}
