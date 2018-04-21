#ifndef GAMELOADDIALOG_H
#define GAMELOADDIALOG_H

#include <QDialog>
#include "gamebegindialog.h"

namespace Ui {
class GameLoadDialog;
}

class GameLoadDialog : public QDialog, public GameBeginDialog
{
	Q_OBJECT
public:
	explicit GameLoadDialog(QWidget *parent = 0);
	~GameLoadDialog();
	QWidget *parent;

public:
	virtual void show();
	virtual void drawCurrentImage();
private:
	Ui::GameLoadDialog *ui;

protected slots:
	void on_setDefault_press();
	void on_loadCustom_press();
	void on_start_press();
};

#endif // GAMELOADDIALOG_H
