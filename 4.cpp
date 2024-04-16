#include <iostream>
#include <fstream>

using namespace std;

void calcf1(ofstream& file) {
    for (int i = 1000; i <= 5000; i += 5) {
        int result = i * 5;
        file.write((char*)&result, sizeof(result));
    }
}

void calcf2(ofstream& file) {
    float a = -0.5;
    for (int i = 0; i < 3; ++i) {
        float result = a * a;
        file.write((char*)&result, sizeof(result));
        a += 0.5;
    }
}

void All() {
    ofstream file("mybin4.dat", ios::binary); 
    if (!file) {
        cout << "XXXX" << endl;
        return; 
    }

    int num1 = 1234;
    file.write((char*)&num1, sizeof(num1));

    calcf1(file);
    calcf2(file);

    file.close(); 
}

int main() {
    All(); 
    return 0;
}
