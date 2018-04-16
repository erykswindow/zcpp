#include <QFileDialog>
#include <QTranslator>
#include <QGraphicsScene>
#include "gameviewcontroller.h"
#include "Model/tile.hpp"

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

void GameViewController::drawIn(QGraphicsScene *_graphicsScene) {
	Board *board = stateController -> getGame() -> board;

	std::vector<Tile *> tiles = board -> tiles;
	for (int i = tiles.size(); i > 0; i--) {
		Tile *t = tiles[i];
		_graphicsScene -> addPixmap(t -> getImage());
	}
}

