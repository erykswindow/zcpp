#ifndef IMAGEPROCESSOR_HPP
#define IMAGEPROCESSOR_HPP

#include "../Model/image.hpp"
#include <iostream>

class ImageProcessor {

public:
    std::vector<std::vector<Image>> divideImage(Image, int, int);

};

#endif // IMAGEPROCESSOR_HPP
