#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int karat(int x, int y)
{
    string sx = to_string(x);
    string sy = to_string(y);
    int nx = sx.size();
    int ny = sy.size();
    if (nx == 1 || ny == 1)
    {
        return x * y;
    }
    else
    {
        int n = max(nx, ny);
        int nby2 = (int)n / 2;
        int a = (int)x / pow(10, nby2);
        int b = fmod(x, pow(10, nby2));
        int c = (int)y / pow(10, nby2);
        int d = fmod(y, pow(10, nby2));
        int ac = karat(a, c);
        int bd = karat(b, d);
        int adplusbc = karat(a + b, c + d) - ac - bd;
        int mul = (ac * pow(10, 2 * nby2)) + (adplusbc * pow(10, nby2)) + bd;
        return mul;
    }
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << karat(x, y);
    return 0;
}