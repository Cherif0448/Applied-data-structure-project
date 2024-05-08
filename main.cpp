#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Ultimate Spell-checker");
    QPixmap background(":/new/prefix1/projectnewbackground.png");
    if (background.isNull()) {
        qDebug() << "Failed to load background image.";
        return -1;
    }

    QPixmap scaledBackground = background.scaled(w.size(), Qt::IgnoreAspectRatio);
    if (scaledBackground.isNull()) {
        qDebug() << "Failed to scale background image.";
        return -1;
    }

    QPalette palette;
    palette.setBrush(QPalette::Window, scaledBackground);
    w.setPalette(palette);

    // Ensure the main window is updated with the new palette
    w.update();

    w.show();

    w.show();
    return a.exec();
}
