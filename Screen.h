#pragma once
#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "Vector3.h"

class Screen
{
public:
	Screen(int width, int height);
	void save_pixel(int x, int y, const Vector3& pixel);
	void save_render(const std::string& path);
	inline int width() const { return width_; }
	inline int height() const { return height_; }
private:
	std::vector<Vector3> pixels;
	int width_;
	int height_;
};
