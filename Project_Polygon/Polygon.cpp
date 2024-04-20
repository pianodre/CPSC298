#include <iostream>
#include <string>

using namespace std;

// Base Class Polygon - an Abstract Base Class, can't be instantiated
class Polygon {

public:
    Polygon(double dWidth, double dHeight);
    virtual ~Polygon();
    virtual double area() = 0; // Pure virtual member function - no implementation in base class
    virtual void displayProperties();

protected:
    double m_dWidth;
    double m_dHeight;
    string m_strType;
};

// Constructor for Polygon
Polygon::Polygon(double dWidth, double dHeight) : m_dWidth(dWidth), m_dHeight(dHeight), m_strType("Polygon")
{

}

// Destructor for Polygon
Polygon::~Polygon()
{
    cout << "Polygon Destructor called" << endl;
}

// Function to display properties of a polygon
void Polygon::displayProperties()
{
    cout << "Polygon Type: " << this->m_strType << ", Width: " << this->m_dWidth << ", Height: " << this->m_dHeight << endl;
    return;
}

// Derived Class Rectangle
class Rectangle : public Polygon
{
public:
    Rectangle(double dWidth, double dHeight);
    ~Rectangle();
    double area();
};

// Constructor for Rectangle
Rectangle::Rectangle(double dWidth, double dHeight) : Polygon(dWidth, dHeight)
{
    this->m_strType = "Rectangle";
}

// Destructor for Rectangle
Rectangle::~Rectangle()
{
    cout << "Rectangle Destructor called" << endl;
}

// Function to calculate area of Rectangle
double Rectangle::area()
{
    return (this->m_dHeight * this->m_dWidth);
}

// Derived Class Triangle
class Triangle : public Polygon
{
public:
    Triangle(double dWidth, double dHeight);
    ~Triangle();
    double area();
};

// Constructor for Triangle
Triangle::Triangle(double dWidth, double dHeight) : Polygon(dWidth, dHeight)
{
    this->m_strType = "Triangle";
}

// Destructor for Triangle
Triangle::~Triangle()
{
    cout << "Triangle Destructor called" << endl;
}

// Function to calculate area of Triangle
double Triangle::area()
{
    return 0.5 * (this->m_dWidth * this->m_dHeight);
}

int main()
{
    Polygon* p_polygonRectangle = new Rectangle(2.0, 4.0);
    Polygon* p_polygonTriangle = new Triangle(3.0, 6.0); // Creating Triangle object

    Polygon* p_polygon[2];

    p_polygon[0] = p_polygonRectangle;
    p_polygon[1] = p_polygonTriangle; // Assigning Triangle object pointer to array

    for (int i = 0; i < 2; i++) // Changed loop condition to iterate over both Rectangle and Triangle
    {
        p_polygon[i]->displayProperties();
        double dArea = p_polygon[i]->area();
        cout << "Area: " << dArea << endl;
    }

    delete p_polygonRectangle;
    delete p_polygonTriangle; // Deleting Triangle object

    return 0;
}
