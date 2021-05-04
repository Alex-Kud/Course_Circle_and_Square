#include "Figures.h"

// ��������� ��������
void Square::show() {
    HWND hwnd = GetConsoleWindow();                                                             // �������� ������������� ����
    HDC hdc = GetDC(hwnd);                                                                      // �������� �������� �����������
    HPEN hRedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));                                      // ������� ������� ����
    HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));                                      // ������� ������� �����
    GetClientRect(hwnd, &rt);                                                                   // �������� ������ ����
    SelectObject(hdc, hRedPen); SelectObject(hdc, hGreenBrush);                                 // ��������� ���� � ����� ��� ���������
    lx = x - 0.7 * r;                                                                                 // ������ ��������� ��� ����������
    ly = y - 0.7 * r;
    rx = x + 0.7 * r;
    ry = y + 0.7 * r;
    if ((lx <= rt.left)||(ly <= rt.top)||(rx >= rt.right)||(ry >= rt.bottom)) throw Border();   // ������������ ������ �� ������� ����
    Rectangle(hdc, lx, ly, rx, ry);                                                             // ������ �������
    DeleteObject(hRedPen);                                                                      // ����������� �������
    DeleteObject(hGreenBrush);
    DeletePen(hRedPen);                                                                         // ������� ������� ����
    DeleteBrush(hGreenBrush);                                                                   // ������� ������� �����
    ReleaseDC(hwnd, hdc);                                                                       // ����������� �������� �����������
}
// �������� ��������
void Square::clear() {
    HWND hwnd = GetConsoleWindow();                                                             // �������� ������������� ����
    HDC hdc = GetDC(hwnd);                                                                      // �������� �������� �����������
    HPEN hRedPen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));                                  // ������� ������� ����
    HBRUSH hGreenBrush = CreateSolidBrush(RGB(242, 242, 242));                                  // ������� ������� �����
    GetClientRect(hwnd, &rt);                                                                   // �������� ������ ����
    SelectObject(hdc, hRedPen); SelectObject(hdc, hGreenBrush);                                 // ��������� ���� � ����� ��� ���������
    Rectangle(hdc, lx, ly, rx, ry);                                                             // ������� �������
    DeleteObject(hRedPen);                                                                      // ����������� �������
    DeleteObject(hGreenBrush);
    DeletePen(hRedPen);                                                                         // ������� ������� ����
    DeleteBrush(hGreenBrush);                                                                   // ������� ������� �����
    ReleaseDC(hwnd, hdc);                                                                       // ����������� �������� �����������
}
// ���������� � ����������� - ������������, ��������� �������
Square::Square(int new_r, int new_x, int new_y) {
    r = new_r;                                                                                  // ���������� ��������� ���������
    x = new_x;
    y = new_y;
    lx = x - 0.7 * r;                                                                                 // ������ ��������� ��� ����������
    ly = y - 0.7 * r;
    rx = x + 0.7 * r;
    ry = y + 0.7 * r;
}