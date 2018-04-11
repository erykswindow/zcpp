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
	GameViewController* vc = (GameViewController *)rootViewController;
	vc -> readInput(this);
}

void PEWindow::setRootViewController(GameViewController * _vc) {
	rootViewController = _vc;
}

void PEWindow::show() {
	QMainWindow::show();
	rootViewController -> presentView(rect());
}
