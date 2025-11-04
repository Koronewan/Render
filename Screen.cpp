#include "Screen.h"

void Screen::save_render(const std::string& path, const std::vector<Vector3>& pixels_rgb_values)
{
    const double max_rgb_value = 255.0;
    std::ofstream render(path);
    render << "P3\n";
    render << width << " " << height << "\n";
    render << max_rgb_value << "\n";

    for (const Vector3& value : pixels_rgb_values)
    {
        render << (value * max_rgb_value) << "\n";
    }

    render.close();
}
