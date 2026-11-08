#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>

// Structure for rectangle dimensions
struct RectangleDimensions {
    double width;
    double height;
};

class Rectangle {
private:
    std::string name;
    RectangleDimensions dims;

    bool isValidDimension(double value) const;

public:
    Rectangle();
    Rectangle(std::string name, double width, double height);
    ~Rectangle();

    void setName(std::string name);
    void setWidth(double w);
    void setHeight(double h);

    std::string getName() const;
    double getWidth() const;
    double getHeight() const;
    double getArea() const;

    // Overloaded operators
    bool operator<=(const Rectangle& other) const;
    Rectangle& operator-=(double value);

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
    friend std::istream& operator>>(std::istream& is, Rectangle& rect);
};

#endif // RECTANGLE_H

