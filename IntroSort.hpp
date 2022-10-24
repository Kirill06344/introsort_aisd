#ifndef INTROSORT_H
#define INTROSORT_H

#include "HeapSort.hpp"
#include "PartitionSort.hpp"
#include "insertionSort.hpp"


namespace kuznetsov {

  template< typename T >
  void introSort(T * arr, int l, int r, int maxDepth, int mihLength) {
    if (r - l + 1 < mihLength) {
      insertionSort(arr, l, r);
    } else if (maxDepth == 0) {
      heapSort(arr, l, r);
    } else {
      if (l + 1 >= r) {
        return;
      }
      int pivot = randomPartition(arr, l, r);
      introSort(arr, l, pivot, maxDepth - 1, mihLength);
      introSort(arr, pivot + 1, r, maxDepth - 1, mihLength);
    }
  }
}

#endif
