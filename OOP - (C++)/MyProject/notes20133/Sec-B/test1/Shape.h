#ifndef __SHAPE_H__     // 1 mark
#define __SHAPE_H__

namespace oop344{       // 1 mark

  struct Color{
    unsigned char _red;
    unsigned char _green;
    unsigned char _blue;
    Color(unsigned char red = 255, unsigned char green = 255,unsigned char blue = 255); 
  };

  struct Coordinates{
    int _x;
    int _y;
    Coordinates(int x = 0, int y= 0);
  };

  class Shape{    // class and attributes 2 marks
    Color _color;
    Coordinates _coord;
    int _width;
    int _hieght;
    bool _solid;
  public:     
    Shape();   //constructors 2 marks     
    Shape(Color color, Coordinates coord, int width= 0, int hieght=0, bool solid=true); // default args 1 mark
    virtual void draw() = 0;     // pure virtual 2 marks
    virtual void hide() = 0;
    void move(Coordinates coord);  // moves 2 marks
    void valMove(Coordinates coord, bool (*val)(Coordinates, const Shape&));
  };
}
#endif