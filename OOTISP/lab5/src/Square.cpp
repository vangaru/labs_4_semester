#include "Square.h"

Square::Square(int side_length) {
    this->side_length = side_length;
}

void Square::set_side_length(int side_length) {
    this->side_length = side_length;
}

int Square::get_side_length() const {
    return side_length;
}

bool Square::operator<(const Square &other) const {
    return this->side_length < other.side_length;
}

bool Square::operator>(const Square &other) const {
    return this->side_length > other.side_length;
}

bool Square::operator==(const Square &other) const {
    return this->side_length == other.side_length;
}

bool Square::operator!=(const Square &other) const {
    return this->side_length != other.side_length;
}
