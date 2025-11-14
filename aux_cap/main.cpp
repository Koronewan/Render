#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "Vector3.h"
#include "Screen.h"
#include "Sphere.h"

constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;

int main(int argc, char* argv[])
{
    std::string path = argv[1];
    auto start = std::chrono::high_resolution_clock::now();

    Screen screen(WIDTH, HEIGHT);
    Vector3 origin(0, 0, 0);
    Sphere sphere(50.0, Vector3(500, 500, 0));

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            Vector3 unitary_target(static_cast<double>(x) / (WIDTH - 1), static_cast<double>(y) / (HEIGHT - 1), 0);
            Ray ray(origin, unitary_target);

            if (sphere.hit(ray))
            {
                screen.save_pixel(x, y, Vector3(1, 0, 0));
            }
            else
            {
                screen.save_pixel(x, y, Vector3(0, 0, 0));
            }
        }
    }

    screen.save_render(path);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::seconds>(stop - start);
    std::cout << "Time taken: " << duration.count() << "s\n";
}
