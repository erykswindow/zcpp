#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#import "Controller/gameviewcontroller.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::GameWindow *ui;
	GameViewController *viewController;
	QGraphicsScene *scene;

public:
	explicit GameWindow(QWidget *parent = 0, GameViewController *_viewController = 0);
	~GameWindow();

public:
	virtual void show();

public slots:
	void on_okButton_clicked();
	void on_startButton_clicked();

protected:
	virtual void resizeEvent(QResizeEvent*);
	virtual void mousePressEvent(QMouseEvent*event);
};

#endif // GAMEWINDOW_H
