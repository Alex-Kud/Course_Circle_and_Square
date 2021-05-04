#include "Figures.h"

int main() {
    SetConsoleTitle((LPCWSTR)L"20VP1_12");                                              // заголовок консоли
    vector <Figura*> figures(2);                                                        // создание вектора для хранения фигур
    figures[0] = reinterpret_cast<Figura*>(new Circle(75, 250, 225));                   // заполнение вектора фигурами
    figures[1] = reinterpret_cast<Figura*>(new Square(75, 250, 380));                   // заполнение вектора фигурами
    figures.push_back(reinterpret_cast<Figura*>(new Complex_Figure(75, 450, 380)));     // добавление фигуры в вектор
    figures.push_back(reinterpret_cast<Figura*>(new Complex_Figure(55, 70, 280)));      // добавление фигуры в вектор
    figures.push_back(reinterpret_cast<Figura*>(new Circle(15, 800, 450)));             // добавление фигуры в вектор
    try {
        for (int i = 0; i < figures.size(); ++i) figures[i]->show();                    // отрисовка фигур из вектора
        figures[2]->move(700, 225);                                                     // перемещение фигуры
        figures[3]->clear();                                                            // удаление фигуры
    }
    catch (Figura::Border) {
        cout << "Breaking window borders" << endl;                                      // обработка исключения выхода за границы окна
    }
    //system("pause");                                                                  // требуется для работы exe-файла
    return 0;
}