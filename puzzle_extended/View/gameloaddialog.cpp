#include <QFileDialog>
#include "gameloaddialog.h"
#include "ui_gameloaddialog.h"
#include "Controller/gameviewcontroller.h"
#include "gamewindow.h"

GameLoadDialog::GameLoadDialog(QWidget *_parent) :
	QDialog(_parent),
	ui(new Ui::GameLoadDialog),
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

GameLoadDialog::~GameLoadDialog() {
	delete ui;
}

void GameLoadDialog::on_setDefault_press() {
	setDefaultImage();
}

void GameLoadDialog::on_loadCustom_press() {
	QString imagePath = QFileDialog::getOpenFileName(
				this,
				tr("Open File"),
				"",
				tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" )
				);

	Image image = Image(imagePath);
	setImage(image);
}


void GameLoadDialog::on_start_press() {
	GameViewController *gameViewController = new GameViewController(currentImage);
	QWidget *parent = this -> parent;
	GameWindow *w = new GameWindow(parent, gameViewController);
	w -> show();
	w -> resumeGame();
	this -> close();
}

void GameLoadDialog::show() {
	QDialog::show();
	setDefaultImage();
}

void GameLoadDialog::drawCurrentImage() {
	Image image = currentImage.scaled(ui -> graphicsView -> size());
	scene -> addPixmap(image);
}
