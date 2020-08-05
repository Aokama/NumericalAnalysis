//
// Created by Aokama on 2020/08/04.
//

#include "Dimension.h"
#include <stdio.h>

Dimension::Dimension()= default;

Dimension::Dimension(int row, int col) {
    this->row = row;
    this->col = col;
}

int Dimension::get_row() const {
    return this->row;
}

int Dimension::get_col() const {
    return this->col;
}

bool Dimension::include(int i, int j) const {
    return (this->row >= i && this->col >= j);
}

bool Dimension::equals_to(Dimension comparer) const {
    return this->row == comparer.get_row() && this->col == comparer.get_col();
}

bool Dimension::is_vector() const {
    return this->col == 1;
}

bool Dimension::is_square() const {
    return this->row == this->col;
}
bool Dimension::can_multiply_from_right(Dimension right) const {
    return this->col == right.get_row();
}

bool Dimension::can_multiply_from_left(Dimension left) const {
    return this->row == left.get_col();
}

bool Dimension::is_initialized() const {
    return this->row == 0 || this->col == 0;
}

void Dimension::show(const char *name) const {
    printf("[%s] Dimension is (%d, %d)\n", name, this->row, this->col);
}




