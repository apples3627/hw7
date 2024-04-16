#include <iostream>
#include <fstream>

using namespace std;

bool Filechk(string& filen1, string& filen2) {
    ifstream file1(filen1, ios::binary);
    ifstream file2(filen2, ios::binary);
    file1.seekg(0, ios::end);
    file2.seekg(0, ios::end);
    if (file1.tellg() != file2.tellg()) {
        return false; 
    }
    file1.seekg(0);
    file2.seekg(0);
    char byte1, byte2;
    while (file1.read(&byte1, sizeof(byte1)) && file2.read(&byte2, sizeof(byte2))) {
        if (byte1 != byte2) {
            return false; 
        }
    }
    return true; 
}

int main() {
    string files[] = {"mybin1.dat", "mybin2.dat", "mybin3.dat", "mybin4.dat"};
    int numFiles = sizeof(files) / sizeof(files[0]); 
    int i = 0; 
    do {
        if (Filechk(files[i], files[i + 1])) {
            cout << files[i] << " " << files[i + 1] << " 크기, 내용 모두 같다." << endl;
        } else {
            cout << files[i] << " " << files[i + 1] << " 크기 or 내용이 다르다." << endl;
        }
        i++;
    } while (i < numFiles - 1);
    return 0;
}
