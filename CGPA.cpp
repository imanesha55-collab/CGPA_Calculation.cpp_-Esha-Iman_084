#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    float grade, sum = 0;

    
    cout << "Enter number of subjects: ";
    cin >> n;

    ofstream fout("grades.txt");
    if (!fout) {
        cout << "File cannot be created!";
        return 0;
    }

    cout << "Enter grade points of " << n << " subjects:\n";

    for (int i = 1; i <= n; i++) {
        cout << "Subject " << i << ": ";
        cin >> grade;
        fout << grade << endl;    
    }

    fout.close();

   
    ifstream fin("grades.txt");
    if (!fin) {
        cout << "File cannot be opened!";
        return 0;
    }

  
    while (fin >> grade) {
        sum += grade;
    }

    fin.close();

    
    float cgpa = sum / n;

    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}
