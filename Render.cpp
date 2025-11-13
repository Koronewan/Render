#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "Vector3.h"
#include "Screen.h"

constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;

void render_image(int width, int height, Screen &screen)
{
    const double z_value = 0.5;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            Vector3 value((float)x / (width - 1), (float)y / (height - 1), z_value);
            screen.save_pixel(x, y, value);
        }
    }
}

int main(int argc, char* argv[])
{
    auto start = std::chrono::high_resolution_clock::now();

    std::string path = argv[1];
    Screen screen(WIDTH, HEIGHT);
    render_image(WIDTH, HEIGHT, screen);
    screen.save_render(path);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "s\n";
}
