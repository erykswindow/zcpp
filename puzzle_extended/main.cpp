#import "View/startwindow.h"
#include <QApplication>
#include "Controller/mainwindowviewcontroller.h"

int main(int argc, char *argv[])
{
	srand( time( NULL ) );
    QApplication a(argc, argv);
    StartWindow w;
	MainWindowViewController *vc = new MainWindowViewController();
	w.setRootViewController(vc);
    w.show();

    return a.exec();
}
