#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "Vector3.h"
#include "Screen.h"

constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;

void render_image(int width, int height, std::vector<Vector3> &pixels_rgb_values)
{
    const double z_value = 0.5;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Vector3 rgb_value((float)x / (width - 1), (float)y / (height - 1), z_value);
            pixels_rgb_values[y * width + x] = rgb_value;
        }
    }
}

int main(int argc, char* argv[])
{
    auto start = std::chrono::high_resolution_clock::now();

    std::string path = argv[1];
    std::vector<Vector3> pixels_rgb_values(HEIGHT * WIDTH);
    Screen screen(WIDTH, HEIGHT);
    render_image(WIDTH, HEIGHT, pixels_rgb_values);
    screen.save_render(path, pixels_rgb_values);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "s\n";
}
