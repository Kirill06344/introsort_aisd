#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP
#include <utility>
namespace kuznetsov {

  template <typename T>
  void insertionSort(T * arr, int l, int r)
  {
    for (int i = l + 1; i < r; ++i) {
      int j = i - 1;
      while (j >= l && arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        j--;
      }
    }
  }

}

#endif