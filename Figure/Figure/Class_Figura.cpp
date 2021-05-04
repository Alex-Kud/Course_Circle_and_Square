#include "Figures.h"

// перемещение фигуры
void Figura::move(int new_x, int new_y) {
    clear();                                                                                // удаление фигуры                                                                             // обновление координат
    x = new_x;
    y = new_y;
    show();                                                                                 // отрисовка фигуры по новым координатам
}