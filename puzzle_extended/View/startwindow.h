#ifndef PEWINDOW_H
#define PEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#import "Controller/gameviewcontroller.h"
#import "gamewindow.h"

namespace Ui {
class PEWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

private:
	Ui::PEWindow *ui;
	Controller *rootViewController;
	QGraphicsScene *scene;

public:
	explicit StartWindow(QWidget *parent = 0);
	~StartWindow();

public:
	void setRootViewController(Controller *);
	virtual void show();

private:
	void setImage();

private slots:
    void on_pushButton_clicked();

};

#endif // PEWINDOW_H
