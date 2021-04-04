#ifndef SRC_SQUARE_H
#define SRC_SQUARE_H

#include <iostream>

using namespace std;

class Square {
private:
    int side_length;
public:
    explicit Square(int side_length = 5);

    void set_side_length(int side_length);
    int get_side_length() const;

    bool operator>(const Square &other) const;
    bool operator<(const Square &other) const;
    bool operator==(const Square &other) const;
    bool operator!=(const Square &other) const;

    friend ostream &operator<<(ostream &out, const Square &square) {
        out << square.side_length;
        return out;
    }

    friend istream& operator>>(istream &in, Square &square) {
        in >> square.side_length;
        return in;
    }

    ~Square() = default;
};


#endif //SRC_SQUARE_H
