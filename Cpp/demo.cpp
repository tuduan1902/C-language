#include <iostream>
using namespace std;

int main() {
    int num1, num2, temp;
    cout << "Input 1st number: ";
    cin >> num1;
    cout << "Input 2st number";
    cin >> num2;
    temp = num2;
    num2 = num1;
    num1 = temp;
    cout << "After swapping the 1st number is: "<< num1 << "\n";
    cout << "After swapping the 2st number is: "<< num2 << "\n\n";
    return 0;
}
