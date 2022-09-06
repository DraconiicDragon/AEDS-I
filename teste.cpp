#include <iostream>

using namespace std;

void incrementa(int *id) {
    *id += 1;
}

int main() {
    int id = 1;
    cout << id << endl;
    incrementa(&id);
    cout << id;
    return 0;
}