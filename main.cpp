#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

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

int sequentialSearch(const std::vector<int>& data, int target) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            return i; // Target found
        }
    }
    
    return -1; // Target not found
}

int main() {
    int N = 5000; // Adjust this value for different test cases
    double SumRBS = 0.0;
    double SumIBS = 0.0;
    double SumSeqS = 0.0;

    std::srand(static_cast<unsigned int>(std::time(0)));

    // Run the test 10 times
    for (int i = 0; i < 10; ++i) {
        // Generate a vector with N random numbers between 1 and 100
        std::vector<int> data;
        for (int j = 0; j < N; ++j) {
            data.push_back(1 + std::rand() % 100);
        }
        
        // Sort the vector for binary searches
        std::sort(data.begin(), data.end());

        // Generate a random target in the range 1 to 100
        int target = 1 + std::rand() % 100;

        // Measure Recursive Binary Search
        auto start = std::chrono::high_resolution_clock::now();
        recursiveBinarySearch(data, 0, data.size() - 1, target);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> duration = end - start;
        SumRBS += static_cast<double>(duration.count());

        // Measure Iterative Binary Search
        start = std::chrono::high_resolution_clock::now();
        iterativeBinarySearch(data, target);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        SumIBS += static_cast<double>(duration.count());

        // Measure Sequential Search
        start = std::chrono::high_resolution_clock::now();
        sequentialSearch(data, target);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        SumSeqS += static_cast<double>(duration.count());
    }

    // Output average running times
    std::cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10 << "\n";
    std::cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10 << "\n";
    std::cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10 << "\n";

    return 0;
}
