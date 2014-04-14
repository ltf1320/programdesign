#include "mainwindow.h"

CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    Ui_MainWindow()
{
    setupUi(this);
    imageWidget=new ImageWidget(this);
    scrollArea=new QScrollArea(this);
    scrollArea->setWidget(imageWidget);
    scrollArea->widget()->setMinimumSize(320,240);
    setCentralWidget(scrollArea);

    scrollArea->show();

    statusBar()->showMessage(tr("就绪"));
    setWindowTitle("图片查看");

    initConnects();
    updateActions();
    index=-1;
}

CMainWindow::~CMainWindow()
{
}

void CMainWindow::initConnects()
{
    connect(actASize,SIGNAL(triggered()),this,SLOT(doASize()));
    connect(actClose,SIGNAL(triggered()),this,SLOT(doclose()));
    connect(actFSize,SIGNAL(triggered()),this,SLOT(doFSize()));
    connect(actL90,SIGNAL(triggered()),this,SLOT(doL90()));
    connect(actR90,SIGNAL(triggered()),this,SLOT(doR90()));
    connect(actLarge,SIGNAL(triggered()),this,SLOT(doLarge()));
    connect(actSmall,SIGNAL(triggered()),this,SLOT(doSmall()));
    connect(actNext,SIGNAL(triggered()),this,SLOT(donext()));
    connect(actPre,SIGNAL(triggered()),this,SLOT(dopre()));
    connect(actOpen,SIGNAL(triggered()),this,SLOT(doopen()));
    connect(actQuit,SIGNAL(triggered()),this,SLOT(close()));
}

void CMainWindow::updateActions()
{
    actASize->setVisible(imageName.isEmpty());
    actClose->setVisible(imageName.isEmpty());
    actFSize->setVisible(imageName.isEmpty());
    actL90->setVisible(imageName.isEmpty());
    actR90->setVisible(imageName.isEmpty());
    actLarge->setVisible(imageName.isEmpty());
    actSmall->setVisible(imageName.isEmpty());
    actNext->setVisible(imageList.isEmpty());
    actPre->setVisible(imageList.isEmpty());
}

void CMainWindow::doopen()
{
    QString fileName;
    fileName=QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        openFile(fileName);
        QFileInfo fileInfo(fileName);
        imageDir=fileInfo.absoluteDir();
        QStringList fliter;
        fliter<<"*.jpg"<<"*.png"<<"*.bmp"<<"*.jepg"<<"*.xmp";
 //       int fnum=fliter.count();
 //       for(int i=0;i<fnum;i++)
 //       {
  //          fliter<<fliter[i].toUpper();
  //      }
        imageList=imageDir.entryList(fliter,QDir::Files);
        for(int i=0;i<imageList.count();i++)
        {
            if(imageList[i]==fileInfo.fileName())
            {
                index=i;
                break;
            }
        }
    }
    updateActions();
}

void CMainWindow::donext()
{
    if(imageList.empty()) return;
    index++;
    if(index>imageList.count())
        index=0;
    openFile(imageList[index]);
}

void CMainWindow::dopre()
{
    if(imageList.empty()) return;
    index--;
    if(index<0)
        index=imageList.count()-1;
    openFile(imageList[index]);
}

void CMainWindow::doL90()
{
    imageWidget->setAngle(-90);

}

void CMainWindow::doR90()
{
    imageWidget->setAngle(90);
}
void CMainWindow::openFile(QString &fileName)
{
    imageWidget->setPixMap(fileName);
    scrollArea->resize(imageWidget->size()+QSize(5,5));
}

void CMainWindow::doclose()
{
    imageWidget->setPixMap(0);
}

void CMainWindow::doFSize()
{
    imageWidget->setbFit(true);
    scrollArea->resize(imageWidget->size()+QSize(5,5));
}

void CMainWindow::doASize()
{
    imageWidget->setASize();
    scrollArea->resize(imageWidget->size()+QSize(5,5));
}

void CMainWindow::doLarge()
{
    actSmall->setVisible(true);
    if(!imageWidget->bLarge())
        actLarge->setVisible(false);
    scrollArea->resize(imageWidget->size()+QSize(5,5));
}

void CMainWindow::doSmall()
{
    actLarge->setVisible(true);
    if(!imageWidget->bSmall())
        actSmall->setVisible(false);
    scrollArea->resize(imageWidget->size()+QSize(5,5));
}


void CMainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        QString localFile;
        QRegExp rx("\\.(jpg|bmp|jpeg|png|xpm)$",Qt::CaseInsensitive);
        foreach (QUrl url,event->mimeData()->urls())
        {
            localFile=url.toLocalFile();
            if(rx.indexIn(localFile)>=0)
            {
                event->accept();
                return;
            }
            else event->ignore();
        }
    }
    else event->ignore();
}

void CMainWindow::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        QString localFile;
        QRegExp rx("\\.(jpg|bmp|jpeg|png|xpm)$",Qt::CaseInsensitive);
        foreach (QUrl url,event->mimeData()->urls())
        {
            localFile=url.toLocalFile();
            if(rx.indexIn(localFile)>=0)
            {
                event->accept();
                imageWidget->setPixMap(localFile);
                return;
            }
            else event->ignore();
        }
    }
    else event->ignore();
}
