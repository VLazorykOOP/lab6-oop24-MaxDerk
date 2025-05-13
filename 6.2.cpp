#include <iostream>
#include <cmath>
using namespace std;
class Abstract
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Abstract() {}
};
class Square : public Abstract
{
private:
    double side;
public:
    Square(double s) : side(s) {}

    double area() const override
    {
        return side * side;
    }
    double perimeter() const override
    {
        return 4 * side;
    }
};
class Rectangle : public Abstract
{
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override
    {
        return width * height;
    }
    double perimeter() const override
    {
        return 2 * (width + height);
    }
};
class Parallelogram : public Abstract
{
private:
    double base, height, side;
public:
    Parallelogram(double b, double h, double s) : base(b), height(h), side(s) {}
    double area() const override
    {
        return base * height;
    }
    double perimeter() const override
    {
        return 2 * (base + side);
    }
};
class Trapezoid : public Abstract
{
private:
    double base1, base2, side1, side2, height;
public:
    Trapezoid(double b1, double b2, double s1, double s2, double h) : base1(b1), base2(b2), side1(s1), side2(s2), height(h) {}
    double area() const override
    {
        return 0.5 * (base1 + base2) * height;
    }
    double perimeter() const override
    {
        return base1 + base2 + side1 + side2;
    }
};
int main()
{
    Abstract* shapes[] =
    {
        new Square(5),
        new Rectangle(3, 6),
        new Parallelogram(5, 3, 4),
        new Trapezoid(4, 6, 3, 3, 2)
    };
    cout << "Square area: " << shapes[0]->area() << "\n";
    cout << "Square perimeter: " << shapes[0]->perimeter() << "\n";
    cout << "Rectangle area: " << shapes[1]->area() << "\n";
    cout << "Rectangle perimeter: " << shapes[1]->perimeter() << "\n";
    cout << "Parallelogram area: " << shapes[2]->area() << "\n";
    cout << "Parallelogram perimeter: " << shapes[2]->perimeter() << "\n";
    cout << "Trapezoid area: " << shapes[3]->area() << "\n";
    cout << "Trapezoid perimeter: " << shapes[3]->perimeter() << "\n";
    return 0;
}