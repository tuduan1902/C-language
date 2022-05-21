#include <iostream>
using namespace std;

int main() {
    int n,i,chan,le;
    cout << "Nhap so phan tu cua mang tu ban phim: " << "\n";
    cin >> n;

    
    int num[n];
    for (int i=0; i<n; i++){
        cout << "Nhap gia tri cua mang:" << "\n";
        cin >> num[i];
    }
    for (int j=0; j<n; j++) {
        if(num[j]%2==0) {
            cout << "So nay la so chan: " << num[j] << "\n";
        } else {

            cout << "So nay la so le: " << num[j] << "\n";
        }
    }
    
    return 0;
}