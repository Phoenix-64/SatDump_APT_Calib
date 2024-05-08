#pragma once

#include "image.h"

namespace image2
{
    void white_balance(Image &img, float percentileValue = 0.05f); // While balance algorithm from Gimp
    void median_blur(Image &img);                                  // Median blur algorithm
    void equalize(Image &img, bool per_channel = false);           // Perform histogram equalization
    void normalize(Image &img);                                    // Normalize the current image data. This takes the current min and max values and extends it to the full bit depth range
    void linear_invert(Image &img);                                // Invert the entire image
}