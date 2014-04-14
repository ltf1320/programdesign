#include <QApplication>
#include <QPixmap>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap result = QPixmap();
    result = QPixmap::grabWindow(QApplication::desktop()->winId()); //抓取当前屏幕的图片
    QString fileName=QString("F:\screenShot.jpg");
    result.save(fileName);

    return a.exec();
}
