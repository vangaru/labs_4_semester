#include <iostream>
#include <set>
#include "task2.h"
#include "Square.h"

using namespace std;

void task2() {
    cout << " === TASK 2 === " << endl;
    Square square1;
    Square square2(3);
    Square square3(7);
    Square square4(14);
    Square square5(9);
    Square square6(18);
    Square square7(16);
    Square square8(23);
    Square square9(1);

    auto comparator = [](Square a, Square b) {return a < b; };

    multiset<Square, decltype(comparator)> multiset1(comparator);
    multiset1.insert(square1);
    multiset1.insert(square6);
    multiset1.insert(square3);
    multiset1.insert(square8);
    multiset1.insert(square7);

    cout << "multiset lookup: ";
    for(auto &item : multiset1)
        cout << item << " ";

    cout << endl << "remove square6 and square7: ";
    multiset1.erase(square6);
    multiset1.erase(square7);
    for(auto &item : multiset1)
        cout << item << " ";

    cout << endl << "insert square2: ";
    multiset1.insert(square2);
    for(auto &item : multiset1)
        cout << item << " ";

    cout << endl << "multiset1 lookup using iterator: ";
    auto multiset1_iterator = multiset1.begin();
    while(multiset1_iterator != multiset1.end()) {
        cout << *multiset1_iterator << " ";
        multiset1_iterator++;
    }

    multiset<Square, decltype(comparator)> multiset2(comparator);
    multiset2.insert(square4);
    multiset2.insert(square5);
    multiset2.insert(square9);

    cout << endl << "multiset2 lookup: ";
    for(auto &item : multiset2)
        cout << item << " ";

    cout << endl << "deleting n elements after square1";
    cout << endl << "enter n: ";
    int n;
    cin >> n;
    auto multiset1_iterator_start = multiset1.find(square1);
    multiset1_iterator_start++;
    auto multiset1_iterator_end = multiset1_iterator_start;

    for(int i = 0; i < n; i++) {
        if(multiset1_iterator_end != multiset1.end())
            multiset1_iterator_end++;
    }

    multiset1.erase(multiset1_iterator_start, multiset1_iterator_end);

    cout << "erased n elements after square1: ";
    for(auto &item : multiset1)
        cout << item << " ";

    cout << endl << "inserting elements from multiset2 into multiset1: ";
    multiset1.insert(multiset2.begin(), multiset2.end());
    for(auto &item : multiset1)
        cout << item << " ";

}

