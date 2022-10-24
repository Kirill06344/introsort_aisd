#ifndef PARTITIONSORT_HPP
#define PARTITIONSORT_HPP

#include <cstdlib>
#include <utility>

namespace {
  template< typename T >
  int partition(T* arr, int l, int r)
  {
    int pivot = arr[l];
    int i = l;
    for (int j = l + 1; j < r; ++j) {
      if (arr[j] <= pivot) {
        std::swap(arr[++i], arr[j]);
      }
    }
    std::swap(arr[i], arr[l]);
    return i;
  }
}

namespace kuznetsov {

  template< typename T >
  int randomPartition(T* arr, int l, int r)
  {
    int i = std::rand() % (r - l) + l;
    std::swap(arr[l], arr[i]);
    return partition(arr, l, r);
  }
}
#endif
