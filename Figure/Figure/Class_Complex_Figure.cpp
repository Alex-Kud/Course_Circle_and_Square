#include "Figures.h"

// ��������� ������� ������
void Complex_Figure::show() {
    circle = Circle(r, x, y);                                                                   // ���������� ��������� ���������� ��� ������ �� move() 
    square = Square(r, x, y);
    circle.show();                                                                              // ��������� �����
    square.show();                                                                              // ��������� ��������
}
// �������� ������� ������
void Complex_Figure::clear() {
    circle.clear();                                                                             // �������� ��������
    square.clear();                                                                             // �������� �����
}
// ���������� � ����������� - ������������, ��������� ������� ������
Complex_Figure::Complex_Figure(int new_r, int new_x, int new_y) {
    r = new_r;                                                                                  // ���������� ��������� ���������
    x = new_x;
    y = new_y;
    circle = Circle(r, x, y);
    square = Square(r, x, y);
}