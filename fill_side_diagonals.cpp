#include <iostream>
using namespace std;

int main() {
    int n, m, cnt = 1;
    cin >> n >> m;
    int a[n][m];
    
    for (int col = 0; col < m; ++col) {
        for (int j = col; j >= 0 && j > col - n; --j) {
            a[col-j][j] = cnt;
            cnt++;
        }
    }
    for (int row = 1; row < n; ++row) {
        for (int i = row; i < n && i <= m + row - 1; ++i) {
            a[i][m+row-i-1] = cnt;
            cnt++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout.width(4);
            cout << a[i][j];
        }
        cout << endl;
    }
    
    return 0;
}


#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int cnt = 0, prev_cnt = 0, x = 0, y = 0, end = n * m;

    while (cnt < end)
    {
        if (x < n && y >= 0 && y < m) // проверка границ (не вышли вниз, влево или вправо)
        {
            cnt++;
            a[x][y] = cnt;
            x++, y--;
            //a[x++][y--] = ++cnt; // идем по заданной диагонали
        }
        else if (y == m)
        { //заступ вправо
            y -= 1; // возвращаемся в границы (значит прошли все верхние диагонали)
            x += 1; // спускаемся на одну клетку вниз

        }
        else
        { // заступ влево/вниз - возвр. вверх к началу следующей диагонали
            int back_shift = cnt - prev_cnt; // по счётчику определяем сдвиг от начала диаонали
            x -= back_shift; // возвращаемстя в начало текущей диагонали
            y += back_shift + 1; // плюс сдвигаемся вправо на следующую диагональ
            prev_cnt = cnt;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout.width(4);
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}