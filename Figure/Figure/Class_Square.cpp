#include "Figures.h"

// отрисовка квадрата
void Square::show() {
    HWND hwnd = GetConsoleWindow();                                                             // получаем идентификатор окна
    HDC hdc = GetDC(hwnd);                                                                      // получаем контекст отображения
    HPEN hRedPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));                                      // создаем красное перо
    HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));                                      // создаем зеленую кисть
    GetClientRect(hwnd, &rt);                                                                   // получаем размер окна
    SelectObject(hdc, hRedPen); SelectObject(hdc, hGreenBrush);                                 // назначаем перо и кисть для рисования
    lx = x - 0.7 * r;                                                                                 // расчёт координат для построения
    ly = y - 0.7 * r;
    rx = x + 0.7 * r;
    ry = y + 0.7 * r;
    if ((lx <= rt.left)||(ly <= rt.top)||(rx >= rt.right)||(ry >= rt.bottom)) throw Border();   // отлавливание выхода за границы окна
    Rectangle(hdc, lx, ly, rx, ry);                                                             // рисуем квадрат
    DeleteObject(hRedPen);                                                                      // освобождаем ресурсы
    DeleteObject(hGreenBrush);
    DeletePen(hRedPen);                                                                         // удаляем красное перо
    DeleteBrush(hGreenBrush);                                                                   // удаляем зеленую кисть
    ReleaseDC(hwnd, hdc);                                                                       // освобождаем контекст отображения
}
// удаление квадрата
void Square::clear() {
    HWND hwnd = GetConsoleWindow();                                                             // получаем идентификатор окна
    HDC hdc = GetDC(hwnd);                                                                      // получаем контекст отображения
    HPEN hRedPen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));                                  // создаем красное перо
    HBRUSH hGreenBrush = CreateSolidBrush(RGB(242, 242, 242));                                  // создаем зеленую кисть
    GetClientRect(hwnd, &rt);                                                                   // получаем размер окна
    SelectObject(hdc, hRedPen); SelectObject(hdc, hGreenBrush);                                 // назначаем перо и кисть для рисования
    Rectangle(hdc, lx, ly, rx, ry);                                                             // стираем квадрат
    DeleteObject(hRedPen);                                                                      // освобождаем ресурсы
    DeleteObject(hGreenBrush);
    DeletePen(hRedPen);                                                                         // удаляем красное перо
    DeleteBrush(hGreenBrush);                                                                   // удаляем зеленую кисть
    ReleaseDC(hwnd, hdc);                                                                       // освобождаем контекст отображения
}
// конструтор с параметрами - координатами, задающими квадрат
Square::Square(int new_r, int new_x, int new_y) {
    r = new_r;                                                                                  // объявление начальных координат
    x = new_x;
    y = new_y;
    lx = x - 0.7 * r;                                                                                 // расчёт координат для построения
    ly = y - 0.7 * r;
    rx = x + 0.7 * r;
    ry = y + 0.7 * r;
}