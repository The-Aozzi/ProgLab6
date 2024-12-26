#ifndef STROKE_H
#define STROKE_H
#include<vector>
class Stroke{
public:
    void addPoint(int x, int y);
private:
    std::vector<std::pair<int, int>>points;
};
#endif