#include <cstdlib>
#include <algorithm>

template<typename T>
inline void selectionSort(T arr[], std::size_t size) {
	for(int i = size - 1; i > 0; i--) {
		int biggest_element_index = 0;
		//find biggest element index
		for(int j = 0; j <= i; j++) {
			if(arr[j] > arr[biggest_element_index])
				biggest_element_index = j;
		}
		if(biggest_element_index != i)
			std::swap(arr[biggest_element_index], arr[i]);
	}
}

template<typename T>
inline void selectionSortOptimized(T arr[], std::size_t size) {
	for(int i = 0, j = size - 1; i < j; i++, j--) {
		int min = arr[i], max = arr[i];
		int min_i = i, max_j = i;

		for(int k = i; k <= j; k++) {
			if(arr[k] > max) {
				max = arr[k];
				max_j = k;
			}else if(arr[k] < min) {
				min = arr[k];
				min_i = k;
			}
		}
		std::swap(arr[i], arr[min_i]);

		if(arr[min_i] == max)
			std::swap(arr[j], arr[min_i]);
		else
			std::swap(arr[j], arr[max_j]);
	}

}

template<typename T>
inline void bubbleSort(T arr[], std::size_t size) {
	for(int i = 0; i < size - 1; i++) {
		bool swapped = false;
		for(int j = 0; j < size - 1; j++) {
			if(arr[j] > arr[j+1]){
				std::swap(arr[j], arr[j+1]);
				swapped = true;		
			}
		}
		if(!swapped)
			break;
	}
}

template<typename T>
inline void bubbleSortOptimized(T arr[], std::size_t size) {
	for(int i = 0; i < size - 1; i++) {
		bool swapped = false;
		for(int j = 0; j < size - i - 1; j++) {
			if(arr[j] > arr[j+1]) {
				std::swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped)
			break;
	}
}
