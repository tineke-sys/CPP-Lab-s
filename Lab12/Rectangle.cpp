#include "Rectangle.h"

bool Rectangle::isValidDimension(double value) const {
    return value > 0.0;
}

Rectangle::Rectangle() : name("Rect-Default") {
    dims.width = 1.0;
    dims.height = 1.0;
}

Rectangle::Rectangle(std::string name, double width, double height) {
    setName(name);
    setWidth(width);
    setHeight(height);
}

Rectangle::~Rectangle() {
}

void Rectangle::setName(std::string name) {
    if (!name.empty()) {
        this->name = name;
    } else {
        this->name = "Rect-Default";
    }
}

void Rectangle::setWidth(double w) {
    if (isValidDimension(w)) {
        dims.width = w;
    } else {
        dims.width = 1.0;
    }
}

void Rectangle::setHeight(double h) {
    if (isValidDimension(h)) {
        dims.height = h;
    } else {
        dims.height = 1.0;
    }
}

std::string Rectangle::getName() const {
    return name;
}

double Rectangle::getWidth() const {
    return dims.width;
}

double Rectangle::getHeight() const {
    return dims.height;
}

double Rectangle::getArea() const {
    return dims.width * dims.height;
}

// Compare rectangles by area
bool Rectangle::operator<=(const Rectangle& other) const {
    return this->getArea() <= other.getArea();
}

// Decrease side lengths by value
Rectangle& Rectangle::operator-=(double value) {
    if (dims.width - value > 0.1) {
        dims.width -= value;
    } else {
        dims.width = 0.1;
    }

    if (dims.height - value > 0.1) {
        dims.height -= value;
    } else {
        dims.height = 0.1;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "[" << rect.name << "] "
       << "Width: " << rect.dims.width
       << ", Height: " << rect.dims.height
       << ", Area: " << rect.getArea();
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rect) {
    std::cout << "Enter name: ";
    std::getline(is >> std::ws, rect.name);

    double w, h;
    std::cout << "Enter width: ";
    is >> w;
    rect.setWidth(w);

    std::cout << "Enter height: ";
    is >> h;
    rect.setHeight(h);

    return is;
}

