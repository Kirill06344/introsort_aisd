#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <utility>

namespace {

  template< typename T >
  void maxHeapify(T* arr, int i, int length, int leftElement)
  {
    int left = 2 * (i - leftElement) + 1 + leftElement;
    int right = 2 * (i - leftElement) + 2 + leftElement;
    int largest = i;
    if (left < length + leftElement && arr[left] > arr[i]) {
      largest = left;
    }

    if (right < length + leftElement && arr[right] > arr[largest]) {
      largest = right;
    }

    if (largest != i) {
      std::swap(arr[largest], arr[i]);
      maxHeapify(arr, largest, length, leftElement);
    }
  }

  template< typename T >
  void buildMaxHeap(T* arr, int l, int r)
  {
    for (int i = (l + r)/ 2; i >= l; --i) {
      maxHeapify(arr, i, r - l, l);
    }
  }
}

namespace kuznetsov {
  template< typename T >
  void heapSort(T* arr, int l, int r)
  {
    buildMaxHeap(arr, l, r);
    int length = r - l;
    for (int i = r - 1; i > l; --i) {
      std::swap(arr[l], arr[i]);
      --length;
      maxHeapify(arr, l, length, l);
    }
  }
}

#endif
