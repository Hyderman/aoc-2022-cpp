#include "main.hpp"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <span>
#include <string>
#include <vector>

void swap(int32_t& x, int32_t& y) {
    int32_t tmp = x;
    x = y;
    y = tmp;
}

void bubble_sort(std::span<int32_t> arr) {
    size_t n = arr.size();
    bool swapped = false;
    for (size_t i = 0; i < n - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::ifstream file("input", std::ios::in);
    std::vector<int32_t> elves_calories;
    std::string line;
    if (file) {
        int sum = 0;
        while (std::getline(file, line)) {
            if (line.empty()) {
                elves_calories.push_back(sum);
                sum = 0;
            } else {
                sum += std::stoi(line);
            }
        }
    } else {
        std::cout << "Can't read file";
    }
    file.close();
    bubble_sort(elves_calories);
    std::cout << elves_calories.back() << std::endl;
    size_t nb_elves = elves_calories.size();
    int32_t three_last = 0;
    for (size_t i = nb_elves - 1; i > nb_elves - 4; --i) {
        std::cout << elves_calories[i] << " ";
        three_last += elves_calories[i];
    }
    std::cout << "Total three elves with the most calories is: " << three_last;
}
