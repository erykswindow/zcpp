#import "pewindow.h"
#include "ui_pewindow.h"
#include "Model/image.hpp"
#include "Controller/imageprocessor.hpp"
#import "Controller/gameviewcontroller.h"

#define NEWLINE "\n"

PEWindow::PEWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::PEWindow) {
    ui->setupUi(this);
}

PEWindow::~PEWindow() {
    delete ui;
	delete rootViewController;
}

void PEWindow::on_pushButton_clicked() {
	GameViewController* vc = new GameViewController();
	vc -> readInput(this);
	this -> gameWindow = new GameWindow(this, vc);
	this -> gameWindow -> show();
}

void PEWindow::setRootViewController(ViewController * _vc) {
	rootViewController = _vc;
}

void PEWindow::show() {
	QMainWindow::show();
	rootViewController -> presentView(rect());
}
