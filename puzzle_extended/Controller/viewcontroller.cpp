#include "viewcontroller.h"

ViewController::ViewController() {
	view  = new View(QRect(0, 0, 0, 0));
}

void ViewController::presentView(QRect _rect) {
	view -> draw(_rect);
}

void ViewController::updateView(QRect _rect) {
	presentView(_rect);
}
