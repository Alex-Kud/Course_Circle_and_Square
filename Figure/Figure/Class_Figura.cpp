#include "Figures.h"

// ����������� ������
void Figura::move(int new_x, int new_y) {
    clear();                                                                                // �������� ������                                                                             // ���������� ���������
    x = new_x;
    y = new_y;
    show();                                                                                 // ��������� ������ �� ����� �����������
}