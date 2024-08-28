#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>
#include <numeric>
#include <chrono>

// Однопотокова реалізація QuickSort
void quickSortSingleThread(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;

    int pivot = vec[right];
    int partitionIndex = left;

    for (int i = left; i < right; ++i) {
        if (vec[i] <= pivot) {
            std::swap(vec[i], vec[partitionIndex]);
            ++partitionIndex;
        }
    }
    std::swap(vec[partitionIndex], vec[right]);

    quickSortSingleThread(vec, left, partitionIndex - 1);
    quickSortSingleThread(vec, partitionIndex + 1, right);
}

// Багатопотокова реалізація QuickSort
void quickSortMultiThread(std::vector<int>& vec, int left, int right, int depth) {
    if (left >= right) return;

    int pivot = vec[right];
    int partitionIndex = left;

    for (int i = left; i < right; ++i) {
        if (vec[i] <= pivot) {
            std::swap(vec[i], vec[partitionIndex]);
            ++partitionIndex;
        }
    }
    std::swap(vec[partitionIndex], vec[right]);

    if (depth > 0) {
        auto future = std::async(std::launch::async, quickSortMultiThread, std::ref(vec), left, partitionIndex - 1, depth - 1);
        quickSortMultiThread(vec, partitionIndex + 1, right, depth - 1);
        future.get();
    }
    else {
        quickSortSingleThread(vec, left, partitionIndex - 1);
        quickSortSingleThread(vec, partitionIndex + 1, right);
    }
}

// Функція, що вимірює час виконання сортування
double measureTime(std::vector<int>& vec, int numThreads) {
    auto start = std::chrono::high_resolution_clock::now();
    int depth = std::log2(numThreads);

    if (numThreads == 1) {
        quickSortSingleThread(vec, 0, vec.size() - 1);
    }
    else {
        quickSortMultiThread(vec, 0, vec.size() - 1, depth);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

int main() {
    std::vector<int> vecSizes = { 1000, 10000, 100000, 1000000 };  // різні розміри векторів для тестів
    int hardwareThreads = std::thread::hardware_concurrency();

    for (auto size : vecSizes) {
        std::vector<int> vec(size);
        std::iota(vec.begin(), vec.end(), 1);
        std::random_shuffle(vec.begin(), vec.end());

        std::vector<int> vec1 = vec, vec2 = vec, vec3 = vec, vec4 = vec;

        double time1 = measureTime(vec1, 1);
        double time2 = measureTime(vec2, 2);
        double time3 = measureTime(vec3, hardwareThreads);
        double time4 = measureTime(vec4, 2 * hardwareThreads);

        std::cout << "Vector size: " << size << '\n';
        std::cout << "1 thread: " << time1 << " s\n";
        std::cout << "2 threads: " << time2 << " s\n";
        std::cout << hardwareThreads << " threads: " << time3 << " s\n";
        std::cout << 2 * hardwareThreads << " threads: " << time4 << " s\n";
        std::cout << "----------------------------------\n";
    }

    return 0;
}
