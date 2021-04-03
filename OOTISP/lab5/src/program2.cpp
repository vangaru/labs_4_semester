#include "Complex.h"
#include <iostream>
#include <iterator>
#include <queue>
#include <set>


int main() {

  Complex c1(1, 0);
  Complex c2(2, 2);
  Complex c3(4, 1);
  Complex c4(3, 7);
  Complex c5(7, 6);
  Complex c6(6, 3);

  multiset <Complex> qu1;
  //qu1.push(c1);
  //qu1.push(c3);
  //qu1.push(c5);
  auto it = qu1.begin();
  cout << *it;

  return 0;
}
