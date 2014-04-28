#include "Shape.h"  // include and namespace 1 mark
namespace oop344{
  Shape::Shape():_width(0), _hieght(0), _solid(true){ // 1 mark
  }
  Shape::Shape(Color color, Coordinates coord, int width, int hieght, bool solid){  // 1 mark
    _color = color;
    _coord = coord;
    _width = width;
    _hieght = hieght;
    _solid = solid;
  }
  void Shape::move(Coordinates coord){  // 2 marks
    hide();
    _coord = coord;
    draw();
  }
  void Shape::valMove(Coordinates coord, bool (*val)(Coordinates, const Shape&)){  // 2 marks
    if(val(coord, *this)){
      move(coord);
    }
  }
}