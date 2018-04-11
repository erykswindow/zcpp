#include <QFileDialog>
#include <QTranslator>
#include "gameviewcontroller.h"

GameViewController::GameViewController() {
	stateController = new GameStateController();
}

void GameViewController::readInput(QWidget *widget) {
	QFileDialog *dialog = new QFileDialog(widget, Qt::Drawer);
	dialog -> setAcceptMode(QFileDialog::AcceptOpen);
	dialog -> selectNameFilter(dialog -> tr("Image (*.png, *.jpg, *.jpeg"));
	QString filename = dialog -> getOpenFileName(widget);

	Image image = Image(filename);

	stateController -> setupGameWithImage(image);

	delete dialog;
}
