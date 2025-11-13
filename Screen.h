#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Vector3.h"

class Screen
{
public:
	Screen(int width, int height);
	void save_pixel(int x, int y, const Vector3& pixel);
	void save_render(const std::string& path);
	int width() const { return this->width_; }
	int height() const { return this->height_; }
private:
	const double max_rgb_value = 255.0;
	std::vector<Vector3> pixels;
	int width_;
	int height_;
};
