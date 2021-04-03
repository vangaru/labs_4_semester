#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
  multiset <char> mset1 = {'a', 'b', 'k', 'k', 'c', 'y', 'x', 'z'};

  cout << endl << "multiset lookup:                 ";
  for(auto &item : mset1) {
    cout << item << " ";
  }

  cout << endl << "remove some elements and lookup: ";
  mset1.erase('k');
  mset1.erase('x');
  for(auto &item : mset1) {
    cout << item << " ";
  }

  cout << endl << "add some elements and lookup:    ";
  mset1.insert('w');
  mset1.insert('v');
  for(auto &item : mset1) {
    cout << item << " ";
  }

  cout << endl << "multiset lookup using iterator:  ";
  auto it1 = mset1.begin();
  while(it1 != mset1.end()) {
    cout << *it1 << " ";
    ++it1;
  }

  multiset <char> mset2 = {'c', 'j', 'l', 'u', 'i', 'p'};

  cout << endl << "multiset2 lookup:                ";
  for(auto &item : mset2) {
    cout << item << " ";
  }

  char element;
  cout << endl << "enter element: ";
  cin >> element;

  int n;
  cout << "enter n: ";
  cin >> n;

  auto it_start = mset1.find(element);
  ++it_start;

  auto it_end = it_start;
  for(int i = 0; i < n; i++) {
    if(it_end != mset1.end())
      ++it_end;
  }

  mset1.erase(it_start, it_end);

  cout << "modified multiset1 lookup             ";
  for(auto &item : mset1) {
    cout << item << " ";
  }



  return 0;
}
