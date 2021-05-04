#include "Figures.h"

// отрисовка сложной фигуры
void Complex_Figure::show() {
    circle = Circle(r, x, y);                                                                   // необходимо обновлять координаты для вызова из move() 
    square = Square(r, x, y);
    circle.show();                                                                              // отрисовка круга
    square.show();                                                                              // отрисовка квадрата
}
// удаление сложной фигуры
void Complex_Figure::clear() {
    circle.clear();                                                                             // удаление квадрата
    square.clear();                                                                             // удаление круга
}
// конструтор с параметрами - координатами, задающими сложную фигуру
Complex_Figure::Complex_Figure(int new_r, int new_x, int new_y) {
    r = new_r;                                                                                  // объявление начальных координат
    x = new_x;
    y = new_y;
    circle = Circle(r, x, y);
    square = Square(r, x, y);
}