#include "view.h"

View::View(QRect _frame): frame(_frame) {}

void View::draw(QRect _rect) {
	for(int i = 0; i < subviews.size(); i++) {
		subviews[i] -> draw(_rect);
	}
}
void View::setFrame(QRect _frame) {
	frame = _frame;
}

void View::addSubview(View *_subview) {
	subviews.push_back(_subview);
}
