#ifndef ARRAYMODIFICATIONS_HPP
#define ARRAYMODIFICATIONS_HPP
#include <iostream>
#include <cmath>
#include <chrono>
#include "IntroSort.hpp"

namespace {
  int getMaxDepth(int n)
  {
    return (int) (std::log(n) * 2);
  }

  template< class T >
  bool isSorted(T* array, int size)
  {
    for (int i = 0; i < size - 1; i++) {
      if (array[i] > array[i + 1]) {
        return false;
      }
    }
    return true;
  }
}

namespace kuznetsov {
  void fillWorstArray(int* array, int size)
  {
    array[0] = std::rand() % 100;
    for (int i = 1; i <= size; i++) {
      array[i] = array[i - 1] + std::rand() % 100;
    }
  }

  void fillBestArray(int* array, int size)
  {
    array[0] = std::rand() % 1000;
    for (int i = 1; i <= size; i++) {
      array[i] = array[i - 1] - std::rand() % 10;
    }
  }

  void fillRandomArray(int* array, int size)
  {
    for (int i = 0; i <= size; i++) {
      array[i] = std::rand() % 100;
    }
  }

  void checkArray(void (* fill)(int*, int))
  {
    for (int i = 100000; i < 100000000; i += 10000000) {
      int* arr = new int[i];
      fill(arr, i);
      std::cout << std::endl;
      auto startTime = std::chrono::high_resolution_clock::now();
      kuznetsov::introSort(arr, 0, i, getMaxDepth(i), 16);
      auto endTime = std::chrono::high_resolution_clock::now();
      std::chrono::duration< float > time = endTime - startTime;
      if (isSorted(arr, i)) {
        std::cout << time.count() << '\n';
      } else {
        std::cerr << "Error! Array isn't sorted!";
      }
    }
  }
}
#endif