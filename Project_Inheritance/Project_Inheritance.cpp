#include <iostream>
#include <cmath> // for M_PI
#include <string>

using namespace std;

class Shape {
protected:
    string m_strType;
    double m_width;
    double m_height;

public:
    Shape(double width, double height) : m_width(width), m_height(height) {}
    virtual ~Shape() {}

    virtual void displayProperties() {
        cout << "Type: " << m_strType << ", Width: " << m_width << ", Height: " << m_height << endl;
    }

    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void scale(double factor) = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : Shape(width, height) {
        m_strType = "Rectangle";
    }
    ~Rectangle() {}

    void displayProperties() {
        Shape::displayProperties();
    }

    double area() {
        return m_width * m_height;
    }

    double perimeter() {
        return 2 * (m_width + m_height);
    }

    void scale(double factor) {
        m_width *= factor;
        m_height *= factor;
    }
};

class Circle : public Shape {
public:
    Circle(double diameter) : Shape(diameter, diameter) {
        m_strType = "Circle";
    }
    ~Circle() {}

    void displayProperties() {
        Shape::displayProperties();
    }

    double area() {
        return 0.25 * M_PI * m_width * m_width;
    }

    double perimeter() {
        return M_PI * m_width;
    }

    void scale(double factor) {
        m_width *= factor;
        m_height *= factor;
    }
};

int main() {
    Shape* p_shapes[2];
    p_shapes[0] = new Circle(2.0);
    p_shapes[1] = new Rectangle(3.0, 2.0);

    for (int i = 0; i < 2; ++i) {
        p_shapes[i]->displayProperties();
        cout << "Area: " << p_shapes[i]->area() << endl;
        cout << "Perimeter: " << p_shapes[i]->perimeter() << endl;
        p_shapes[i]->scale(2.0);
        p_shapes[i]->displayProperties();
        cout << "Area after scaling: " << p_shapes[i]->area() << endl;
        cout << "Perimeter after scaling: " << p_shapes[i]->perimeter() << endl;
    }

    // Deallocate memory
    for (int i = 0; i < 2; ++i) {
        delete p_shapes[i];
    }

    return 0;
}
