#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent, GameViewController *_viewController) :
	QMainWindow(parent),
	ui(new Ui::GameWindow),
	viewController(_viewController)
{
	ui->setupUi(this);

	scene = new QGraphicsScene();

	connect(ui -> saveButton, SIGNAL(clicked()),
			this, SLOT(on_saveButton_clicked()));

	connect(ui -> startButton, SIGNAL(clicked()),
			this, SLOT(on_startButton_clicked()));

	ui -> graphicsView -> setScene(scene);
	viewController -> setScene(scene);
	viewController -> setUpdateHandler(this);
	setFocusPolicy(Qt::ClickFocus);
	this -> setAttribute(Qt::WA_DeleteOnClose);
	this -> grabKeyboard();

}

GameWindow::~GameWindow()
{
	delete ui;
	delete scene;
	delete viewController;
}

void GameWindow::on_saveButton_clicked() {
	viewController -> handleSave();
}

void GameWindow::on_startButton_clicked() {
	viewController -> start();
	resumeGame();
}

void GameWindow::resumeGame() {
	if (timerId != 0) this -> killTimer(timerId);
	timerId = this -> startTimer(1000);
}

void GameWindow::resizeEvent(QResizeEvent *_event) {
	QMainWindow::resizeEvent(_event);
	QSize size = {
		ui -> graphicsView -> width(),
		ui -> graphicsView -> height()
	};

	viewController -> setScreenSize(size);
}

void GameWindow::mousePressEvent(QMouseEvent *event) {
	QPoint pos = event -> globalPos();
	QPoint nPos = ui -> graphicsView -> mapFromGlobal(pos);
	viewController -> handleClick(nPos);
}

void GameWindow::keyPressEvent(QKeyEvent *event) {
	QMainWindow::keyPressEvent(event);
	viewController -> handleKeboard(event);
}

void GameWindow::timerEvent(QTimerEvent *event) {
	viewController -> incrementTimer();
}

void GameWindow::update() {
	QString time = QString::fromStdString(std::to_string(viewController -> getCurrentTime()));
	QString moves = QString::fromStdString(std::to_string(viewController -> getCurrentMoves()));
	ui -> timeValueLabel -> setText(time);
	ui -> movesValueLabel -> setText(moves);
	ui -> startButton -> setEnabled(viewController -> currentGameStatus());
	ui -> saveButton -> setEnabled(!(viewController -> currentGameStatus()));
}

void GameWindow::show() {
	QMainWindow::show();
	QSize size = {
		ui -> graphicsView -> width(),
		ui -> graphicsView -> height()
	};
	viewController -> setScreenSize(size);
}


