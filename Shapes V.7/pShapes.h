#pragma once
// identification comments code block
// Programmer: Milo Dominguez
// Programmer's ID: 1989801

#ifndef PSHAPES_H
#define PSHAPES_H

// C Libraries
#include <cmath>  //sqrt

// C++ Libraries
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Shape { //every shape is a shape
  virtual void output(ostream&) const = 0;
  virtual ~Shape() { }
};
ostream& operator<<(ostream&, const Shape* const);

class Square : public Shape { //shape type 1
protected:
  const double side;

public:
  void output(ostream&) const;
  Square& operator=(const Square&);
  Square(const vector<string>& tokens);
};

namespace comsc {
  class Rectangle : public Shape { //shape type 2
  protected:
    const double length;
    const double width;

  public:
    void output(ostream&) const;
    Rectangle& operator=(const Rectangle&);
    Rectangle(const vector<string>& tokens);
  };
}

class Circle : public Shape { //shape type 3
protected:
  const double radius;

public:
  void output(ostream&) const;
  Circle& operator=(const Circle&);
  Circle(const vector<string>& tokens);
};

class Triangle : public Shape { //shape type 4
protected:
  const double side;

public:
  void output(ostream&) const;
  Triangle& operator=(const Triangle&);
  Triangle(const vector<string>& tokens);
};

class Cube : public Square { //shape type 5
public:
  void output(ostream&) const;
  Cube& operator=(const Cube&);
  Cube(const vector<string>& tokens) : Square(tokens) { }
};

class Box : public comsc::Rectangle { //shape type 6
  const double height;

public:
  void output(ostream&) const;
  Box& operator=(const Box&);
  Box(const vector<string>& tokens) : comsc::Rectangle(tokens), height(tokens.size() <= 3 ? 0.0 : atof(tokens[3].c_str())) { }
};

class Cylinder : public Circle { //shape type 7
  const double height;

public:
  void output(ostream&) const;
  Cylinder& operator=(const Cylinder&);
  Cylinder(const vector<string>& tokens) : Circle(tokens), height(tokens.size() <= 2 ? 0.0 : atof(tokens[2].c_str())) { }
};

class Prism : public Triangle { //shape type 8
  const double height;

public:
  void output(ostream&) const;
  Prism& operator=(const Prism&);
  Prism(const vector<string>& tokens) : Triangle(tokens), height(tokens.size() <= 2 ? 0.0 : atof(tokens[2].c_str())) { }
};

ostream& roundingTwo(ostream&); //rounds output to precision 2
ostream& roundingOff(ostream&); //sets output back to default (precision 6)

//numberCheck function checks if dimensions given are numbers, otherwise returns string "0.0"
string numberCheck(const string&);
#endif