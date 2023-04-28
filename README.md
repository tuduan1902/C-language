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
- [5. Dynamic memory allocation](#) :
   - [5.1. Cấp phát bộ nhớ](#) : 
      - Cấp phát bộ nhớ tĩnh (biến toàn cục và biến cục bộ) và cấp phát bộ nhớ tự động(tham số truyền vào hàm và các biến trong hàm)
      - Bộ nhớ khi sử dụng được lưu vào STACK tối đa 1MB
   - [5.2. Cấp phát động](#) : 
      - Yêu cầu bộ nhớ từ hệ điều hành khi cần thiết gọi là HEAP lên tới GB 
         ```cpp
         // Cấp phát động một số nguyên và gán địa chỉ cho con trỏ ptr nắm giữ
         // dynamic memory allocation int and assign address for pointer holds
         int  *ptr = new int(value);

         // When u don't use it anymore, u should delete pointer and return memory for operating system.
         delete ptr;
         // or
         ptr = NULL;
         ```

      - Con trỏ lơ lửng là con trỏ trỏ vào vùng nhớ đã được giải phóng.
      - Con trỏ lúc này trỏ tới một vùng nhớ nằm ngoài khả năng quản lý, vì khi giải phóng ô nhớ thì hệ điều hành đã tiếp quản và sử dụng.
      - Example : 
         I use syntax of C++ for this example.
         ```cpp
         int *ptr = new int;
         *ptr = 10;  //assgin 10 for memory of ptr

         // giải phóng vùng nhớ cho hệ điều hành, ptr đang là con trỏ lơ lửng
         delete ptr;

         // truy cập vùng nhớ ptr đang trỏ tới => lỗi undefined behavior
         printf("%d /n", *ptr);

         // giải phóng vùng nhớ con trỏ đã được giải phóng trước đó => lỗi underfined behavior
         delete ptr
         ```
         ```cpp
         int *ptr = new int; // cấp phát động một số nguyên
         int *otherPtr = ptr; // otherPtr và ptr đang cùng trỏ đến một vùng nhớ

         // giải phóng vùng nhớ cho hệ điều hành, ptr và otherPtr đang là con trỏ lơ lửng
         delete ptr;
         ptr = nullptr; // ptr đang là con trỏ null

         // Tuy nhiên, otherPtr vẫn là con trỏ lơ lửng và chương trình không báo lỗi underfined behavior
         ```
   - [5.3. Cấp phát mảng động](#) : 
      - Syntax
         ```cpp
         int length;
         scanf_s("%d", &length);
         int *array = malloc(length* sizeof(int)); // kích thước mảng có thể là biến số
         // sử dụng ...
         // Xóa mảng động
         free(array); // return memory of array for operating system
         ```
   - [5.4. Pointer and const](#) :
      - Con trỏ hằng (pointer to const value) : can't change value of memory it stores but can change address
         - Syntax
            ```cpp
            const <datatype> pointer_name;
            // thị phạm
            const int value = 10;
            const int *ptr = &value;
            ```
         -  Example: 
            ```cpp
            int value = 10;
            const int *ptr = &value; // ptr là con trỏ hằng
            value = 20; // ok
            *ptr = 20; // error because ptr is pointer to const value

            // Nhưng con trỏ hằng có thể trỏ tới địa chỉ ô nhớ khác
            int value2 = 6;
            ptr = &value2;
            ```
      - Hằng con trỏ (constant pointer) : can't change address of the memory it stores but can change the value of address stores
         - Syntax:
            ```cpp
            <datatype> *const pointer_name;
            // thị phạm
            int value = 10;
            int *const ptr = &value;
            ```
         - Example: 
            ```cpp
            int value1 = 10;
            int value2 = 20;

            int *const ptr = &value1;
            ptr = &value2; // error because ptr is constant value
            ```
      - Hằng con trỏ hằng (const pointer to a const value) : can't change address of the memory and value.
         - Syntax: 
            ```cpp
            const <datatype> *const pointer_name;
            // thị phạm
            int value = 10;
            const int *const ptr = &value;
            ```
- [6. Reference value](#) : 
   