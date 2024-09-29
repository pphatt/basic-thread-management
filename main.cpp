#include <iostream>
#include <thread>
#include <vector>

void threadFunction(int id, int numIterations) {
    for (int i = 0; i < numIterations; ++i) {
        std::cout << "Thread " << id << " is running iteration " << i + 1 << std::endl;
    }
}

int main() {
    const int numThreads = 5;
    const int numIterations = 3;

    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(threadFunction, i + 1, numIterations);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All threads have finished execution." << std::endl;

    return 0;
}
