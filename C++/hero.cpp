#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 10;
    int map[10][10] = {};
    int tree[2] = {rand() % 10, rand() % 10};
    int x_hero =  1; //Sunday
    int y_hero =  2; //65090500432
    int x_monster = 10 - x_hero;
    int y_monster =  3;
    int Taxicab = abs(y_hero - x_hero) + abs(y_monster - x_monster);
    double Euclidean = sqrt(pow(y_hero - x_hero, 2) + pow(y_monster - x_monster, 2));
    int Chebyshev = std::max(abs(x_hero - x_monster), abs(y_hero - y_monster));

    map[tree[0]][tree[1]] = 1;    // tree
    map[x_hero][y_hero] = 2;    // birthday
    map[x_monster][y_monster] = 3;    // monster

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Taxicab: " << Taxicab << endl;
    cout << "Euclidean: " << Euclidean << endl;
    cout << "Chebyshev: " << Chebyshev << endl;
}