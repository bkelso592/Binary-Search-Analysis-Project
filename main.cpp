#include <iostream>
#include <vector>
#include <algorithm>

// Recursive Binary Search
int recursiveBinarySearch(const std::vector<int>& data, int left, int right, int target) {
    if (left > right) {
        return -1; // Target not found
    }

    int mid = left + (right - left) / 2;

    if (data[mid] == target) {
        return mid; // Target found
    }
    else if (data[mid] > target) {
        return recursiveBinarySearch(data, left, mid - 1, target);
    }
    else {
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
        }
        else if (data[mid] > target) {
            right = mid - 1;
        }
        else {
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
    // Initialize vector with test data
    std::vector<int> data = { 45, 12, 25, 30, 18, 33, 50 };

    // Sort the vector for binary search algorithms
    std::sort(data.begin(), data.end());

    // Define targets
    int target1 = 25;  // Item that is in the list
    int target2 = 99;  // Item that is not in the list

    // Output vector contents
    std::cout << "Vector contents: ";
    for (int item : data) {
        std::cout << item << " ";
    }
    std::cout << "\n";

    // Recursive Binary Search
    int index = recursiveBinarySearch(data, 0, data.size() - 1, target1);
    if (index != -1) {
        std::cout << "Target " << target1 << " found at location " << index << " (Recursive Binary Search)\n";
    }
    else {
        std::cout << "Target " << target1 << " was not found, return value is " << index << " (Recursive Binary Search)\n";
    }

    index = recursiveBinarySearch(data, 0, data.size() - 1, target2);
    if (index != -1) {
        std::cout << "Target " << target2 << " found at location " << index << " (Recursive Binary Search)\n";
    }
    else {
        std::cout << "Target " << target2 << " was not found, return value is " << index << " (Recursive Binary Search)\n";
    }

    // Iterative Binary Search
    index = iterativeBinarySearch(data, target1);
    if (index != -1) {
        std::cout << "Target " << target1 << " found at location " << index << " (Iterative Binary Search)\n";
    }
    else {
        std::cout << "Target " << target1 << " was not found, return value is " << index << " (Iterative Binary Search)\n";
    }

    index = iterativeBinarySearch(data, target2);
    if (index != -1) {
        std::cout << "Target " << target2 << " found at location " << index << " (Iterative Binary Search)\n";
    }
    else {
        std::cout << "Target " << target2 << " was not found, return value is " << index << " (Iterative Binary Search)\n";
    }

    // Sequential Search
    index = sequentialSearch(data, target1);
    if (index != -1) {
        std::cout << "Target " << target1 << " found at location " << index << " (Sequential Search)\n";
    }
    else {
        std::cout << "Target " << target1 << " was not found, return value is " << index << " (Sequential Search)\n";
    }

    index = sequentialSearch(data, target2);
    if (index != -1) {
        std::cout << "Target " << target2 << " found at location " << index << " (Sequential Search)\n";
    }
    else {
        std::cout << "Target " << target2 << " was not found, return value is " << index << " (Sequential Search)\n";
    }

    return 0;
}