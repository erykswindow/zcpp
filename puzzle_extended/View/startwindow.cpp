#include "startwindow.h"
#include "ui_startwindow.h"
#include "Model/image.hpp"
#include "Utilities/imageprocessor.hpp"
#include "Controller/gameviewcontroller.h"
#include "gamestartdialog.h"
#include "gameloaddialog.h"

#define NEWLINE "\n"

StartWindow::StartWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::StartWindow) {
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
	scene = new QGraphicsScene;
    ui->setupUi(this);
	ui -> graphicsView -> setScene(scene);
}

StartWindow::~StartWindow() {
	delete ui;
	delete rootViewController;
	delete scene;
}

void StartWindow::on_pushButton_clicked() {
	GameStartDialog *dialog = new GameStartDialog(this);
	dialog -> show();
}


void StartWindow::on_loadGame_clicked() {
	GameLoadDialog *dialog = new GameLoadDialog(this);
	dialog -> show();
}

void StartWindow::setRootViewController(Controller * _vc) {
	rootViewController = _vc;
}

void StartWindow::show() {
	QMainWindow::show();
	setImage();
}

void StartWindow::setImage() {
	QString filename(":/LogoImage.jpg");

	Image image = Image(filename);
	image = image.scaled(ui -> graphicsView -> size());
	scene -> addPixmap(image);
}
