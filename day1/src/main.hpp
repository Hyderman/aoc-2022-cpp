#pragma once

#include <cstdint>
#include <span>

void swap(int32_t& x, int32_t& y);

void bubble_sort(std::span<int32_t> arr);
