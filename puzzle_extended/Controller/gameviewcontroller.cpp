#include <QFileDialog>
#include <QTranslator>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "gameviewcontroller.h"
#include "Model/tile.hpp"
#include <cmath>

//COnstructors & Destructors
GameViewController::GameViewController() {
	stateController = new GameStateController();
}

//Public methods
void GameViewController::readInput(QWidget *widget) {
	QFileDialog *dialog = new QFileDialog(widget, Qt::Drawer);
	dialog -> setAcceptMode(QFileDialog::AcceptOpen);
	dialog -> selectNameFilter(dialog -> tr("Image (*.png, *.jpg, *.jpeg"));
	QString filename = dialog -> getOpenFileName(widget);

	Image image = Image(filename);

	stateController -> setupGameWithImage(image);

	delete dialog;
}

void GameViewController::setScene(QGraphicsScene *_scene) {
	this -> _scene = _scene;
	redraw();
}

void GameViewController::setScreenSize(QSize _size) {
	this -> _screenSize = _size;
	redraw();
}

void GameViewController::start() {
	stateController -> startGame();
	redraw();
}

void GameViewController::handleClick(QPoint pos) {
	Board *board = stateController -> getGame() -> board;
	double width = _screenSize.width();
	double height = _screenSize.height();
	double verticalStep = double(height)/(double)(board -> height);
	double horizontalStep = double(width)/(double)(board -> width);

	int h = floor((double)pos.x()/horizontalStep);
	int v = floor((double)pos.y()/verticalStep);

	Location<int> loc = { h, v };
	stateController -> moveIfPossible(loc);
	redraw();
}

//Private methods
void GameViewController::resetItems() {
	for (std::vector<QGraphicsItem *>::iterator i = _currentItems.begin(); i != _currentItems.end(); i++) {
		_scene -> removeItem(*i);
		delete *i;
	}

	std::vector<QGraphicsItem *> v;
	_currentItems = v;
}

void GameViewController::redraw() {
	Location<double> spacing = { 2.0, 2.0 };

	resetItems();
	Board *board = stateController -> getGame() -> board;
	std::vector<Tile *> tiles = board -> tiles;

	for (std::vector<Tile *>::iterator iter = tiles.begin(); iter != tiles.end(); iter++) {
		Tile *tile = *iter;
		double width = _screenSize.width();
		double height = _screenSize.height();
		double verticalStep = double(height)/(double)(board -> height) - spacing.vertical/2.0;
		double horizontalStep = double(width)/(double)(board -> width)  - spacing.horizontal/2.0;

		Image image = tile -> getImage().scaled(horizontalStep, verticalStep);

		if (tile -> isEmpty) {
			QColor color = QColor(0, 0, 0);
			image.fill(color);
		}

		QGraphicsPixmapItem *item = _scene -> addPixmap(image);
		item -> setPos(tile -> getLocation().horizontal * (horizontalStep + spacing.horizontal),
					   tile -> getLocation().vertical * verticalStep + spacing.vertical);
		_currentItems.push_back(item);
	}
}
