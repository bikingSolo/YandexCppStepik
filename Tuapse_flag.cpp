// 1.8

#include <iostream>
#define MAX_ARR_SIZE 100 // задаём размерность матрицы
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[MAX_ARR_SIZE][MAX_ARR_SIZE];

    for (int i = 0; i < n; i++)
    {
        a[i][i] = 1; // заполняем главную диагональ одним проходом
        for (int j = i+1; j < n; j++) // обходим только верхний треугольник
        {
            a[i][j] = 0; // заполняем верхний треугольник
            a[j][i] = 2; // заполняем нижний треугольник зеркальным отображением
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}