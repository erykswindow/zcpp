#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#import "Controller/gameviewcontroller.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit GameWindow(QWidget *parent = 0, GameViewController *_viewController = 0);
	~GameWindow();

private:
	Ui::GameWindow *ui;
	GameViewController *viewController;
	QGraphicsScene *scene;

public slots:
	void on_okButton_clicked();
	void on_startButton_clicked();
};

#endif // GAMEWINDOW_H
