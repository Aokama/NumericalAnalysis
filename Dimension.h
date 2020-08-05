//
// Created by Aokama on 2020/08/04.
//

#ifndef NUMERICALANALYSIS_DIMENSION_H
#define NUMERICALANALYSIS_DIMENSION_H


class Dimension {
private:
    int row = 0;
    int col = 0;
public:
    Dimension();
    Dimension(int row, int col);
    int get_row() const;
    int get_col() const;
    bool include(int row, int col) const;
    bool equals_to(Dimension comparer) const;
    bool is_vector() const;
    bool is_square() const;
    bool can_multiply_from_right(Dimension right) const;
    bool can_multiply_from_left(Dimension left) const;
    bool is_initialized() const ;
    void show(const char *name) const;
};


#endif //NUMERICALANALYSIS_DIMENSION_H
