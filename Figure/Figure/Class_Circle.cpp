#include "Figures.h"

// ��������� �����
void Circle::show() {
    HWND hwnd = GetConsoleWindow();                                                             // �������� ������������� ����
    HDC hdc = GetDC(hwnd);                                                                      // �������� �������� �����������
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));                                          // ������� ����
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 0));                                          // ������� �����
    GetClientRect(hwnd, &rt);                                                                   // �������� ������ ����
    SelectObject(hdc, pen); SelectObject(hdc, brush);                                           // ��������� ���� � ����� ��� ���������
    lx = x - r;                                                                                 // ��������� ���������� ��� ����������
    ly = y - r;
    rx = x + r;
    ry = y + r;
    if ((lx <= rt.left)||(ly <= rt.top)||(rx >= rt.right)||(ry >= rt.bottom)) throw Border();   // ������������ ������ �� ������� ����
    Ellipse(hdc, lx, ly, rx, ry);                                                               // ������ ����������
    DeleteObject(pen);                                                                          // ����������� �������
    DeleteObject(brush);
    DeletePen(pen);                                                                             // ������� ����
    DeleteBrush(brush);                                                                         // ������� �����
    ReleaseDC(hwnd, hdc);                                                                       // ����������� �������� �����������
}
// �������� �����
void Circle::clear() {
    HWND hwnd = GetConsoleWindow();                                                             // �������� ������������� ����
    HDC hdc = GetDC(hwnd);                                                                      // �������� �������� �����������
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));                                      // ������� ����
    HBRUSH brush = CreateSolidBrush(RGB(242, 242, 242));                                        // ������� �����
    GetClientRect(hwnd, &rt);                                                                   // �������� ������ ����
    SelectObject(hdc, pen); SelectObject(hdc, brush);                                           // ��������� ���� � ����� ��� ���������
    Ellipse(hdc, lx, ly, rx, ry);                                                               // ������� ����������
    DeleteObject(pen);                                                                          // ����������� �������
    DeleteObject(brush);
    DeletePen(pen);                                                                             // ������� ����
    DeleteBrush(brush);                                                                         // ������� �����
    ReleaseDC(hwnd, hdc);                                                                       // ����������� �������� �����������
}
// ���������� � ����������� - ������������, ��������� ����
Circle::Circle(int new_r, int new_x, int new_y) {
    r = new_r;                                                                                  // ���������� ��������� ���������
    x = new_x;
    y = new_y;
    lx = x - r;                                                                                 // ������ ��������� ��� ����������
    ly = y - r;
    rx = x + r;
    ry = y + r;
}