#pragma once
#define INT_MAX 10000000


class DSNode {
   public:
    char id;
    DSNode* previous;
    int distanceFromStart;

   public:
    DSNode(char id): id(id), previous(nullptr), distanceFromStart(INT_MAX) {}

};

class DSEdge {
   public:
  DSNode* node1;
  DSNode* node2;
  int distance;

    public:
    DSEdge(DSNode* node1, DSNode* node2, int distance): node1(node1), node2(node2), distance(distance) {}

    bool Connects(DSNode* node1, DSNode* node2) {
        return (
            (node1 == this->node1 &&
            node2 == this->node2) ||
            (node1 == this->node2 &&
            node2 == this->node1));
        }

};


// TODO: Finish djikstra