#ifndef POINT_H_
#define POINT_H_
struct Point
{
    unsigned int x;
    unsigned int y;
    Point(unsigned int x, unsigned int y) {

        this->x = x;
        this->y = y;

    }


    Point(){}

};

#endif // !POINT_H_
