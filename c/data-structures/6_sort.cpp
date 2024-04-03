#include "utils.h"

// Merge Sort Implementation
// get_slice returns a slice of an array from start to end
int* get_slice(int arr[], int start, int end) {
  int *slice = new int[end - start + 1];

  for (int i = start; i <= end; i++) {
    slice[i - start] = arr[i];
  }

  return slice;
}

// merge merges two arrays into one
void merge(int arr[], int start, int mid, int end) {
  int left_len = mid - start + 1;
  int right_len = end - mid;

  int *left = get_slice(arr, start, mid);
  int *right = get_slice(arr, mid + 1, end);

  int l_index = 0;
  int r_index = 0;
  int arr_index = start;
 
  // Merge the left and right arrays  
  while (l_index < left_len && r_index < right_len) {
    int left_int = left[l_index];
    int right_int = right[r_index];

    if (left_int <= right_int) {
      arr[arr_index] = left_int;
      l_index++;
    } else {
      arr[arr_index] = right_int;
      r_index++;
    }

    arr_index++;
  }

  // Copy the remaining elements of left
  while (l_index < left_len) {
    arr[arr_index] = left[l_index];
    l_index++;
    arr_index++;
  }

  // Copy the remaining elements of right
  while (r_index < right_len) {
    arr[arr_index] = right[r_index];
    r_index++;
    arr_index++;
  }

  delete[] left;
  delete[] right;
}

void merge_sort(int arr[], int start, int end) {
  if (start >= end) return;

  int mid = start + (end - start) / 2;

  merge_sort(arr, start, mid);
  merge_sort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}

// Quicksort Implementation
void quick_sort(int arr[], int start, int end) {
  if (start >= end) return;

  int pivot = arr[start];
  int l_index = start + 1;
  int r_index = end;

  // Partition the array
  while (l_index <= r_index) {
    int &left_int = arr[l_index];
    int &right_int = arr[r_index];

    if (left_int > pivot && right_int < pivot) {
      swap(left_int, right_int);
    }

    if (left_int <= pivot) {
      l_index++;
    }

    if (right_int >= pivot) {
      r_index--;
    }
  }

  swap(arr[start], arr[r_index]);

  quick_sort(arr, start, r_index - 1);
  quick_sort(arr, r_index + 1, end);
}

// Heap Sort Implementation
void heapify(int arr[], int len, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < len && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < len && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, len, largest);
  }
}

void heap_sort(int arr[], int len) {
  // Build the heap
  for (int i = len / 2 - 1; i >= 0; i--) {
    heapify(arr, len, i);
  }

  // Extract elements from the heap
  for (int i = len - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {5, 2, 3, 1, 4};
  merge_sort(arr, 0, 4);
  print_arr("Sorted array with merge sort", arr, 5);

  int arr_2[] = {5, 2, 3, 1, 4};
  quick_sort(arr_2, 0, 4);
  print_arr("Sorted array with quick sort", arr_2, 5);

  int arr_3[] = {5, 2, 3, 1, 4};
  heap_sort(arr_3, 5);
  print_arr("Sorted array with heap sort", arr_3, 5);

  return 0;
}