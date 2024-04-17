#include <iostream>
#include <fstream>

using namespace std;

struct memoryb {
    char memory[44];
    void* getadd(int set) {
        return memory + set;
    }
};

void calcf1(ofstream& file, memoryb& mem) {
    int* i = (int*)mem.getadd(16);
    *i = 1000;
    int* result1 = (int*)mem.getadd(4);
    while (*i <= 5000) {
        *result1 = *i * 5;
        file.write((char*)result1, sizeof(int));
        *i += 5;
    }
}

void calcf2(ofstream& file, memoryb& mem) {
    float* a = (float*)mem.getadd(12);
    *a = -0.5;
    int* i = (int*)mem.getadd(16);
    float* result2 = (float*)mem.getadd(8);
    for (*i = 0; *i < 3; ++(*i)) {
        *result2 = *a * *a;
        file.write((char*)result2, sizeof(float));
        *a += 0.5;
    }
}

int main() {
    ofstream file("mybin3.dat", ios::binary);
    if (!file) {
        cout << "XXXX" << endl;
        return 1;
    }

    memoryb mem;
    *((int*)mem.getadd(0)) = 1234;
    file.write((char*)mem.getadd(0), sizeof(int));

    calcf1(file, mem);
    calcf2(file, mem);

    file.close();
    return 0;
}
