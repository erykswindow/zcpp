#include "gamebegindialog.h"

GameBeginDialog::GameBeginDialog() { }


void GameBeginDialog::setDefaultImage() {
	QString filename(":/defaultImage.jpg");
	Image image = Image(filename);
	setImage(image);
}

void GameBeginDialog::setImage(Image _image) {
	currentImage = _image;
	QList<QGraphicsItem *> items = scene -> items();
	QList<QGraphicsItem *>::iterator i;
	for (i = items.begin(); i != items.end(); i++) {
		QGraphicsItem *item = *i;
		scene -> removeItem(item);
	 }
//
	drawCurrentImage();
}
