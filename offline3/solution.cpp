#include <iostream>
// your code
using namespace std;

class Point2D
{
    double x, y;

public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(double x, double y);
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void print();
    ~Point2D();
    // your code
    Point2D operator+(Point2D p);
    Point2D operator*(double n);
    bool operator==(Point2D p);
    bool operator!=(Point2D p);
};

Point2D::Point2D(double argx, double argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(double argx)
{
    x = argx;
}

void Point2D::setY(double argy)
{
    y = argy;
}

double Point2D::getX()
{
    return x;
}

double Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

Point2D::~Point2D()
{
    x = 0;
    y = 0;
}

// your code
Point2D Point2D::operator+(Point2D p)
{
    Point2D point;
    point.x = x + p.x;
    point.y = y + p.y;
    return point;
}
// asked to return a new point
Point2D Point2D ::operator*(double n)
{
    Point2D newPoint;
    newPoint.x = n * x;
    newPoint.y = n * y;
    return newPoint;
}
bool Point2D ::operator==(Point2D p)
{
    if (x == p.x && y == p.y)
    {
        return true;
    }
    else
        return false;
}
bool Point2D ::operator!=(Point2D p)
{
    if (x != p.x || y != p.y)
    {
        return true;
    }
    else
        return false;
}

class Circle
{
    Point2D center;
    double radius;

public:
    Circle();
    Circle(Point2D c, double r);
    void setCenter(Point2D c);
    void setRadius(double r);
    Point2D getCenter();
    double getRadius();
    void print();
    ~Circle();
    // your code
    Circle operator+(Point2D);
    Circle operator*(double);
    Circle operator+(Circle);
    Circle operator-(Circle);
    bool operator==(Circle);
    bool operator>(Circle);
    bool operator>=(Circle);
    bool operator<(Circle);
    bool operator<=(Circle);
    Circle operator++();
    Circle operator++(int);
};

Circle::Circle()
{
    center.setX(0);
    center.setY(0);
    radius = 0;
}

Circle::Circle(Point2D c, double r)
{
    center.setX(c.getX());
    center.setY(c.getY());
    radius = r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius = r;
}
Point2D Circle::getCenter()
{
    return center;
}
double Circle::getRadius()
{
    return radius;
}

void Circle::print()
{
    cout << "[Center: ";
    center.print();
    cout << " Radius: " << radius;
    cout << "]";
}

Circle::~Circle()
{
    center.setX(0);
    center.setY(0);
    radius = 0;
}

// your code
Circle Circle ::operator+(Point2D point)
{
    /*Circle circle;
    circle.center.setX(this->getX()+point.getX());
    circle.center.setY(center.getY()+point.getY());
    circle.setRadius(this->radius);
    return circle;*/

    Circle circle;
    circle.setCenter(center + point);
    circle.setRadius(radius);
    return circle;
    /*circle.center.setX(center.getX()+point.getX())
    circle.center.setY(center.getY()+point.getY());
    circle.setRadius(this->radius);
    return circle;

    Point2D newCenter(center.getX()+point.getX(),center.getY()+point.getY());
    return Circle(newCenter,radius);*/
}
Circle Circle ::operator*(double n)
{
    Circle newCircle;
    newCircle.center.setX(n * center.getX());
    newCircle.center.setY(n * center.getY());
    newCircle.radius = n * radius;
    return newCircle;
}

Circle Circle ::operator+(Circle c)
{
    Circle circle;
    double alpha = radius / (radius + c.radius);
    circle.setCenter((center * alpha) + (c.center) * (1 - alpha));
    circle.setRadius(radius + c.radius);
    return circle;
}
Circle Circle ::operator-(Circle c)
{
    Circle circle;
    double alpha = radius / (radius + c.radius);
    circle.setCenter((center * alpha) + (c.center) * (1 - alpha));
    circle.setRadius(radius - c.radius);
    return circle;
}
bool Circle ::operator==(Circle c)
{
    double area1 = 3.14 * radius * radius;
    double area2 = 3.14 * c.radius * c.radius;
    if (area1 == area2)
        return true;
    else
        return false;
}
bool Circle ::operator>(Circle c)
{
    double area1 = 3.14 * radius * radius;
    double area2 = 3.14 * c.radius * c.radius;
    if (area1 > area2)
        return true;
    else
        return false;
}
bool Circle ::operator>=(Circle c)
{
    double area1 = 3.14 * radius * radius;
    double area2 = 3.14 * c.radius * c.radius;
    if (area1 > area2 || area1 == area2)
        return true;
    else
        return false;
}
bool Circle ::operator<(Circle c)
{
    double area1 = 3.14 * radius * radius;
    double area2 = 3.14 * c.radius * c.radius;
    if (area1 < area2)
        return true;
    else
        return false;
}
bool Circle ::operator<=(Circle c)
{
    double area1 = 3.14 * radius * radius;
    double area2 = 3.14 * c.radius * c.radius;
    if (area1 < area2 || area1 == area2)
        return true;
    else
        return false;
}
Circle Circle ::operator++()
{
    ++radius;
    return *this;
}
Circle Circle::operator++(int unused)
{
    radius++;
    return *this;
}

class Rectangle
{
    Point2D topRightPoint, bottomLeftPoint;

public:
    Rectangle();
    Rectangle(Point2D oneCorner, Point2D anotherCorner);
    void setTopRightPoint(Point2D oneCorner);
    void setbottomLeftPoint(Point2D anotherCorner);
    Point2D getTopRightPointPoint();
    Point2D getBottomLeftPoint();
    void print();
    ~Rectangle();
    // your code
    Rectangle operator+(Point2D);
    Rectangle operator*(double n);
};

Rectangle::Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}
Rectangle::Rectangle(Point2D oneCorner, Point2D anotherCorner)
{
    topRightPoint = oneCorner;
    bottomLeftPoint = anotherCorner;
}

