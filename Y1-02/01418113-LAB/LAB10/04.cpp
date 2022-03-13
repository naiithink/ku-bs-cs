#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct _point
{
    double xPosition;
    double yPosition;
} point;

class Circle
{
public:
    point center;
    double radius;

    explicit Circle(point center, double radius)
    {
        this->center = center;
        this->radius = radius;
    }

    double area(void)
    {
        double res = 0;

        res = M_PI * pow(radius, 2);

        return res;
    }

    double distanceFromCenter(point pt)
    {
        double res = 0;

        res = pow((pow((this->center.xPosition - pt.xPosition), 2) + pow((this->center.yPosition - pt.yPosition), 2)), 0.5);

        return res;
    }

    double contains(point pt)
    {
        double res = 0;
        double distance = 0;
        double diff = 0;

        distance = distanceFromCenter(pt);
        diff = radius - distance;

        if (diff < 0)
            res = 0;
        else
            res = 1;

        return res;
    }
};

int main()
{
    point center, P;
    float radius = 0;

    cout << "Center of Circle: ";
    cin >> center.xPosition >> center.yPosition;
    cout << "Radius of Circle: ";
    cin >> radius;

    Circle foo(center, radius);

    cout << "Point to Check: ";
    cin >> P.xPosition >> P.yPosition;

    cout << "Area of Circle is " << foo.area() << endl;
    cout << "Distance from Center to Point (" << P.xPosition << ", " << P.yPosition << ") is " << foo.distanceFromCenter(P) << endl;
    if (foo.contains(P))
        cout << "This circle contains this point." << endl;
    else
        cout << "This point is not in this circle." << endl;

    return 0;
}