#pragma once
#include "Point.h"

class BFSPoint : public Point {
    private:
        Point *point;
        int distance;

    public:
        BFSPoint(Point* point_, int distance_);

        virtual void SetDistance(int distance_);
        virtual int GetDistance();

        virtual void SetPoint(Point *point_);
        virtual Point *GetPoint();
};