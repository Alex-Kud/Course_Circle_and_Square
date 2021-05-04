#include "Figures.h"

// отрисовка круга
void Circle::show() {
    HWND hwnd = GetConsoleWindow();                                                             // получаем идентификатор окна
    HDC hdc = GetDC(hwnd);                                                                      // получаем контекст отображения
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));                                          // создаем перо
    HBRUSH brush = CreateSolidBrush(RGB(255, 255, 0));                                          // создаем кисть
    GetClientRect(hwnd, &rt);                                                                   // получаем размер окна
    SelectObject(hdc, pen); SelectObject(hdc, brush);                                           // назначаем перо и кисть для рисования
    lx = x - r;                                                                                 // обновляем координаты для построения
    ly = y - r;
    rx = x + r;
    ry = y + r;
    if ((lx <= rt.left)||(ly <= rt.top)||(rx >= rt.right)||(ry >= rt.bottom)) throw Border();   // отлавливание выхода за границы окна
    Ellipse(hdc, lx, ly, rx, ry);                                                               // рисуем окружность
    DeleteObject(pen);                                                                          // освобождаем ресурсы
    DeleteObject(brush);
    DeletePen(pen);                                                                             // удаляем перо
    DeleteBrush(brush);                                                                         // удаляем кисть
    ReleaseDC(hwnd, hdc);                                                                       // освобождаем контекст отображения
}
// удаление круга
void Circle::clear() {
    HWND hwnd = GetConsoleWindow();                                                             // получаем идентификатор окна
    HDC hdc = GetDC(hwnd);                                                                      // получаем контекст отображения
    HPEN pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));                                      // создаем перо
    HBRUSH brush = CreateSolidBrush(RGB(242, 242, 242));                                        // создаем кисть
    GetClientRect(hwnd, &rt);                                                                   // получаем размер окна
    SelectObject(hdc, pen); SelectObject(hdc, brush);                                           // назначаем перо и кисть для рисования
    Ellipse(hdc, lx, ly, rx, ry);                                                               // стираем окружность
    DeleteObject(pen);                                                                          // освобождаем ресурсы
    DeleteObject(brush);
    DeletePen(pen);                                                                             // удаляем перо
    DeleteBrush(brush);                                                                         // удаляем кисть
    ReleaseDC(hwnd, hdc);                                                                       // освобождаем контекст отображения
}
// конструтор с параметрами - координатами, задающими круг
Circle::Circle(int new_r, int new_x, int new_y) {
    r = new_r;                                                                                  // объявление начальных координат
    x = new_x;
    y = new_y;
    lx = x - r;                                                                                 // расчёт координат для построения
    ly = y - r;
    rx = x + r;
    ry = y + r;
}