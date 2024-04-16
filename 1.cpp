#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream file("mybin1.dat", ios::binary);
    if (!file) {
        cout << "XXXXX" << endl;
        return 1;
    }
    int num1 = 1234;
    file.write((char*)&num1, sizeof(num1));
    for (int i = 1000; i <= 5000; i += 5) {
        int calc2 = i * 5;
        file.write((char*)&calc2, sizeof(calc2));
    }
    float a = -0.5;
    for (int i = 0; i < 3; ++i) {
        float calc3 = a * a;
        file.write((char*)&calc3, sizeof(calc3));
        a += 0.5;
    }
    file.close();

    return 0;
}
