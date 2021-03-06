#include "gamestartdialog.h"
#include "ui_gamestartdialog.h"
#include "View/gamewindow.h"
#include "Model/image.hpp"
#include "Controller/gameviewcontroller.h"

#include <QFileDialog>
#include "startwindow.h"

GameStartDialog::GameStartDialog(QWidget *_parent): GameBeginDialog(), QDialog(_parent),
	ui(new Ui::GameStartDialog),
	parent(_parent)
{
	scene = new QGraphicsScene;
	ui->setupUi(this);
	ui -> graphicsView -> setScene(scene);

	connect(ui -> defaultButton, SIGNAL(clicked()),
			this, SLOT(on_setDefault_press()));
	connect(ui -> customButton, SIGNAL(clicked()),
			this, SLOT(on_loadCustom_press()));
	connect(ui -> startButton, SIGNAL(clicked()),
			this, SLOT(on_start_press()));
	this -> setAttribute(Qt::WA_DeleteOnClose);
}

GameStartDialog::~GameStartDialog() {
	delete ui;
}

void GameStartDialog::on_setDefault_press() {
	setDefaultImage();
}

void GameStartDialog::on_loadCustom_press() {
	QString imagePath = QFileDialog::getOpenFileName(
				this,
				tr("Open File"),
				"",
				tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
				);

	Image image = Image(imagePath);
	setImage(image);
}


void GameStartDialog::on_start_press() {
	GameViewController* vc = new GameViewController(currentImage,
													ui -> horizontalSpinBox -> value(),
													ui -> verticalSpinBox -> value());
	GameWindow *w = new GameWindow(this -> parent, vc);
	w -> show();
	this -> close();
}

void GameStartDialog::show() {
	QDialog::show();
	setDefaultImage();
}

void GameStartDialog::drawCurrentImage() {
	Image image = currentImage.scaled(ui -> graphicsView -> size());
	scene -> addPixmap(image);
}
