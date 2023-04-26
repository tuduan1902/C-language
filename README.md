# Study C/C++
## In this, I use syntax of C to code
## 1. Data type and operator 
- int (%d), float(%f), double(%lf), char(%c), long long(%lld)
- & : toán tử địa chỉ (address operator)
   ``` cpp
   // Đọc từ bàn phím giá trị của a và tìm tới địa chỉ ô nhớ của a và gán giá trị của a vào ô nhớ đó.
   // Read the value of a from keyboard and find to memory address of a and assign the value of a to memnory this.
   int a;
   scanf_s("%d", &a);
   ```

## 2. Function 
- [1. The format](#) :
   The format of a function is
   ``` cpp
   return-value-type function-name( parameter list) {
      statements;
   }
   ```
- [2. Parameters](#) : 
   - parameter: tham số khi khởi tạo hàm (format parameter)
   - arguments : đối số truyền vào khi gọi hàm chạy (real parameter)
   
      ```cpp
      int sum(int n) {
         int sum = 0;
         for(int i = 0; i < n; i++) sum += i;
         return sum;
      } // n is parameter
      
      int main() {
         int m = 100;
         int kq = sum(m);
         return 0;
      } // m is argument

      // Khi gọi hàm thì ta gán giá trị của đối số cho tham số và thực thi trên tham số nên giá trị của đối số không thay đổi
      // When calling the function, assign the value of argument to the parameter and execute on the parameter so the value of argument not change
      ```
- [3. Pass by value](#) : 
   Truyền cho đối số 1 bản sao
   ```cpp
   void changeValue(int x) {
      x = 2;
   }
   
   int main() {
      int x = 0;
      changValue(x);
      printf("%d", x);
      return 0;
   } // When the program is finish running, the value of x in main function doesn't change
   ```
- [4. Pass by reference](#) : 
   Truyền cho nó một bản gốc thông qua địa chỉ "&"
   ```cpp
   void changeValue(int &x) {
      x = 2;
   }
   
   int main() {
      int x = 0;
      changValue(x);
      printf("%d", x);
      return 0;
   } // When the program is finish running, the value of x in main function change because x in changValue function get the address of x in main function so value of x in changValue function changes, the value of x in main function also changes 
   ```

## 3. Array 
- [1. Define](#) : Array is a group of contiguous memnory locations that all have the same type.
- [2. Syntax](#) : 
   ```cpp
   dataType ArrayName[sizeofArray];
   ```

## 4. 2-dimensional Array
- [1.Syntax](#) :
   ```cpp
   dataType ArrayName[row][column];
   ```

## 5. Pointer
- [1. Define](#) : Pointer are variable whose values are MEMORY ADDRESSES
- *pointer_name : giải tham chiếu và in ra giá trị mà con trỏ pointer_name đang quản lí
   ```cpp
   int value = 10;
   int *ptr = &value;

   printf("%d \n", &value); // in địa chỉ của biến value
   printf("%d \n", ptr); // in địa chỉ của con trỏ ptr đang giữ
   printf("%d \n", *ptr) // in ra giá trị của địa chỉ mà con trỏ đang quản lí

   *ptr = 100;
   printf("%d", value); // in ra 100 
   ```
- [2. Cấp phát động](#) :
   - dataType *pointerName = (type_cast*)malloc(size_of_byte)
   - int *ptr = (int*)malloc(1000)
- [3. NULL Pointer](#) : 
   - In C++ 11, I have keyword "nullptr", it is null pointer when u want start up
   ```cpp
   // Syntax in C++
   int *ptr = nullptr;

   // Syntax in C
   int *ptr = NULL;
   ```
- [4. Pointers and Arrays](#) : 
   - An array name can be thought of as a constant pointer.
   - Address of an array name is address of first element.
      ```cpp
      int array[3] =  {1, 3 ,4};
      printf("%d \n", array);
      printf("%d \n", &array);
      printf("%d \n", &array[0]);
      // The same result
      ```
   