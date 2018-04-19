#import "pewindow.h"
#include "ui_pewindow.h"
#include "Model/image.hpp"
#include "Controller/imageprocessor.hpp"
#import "Controller/gameviewcontroller.h"
#import "gamestartdialog.h"

#define NEWLINE "\n"

PEWindow::PEWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::PEWindow) {
	setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
	scene = new QGraphicsScene;
    ui->setupUi(this);
	ui -> graphicsView -> setScene(scene);
}

PEWindow::~PEWindow() {
	delete ui;
	delete rootViewController;
	delete scene;
}

void PEWindow::on_pushButton_clicked() {


	GameStartDialog *dialog = new GameStartDialog(this);
	dialog -> show();
}

void PEWindow::setRootViewController(ViewController * _vc) {
	rootViewController = _vc;
}

void PEWindow::show() {
	QMainWindow::show();
	setImage();
	rootViewController -> presentView(rect());
}

void PEWindow::setImage() {
	QString filename(":/LogoImage.jpg");

	Image image = Image(filename);
	image = image.scaled(ui -> graphicsView -> size());
	scene -> addPixmap(image);
}
