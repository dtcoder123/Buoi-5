#include <iostream>
using namespace std;

void MoveDisk(char from, char to) {
    cout << "Chuyen dia tu cot " << from << " sang cot " << to << endl;
}

void Tower(int n, char colA, char colB, char colC) {
    if (n == 1) {
        MoveDisk(colA, colC);
    } else {
        Tower(n - 1, colA, colC, colB);
        MoveDisk(colA, colC);
        Tower(n - 1, colB, colA, colC);
    }
}

int main() {
    int n; 
    cout << "Nhap so luong dia: ";
    cin >> n;
    Tower(n, 'A', 'B', 'C');
    
    return 0;
}

