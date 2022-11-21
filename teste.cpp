#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

int main() {
    time_t antes = clock();
    system("pause");
    cout << (clock() - antes)/CLOCKS_PER_SEC;
}