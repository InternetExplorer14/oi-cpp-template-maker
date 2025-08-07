#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString stdtemplatefile=
"#include<iostream>\n\nusing namespace std;\n\nint main(){\n	ios::sync_with_stdio(0);\n	cin.tie(nullptr);\n	\n	\n	return 0;\n}";//template code

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QAction *enterAction=new QAction(this);
    enterAction->setShortcut(QKeySequence(Qt::Key_Return));//Enter
    enterAction->setText("运行");
    ui->pushButton_entry->addAction(enterAction);

    QAction *exitAction=new QAction(this);
    exitAction->setShortcut(QKeySequence(Qt::Key_Escape));
    exitAction->setText("退出程序");
    this->addAction(exitAction);

    connect(enterAction, &QAction::triggered, this, &MainWindow::entry);
    connect(exitAction,&QAction::triggered,this,&MainWindow::close);
    connect(ui->comboBox,&QComboBox::currentIndexChanged,this,&MainWindow::combochanged);
    connect(ui->pushButton_entry,&QPushButton::clicked,this,&MainWindow::entry);

    ui->groupBox_gonoicontext->hide();
    ui->groupBox_gonoiproblem->hide();
    ui->groupBox_luogucontest->hide();
    ui->groupBox_luoguproblem->show();
    ui->groupBox_517problem->hide();
    setWindowTitle("新建");
}
void MainWindow::entry(bool){
    switch(ui->comboBox->currentIndex()){
        case 0:{
            //洛谷题目
            QString filename=ui->lineEdit_luoguproblem->text();
            if(filename==""){
                return;
            }
            filename=filename.toLower();
            QString dirname="F:/Documents/problem-code/luogu";
            QDir dir(dirname+'/'+filename);
            if(!dir.mkpath(".")){
                QMessageBox::critical(this,"错误","没有操作权限，文件（夹）是否为只读？");
                exit(1);
            }
            if(!dir.exists()){
                QMessageBox::critical(this,"错误","luogu文件夹呢？看看配置吧哥们");
                exit(1);
            }
            filename=dir.filePath(filename+".cpp");
            QFile file(filename);
            if(file.open(QIODevice::WriteOnly)){
                QTextStream oss(&file);
                oss<<stdtemplatefile;
            }
            file.close();
            break;
        }
        case 1:{
            //来做梦题目
            QString filename=ui->lineEdit_gonoiproblem->text();
            if(filename==""){
                return;
            }
            filename=filename.toLower();
            QString dirname="F:/Documents/problem-code/gonoi";
            QDir dir(dirname+'/'+filename);
            if(!dir.mkpath(".")){
                QMessageBox::critical(this,"错误","没有操作权限，文件（夹）是否为只读？");
                exit(1);
            }
            if(!dir.exists()){
                QMessageBox::critical(this,"错误","gonoi文件夹呢？看看配置吧哥们");
                exit(1);
            }
            filename=dir.filePath(filename+".cpp");
            QFile file(filename);
            if(file.open(QIODevice::WriteOnly)){
                QTextStream oss(&file);
                oss<<stdtemplatefile;
            }
            file.close();
            break;
        }
        case 2:{
            //洛谷比赛
            QString filename=ui->lineEdit_luogucontext->text();
            if(filename==""){
                return;
            }
            filename=filename.toLower();
            QString dirname="F:/Documents/problem-code/context/luogu";
            QDir dir(dirname+'/'+filename);
            if(!dir.mkpath(".")){
                QMessageBox::critical(this,"错误","没有操作权限，文件（夹）是否为只读？");
                exit(1);
            }
            if(!dir.exists()){
                QMessageBox::critical(this,"错误","context/luogu文件夹呢？看看配置吧哥们");
                exit(1);
            }
            int ns=ui->lineEdit_luogucontext_2->text().toInt();
            for(int i=0;i<ns;i++){
                QFile file(dir.filePath(QString(static_cast<char>(i+'a'))+".cpp"));
                if(file.open(QIODevice::WriteOnly)){
                    QTextStream oss(&file);
                    oss<<stdtemplatefile;
                }
                file.close();
            }
            break;
        }
        case 3:{
            //来做梦周赛
            QString filename=ui->lineEdit_gonoicontext->text();
            if(filename==""){
                return;
            }
            filename+=ui->comboBox_2->currentText();
            filename=filename.toLower();
            QString dirname="F:/Documents/problem-code/context/gonoi";
            QDir dir(dirname+'/'+filename);
            if(!dir.mkpath(".")){
                QMessageBox::critical(this,"错误","没有操作权限，文件（夹）是否为只读？");
                exit(1);
            }
            if(!dir.exists()){
                QMessageBox::critical(this,"错误","context/gonoi文件夹呢？看看配置吧哥们");
                exit(1);
            }
            for(char c='a';c<='d';c++){
                QFile file(dir.filePath(QString(c)+".cpp"));
                if(file.open(QIODevice::WriteOnly)){
                    QTextStream oss(&file);
                    oss<<stdtemplatefile;
                }
                file.close();
            }
            break;
        }
        case 4:{
            //517题目
            QString filename=ui->lineEdit_517problem->text();
            if(filename==""){
                return;
            }
            filename=filename.toLower();
            QString dirname="F:/Documents/problem-code/517";
            QDir dir(dirname+'/'+filename);
            if(!dir.mkpath(".")){
                QMessageBox::critical(this,"错误","没有操作权限，文件（夹）是否为只读？");
                exit(1);
            }
            if(!dir.exists()){
                QMessageBox::critical(this,"错误","517文件夹呢？看看配置吧哥们");
                exit(1);
            }
            filename=dir.filePath(filename+".cpp");
            QFile file(filename);
            if(file.open(QIODevice::WriteOnly)){
                QTextStream oss(&file);
                oss<<stdtemplatefile;
            }
            QString &command=filename;
            QProcess process;
            QStringList arguments;
            arguments<<command;
            process.start("F:/Program Files/Notepad++/notepad++.exe",arguments);
            if(!process.waitForStarted()){
                QMessageBox::critical(this,"错误",QString("无法启动命令：%1").arg(process.errorString()));
                exit(-1);
            }
            if(!process.waitForFinished()){
                QMessageBox::critical(this,"错误",QString("命令执行失败：%1").arg(process.errorString()));
                exit(-1);
            }
            QString output=QString::fromLocal8Bit(process.readAllStandardOutput());
            QString errorOutput=QString::fromLocal8Bit(process.readAllStandardError());
            file.close();
            break;
        }
    }
    exit(0);
}
void MainWindow::combochanged(int index){
    ui->groupBox_gonoicontext->hide();
    ui->groupBox_gonoiproblem->hide();
    ui->groupBox_luogucontest->hide();
    ui->groupBox_luoguproblem->hide();
    ui->groupBox_517problem->hide();
    switch(index){
        case 0:{
            //洛谷题目
            ui->groupBox_luoguproblem->show();
            break;
        }
        case 1:{
            //来做梦题目
            ui->groupBox_gonoiproblem->show();
            break;
        }
        case 2:{
            //洛谷比赛
            ui->groupBox_luogucontest->show();
            break;
        }
        case 3:{
            //来做梦周赛
            ui->groupBox_gonoicontext->show();
            break;
        }
        case 4:{
            //517题目
            ui->groupBox_517problem->show();
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
