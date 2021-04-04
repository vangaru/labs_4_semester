#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include "Square.h"
#include "task3.h"

using namespace std;

bool side_length_is_even(Square square) {
    return (square.get_side_length() % 2) == 0;
}

void task3() {
    cout << " === TASK 3 === " << endl;
    Square square1;
    Square square3(7);
    Square square6(18);
    Square square7(16);
    Square square8(23);

    auto multiset1_comparator = [](Square a, Square b) {return a > b; };

    multiset<Square, decltype(multiset1_comparator)> multiset1(multiset1_comparator);
    multiset1.insert(square1);
    multiset1.insert(square6);
    multiset1.insert(square3);
    multiset1.insert(square8);
    multiset1.insert(square7);

    cout << "multiset1 lookup: ";
    for(auto &item : multiset1)
        cout << item << " ";

    auto multiset_iterator = find_if(multiset1.begin(), multiset1.end(), side_length_is_even);
    cout << endl << "square with even side length: " << *multiset_iterator;

    queue<Square> queue1;

    for(auto &item : multiset1)
        if(side_length_is_even(item))
            queue1.push(item);

    cout << endl << "queue lookup: ";
    while(!queue1.empty()) {
        cout << queue1.front() << " ";
        queue1.pop();
    }

    for(auto &item : multiset1)
        if(side_length_is_even(item))
            queue1.push(item);


    auto multiset2_comparator = [](Square a, Square b) { return a < b; };
    multiset<Square, decltype(multiset2_comparator)> multiset2(multiset2_comparator);
    cout << endl << "sorting containers" << endl << "container1(multiset): ";
    for(auto &item : multiset1)
        multiset2.insert(item);

    for(auto &item : multiset2)
        cout << item << " ";

    vector<Square> v;
    while(!queue1.empty()) {
        v.push_back(queue1.front());
        queue1.pop();
    }

    sort(v.begin(), v.end());
    for(auto &item : v)
        queue1.push(item);

    cout << endl << "Container2(queue): ";
    while(!queue1.empty()) {
        cout << queue1.front() << " ";
        queue1.pop();
    }

    for(auto &item : multiset2)
        if(side_length_is_even(item))
            queue1.push(item);

    multiset<Square, decltype(multiset2_comparator)> multiset3(multiset2_comparator);
    for(auto &item : multiset2)
        multiset3.insert(item);

    while(!queue1.empty()) {
        multiset3.insert(queue1.front());
        queue1.pop();
    }

    cout << endl << "Container3: ";
    for(auto &item : multiset3)
        cout << item << " ";

    int amount_of_responded_elements = count_if(multiset3.begin(), multiset3.end(), side_length_is_even);
    cout << endl << "amount of responded to condition elements: " << amount_of_responded_elements << endl;

    amount_of_responded_elements != 0 ? cout << "yes" : cout << "no";

}


