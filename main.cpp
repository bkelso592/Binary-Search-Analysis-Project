#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Recursive Binary Search
int recursiveBinarySearch(const std::vector<int>& data, int left, int right, int target) {
    if (left > right) {
        return -1; // Target not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (data[mid] == target) {
        return mid; // Target found
    } else if (data[mid] > target) {
        return recursiveBinarySearch(data, left, mid - 1, target);
    } else {
        return recursiveBinarySearch(data, mid + 1, right, target);
    }
}

// Iterative Binary Search
int iterativeBinarySearch(const std::vector<int>& data, int target) {
    int left = 0;
    int right = data.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (data[mid] == target) {
            return mid; // Target found
        } else if (data[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return -1; // Target not found
}

// Sequential Search
int sequentialSearch(const std::vector<int>& data, int target) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            return i; // Target found
        }
    }
    
    return -1; // Target not found
}

int main() {
    // Seed for random number generation
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Generate a vector with random values in the range 1 to 100
    std::vector<int> data;
    for (int i = 0; i < 10; ++i) { // A small vector for testing
        data.push_back(1 + std::rand() % 100);
    }
    
    // Sort the vector for binary searches
    std::sort(data.begin(), data.end());

    // Randomly select a target value in the range 1 to 100
    int target = 1 + std::rand() % 100;

    // Output vector contents
    std::cout << "Vector contents: ";
    for (int item : data) {
        std::cout << item << " ";
    }
    std::cout << "\nTarget: " << target << "\n";

    // Recursive Binary Search
    int index = recursiveBinarySearch(data, 0, data.size() - 1, target);
    if (index != -1) {
        std::cout << "Target " << target << " found at location " << index << " (Recursive Binary Search)\n";
    } else {
        std::cout << "Target " << target << " was not found (Recursive Binary Search)\n";
    }

    // Iterative Binary Search
    index = iterativeBinarySearch(data, target);
    if (index != -1) {
        std::cout << "Target " << target << " found at location " << index << " (Iterative Binary Search)\n";
    } else {
        std::cout << "Target " << target << " was not found (Iterative Binary Search)\n";
    }

    // Sequential Search
    index = sequentialSearch(data, target);
    if (index != -1) {
        std::cout << "Target " << target << " found at location " << index << " (Sequential Search)\n";
    } else {
        std::cout << "Target " << target << " was not found (Sequential Search)\n";
    }

    return 0;
}
