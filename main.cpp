#include "FireRescue.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FireRescue fr;
    fr.show();

    return a.exec();
}
