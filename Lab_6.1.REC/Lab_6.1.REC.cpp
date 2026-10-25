
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне формування масиву
void Create(int a[], int n, int Low, int High, int i)
{
    if (i < n)
    {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, n, Low, High, i + 1);
    }
}

// Рекурсивне виведення масиву
void Print(int a[], int n, int i)
{
    if (i < n)
    {
        cout << setw(4) << a[i];
        Print(a, n, i + 1);
    }
    else
        cout << endl;
}

// Рекурсивний підрахунок кількості
int Count(int a[], int n, int i)
{
    if (i >= n)
        return 0;

    if (a[i] < 0 || a[i] % 2 != 0)
        return 1 + Count(a, n, i + 1);

    return Count(a, n, i + 1);
}

// Рекурсивне обчислення суми
int Sum(int a[], int n, int i)
{
    if (i >= n)
        return 0;

    if (a[i] < 0 || a[i] % 2 != 0)
        return a[i] + Sum(a, n, i + 1);

    return Sum(a, n, i + 1);
}

// Рекурсивна заміна елементів нулями
void Replace(int a[], int n, int i)
{
    if (i < n)
    {
        if (a[i] < 0 || a[i] % 2 != 0)
            a[i] = 0;

        Replace(a, n, i + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 24;
    int a[n];

    int Low = -50;
    int High = 15;

    Create(a, n, Low, High, 0);

    cout << "Original array:" << endl;
    Print(a, n, 0);

    int k = Count(a, n, 0);
    int s = Sum(a, n, 0);

    cout << "Count = " << k << endl;
    cout << "Sum = " << s << endl;

    Replace(a, n, 0);

    cout << "Modified array:" << endl;
    Print(a, n, 0);

    return 0;
}
