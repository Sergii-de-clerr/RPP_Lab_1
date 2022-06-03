#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    srand(time(0));
    int max_val = 0;
    /*int n = 12;
    int a[12];*/
    const int n = 200000;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = rand();
    std::cout << "Enter number of threads: ";
    int num_threads = 0;
    std::cin >> num_threads;
    omp_set_dynamic(0);
    omp_set_num_threads(num_threads);
    double startPar = omp_get_wtime();
#pragma omp parallel for reduction (max : max_val)
    {
#pragma omp for
        for (int i = 0; i < n; i++) {
            if (max_val < a[i])
                max_val = a[i];
        }
    }
//#pragma omp parallel for reduction (max : max_val)
//    for (int i = 0; i < n; i++) {
//        if (max_val < a[i]) {
//#pragma omp critical
//            {
//                max_val = a[i];
//            }
//        }
//    }
    double endPar = omp_get_wtime();
    printf("The max num is %d\n\n\n", max_val);
    printf("%\nTime elapsed: %7.4f", endPar - startPar);
    system("pause");
}