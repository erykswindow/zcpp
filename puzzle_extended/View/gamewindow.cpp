#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent, GameViewController *_viewController) :
	QMainWindow(parent),
	ui(new Ui::GameWindow),
	viewController(_viewController)
{
	ui->setupUi(this);

	scene = new QGraphicsScene();

	connect(ui -> okButton, SIGNAL(clicked()),
			this, SLOT(on_okButton_clicked()));

	connect(ui -> startButton, SIGNAL(clicked()),
			this, SLOT(on_startButton_clicked()));

	ui -> graphicsView -> setScene(scene);
	viewController -> setScene(scene);
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

void GameWindow::on_okButton_clicked() {

}

void GameWindow::on_startButton_clicked() {
	viewController -> start();
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

void GameWindow::show() {
	QMainWindow::show();
	QSize size = {
		ui -> graphicsView -> width(),
		ui -> graphicsView -> height()
	};
	viewController -> setScreenSize(size);
}


