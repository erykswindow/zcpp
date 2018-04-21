#include "imageprocessor.hpp"

ImageMatrix ImageProcessor::divideImage(Image input, int width, int height) {
	int widthPart = input.width()/width;
	int heightPart = input.height()/height;

	ImageMatrix columns (height);

	for (int v = 0; v < height; v++) {
		std::vector<Image> row (width);
		 for (int h = 0; h < width; h++) {
			QRect rect = QRect(h * widthPart,
							   v * heightPart,
							   widthPart,
							   heightPart);

			row[h] = input.copy(rect);
        }
		columns[v] = row;
    }
	return columns;
}
