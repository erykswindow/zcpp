#ifndef VIEW_H
#define VIEW_H

#import <QRect>
#include <vector>

class View
{
public:
	QRect frame;
	std::vector<View *> subviews;

public:
	View(QRect _frame);

public:
	void setFrame(QRect _frame);
	virtual void draw(QRect _rect);
	void addSubview(View* );
};

#endif // VIEW_H
