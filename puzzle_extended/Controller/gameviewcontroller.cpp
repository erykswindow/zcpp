#include <cmath>
#include <QFileDialog>
#include <QTranslator>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "gameviewcontroller.h"

//Constructors & Destructors
GameViewController::GameViewController(Image _image, int _h, int _v) {
	imageProcessor = new ImageProcessor;
	stateController = new GameStateController(_h, _v);
	images = imageProcessor -> divideImage(_image, _h, _v);
}

GameViewController::GameViewController(Image _image) {
	stateController = new GameStateController();
	imageProcessor = new ImageProcessor;
	int height = stateController -> getGame() -> board -> height;
	int width = stateController -> getGame() -> board -> width;
	images = imageProcessor -> divideImage(_image, width, height);
}

GameViewController::~GameViewController() {
	delete stateController;
	delete imageProcessor;
}

//Public methods
void GameViewController::setScene(QGraphicsScene *_scene) {
	this -> scene = _scene;
	redraw();
}

void GameViewController::setScreenSize(QSize _size) {
	this -> screenSize = _size;
	redraw();
}

void GameViewController::start() {
	stateController -> startGame();
	redraw();
	updateHandler -> update();
}

void GameViewController::handleSave() {
	stateController -> generateSavefile();
}

void GameViewController::incrementTimer() {
	stateController -> incrementTimer();
	updateHandler -> update();
}

int GameViewController::getCurrentMoves() {
	return stateController -> currentState().moves;
}

int GameViewController::getCurrentTime() {
	return stateController -> currentState().time;
}

bool GameViewController::currentGameStatus() {
	return !(stateController -> currentState().time > 0);
}

void GameViewController::setUpdateHandler(Updateable* _handler) {
	updateHandler = _handler;
}

void GameViewController::handleClick(QPoint pos) {
	Board *board = stateController -> getGame() -> board;
	double width = screenSize.width();
	double height = screenSize.height();
	double verticalStep = double(height)/(double)(board -> height);
	double horizontalStep = double(width)/(double)(board -> width);

	int h = floor((double)pos.x()/horizontalStep);
	int v = floor((double)pos.y()/verticalStep);

	Location<int> loc = { h, v };
	stateController -> moveIfPossible(loc);
	redraw();
	updateHandler -> update();
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
	updateHandler -> update();
}

//Private methods
void GameViewController::resetItems() {
	for (std::vector<QGraphicsItem *>::iterator i = currentItems.begin(); i != currentItems.end(); i++) {
		scene -> removeItem(*i);
		delete *i;
	}

	std::vector<QGraphicsItem *> v;
	currentItems = v;
}

void GameViewController::redraw() {
	Location<double> spacing = { 2.0, 2.0 };

	resetItems();
	Board *board = stateController -> getGame() -> board;
	std::vector<Tile *> tiles = board -> tiles;

	double width = screenSize.width();
	double height = screenSize.height();

	if (!(width > 0.0 && height > 0.0)) {
		return;
	}

	double verticalStep = double(height)/(double)(board -> height) - spacing.vertical/2.0;
	double horizontalStep = double(width)/(double)(board -> width)  - spacing.horizontal/2.0;

	for (std::vector<Tile *>::iterator iter = tiles.begin(); iter != tiles.end(); iter++) {
		Tile *tile = *iter;


		Location<int> loc = tile -> getLocation();
		Location<int> imageLoc = tile -> getDesiredLocation();

		Image image = images[imageLoc.vertical][imageLoc.horizontal].scaled(horizontalStep, verticalStep);

		if (tile -> isEmpty) {
			QColor color = QColor(0, 0, 0);
			image.fill(color);
		}

		QGraphicsPixmapItem *item = scene -> addPixmap(image);
		item -> setPos(loc.horizontal * (horizontalStep + spacing.horizontal/2.0),
					   loc.vertical * verticalStep + spacing.vertical/2.0);
		currentItems.push_back(item);
	}
}
