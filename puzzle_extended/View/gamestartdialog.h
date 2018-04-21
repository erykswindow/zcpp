#ifndef GAMESTARTDIALOG_H
#define GAMESTARTDIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include "Model/image.hpp"
#include "gamebegindialog.h"


namespace Ui {
class GameStartDialog;
}

class GameStartDialog : public QDialog, public GameBeginDialog
{
	Q_OBJECT
public:
	explicit GameStartDialog(QWidget *_parent = 0);
	~GameStartDialog();
	QWidget *parent;

public:
	virtual void show();
	virtual void drawCurrentImage();
private:
	Ui::GameStartDialog *ui;

protected slots:
	void on_setDefault_press();
	void on_loadCustom_press();
	void on_start_press();
};

#endif // GAMESTARTDIALOG_H
