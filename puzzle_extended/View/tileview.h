#ifndef TILEVIEW_H
#define TILEVIEW_H
#import "view.h"
#import "Model/tile.hpp"

class TileView: public View {
public:
	Tile *tile;

public:
	TileView(Tile*, QRect);
};

#endif // TILEVIEW_H
