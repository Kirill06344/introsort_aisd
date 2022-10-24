#include <iostream>
#include "ArrayModifications.hpp"

int main()
{
  std::cout<< "best array case:\n";
  kuznetsov::checkArray(kuznetsov::fillBestArray);
  std::cout << "average array case:\n";
  kuznetsov::checkArray(kuznetsov::fillRandomArray);
  std::cout << "worst array case:\n";
  kuznetsov::checkArray(kuznetsov::fillWorstArray);
}
