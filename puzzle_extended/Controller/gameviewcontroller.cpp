#include <cmath>
#include <QFileDialog>
#include <QTranslator>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "gameviewcontroller.h"

//Constructors & Destructors
GameViewController::GameViewController(Image _image, int _h, int _v) {
	stateController = new GameStateController(_image, _h, _v);
}

GameViewController::~GameViewController() {
	delete stateController;
}

//Public methods

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

void GameViewController::handleSave() {
	std::cout << stateController -> generateSavefile();
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

void GameViewController::handleKeboard(QKeyEvent *event) {
	switch (event -> key()) {
	case Qt::Key_Up:
	case Qt::Key_W:
		stateController -> moveIfPossible(down);
		break;
	case Qt::Key_Down:
	case Qt::Key_S:
		stateController -> moveIfPossible(up);
		break;
	case Qt::Key_Left:
	case Qt::Key_A:
		stateController -> moveIfPossible(right);
		break;
	case Qt::Key_Right:
	case Qt::Key_D:
		stateController -> moveIfPossible(left);
		break;
	default:
		return;
	}
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
		item -> setPos(tile -> getLocation().horizontal * (horizontalStep + spacing.horizontal/2.0),
					   tile -> getLocation().vertical * verticalStep + spacing.vertical/2.0);
		_currentItems.push_back(item);
	}
}
