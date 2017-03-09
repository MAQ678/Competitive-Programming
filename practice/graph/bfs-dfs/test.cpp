#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int NN = 50105;

int x[NN];

int main() {
    freopen("a.in", "w", stdout);

    double cl = clock();

    int cases = 8;
    printf("%d\n", cases + 12);
    while( cases-- ) {
        int n = 50000 - rand() % 10000;

        if( cases == 5 ) n = 50000;

        printf("%d\n", n);
        x[0] = rand() % 50000 + 1;
        for( int i = 1; i < n; i++ ) {
            int k = rand() % 50000 + 1;

            if( cases == 2 ) k = rand() % 1000 + 1;
            if( cases == 4 ) k = rand() % 100 + 1;

            if( cases == 5 ) k = 50000 - rand() % 10000;

            if( k == x[i-1] || ( i == n - 1 && k == x[0] ) ) {
                i--;
                continue;
            }
            x[i] = k;
        }
        for( int i = 0; i < n; i++ ) {
            if( i ) putchar(' ');
            printf("%d", x[i]);
        }
        puts("");
    }

    puts("7");
    puts("50000 30 20 10 50000 60 20");

    puts("14");
    puts("9 1 4 8 5 1 6 8 3 2 9 2 7 8");

    cases = 10;
    while( cases-- ) {
        int n = 50000 - rand() % 10000;

        if( cases == 5 ) n = 50000;

        printf("%d\n", n);


        for( int i = 0; i < n; i++ ) x[i] = i + 1;

        int xx = rand() % 20000;

        while( xx-- ) {
            int i = rand() % n;
            int j = rand() % n;
            swap( x[i], x[j] );
        }

        xx = rand() % 1000;

        if( cases == 5 || cases == 7 ) xx = 0;
        while( xx-- ) {
            int i = rand() % n;
            if( i > 0 && i < n - 1 ) {
                int k = rand() % 50000 + 1;

                if( x[i-1] != k && x[i+1] != k ) {
                    x[i] = k;
                }
            }
        }

        for( int i = 0; i < n; i++ ) {
            if( i ) putchar(' ');
            printf("%d", x[i]);
        }
        puts("");
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
