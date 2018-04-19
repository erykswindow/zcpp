#ifndef PEWINDOW_H
#define PEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#import "Controller/gameviewcontroller.h"
#import "gamewindow.h"

namespace Ui {
class PEWindow;
}

class PEWindow : public QMainWindow
{
    Q_OBJECT

private:
	Ui::PEWindow *ui;
	ViewController *rootViewController;
	QGraphicsScene *scene;

private:
	GameWindow *gameWindow;


public:
    explicit PEWindow(QWidget *parent = 0);
    ~PEWindow();

public:
	void setRootViewController(ViewController *);
	virtual void show();

private:
	void setImage();

private slots:
    void on_pushButton_clicked();

};

#endif // PEWINDOW_H
