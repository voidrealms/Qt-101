#include <QtCore/QCoreApplication>
#include "tester.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Tester cTest;
    cTest.GetUrl();

    return a.exec();
}
