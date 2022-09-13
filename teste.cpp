#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    ifstream arqEntrada("funcionarios.bin");
    
    char sus;
    arqEntrada.get(sus);
    arqEntrada >> sus;
    cout << sus;

    return 0;
}