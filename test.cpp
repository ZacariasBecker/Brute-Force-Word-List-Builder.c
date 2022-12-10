
#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

// int main()
// {
//     time_t rimeRec1 = time(nullptr);
//     time_t timeRec2 = time(nullptr);

//     long double timeRec3 = difftime(timeRec2, rimeRec1);

//     time_t timeRec4 = time(nullptr);

//     cout << "t1: " << asctime(localtime(&rimeRec1)) << endl;
//     cout << "t2: " << asctime(localtime(&timeRec2)) << endl;
//     cout << "t3: " << timeRec3 << endl;

//     clock_t tC;

//     for (size_t i = 0; i < 7777777; i++)
//     {

//     }

//     return 0;
// }

void fun()
{
    int rep = 5;
    for (size_t a = 0; a < rep; a++)
    {
        for (size_t b = 0; b < rep; b++)
        {
            for (size_t c = 0; c < rep; c++)
            {
                system("cls");
                cout << "a: " << a << endl;
                cout << "b: " << b << endl;
                cout << "c: " << c << endl;
            }
        }
    }
}

int main()
{
    clock_t timer = clock();

    fun();

    double diffTime = clock() - timer;
    printf("Segundos: %.2lf.\n", diffTime / CLOCKS_PER_SEC);
    return 0;
}