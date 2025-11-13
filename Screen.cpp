#include "Screen.h"

Screen::Screen(int width, int height) :width_(width), height_(height)
{
    // We use resize because if we use save_renderer before saving a pixel, we will have default values
    this->pixels.resize(width * height);
}

void Screen::save_pixel(int x, int y, const Vector3& pixel)
{
    // TODO: is this necessary? adds load in critical function
    if (x >= this->width_ || y >= this->height_)
        throw std::out_of_range("save_pixel: index out of bounds");

    this->pixels[x + this->width_ * y] = pixel * this->max_rgb_value;
}

void Screen::save_render(const std::string& path)
{
    std::ofstream render(path);
    render << "P3\n";
    render << this->width_ << " " << this->height_ << "\n";
    render << this->max_rgb_value << "\n";

    for (const Vector3& pixel : this->pixels)
    {
        render << static_cast<int>(pixel.x()) << " " 
            << static_cast<int>(pixel.y()) << " " 
            << static_cast<int>(pixel.z()) << " " << "\n";
    }

    render.close();
}
