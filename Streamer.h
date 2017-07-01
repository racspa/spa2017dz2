#ifndef STREAMER_H_
#define STREAMER_H_
#include <iostream>
#include "Point.h"

typedef Point ELTYPE;
typedef int POSITION;

class Traveling {

private:
    static const unsigned int REDAK = 21;
    static const unsigned int STUPAC = 41;
    char _field_dot[REDAK][STUPAC];
    char char_pointA = 'A';
    char char_pointB = 'B';
    char char_traveling = 'X';
    char char_empty = '-';
        
public:
    void input(ELTYPE &A, ELTYPE &B);
    void draw();
    void put(ELTYPE &A, ELTYPE &B);
    void Streaming(ELTYPE &A, ELTYPE &B);
    void putt_x(ELTYPE &A);
    void swap(ELTYPE &A);
    void swap_A(ELTYPE &A);
    Traveling();

};

#endif // !STREAMER_H_
