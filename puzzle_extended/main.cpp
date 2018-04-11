#import "View/pewindow.h"
#include <QApplication>
#import "Controller/gameviewcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PEWindow w;
	GameViewController *vc = new GameViewController();
	w.setRootViewController(vc);
    w.show();

    return a.exec();
}
