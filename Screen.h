#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Vector3.h"

class Screen
{
public:
	Screen(int width, int height) : width(width), height(height) { };
	void save_render(const std::string& path, const std::vector<Vector3>& pixels_rgb_values);
private:
	int width;
	int height;
};
