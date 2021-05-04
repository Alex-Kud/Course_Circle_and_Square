#pragma once
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <vector>
using namespace std;

const int NotUsed = system("color F0");                                                     // ���� ���� ����

class Figura {
protected:
    int r = 0;                                                                              // ������ ������
    int x = 0;                                                                              // �������� ������ ������
    int y = 0;                                                                              // �������� ������ ������
    RECT rt;                                                                                // rt-�������������
public:
    virtual void show() = 0;                                                                // ��������� ������
    virtual void clear() = 0;                                                               // �������� ������
    void move(int, int);                                                                    // ����������� ������
    class Border {};                                                                        // ����� ��� ��������� ����������
};

class Circle :public Figura {
private:
    int lx, ly, rx, ry;                                                                     // ���������� �������� ������ � ������� ������� �����
public:
    void show() override;                                                                   // ��������� �����
    void clear() override;                                                                  // �������� �����
    Circle(int new_r = 0, int new_x = 0, int new_y = 0);                                    // ���������� � ����������� - ������������, ��������� ����
};

class Square :public Figura {
private:
    int lx, ly, rx, ry;                                                                     // ���������� �������� ������ � ������� ������� �����
public:
    void show() override;                                                                   // ��������� ��������
    void clear() override;                                                                  // �������� ��������
    Square(int new_r = 0, int new_x = 0, int new_y = 0);                                    // ���������� � ����������� - ������������, ��������� �������
};

class Complex_Figure : Figura {
private:
    Circle circle;
    Square square;
public:
    void show() override;                                                                   // ��������� ������� ������
    void clear() override;                                                                  // �������� ������� ������
    Complex_Figure(int new_r = 0, int new_x = 0, int new_y = 0);                            // ���������� � ����������� - ������������, ��������� ������� ������
};