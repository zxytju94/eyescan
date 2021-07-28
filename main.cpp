#include "scanplot.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScanPlot w;
    w.show();

    return a.exec();
}
