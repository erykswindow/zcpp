#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent, GameViewController *_viewController) :
	QWidget(parent),
	ui(new Ui::GameWidget),
	viewController(_viewController)
{
	ui -> setupUi(this);
	viewController -> setViewRect(rect());
}

GameWidget::~GameWidget()
{
	delete ui;
}

void GameWidget::show()
{
	QWidget::show();
	viewController -> updateView(rect());
}
