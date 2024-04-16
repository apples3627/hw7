#include <iostream>
#include <fstream>

using namespace std;

void calcf1(ofstream& file) {
    int num1 = 1234;
    file.write((char*)&num1, sizeof(num1));
}

void calcf2(ofstream& file) {
    for (int i = 1000; i <= 5000; i += 5) {
        int calc2 = i * 5;
        file.write((char*)&calc2, sizeof(calc2));
    }
}

void calcf3(ofstream& file) {
    float a = -0.5;
    for (int i = 0; i < 3; ++i) {
        float calc3 = a * a;
        file.write((char*)&calc3, sizeof(calc3));
        a += 0.5;
    }
}

int main() {
    ofstream file("mybin2.dat", ios::binary);
    if (!file) {
        cout << "XXXX" << endl;
        return 1;
    }

    calcf1(file);
    calcf2(file);
    calcf3(file);
    file.close();

    return 0;
}
