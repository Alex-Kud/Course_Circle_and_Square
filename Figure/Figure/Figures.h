#pragma once
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <vector>
using namespace std;

const int NotUsed = system("color F0");                                                     // цвет фона окна

class Figura {
protected:
    int r = 0;                                                                              // радиус фигуры
    int x = 0;                                                                              // абсцисса центра фигуры
    int y = 0;                                                                              // ордината центра фигура
    RECT rt;                                                                                // rt-прямоугольник
public:
    virtual void show() = 0;                                                                // отрисовка фигуры
    virtual void clear() = 0;                                                               // удаление фигуры
    void move(int, int);                                                                    // перемещение фигуры
    class Border {};                                                                        // класс для обработки исключений
};

class Circle :public Figura {
private:
    int lx, ly, rx, ry;                                                                     // координаты верхнего левого и нижнего правого углов
public:
    void show() override;                                                                   // отрисовка круга
    void clear() override;                                                                  // удаление круга
    Circle(int new_r = 0, int new_x = 0, int new_y = 0);                                    // конструтор с параметрами - координатами, задающими круг
};

class Square :public Figura {
private:
    int lx, ly, rx, ry;                                                                     // координаты верхнего левого и нижнего правого углов
public:
    void show() override;                                                                   // отрисовка квадрата
    void clear() override;                                                                  // удаление квадрата
    Square(int new_r = 0, int new_x = 0, int new_y = 0);                                    // конструтор с параметрами - координатами, задающими квадрат
};

class Complex_Figure : Figura {
private:
    Circle circle;
    Square square;
public:
    void show() override;                                                                   // отрисовка сложной фигуры
    void clear() override;                                                                  // удаление сложной фигуры
    Complex_Figure(int new_r = 0, int new_x = 0, int new_y = 0);                            // конструтор с параметрами - координатами, задающими сложную фигуру
};