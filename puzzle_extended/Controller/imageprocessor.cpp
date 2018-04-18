#include "imageprocessor.hpp"

std::vector<std::vector<Image>> ImageProcessor::divideImage(Image input, int height, int width) {
    int heightPart = input.height()/height;
    int widthPart = input.width()/width;

    std::vector<std::vector<Image>> heightVector (height);

    for (int h = 0; h < height; h++) {

        std::vector<Image> widthVector (width);

        for (int w = 0; w < width; w++) {
			QRect rect = QRect(w * widthPart,
							   h * heightPart,
							   widthPart,
							   heightPart);

            widthVector[w] = input.copy(rect);
        }
        heightVector[h] = widthVector;
    }
    return heightVector;
}
