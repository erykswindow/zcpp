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
}

GameWindow::~GameWindow()
{
	delete ui;
	delete scene;
}

void GameWindow::on_okButton_clicked() {

}

void GameWindow::on_startButton_clicked() {
	viewController -> drawIn(this -> scene);
}
