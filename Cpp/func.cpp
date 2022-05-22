#include <iostream>

using namespace std;
// B1: nhập số phần tử của mảng và thêm giá trị vào cho mảng
// B2: duyệt qua số phần tử của mảng và sắp xếp theo thứ tự tăng dần
  
int countOddNumberinArray(int arr[1000], int n) {
    int count = 0;
    for(int i =0; i<n; i++){
        if(arr[i]%2 == 1){
            count ++;
        }
    }
    return count;
}

int main() {
    int n;
    int arr[1000];
    cin >> n;
    for (int i = 0; i < n ;i++) {
        cin >> arr[i];
    }
    cout << "Trong mảng có: " << countOddNumberinArray(arr, n) << " số lẻ"<< endl;
    return 0;
}
