#include "Screen.h"

Screen::Screen(int width, int height) :width_(width), height_(height)
{
    // We use resize because if we use save_renderer before saving a pixel, we will have default values
    pixels.resize(width * height);
}

void Screen::save_pixel(int x, int y, const Vector3& pixel)
{
    assert(x < width_ && "x coordinate out of bounds");
    assert(y < height_ && "y coordinate out of bounds");
    assert(x >= 0 && "x coordinate must be positive");
    assert(y >= 0 && "y coordinate must be positive");

    pixels[x + width_ * y] = pixel;
}

void Screen::save_render(const std::string& path)
{
    constexpr int max_rgb_value = 255;
    constexpr double max_rgb_double = 255.999; 

    std::ofstream render(path);
    render << "P3\n";
    render << width_ << " " << height_ << "\n";
    render << max_rgb_value << "\n";

    for (const Vector3& pixel : pixels)
    {
        render << static_cast<int>(max_rgb_double * pixel.x()) << " "
            << static_cast<int>(max_rgb_double * pixel.y()) << " "
            << static_cast<int>(max_rgb_double * pixel.z()) << "\n";
    }
    render.close();
}
