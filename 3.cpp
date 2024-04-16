#include <iostream>
#include <fstream>

using namespace std;

struct Data {
    int num1;
    int calc2[801];
    float calc3[3];
};

void CalcA(Data& data) {
    data.num1 = 1234;
    int x = 0;
    for (int i = 1000; i <= 5000; i += 5) {
        data.calc2[x] = i * 5;
        x++;
    }
    float a = -0.5;
    for (int i = 0; i < 3; ++i) {
        data.calc3[i] = a * a;
        a += 0.5;
    }
}
void Datawrite(const Data& data) {
    ofstream file("mybin3.dat", ios::binary);
    if (!file) {
        cout << "XXXX" << endl;
        return;
    }
    file.write((char*)&data, sizeof(data));
    file.close();
}
int main() {
    Data data;
    CalcA(data);
    Datawrite(data);

    return 0;
}
