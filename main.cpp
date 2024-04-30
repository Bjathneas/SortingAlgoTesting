#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <limits.h>
#include <cstdlib>
#include <random>
#include <functional>
#include <unordered_map>

#include "Sort.hpp"
#include "Clock.hpp"

#define NUM_OF_ELEMENTS 10000
#define NUM_OF_INSTANCES 12

template<typename T>
void printArray(T arr[], std::size_t size) {
	printf("\n[");
	for(int i = 0; i < size; i++) {
		if(i < size-1) 
			printf("%i,", arr[i]);
		else
			printf("%i", arr[i]);
	}
	printf("]\n");
}

std::vector<int> generateRandomArray(int size) {
	std::vector<int> arr;
	for(int i = 0; i < size; i++) {
		arr.push_back((rand() % INT_MAX) - INT_MIN/2);
	}
	return arr;
}

std::vector<int> generateBasicArray() {
	std::vector<int> arr;
	for(int i = 0; i < 100; i++) {
		arr.push_back(i);
	}
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(arr), std::end(arr), rng);
	return arr;
}
template<typename T>
bool isSorted(T arr[], std::size_t size) {
	for(int i = 0; i < size - 2; i++) {
		if(arr[i] > arr[i+1]){
			printf("%f !> %f \n", arr[i], arr[i+1]);
			return false;
		}
	}
	return true;
}

double testAlgorithm(const char* name, std::function<void(int*, std::size_t)> algorithm) {
	std::vector<int> list = generateRandomArray(NUM_OF_ELEMENTS);
	Clock clock;
	algorithm(list.data(), list.size());
	double time = clock.getTime();
	if(!isSorted(list.data(), list.size())){
		printf("%s did not sort\n", name);
		printArray(list.data(), list.size());
		exit(EXIT_FAILURE);
	}
	printf("%s Time: %fms\n", name, time);
	return time;
}

std::unordered_map<double, const char*> avg_times;

void benchAlgorithm(const char* name, std::function<void(int*, std::size_t)> algorithm) {
	double times_total;

	for(int i = 0; i < NUM_OF_INSTANCES; i++) {
		times_total += testAlgorithm(name, algorithm);
	}
	printf("\n\t%s Avg. Time: %fms\n", name, times_total / NUM_OF_INSTANCES);
	avg_times[times_total / NUM_OF_INSTANCES] = name;
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	benchAlgorithm("SelectionSort", selectionSort<int>);
	benchAlgorithm("SelectionSortOptimized", selectionSortOptimized<int>);
	benchAlgorithm("BubbleSort", bubbleSort<int>);
	benchAlgorithm("BubbleSortOptimized", bubbleSortOptimized<int>);

	double min_time = INT_MAX;

	for(std::pair<double, const char*> pair : avg_times) {
		if(pair.first < min_time)
			min_time = pair.first;
	}

	printf("WINNER IS %s at %fms\n", avg_times[min_time], min_time);
	return EXIT_SUCCESS;

}
