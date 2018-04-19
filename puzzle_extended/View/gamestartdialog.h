#ifndef GAMESTARTDIALOG_H
#define GAMESTARTDIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include "Model/image.hpp"


namespace Ui {
class GameStartDialog;
}

class GameStartDialog : public QDialog
{
	Q_OBJECT

private:
	QGraphicsScene *scene;
	Image currentImage;
	QWidget *parent;

public:
	explicit GameStartDialog(QWidget *_parent = 0);
	~GameStartDialog();

	virtual void show();
private:
	Ui::GameStartDialog *ui;
	void setDefaultImage();

	void setImage(Image image);
protected slots:
	void on_setDefault_press();
	void on_loadCustom_press();
	void on_start_press();
};

#endif // GAMESTARTDIALOG_H
