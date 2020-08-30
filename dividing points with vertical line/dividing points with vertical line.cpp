#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {};
};

bool my_comp1(const Point& p1, const Point& p2) {
    if (p1.x < p2.x)
        return true;
    if (p1.x > p2.x)
        return false;
    return p1.y < p2.y;
}

bool my_comp2(const Point& p1, const Point& p2) {
    if (p1.x < p2.x)
        return true;
    if (p1.x > p2.x)
        return false;
    return p1.y > p2.y;
}

bool HasVerticalSymLine(std::vector<Point>& points) {
    if (points.size() < 1)
        return false;
    if (points.size() == 1)
        return true;
    std::sort(points.begin(), points.end(), my_comp1);
    std::partial_sort(points.begin(), points.begin() + points.size()/2, points.end(), my_comp2);
    
    //~ for(auto el: points) {
		//~ cout << '(' << el.x << ", " << el.y << ')' << endl;
	//~ }
    
    int x_line = points[points.size()-1].x + points[0].x;
    for (unsigned int i = 0; i < points.size()/2; ++i) {
        if (points[points.size() - i - 1].y != points[i].y) {
            if (2*x_line != points[i].x or 2*x_line != points[points.size()-i-1].x)
                return false;  
        }
        else {
            if ( x_line != points[points.size()-i-1].x + points[i].x )
                return false;
        }
    }
    return true;
}

int main() {
	vector<Point> v {Point(1, 2), Point(1, 2), Point(1, 5), Point(2, 5), Point(2, 4), Point(4, 4), Point(4, 5), Point(5, 5), Point(5, 2), Point(5, 2), Point(4, 4)};
	cout << HasVerticalSymLine(v);
	return 0;
}