void Rectangle::setTopRightPoint(Point2D oneCorner)
{
    topRightPoint = oneCorner;
}
void Rectangle::setbottomLeftPoint(Point2D anotherCorner)
{
    bottomLeftPoint = anotherCorner;
}
Point2D Rectangle::getTopRightPointPoint()
{
    return topRightPoint;
}
Point2D Rectangle::getBottomLeftPoint()
{
    return bottomLeftPoint;
}

void Rectangle::print()
{
    cout << "[Top Right Point: ";
    topRightPoint.print();
    cout << "  Bottom left Point: ";
    bottomLeftPoint.print();
    cout << "]";
}
Rectangle::~Rectangle()
{
    topRightPoint.setX(0);
    topRightPoint.setY(0);
    bottomLeftPoint.setX(0);
    bottomLeftPoint.setY(0);
}

// your code

Rectangle Rectangle ::operator+(Point2D point)
{
    Rectangle rect;
    rect.setbottomLeftPoint(bottomLeftPoint + point);
    rect.setTopRightPoint(topRightPoint + point);
    return rect;
}
Rectangle Rectangle ::operator*(double n)
{
    Rectangle newRectangle;
    newRectangle.topRightPoint = topRightPoint * n;
    newRectangle.bottomLeftPoint = bottomLeftPoint * n;
    return newRectangle;
}

int main()
{
    // Point2D examples
    Point2D p1(3, 4);
    Point2D p2(1, 2);
    Point2D p3 = p1 + p2;
    Point2D p4 = p2 * 2;

    cout << "Point2D Examples:" << endl;
    cout << "p1: ";
    p1.print();
    cout << endl;
    cout << "p2: ";
    p2.print();
    cout << endl;
    cout << "p1 + p2: ";
    p3.print();
    cout << endl;
    cout << "p2 * 2: ";
    p4.print();
    cout << endl;
    cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << endl;
    cout << "p1 != p2: " << (p1 != p2 ? "true" : "false") << endl;

    // Circle examples
    Point2D center1(1, 1);
    Point2D center2(2, 2);
    Circle c1(center1, 5);
    Circle c2(center2, 3);
    Circle c3 = c1 + center2;
    Circle c4 = c2 * 2;
    Circle c5 = c1 + c2;
    Circle c6 = c1 - c2;

    cout << endl;
    cout << "Circle Examples:" << endl;
    cout << "c1: ";
    c1.print();
    cout << endl;
    cout << "c2: ";
    c2.print();
    cout << endl;
    cout << "c1 + center2: ";
    c3.print();
    cout << endl;
    cout << "c2 * 2: ";
    c4.print();
    cout << endl;
    cout << "c1 + c2: ";
    c5.print();
    cout << endl;
    cout << "c1 - c2: ";
    c6.print();
    cout << endl;
    cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << endl;
    cout << "c1 > c2: " << (c1 > c2 ? "true" : "false") << endl;
    cout << "c1 < c2: " << (c1 < c2 ? "true" : "false") << endl;
    cout << "c1 >= c2: " << (c1 >= c2 ? "true" : "false") << endl;
    cout << "c1 <= c2: " << (c1 <= c2 ? "true" : "false") << endl;

    //post and pre increment
    c1++;
    ++c2;
    cout<<"After post increment c1:"<<endl;
    c1.print();
    cout<<endl;
    cout<<"After pre increment c2:"<<endl;
    c2.print();
    cout<<endl;

    // Rectangle examples
    Point2D bottomLeft(1, 1);
    Point2D topRight(3, 3);
    Rectangle r1(topRight, bottomLeft);
    Rectangle r2 = r1 + p1;
    Rectangle r3 = r2 * 2;

    cout << endl;
    cout << "Rectangle Examples:" << endl;
    cout << "r1: ";
    r1.print();
    cout << endl;
    cout << "r2 (translated): ";
    r2.print();
    cout << endl;
    cout << "r3 (scaled): ";
    r3.print();
    cout << endl;
    return 0;
}
