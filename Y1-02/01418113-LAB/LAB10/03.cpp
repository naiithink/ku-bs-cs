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
    // สร้าง Object เพื่อทดสอบด้วยตัวเอง
    point p;

    p.xPosition = 0;
    p.yPosition = 0;

    Circle foo(p, 5);

    point bar, baz;

    bar.xPosition = 5;
    bar.yPosition = 0;
    baz.xPosition = 6;
    baz.yPosition = 0;

    cout << "bar" << endl;
    cout << foo.distanceFromCenter(bar) << endl;
    cout << foo.contains(bar) << endl;

    cout << "baz" << endl;
    cout << foo.distanceFromCenter(baz) << endl;
    cout << foo.contains(baz) << endl;

    return 0;
}