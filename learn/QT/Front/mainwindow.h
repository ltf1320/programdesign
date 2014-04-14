#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QScrollArea>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    
protected slots:
    void changeFontColor();
    void fontSizeChanged(const QString &text);
private:
    void createActions();
    void createMenus();
    void createToolBars();
    void listAllFonts();
    void updateColor();

    QScrollArea *scrollArea;
    QTextEdit *fontEdit;

    QMenu *fontMenu;
    QToolBar *fontToolBar;
    QComboBox *sizeComboBox;
    QAction *fontColorAct;

    uint fontSize;
    bool bShowStyles;
    QColor fontColor;
};

#endif // MAINWINDOW_H
