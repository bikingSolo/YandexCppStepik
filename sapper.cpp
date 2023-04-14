// 1.8

#include <iostream>
#include <vector>
#include <utility> // содержит класс pair

using namespace std;

int main()
{
    const int MINE = -1;
    int n, m;
    cin >> n >> m;
    // создаём поле как вектор векторов с рамочкой вокруг
    vector<vector<int>> field(n+2, vector<int>(m+2));

    // заполняем нулями только "рамочку" вокруг поля
    //for (int i = 0; i < m+2; i++) field[0][i] = field[n+1][i] = 0;
    //for (int i = 0; i < n+2; i++) field[i][0] = field[i][m+1] = 0;

    // вектор координат мин
    vector<pair<int, int>> mines;

    // чтение данных + отбор мин
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            cin >> field[i][j];
            if (field[i][j]) {
                mines.push_back({i, j}); // запоминаем координаты мин
                field[i][j] = MINE; // помечаем мины отрицательным числом
            }
        }
    }

    // координаты сдвигов в 8-и направлениях
    int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // обходим мины (звучит жутко, я знаю :))
    for (auto mine:mines) {
        int i=mine.first, j=mine.second; // берём координаты мины
        for (int k = 0; k < 8; k++) {
            int ni = i + dy[k], nj = j + dx[k]; // находим координаты соседних с миной клеток
            field[ni][nj] += (field[ni][nj] != MINE); // если сосед не мина добавляем ему 1
        }
    }


    // вывод
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (field[i][j] == MINE) cout << "*";
            else cout << field[i][j];
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
