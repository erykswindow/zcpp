#ifndef PEWINDOW_H
#define PEWINDOW_H

#include <QMainWindow>
#import "Controller/gameviewcontroller.h"

namespace Ui {
class PEWindow;
}

class PEWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PEWindow(QWidget *parent = 0);
    ~PEWindow();

	void setRootViewController(GameViewController *);
	virtual void show();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PEWindow *ui;

	GameViewController *rootViewController;
};

#endif // PEWINDOW_H
