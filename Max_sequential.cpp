#include <stdio.h>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    int max = 0;
    const long int n = 200000;
    float a[n];
    for (int i = 0; i < n; i++)
        a[i] = rand();
    auto start = steady_clock::now();
    for (int i = 0; i < n; i++)
        if (max < a[i])
            max = a[i];

    auto end = steady_clock::now();
    printf("%\nTime elapsed: %7.4f\n", (double)duration_cast<microseconds>(end - start).count() / 1000000.0);
    printf("The max num is %d\n\n\n", max);
    system("pause");
}