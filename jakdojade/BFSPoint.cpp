#include "BFSPoint.h"

BFSPoint::BFSPoint(Point* point_, int distance_) {
    this->point = point_;
    this->distance = distance_;
}
void BFSPoint::SetDistance(int distance_) {
    this->distance = distance_;
}
int BFSPoint::GetDistance() {
    return this->distance;
}

void BFSPoint::SetPoint(Point *point_) {
    this->point = point_;
}
Point *BFSPoint::GetPoint() {
    return this->point;
}