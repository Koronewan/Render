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
    Vector3 origin(0, 0, 1);
    Sphere sphere(0.5, Vector3(0, 0, -1));
    double aspect_ratio = static_cast<double>(WIDTH) / HEIGHT;
    double virtual_screen_height = 2.0;
    double virtual_screen_width = aspect_ratio * virtual_screen_height;

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {

            // Debemos transformar las coordenadas de la pantalla a las coordenadas de una pantalla virtual
            double x_norm = static_cast<double>(x) / (WIDTH - 1);
            double y_norm = static_cast<double>(y) / (HEIGHT - 1);

            double virtual_x = (x_norm - 0.5) * virtual_screen_width;
            double virtual_y = (y_norm - 0.5) * virtual_screen_height;

            Vector3 virtual_point(virtual_x, virtual_y, 0);
            Vector3 direction = virtual_point - origin;

            Ray ray(origin, direction);

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
