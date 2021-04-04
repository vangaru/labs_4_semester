#include <iostream>
#include <set>
#include "task1.h"

using namespace std;

void task1() {
    cout << " === TASK 1 === " << endl;
    multiset<char> multiset1 = {'a', 'b', 'k', 'k', 'c', 'y', 'x', 'z'};

    cout << "multiset1 lookup: ";
    for(auto &item : multiset1)
        cout << item << " ";

    cout << endl << "remove elements 'k' and 'x': ";
    multiset1.erase('k');
    multiset1.erase('x');
    for(auto &item : multiset1)
        cout << item << " ";

    cout << endl << "insert elements 'w' and 'v': ";
    multiset1.insert('w');
    multiset1.insert('v');
    for(auto &item : multiset1)
        cout << item << " ";

    cout << endl << "multiset1 lookup using iterator: ";
    auto multiset1_iterator = multiset1.begin();
    while(multiset1_iterator != multiset1.end()) {
        cout << *multiset1_iterator << " ";
        multiset1_iterator++;
    }

    multiset <char> multiset2 = {'c', 'j', 'l', 'u', 'i', 'p'};
    cout << endl << "multiset2 lookup: ";
    for(auto &item : multiset2)
        cout << item << " ";

    cout << endl << "deleting n elements after selected" << endl;

    char element;
    cout << "enter element: ";
    cin >> element;

    int n;
    cout << "enter n: ";
    cin >> n;

    auto multiset1_iterator_start = multiset1.find(element);
    multiset1_iterator_start++;
    auto multiset1_iterator_end = multiset1_iterator_start;

    for(int i = 0; i < n; i++) {
        if(multiset1_iterator_end != multiset1.end())
            multiset1_iterator_end++;
    }

    multiset1.erase(multiset1_iterator_start, multiset1_iterator_end);
    cout << "erased n elements after selected: ";
    for(auto &item : multiset1)
        cout << item << " ";

    cout << endl << "Inserting elements from multiset2 into multiset1: ";
    multiset1.insert(multiset2.begin(), multiset2.end());
    for(auto &item : multiset1)
        cout << item << " ";

}
