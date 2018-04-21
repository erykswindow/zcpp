#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#import "Controller/gameviewcontroller.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow, public Updateable
{
	Q_OBJECT

private:
	Ui::GameWindow *ui;
	GameViewController *viewController;
	QGraphicsScene *scene;
	int timerId = 0;

public:
	explicit GameWindow(QWidget *parent = 0, GameViewController *_viewController = 0);
	~GameWindow();

public:
	virtual void show();
	void update();
	void resumeGame();

protected:
	virtual void resizeEvent(QResizeEvent*);
	virtual void mousePressEvent(QMouseEvent*event);
	virtual void keyPressEvent(QKeyEvent *ev);
	virtual void timerEvent(QTimerEvent *event);
protected slots:
	void on_startButton_clicked();
	void on_saveButton_clicked();
};

#endif // GAMEWINDOW_H
