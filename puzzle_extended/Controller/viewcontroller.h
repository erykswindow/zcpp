#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H

#import "View/view.h"

class ViewController
{	
protected:
	View *view;

public:
	ViewController();

public:
	void presentView(QRect _rect);
	void updateView(QRect _rect);
};

#endif // VIEWCONTROLLER_H
