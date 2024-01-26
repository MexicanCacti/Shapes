// identification comments code block
// Programmer: Milo Dominguez
// Programmer's ID: 1989801

#include "pch.h"

#include "pShapes.h"

const double M_PI = 3.14;

#include <string>

//numberCheck function checks if dimensions given are numbers, otherwise returns string "0.0"
string numberCheck(const string& a) {
  for (int i = 0; i < a.length(); i++) {
    if (!isdigit(a[i]) && a[i] != '.') {
      return "0.0";
    }
  }
  return a;
}

ostream& operator<<(ostream& out, const Shape* const shape)
{
  shape->output(out);
  return out;
}

//square constructor
Square::Square(const vector<string>& tokens) : side(tokens.size() == 1 ? 0.0 : atof(numberCheck(tokens[1]).c_str())) {

}

Square& Square::operator=(const Square& copyThis) {
  Square& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

//rectangle constructor
comsc::Rectangle::Rectangle(const vector<string>&tokens) : length(tokens.size() >= 2 ? atof(numberCheck(tokens[1]).c_str()) : 0.0), width(tokens.size() >= 3 ? atof(numberCheck(tokens[2]).c_str()) : 0.0) {

}

comsc::Rectangle& comsc::Rectangle::operator=(const Rectangle& copyThis) {
  Rectangle& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  return host;
}

//circle constructor
Circle::Circle(const vector<string>& tokens) : radius(tokens.size() == 1 ? 0.0 : atof(numberCheck(tokens[1]).c_str())) {

}

Circle& Circle::operator=(const Circle& copyThis) {
  Circle& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host;
}

//triangle constructor
Triangle::Triangle(const vector<string>& tokens) : side(tokens.size() == 1 ? 0.0 : atof(numberCheck(tokens[1]).c_str())) {

}

Triangle& Triangle::operator=(const Triangle& copyThis) {
  Triangle& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

Cube& Cube::operator=(const Cube& copyThis) {
  Cube& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

Box& Box::operator=(const Box& copyThis) {
  Box& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis) {
  Cylinder& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.radius) = copyThis.radius;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

Prism& Prism::operator=(const Prism& copyThis) {
  Prism& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.side) = copyThis.side;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

ostream& roundingTwo(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2); // 2 decimal digits
  return out;
}

ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6); // the C++ default 
  return out;
}

//fuctions that use shape objects to output dimensions & calculations to console and textfile
void Square::output(ostream& out) const {
  const double area = Square::side * Square::side;
  const double perimeter = 4.0 * Square::side;
  out << "SQUARE Side = " << Square::side << "\r\n";
  out << roundingTwo << " Area = " << area << " Perimeter = " << perimeter << roundingOff << endl;
}

void comsc::Rectangle::output(ostream& out) const {
  const double area = Rectangle::length * Rectangle::width;
  const double perimeter = (2.0 * Rectangle::length) + (2.0 * Rectangle::width);
  out << "RECTANGLE Length = " << Rectangle::length << " Width = " << Rectangle::width << "\r\n";
  out << roundingTwo << " Area = " << area << " Perimeter = " << perimeter << roundingOff << endl;
}

void Circle::output(ostream& out) const {
  const double area = M_PI * (Circle::radius * Circle::radius);
  const double perimeter = 2.0 * M_PI * Circle::radius;
  out << "CIRCLE Radius = " << Circle::radius << "\r\n";
  out << roundingTwo << " Area = " << area << " Perimeter = " << perimeter << roundingOff << endl;

}

void Triangle::output(ostream& out) const {
  const double area = (sqrt(3.0) / 4.0) * (Triangle::side * Triangle::side);
  const double perimeter = 3.0 * Triangle::side;
  out << "TRIANGLE Side = " << Triangle::side << "\r\n";
  out << roundingTwo << " Area = " << area << " Perimeter = " << perimeter << roundingOff << endl;
}

void Cube::output(ostream& out) const {
  const double volume = Cube::side * Cube::side * Cube::side;
  const double surfaceArea = 6.0 * (Cube::side * Cube::side);
  out << "CUBE Side = " << Cube::side << "\r\n";
  out << roundingTwo << " Volume = " << volume << " Surface Area = " << surfaceArea << roundingOff << endl;
}

void Box::output(ostream& out) const {
  const double volume = Box::length * Box::width * Box::height;
  const double surfaceArea = (2.0 * Box::length * Box::width) + (2.0 * Box::width * Box::height) + (2.0 * Box::length * Box::height);
  out << "BOX Length = " << Box::length << " Width = " << Box::width << " Height = " << Box::height << "\r\n";
  out << roundingTwo << " Volume = " << volume << " Surface Area = " << surfaceArea << roundingOff << endl;
}

void Cylinder::output(ostream& out) const {
  const double volume = M_PI * (Cylinder::radius * Cylinder::radius) * Cylinder::height;
  const double surfaceArea = (2.0 * M_PI * (Cylinder::radius * Cylinder::radius)) + (2.0 * M_PI * Cylinder::radius * Cylinder::height);
  out << "CYLINDER Radius = " << Cylinder::radius << " Height = " << Cylinder::height << "\r\n";
  out << roundingTwo << " Volume = " << volume << " Surface Area = " << surfaceArea << roundingOff << endl;
}

void Prism::output(ostream& out) const {
  const double volume = (sqrt(3.0) / 4.0) * (Prism::side * Prism::side) * Prism::height;
  const double surfaceArea = (2.0 * ((sqrt(3.0) / 4.0) * (Prism::side * Prism::side))) * (3.0 * (Prism::side * Prism::height));
  out << "PRISM Side = " << Prism::side << " Height = " << Prism::height << "\r\n";
  out << roundingTwo << " Volume = " << volume << " Surface Area = " << surfaceArea << roundingOff << endl;
}
