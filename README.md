# MACRO

khái niệm:

Macro trong C là một tính năng của tiền xử lý (preprocessor), giúp định nghĩa các hằng số, hàm, hoặc các đoạn mã được thay thế trực tiếp vào chương trình trước khi biên dịch. Macro giúp giảm sự lặp lại mã nguồn và làm cho mã ngắn gọn hơn.

Macro được định nghĩa bằng từ khóa #define và không có dấu chấm phẩy (;) ở cuối.

* Macro hằng số: Định nghĩa các hằng số hoặc chuỗi ký tự.

 ví dụ:

    #include <stdio.h>

    #define PI 3.14159  // Định nghĩa hằng số PI
    #define MAX 100     // Định nghĩa hằng số MAX

    int main()
    {
        printf("Giá trị của PI: %f\n", PI);
        printf("Giá trị của MAX: %d\n", MAX);
        return 0;
    }

* Macro hàm: Được định nghĩa bằng từ khóa #define, chỉ là sự thay thế văn bản (textual substitution) trong quá trình tiền xử lý (preprocessing) trước khi mã nguồn được biên dịch.

ví dụ:

    #define MAX(a, b) ((a) > (b) ? (a) : (b))

    int x = MAX(3, 5); // Preprocessor thay thế MAX(3, 5) thành ((3) > (5) ? (3) : (5))


khác nhau giữa macro hàm và hàm

-Macro hàm:
Nhanh hơn vì macro được thay thế trực tiếp vào mã nguồn (inline code), không cần thêm chi phí cho việc gọi hàm.
Tuy nhiên, nếu macro hàm quá lớn hoặc được gọi nhiều lần, nó có thể tăng kích thước mã nguồn (code size) do nó sao chép toàn bộ mã của macro mỗi khi được gọi.

-Hàm thông thường:
Chậm hơn một chút vì có chi phí cho việc gọi hàm (stack push/pop, nhảy tới mã hàm), nhưng hiệu quả hơn trong các hàm lớn hoặc được gọi nhiều lần vì chỉ có một lần thực hiện mã hàm.
Tối ưu hóa bởi compiler: Các hàm nhỏ có thể được compiler tối ưu hóa bằng cách "inlining" (nhúng mã trực tiếp vào vị trí gọi hàm, như macro).

-Quá trình xử lý

Macro hàm:

Được thay thế trực tiếp vào mã nguồn tại vị trí được gọi trước khi biên dịch (bởi preprocessor).
Không có kiểm tra kiểu dữ liệu hoặc tính năng bảo vệ tương tự như hàm thực sự.

Hàm thông thường:

Được biên dịch thành mã máy (machine code) một cách bình thường và thực thi trong quá trình chạy chương trình.
Có kiểm tra kiểu dữ liệu và có thể quản lý bộ nhớ tốt hơn (ví dụ: sử dụng tham chiếu hoặc con trỏ).

-Hiệu năng

Macro hàm:

Nhanh hơn vì macro được thay thế trực tiếp vào mã nguồn (inline code), không cần thêm chi phí cho việc gọi hàm.
Tuy nhiên, nếu macro hàm quá lớn hoặc được gọi nhiều lần, nó có thể tăng kích thước mã nguồn (code size) do nó sao chép toàn bộ mã của macro mỗi khi được gọi.

Hàm thông thường:

Chậm hơn một chút vì có chi phí cho việc gọi hàm (stack push/pop, nhảy tới mã hàm), nhưng hiệu quả hơn trong các hàm lớn hoặc được gọi nhiều lần vì chỉ có một lần thực hiện mã hàm.
Tối ưu hóa bởi compiler: Các hàm nhỏ có thể được compiler tối ưu hóa bằng cách "inlining" (nhúng mã trực tiếp vào vị trí gọi hàm, như macro).

-Kiểm tra kiểu dữ liệu

Macro hàm:

Không kiểm tra kiểu dữ liệu, chỉ thay thế văn bản. Điều này có thể gây lỗi không mong muốn.

Hàm thông thường:

Kiểm tra kiểu dữ liệu tại thời điểm biên dịch, đảm bảo rằng các tham số đúng kiểu và ngăn ngừa lỗi.

-Tính năng bảo mật và xử lý lỗi

Macro hàm:

Không có kiểm tra lỗi và không thể trả về mã lỗi (error code). Mọi lỗi đều xảy ra trong thời gian tiền xử lý và khó phát hiện hơn so với hàm.
Không thể sử dụng con trỏ, tham chiếu, hoặc trả về con trỏ động.

Hàm thông thường:

Có khả năng xử lý lỗi tốt hơn. Bạn có thể kiểm tra và trả về mã lỗi, exception hoặc sử dụng các cách kiểm soát lỗi.
Các kiểu dữ liệu như con trỏ, cấu trúc phức tạp có thể dễ dàng được quản lý trong hàm.

-Dễ bảo trì và debug

Macro hàm:

Khó bảo trì và debug hơn vì chúng chỉ là sự thay thế văn bản. Khi xảy ra lỗi, việc xác định vấn đề với macro có thể khó khăn.
Không có dấu hiệu rõ ràng trong code rằng macro đã thay thế đoạn mã tại thời điểm biên dịch.

Hàm thông thường:

Dễ bảo trì và debug hơn nhiều vì chúng được biên dịch và xử lý như một phần của mã nguồn. Trình biên dịch và trình debug có thể dễ dàng xác định và theo dõi lỗi trong quá trình thực thi.

Tính năng mở rộng

Macro hàm:
Không thể sử dụng các khái niệm cao cấp như đệ quy, con trỏ hoặc tham số tham chiếu. Nó cũng không hỗ trợ khả năng đa hình (polymorphism).

Hàm thông thường:
Có thể mở rộng với các tính năng như đệ quy, quản lý con trỏ, truyền tham chiếu, và có thể hỗ trợ tính năng đa hình (trong trường hợp C++ hoặc các ngôn ngữ khác dựa trên C).

* Macro điều kiện: Dùng để kiểm tra điều kiện biên dịch hoặc thay đổi cách biên dịch theo các điều kiện khác nhau.


Một số loại chỉ thị tiền xử lý phổ biến trong C:

#define: Định nghĩa macro (hằng số, hàm)
#include: Nhúng file tiêu đề (header file)
#if, #ifdef, #ifndef, #else, #elif, #endif: Điều kiện biên dịch
#undef: Hủy định nghĩa macro
#pragma: Chỉ thị cho trình biên dịch

1. #define: Định nghĩa macro
Chỉ thị #define được dùng để định nghĩa các macro, có thể là hằng số hoặc macro hàm.

Định nghĩa hằng số:

    #define PI 3.14159
    #define MAX_BUFFER_SIZE 1024

PI sẽ được thay thế bằng giá trị 3.14159 ở bất cứ đâu trong mã nguồn.
MAX_BUFFER_SIZE sẽ được thay thế bằng 1024.

Macro hàm:

    #define SQUARE(x) ((x) * (x))

Bất kỳ chỗ nào bạn gọi SQUARE(5), nó sẽ được thay thế bằng ((5) * (5)).

2. #include: Nhúng file tiêu đề

Chỉ thị #include được sử dụng để nhúng các tệp tiêu đề (header file) vào mã nguồn, ví dụ như các tệp chứa khai báo hàm hoặc macro. Có hai loại #include:

Thư viện chuẩn: Nhúng các tệp tiêu đề từ thư viện chuẩn C.

    #include <stdio.h>   // Nhúng tệp tiêu đề chuẩn
    #include <stdlib.h>


Tệp do người dùng định nghĩa: Nhúng tệp tiêu đề trong dự án.

    #include "my_header.h"   // Nhúng tệp tiêu đề do người dùng định nghĩa

3. #if, #ifdef, #ifndef, #else, #elif, #endif: Điều kiện biên dịch

Các chỉ thị này cho phép biên dịch có điều kiện, tức là một đoạn mã chỉ được biên dịch nếu điều kiện được thỏa mãn.

#ifdef và #ifndef: Kiểm tra xem một macro có được định nghĩa hay không.

#ifdef: Nếu macro đã được định nghĩa, đoạn mã bên trong sẽ được biên dịch.
 
    #define DEBUG

    #ifdef DEBUG
    printf("Debugging mode is ON\n");
    #endif

Nếu DEBUG đã được định nghĩa trước đó, dòng printf sẽ được biên dịch.

#ifndef: Nếu macro chưa được định nghĩa, đoạn mã bên trong sẽ được biên dịch.
 
    #ifndef RELEASE
    printf("Release mode is OFF\n");
    #endif

#if, #else, #elif và #endif: Biên dịch có điều kiện phức tạp hơn.

#if: Cho phép biên dịch dựa trên điều kiện cụ thể.


 
    #if MAX_BUFFER_SIZE > 512
    printf("Buffer size is large enough\n");
    #else
    printf("Buffer size is too small\n");
    #endif

    #elif: Tương tự như else if trong ngôn ngữ lập trình.

    #if MAX_BUFFER_SIZE > 512
    printf("Buffer size is large enough\n");
    #elif MAX_BUFFER_SIZE == 512
    printf("Buffer size is just right\n");
    #else
    printf("Buffer size is too small\n");
    #endif

4. #undef: Hủy định nghĩa macro

Chỉ thị #undef được dùng để hủy định nghĩa một macro đã được định nghĩa trước đó.
 
    #define PI 3.14159
    #undef PI  // Hủy định nghĩa PI

Sau khi #undef, PI sẽ không còn được nhận diện là một macro nữa.

5. #pragma: Chỉ thị cho trình biên dịch

Chỉ thị #pragma cung cấp các hướng dẫn cụ thể cho trình biên dịch. Tùy thuộc vào trình biên dịch mà bạn sử dụng, các #pragma có thể khác nhau.

Ví dụ:

 
    #pragma once  // Đảm bảo rằng tệp tiêu đề chỉ được nhúng một lần

Một ví dụ khác trong GCC để tắt cảnh báo cụ thể:

    #pragma GCC diagnostic ignored "-Wunused-variable"

6. __LINE__, __FILE__, __DATE__, __TIME__, __func__: Các macro đặc biệt
Đây là các macro có sẵn trong C và cung cấp thông tin về mã nguồn.

__LINE__: Trả về số dòng hiện tại trong mã nguồn.
__FILE__: Trả về tên file nguồn hiện tại.
__DATE__: Trả về ngày biên dịch (ví dụ: "Oct 7 2024").
__TIME__: Trả về thời gian biên dịch (ví dụ: "12:34:56").
__func__: Trả về tên hàm hiện tại.

Ví dụ:


    #include <stdio.h>

    void example_function() {
        printf("This is line %d in file %s\n", __LINE__, __FILE__);
    }

    int main() {
        example_function();
        return 0;
    }

# THƯ VIỆN STDARG.H
Khái niệm: 
Thư viện stdarg.h trong C cung cấp các macro để xử lý danh sách tham số có số lượng biến đổi (variable-length argument lists). Thư viện này hữu ích khi bạn muốn viết các hàm có thể nhận một số lượng tham số khác nhau, giống như cách các hàm như printf hoạt động.

1. Các macro chính trong stdarg.h

va_list: Kiểu dữ liệu dùng để khai báo biến chứa danh sách các đối số biến đổi.
va_start: Khởi tạo danh sách tham số biến đổi.
va_arg: Lấy giá trị của tham số tiếp theo từ danh sách tham số biến đổi.
va_end: Kết thúc quá trình xử lý danh sách tham số biến đổi.

2. Cú pháp và cách sử dụng

a. va_list:

Khai báo một biến kiểu va_list để chứa danh sách các tham số biến đổi.

b. va_start(va_list, param):

Khởi tạo danh sách các tham số biến đổi. Tham số param là tên của tham số cuối cùng trước danh sách tham số biến đổi (thường là một tham số có tên rõ ràng).

c. va_arg(va_list, type):

Lấy tham số tiếp theo từ danh sách, với type là kiểu dữ liệu của tham số đó. Macro này di chuyển qua từng tham số trong danh sách.

d. va_end(va_list):

Kết thúc quá trình xử lý danh sách tham số biến đổi và giải phóng bộ nhớ cần thiết.

ví dụ:

    #include <stdio.h>
    #include <stdarg.h>

    // Hàm nhận số lượng biến đổi và in ra các giá trị kiểu int và double
    void print_values(const char* types, ...) 
    {
        va_list args;
        va_start(args, types);  // Bắt đầu xử lý danh sách tham số biến đổi

        while (*types) 
        {  // Duyệt qua chuỗi 'types' để xác định kiểu dữ liệu
            if (*types == 'i') 
            {
                int i = va_arg(args, int);
                printf("int: %d\n", i);
            } else if (*types == 'd') 
            {
                double d = va_arg(args, double);
                printf("double: %f\n", d);
            }
            types++;
        }

        va_end(args);  // Kết thúc xử lý danh sách tham số
    }

    int main() 
    {
        print_values("idid", 10, 3.14, 42, 2.71);
        return 0;
    }

# THƯ VIỆN ASSENT.H

KHÁI NIỆM
Trong ngôn ngữ C, assert.h là một thư viện chuẩn được sử dụng để kiểm tra điều kiện trong mã và cung cấp khả năng kiểm tra lỗi trong quá trình phát triển. Nó cung cấp macro assert, giúp xác minh tính đúng đắn của một điều kiện tại thời điểm chạy chương trình. Nếu điều kiện sai (tức là trả về giá trị false), chương trình sẽ in ra thông báo lỗi và dừng lại.

1. Cú pháp của assert:
c
Copy code

    #include <assert.h>

void assert(int expression);

expression: Biểu thức điều kiện cần được kiểm tra. Nếu biểu thức này sai (tức là kết quả bằng 0), chương trình sẽ hiển thị thông báo lỗi và dừng chương trình.

2. Hoạt động của assert:

Khi biểu thức điều kiện đúng (tức là không bằng 0), chương trình sẽ tiếp tục thực thi bình thường.
Khi biểu thức sai (tức là bằng 0), chương trình sẽ:
In ra thông báo lỗi bao gồm: tên tệp, số dòng, và biểu thức không thỏa mãn.
Kết thúc chương trình bằng hàm abort() (hàm dừng chương trình ngay lập tức).

    #include <stdio.h>
    #include <assert.h>

    int divide(int a, int b) 
    {
        assert(b != 0);  // Kiểm tra điều kiện b != 0 trước khi thực hiện phép chia
        return a / b;
    }

    int main() 
    {
        int x = 10, y = 0;

        printf("Chia 10 cho 2: %d\n", divide(10, 2));  // Hoạt động bình thường
        printf("Chia 10 cho 0: %d\n", divide(x, y));   // Lỗi, assert sẽ phát hiện và dừng chương trình

        return 0;
    }



# BIT MASK

khái niệm:
Bitmask trong C là một kỹ thuật thao tác trực tiếp trên các bit của dữ liệu, giúp thực hiện các phép toán logic, kiểm tra, thiết lập hoặc xóa các bit cụ thể trong một giá trị. Kỹ thuật này thường được sử dụng khi bạn cần quản lý bộ nhớ hiệu quả, làm việc với cờ (flags), hoặc khi tối ưu hóa mã.

* NOT bitwise
Dùng để thực hiện phép NOT bitwise trên từng bit của một số. Kết quả là bit đảo ngược của số đó.

* AND bitwise
Dùng để thực hiện phép AND bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0.

* OR bitwise
Dùng để thực hiện phép OR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu có hơn một bit tương ứng là 1.

* XOR bitwise
Dùng để thực hiện phép XOR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu chỉ có một bit tương ứng là 1.

* Shift left và Shift right bitwise

Dùng để di chuyển bit sang trái hoặc sang phải.
Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).

ví dụ:

    #include <stdio.h>

    // Định nghĩa các quyền bằng bitmask
    #define READ    (1 << 0)  // 0001
    #define WRITE   (1 << 1)  // 0010
    #define EXECUTE (1 << 2)  // 0100
    #define ADMIN   (1 << 3)  // 1000

    // Thêm quyền cho người dùng
    void addPermission(int *userPermissions, int permission) {
        *userPermissions |= permission;
    }

    // Xóa quyền của người dùng
    void removePermission(int *userPermissions, int permission) {
        *userPermissions &= ~permission;
    }

    // Kiểm tra xem người dùng có quyền cụ thể không
    int hasPermission(int userPermissions, int permission) {
        return (userPermissions & permission) != 0;
    }

    // Hiển thị các quyền của người dùng
    void displayPermissions(int userPermissions) {
        printf("User permissions: ");
        if (userPermissions & READ)    printf("READ ");
        if (userPermissions & WRITE)   printf("WRITE ");
        if (userPermissions & EXECUTE) printf("EXECUTE ");
        if (userPermissions & ADMIN)   printf("ADMIN ");
        printf("\n");
    }

    int main() {
        int userPermissions = 0;  // Khởi tạo quyền của người dùng (không có quyền nào)

        // Thêm quyền READ và WRITE cho người dùng
        addPermission(&userPermissions, READ);
        addPermission(&userPermissions, WRITE);
        displayPermissions(userPermissions);  // Hiển thị quyền hiện tại

        // Kiểm tra quyền EXECUTE
        if (hasPermission(userPermissions, EXECUTE)) {
            printf("User has EXECUTE permission\n");
        } else {
            printf("User does not have EXECUTE permission\n");
        }

        // Thêm quyền EXECUTE cho người dùng
        addPermission(&userPermissions, EXECUTE);
        displayPermissions(userPermissions);  // Hiển thị quyền sau khi thêm EXECUTE

        // Xóa quyền WRITE của người dùng
        removePermission(&userPermissions, WRITE);
        displayPermissions(userPermissions);  // Hiển thị quyền sau khi xóa WRITE

        return 0;
    }

# POINTER

1.	Khái niệm:
•	Con trỏ hay biến con trỏ cũng là một biến thông thường nhưng giá trị mà nó lưu lại là địa chỉ của 1 biến khác


    int arr [5] = {100,5,8,8,54} ; // khái báo  1 mảng
    int *ptr = arr ; // khai báo con trỏ cho mảng


•	Kích thước của con trỏ không phụ thuộc vào kiểu dữ liệu nó phụ thuộc vào trình biên dịch 

printf("%d byte\n", sizeof(float*)); // kich thuoc con tro phu thuoc vao trinh bien dich 

•	ví dụ về cập nhật giá trị của biến

    int main() {
      int x = 10;
    
      
      int * ptr = & x;
      printf("Value of x = %d\n", * ptr);
      * ptr = 20;
      printf("Value of x = %d\n", * ptr);
    
      return 0;
    }


# Function pointer

Khái niêm
Là một con trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
•	con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác
•	lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu
•	truyền hàm như một giá trị trả về từ một hàm khác


ví dụ truyền một hàm như là một đối số cho một hàm khác

    int addition (int a, int b){
       return a + b;
    }
    
    int main(){
        int x = 10, y = 20;
       
       void (*ptr)() ;
       ptr = addition(x,y);
       int z = *ptr;
   

   printf("Addition of x: %d and y: %d = %d", x, y, z);
   
   return 0;
}


ví dụ lưu trữ hàm trong 1 cấu trúc dữ liệu.
    void swap(int *a, int *b){
       int c;
       c = *a;
       *a = *b;
       *b = c;
    }

    int main(){
       
       void (*ptr)(int *, int *) = swap;
       
       int x = 10, y = 20;
       printf("Values of x: %d and y: %d before swap\n", x, y);
       
       (*ptr)(&x, &y);
       printf("Values of x: %d and y: %d after swap", x, y);
       
       return 0;
    }


ví dụ truyền hàm như một giá trị trả về từ một hàm khác

    void func1(void (*ptr)());  
    void func2();
    void func1(void (*ptr)())  
    {  
        printf("Function1 is called");  
        (*ptr)();  
    }  
    void func2()  
    {  
        printf("\nFunction2 is called");  
    }  
    int main()  
    {  
        func1(func2);  
         return 0;  
    }  


# Pointer to constant
Khái niệm
Một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.

VÍ DỤ

    int EX1 = 8;
    int const *ptr_const = &EX1;

    printf("value: %d\n", *ptr_const);

    EX1 = 9;

    printf("value: %d\n", *ptr_const);

    return 0;



# Constant Pointer
Khái niệm:
con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. chỉ được khỏi tạo một lần và không thay đổi được địa chỉ.


Ví dụ

    int EX1 = 15;
    int *const const_ptr = &EX1;

    printf("value: %d\n", *const_ptr);


# Pointer to pointer
Khái niệm :
Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc.


Ví dụ

    int var = 789;
    int* ptr1;
    int** ptr2;
    ptr1 = &var; 
    ptr2 = &ptr1;
    printf("Value of var = %d\n", var);
    printf("Value of var using single pointer = %d\n", *ptr1);
    printf("Value of var using double pointer = %d\n", **ptr2);



#   GOTO

1. Khái niệm 

Câu lệnh goto trong C cung cấp một bước nhảy vô điều kiện từ 'goto' đến một câu lệnh có nhãn trong cùng một hàm,cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm

ví dụ:  in ra các giá trị của a từ 10-20 và bỏ qua số 15

    #include <stdio.h>
    int main () {
    int a = 10;
 
    jump:
    do {
        if( a == 15)
         {
            a = a + 1;
            goto jump;
        }
        printf("Gia tri cua a: %d\n", a);
        a++;
    } while( a < 20 );
     return 0;
    }


## setjump.h

1.khái niệm

setjmp.h là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là setjmp và longjmp. Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ này.




bài tập

        #include <stdio.h>
        #include <string.h>
        #include <setjmp.h>

        jmp_buf buf;
        int exception_code;

        int VALUE = 1 ;

        char source[100];

        #define TRY if ((exception_code = setjmp(buf)) == 0) 
        #define CATCH(x) else if (exception_code == (x)) 
        #define THROW(x,n) strcpy(source, #n) , longjmp(buf, (x)) 

        enum ErrorCodes 
        { 
            NO_ERROR =0 , 
            FILE_ERROR =1 , 
            NETWORK_ERROR = 2, 
            CALCULATION_ERROR = 3 
        };

        void read_File() 
        {
            printf("read file...1\n");

            if(VALUE==1 )
            {
                THROW( FILE_ERROR, "read file error." );
            }

        }

        void network_Operation() 
        {
            printf("read file...2\n");
            
            if(VALUE==2 )
            {
                THROW(NETWORK_ERROR, "Net work don't working.");
            } 
        }

        void calculate_Data() 
        {
            printf("read file...3\n");

            if(VALUE==3)
            {
            THROW(CALCULATION_ERROR, "number invalid");
            } 

        }

        int main()
        {
            /* code */
            TRY 
            {
                read_File();
                network_Operation();
                calculate_Data();
            } 


            CATCH(FILE_ERROR) 
            {
                printf("%s\n", source); 
            } 

            CATCH(NETWORK_ERROR) 
            {
                printf("%s\n", source); 
            } 

            CATCH(CALCULATION_ERROR) 
            {
                printf("%s\n", source); 
            } 


            return 0;
        }

# Exten

Khái niệm :

Extern là một lệnh trong ngôn ngữ lập trình C được sử dụng khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác

● Biến extern tham chiếu của một biến, đã được định nghĩa bên ngoài (ở một file source khác). 

● Nó chỉ mang ý nghĩa khai báo (declare) chứ không định nghĩa (define) ( tức là không xin cấp phát thêm bộ nhớ cho biến, bởi biến này đã tồn tại ở dạng toàn cục, được khai báo ở một nơi nào đó ).

● Biến được tham chiếu phải được khai báo ở cấp độ cao nhất (toàn cục), và có thể nằm trong một file khác

● Extern cho phép bạn chia sẻ biến và hàm giữa nhiều file nguồn trong một chương trình.

● Điều này hữu ích khi bạn muốn tách chương trình thành các phần nhỏ để quản lý dễ dàng hơn.

● Extern có thể được sử dụng để kết nối các module hoặc thư viện trong một dự án lớn.

● Nếu bạn muốn sử dụng một hàm trước khi nó được định nghĩa trong mã nguồn, bạn có thể sử dụng extern để khai báo hàm.

● Khi có một biến toàn cục được sử dụng trong nhiều file nguồn, extern giúp các file nguồn biết về sự tồn tại của biến đó.


ví dụ:
File 1.c
    #include<stdio.h>
    #include"File_1.h"

    int a = 10 ;
    void display1()
    {
        printf("print file 1\n");
    }

File 1.h

    #ifndef _FILE1_H
    #define _FILE1_H

    extern int a ;
    void display1();


    #endif
    

File 2.c

    #include<stdio.h>
    #include"File_2.h"


    int b = 20 ;
    void display2()
    {
        printf("print file 2\n");
    }

File 2.h

    #ifndef _FILE2_H
    #define _FILE2_H
    extern int b ;
    void display2();


    #endif

main.c

    #include <stdio.h>
    #include"File_1.h"
    #include"File_2.h"

    extern void display1() ;
    extern void display2() ;

    //gcc main.c File_1.c File_2.c -o main
    // \.main
    int main()
    {
        a = 15 ;
        printf("%d\n",a);
        b = 35 ;
        printf("%d\n",b);

        display1();
        display2();

        return 0 ;
    }


# Static local variables

Khái niệm:

Biến tĩnh cục bộ là biến có thể duy trì giá trị của nó từ lệnh gọi hàm này sang lệnh gọi hàm khác và nó sẽ tồn tại cho đến khi chương trình kết thúc. Khi một biến tĩnh cục bộ được tạo, nó phải được gán một giá trị ban đầu.

ví dụ

    #include <stdio.h>

    void exampleFunction() {
        static int count_1  = 0;  // Biến static giữ giá trị qua các lần gọi hàm
        count_1++;
        int count_2 = 0;
        count_2++ ;
        printf("Count 1: %d\nCount 2: %d\n", count_1,count_2);
    }

    int main() {
        exampleFunction();  // In ra lần 1
        exampleFunction();  // In ra lần 2
        exampleFunction();  // In ra lần 3
        return 0;
    }

giá trị cout_1 thay đổi qua mổi lần gọi hàm , giá trị count_2 không thay đổi

# Static global variables

Khái niệm

Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.

ví dụ:

    #include <stdio.h>

    int g_value = 30;
    static int s_g_value = 20;

    void display()
    {
        printf("static global value: %d\n", s_g_value);
        printf("global value: %d\n", g_value);
    }

# Register

Khái niệm

* Register được sử dụng để tạo ra một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. 
* Một register có thể có địa chỉ của một vị trí bộ nhớ.
* Register chỉ có thể được sử dụng trong phạm vi khối (cục bộ), không thể sử dụng trong phạm vi toàn cục (bên ngoài khối chính).

ví dụ sử dụng register giảm thời hoạt động chương trình

    #include <stdio.h>
    #include <time.h>

    int main() {
        // Lưu thời điểm bắt đầu
        clock_t start_time = clock();
        int i;

        // Đoạn mã của chương trình
        for (i = 0; i < 2000000; ++i) {
            // Thực hiện một số công việc bất kỳ
        }

        // Lưu thời điểm kết thúc
        clock_t end_time = clock();

        // Tính thời gian chạy bằng miligiây
        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

        return 0;
    }

# Volatile

Khái niệm
* "volatile" được sử dụng để cho biết cho trình biên dịch rằng một biến hoặc vị trí bộ nhớ cụ thể có thể được thay đổi bên ngoài sự kiểm soát của chương trình. Điều này có nghĩa là trình biên dịch không thể đưa ra bất kỳ giả định nào về giá trị của biến và luôn phải tải và lưu trữ biến như nó có thể thay đổi bất cứ lúc nào.
*  "volatile" đặc biệt hữu ích khi làm việc với các thiết bị phần cứng, các hàm dịch vụ ngắt, lỗi.

ví dụ

    #include "stm32f10x.h"

    volatile int i = 0;
    int a = 100;

    int main()
    {
        
        while(1)
        {
            i = *((int*) 0x20000000);
            if (i > 0)
            {
            break;
            }	
            
        }
        a = 200;
    }


# Text segment

Khái niệm
Text Segment, còn gọi là Code Segment, là phần trong bộ nhớ nơi mã thực thi của chương trình được lưu trữ. Mỗi khi bạn viết một chương trình và biên dịch nó, mã nguồn C sẽ được chuyển đổi thành mã máy (binary) và được lưu vào Text Segment. Phần này của bộ nhớ chứa các lệnh và chỉ thị mà CPU sẽ thực thi trong quá trình chạy chương trình.

Text segment đặc điểm:

* Mã lệnh của chương trình (các hàm).
* Chuỗi hằng số và các hằng số khác không thể thay đổi.
* Mã thư viện từ các thư viện chuẩn.
* Do tính chất chỉ đọc, vùng này không thể bị thay đổi trong quá trình chương trình chạy, và mọi cố gắng ghi vào text segment sẽ dẫn đến lỗi Segmentation fault.

ví dụ

    #include <stdio.h>
    #include <math.h>

    char a[] = "Number is prime " ; // chuổi nằm trong text segment
    char b[] = "Number isn't prime" ;
    char *ptr = "Hello";

    int prime[100001] ;

    //hàm sàng số nguyên tố nằm trong text segment
    void sieve()
    {
        for(int i= 0 ; i<=100001;i++)
        {
            prime[i] =1 ;
        }

        prime[0] = prime [1] = 1 ;
        for (int i =2 ; i<= sqrt(100001);i++)
        {
            if(prime[i]==1)
            {
                for (int j=i*i;j<=100001;j+=i)
                {
                    prime[j] = 0;
                }
            }
        }

    }

    int main()
    {
        sieve();
        for (int i =0 ; i<10; i++)
        {
            if(prime[i]==0)
            {
                ptr = b ;
                printf("Number :%d %s \n",i,ptr ) ;

            }
            else if (prime[i]==1)
            {
                ptr =a ;
                printf("Number :%d %s \n",i,ptr) ;
                
            }
        }


    }

# Bss segment

Khái niệm:

BSS Segment (Block Started by Symbol) là một vùng bộ nhớ trong chương trình, được sử dụng để lưu trữ các biến toàn cục và biến tĩnh (static) chưa được khởi tạo hoặc được khởi tạo bằng 0 (zero). Đây là một trong những vùng quan trọng của bộ nhớ trong chương trình, đặc biệt khi làm việc với các biến toàn cục hoặc tĩnh.

Bss segment đặc điểm:

* Lưu trữ các biến toàn cục và tĩnh chưa khởi tạo: Các biến này chưa được gán giá trị cụ thể khi khai báo.
* Khởi tạo bằng 0: Nếu biến chưa được khởi tạo giá trị, hệ thống tự động khởi tạo giá trị 0.
* Tối ưu bộ nhớ: Không thực sự chiếm dung lượng trong file chương trình đã biên dịch (file executable), nhưng khi chạy chương trình, các biến này sẽ được cấp phát không gian trong bộ nhớ RAM.


ví dụ:

    #include <stdio.h>

    void count_repeats(int arr[], int n, int x) {
        static int repeat_count;  // Biến tĩnh, nằm trong BSS Segment
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                repeat_count++;
            }
        }

        printf("Element %d appears %d times\n", x, repeat_count);
    }

    int main() 
    {
        int arr[] = {1, 2, 2, 3, 2, 4};
        count_repeats(arr, 6, 2);
        return 0;
    }

# Stack

Khái niệm:

Stack là một vùng bộ nhớ trong chương trình, được sử dụng để lưu trữ các biến cục bộ, tham số của hàm, và địa chỉ trả về của hàm trong khi chương trình đang thực thi. Stack là vùng bộ nhớ có cấu trúc LIFO (Last In, First Out), nghĩa là phần tử được đẩy vào cuối cùng sẽ được lấy ra đầu tiên.

Stack đặc điểm:
1.Lưu trữ biến cục bộ:
*Mỗi khi một hàm được gọi, các biến cục bộ trong hàm sẽ được lưu trữ trên stack.
* Khi hàm kết thúc, các biến cục bộ này sẽ bị xóa khỏi stack.

2.Lưu trữ tham số hàm:
* Các tham số được truyền vào hàm cũng được lưu trên stack.
* Điều này giúp hàm có thể truy cập các tham số mà nó nhận được khi được gọi.

3.Lưu trữ địa chỉ trả về:
* Khi một hàm được gọi, địa chỉ của vị trí tiếp theo trong chương trình (sau khi hàm thực hiện xong) được lưu trên stack.
* Khi hàm kết thúc, chương trình sẽ quay lại vị trí địa chỉ này để tiếp tục thực thi.

4.Quản lý tự động:
* Stack được quản lý tự động bởi trình biên dịch và hệ điều hành. Bạn không cần phải tự động quản lý bộ nhớ cho các biến cục bộ hay tham số hàm.
* Khi hàm được gọi, các biến cục bộ sẽ tự động được cấp phát trên stack, và khi hàm kết thúc, bộ nhớ sẽ tự động được thu hồi.

5.Kích thước giới hạn:
* Kích thước của stack thường bị giới hạn bởi hệ điều hành. Nếu sử dụng quá nhiều bộ nhớ stack (do đệ quy sâu hoặc khai báo mảng lớn trong hàm), có thể gây ra lỗi Stack Overflow.
* Cấp phát tĩnh (Static Allocation):

Bộ nhớ trên stack được cấp phát và giải phóng theo thứ tự LIFO và không thay đổi trong suốt thời gian thực thi hàm.
Các biến trên stack không thể tồn tại sau khi hàm kết thúc.

ví dụ:

    #include <stdio.h>

    // Hàm tính giai thừa sử dụng đệ quy
    int factorial(int n) 
    {
        if (n == 0) 
        {
            return 1;  // Điều kiện dừng của đệ quy
        }
        return n * factorial(n - 1);  // Gọi đệ quy
    }

    int main() 
    {
        int num = 5;  // Biến cục bộ, được lưu trên stack
        int result = factorial(num);  // Gọi hàm, lưu các tham số và biến cục bộ của hàm trên stack
        printf("Factorial of %d is %d\n", num, result);  // In kết quả
        return 0;
    }

# Heap

Khái niệm:
Heap là một vùng bộ nhớ trong chương trình C, được sử dụng để cấp phát và quản lý bộ nhớ động trong thời gian chạy. Bộ nhớ trên heap được cấp phát thủ công bằng các hàm như malloc(), calloc(), hoặc realloc() và cần được giải phóng khi không còn sử dụng bằng cách gọi hàm free().

Chức năng của Heap:

1.Cấp phát bộ nhớ động:
* Trong chương trình trên, chúng ta sử dụng malloc() để cấp phát một mảng động có kích thước n trên heap. malloc() trả về một con trỏ trỏ đến vùng nhớ đã được cấp phát.
* Kích thước của bộ nhớ cấp phát là n * sizeof(int), đủ để lưu trữ n số nguyên.

2. Kiểm tra việc cấp phát:
* Sau khi gọi malloc(), nếu ptr là NULL, nghĩa là việc cấp phát bộ nhớ thất bại do hệ thống không có đủ bộ nhớ trống.

3. Sử dụng bộ nhớ trên heap:
* Sau khi cấp phát thành công, chúng ta có thể sử dụng bộ nhớ này như một mảng động để lưu trữ và in ra các phần tử.

4. Giải phóng bộ nhớ:
* Sau khi sử dụng xong, chúng ta cần gọi hàm free() để giải phóng bộ nhớ đã cấp phát trên heap. Nếu không gọi free(), bộ nhớ sẽ không được giải phóng và có thể dẫn đến memory leak.

ví dụ:

    #include <stdio.h>
    #include <stdlib.h>  // Thư viện cho các hàm malloc, free

    int main() 

    {
        int *ptr;
        int n = 5;

        // Nhập số phần tử
        printf("Enter number of elements: ");
        scanf("%d", &n);

        // Cấp phát bộ nhớ động cho mảng
        ptr = (int *)malloc(n * sizeof(int));

        // Kiểm tra nếu cấp phát bộ nhớ thất bại
        if (ptr == NULL) 
        {
            printf("Memory not allocated.\n");
            return 1;
        }

        // Gán giá trị và in mảng
        printf("Memory successfully allocated using malloc.\n");
        for (int i = 0; i < n; i++) 
        {
            ptr[i] = i + 1;
            printf("%d ", ptr[i]);
        }
        printf("\n");

        // Giải phóng bộ nhớ
        free(ptr);

        return 0;
    }


# Malloc

Khái niệm malloc() trong Heap:

Trong C, malloc() (Memory Allocation) là một hàm được sử dụng để cấp phát bộ nhớ động từ vùng heap. Bộ nhớ được cấp phát bởi malloc() sẽ không được khởi tạo (các giá trị trong bộ nhớ là ngẫu nhiên), và nó cho phép lập trình viên xác định kích thước của bộ nhớ cần cấp phát trong thời gian chạy (runtime), thay vì xác định trước như với các biến tĩnh hoặc biến cục bộ.

Đặc điểm của malloc():

* Cấp phát từ vùng Heap: Bộ nhớ được cấp phát từ vùng heap và tồn tại cho đến khi bạn giải phóng nó bằng cách sử dụng hàm free().
* Không khởi tạo giá trị: Bộ nhớ cấp phát bằng malloc() không được khởi tạo, nghĩa là giá trị bên trong nó là ngẫu nhiên và phụ thuộc vào trạng thái của bộ nhớ trước đó.
* Yêu cầu giải phóng thủ công: Sau khi sử dụng xong, bạn phải giải phóng bộ nhớ đã cấp phát bằng hàm free() để tránh memory leak (rò rỉ bộ nhớ).

ví dụ:

    #include <stdio.h>
    #include <stdlib.h>

    int main() 
    {
        int *arr;
        int n, i, sum = 0;

        // Nhập số phần tử cho mảng
        printf("Enter number of elements: ");
        scanf("%d", &n);

        // Cấp phát bộ nhớ động cho mảng
        arr = (int *)malloc(n * sizeof(int));

        // Kiểm tra nếu cấp phát bộ nhớ thất bại
        if (arr == NULL) 
        {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Nhập các phần tử vào mảng và tính tổng
        printf("Enter %d integers: ", n);
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }

        // In ra tổng các phần tử
        printf("Sum of array elements: %d\n", sum);

        // Giải phóng bộ nhớ
        free(arr);

        return 0;
    }

#Calloc

Khái niệm:
calloc() (Contiguous Allocation) là một hàm dùng để cấp phát bộ nhớ động từ vùng heap. calloc() tương tự như malloc(), nhưng có một điểm khác biệt chính: calloc() không chỉ cấp phát bộ nhớ mà còn khởi tạo tất cả các byte của vùng nhớ đó về 0.

ví dụ:

    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int *arr;
        int n, i;

        // Nhập số phần tử cần cấp phát
        printf("Enter number of elements: ");
        scanf("%d", &n);

        // Cấp phát bộ nhớ động cho mảng bằng calloc
        arr = (int *)calloc(n, sizeof(int));

        // Kiểm tra nếu cấp phát bộ nhớ thất bại
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // In ra các giá trị mặc định của mảng (đã được khởi tạo bằng 0)
        printf("Array elements initialized by calloc: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Giải phóng bộ nhớ
        free(arr);

        return 0;
    }

# realloc

khái niệm :

hàm realloc() (Reallocation) được sử dụng để thay đổi kích thước của vùng bộ nhớ đã được cấp phát trước đó (từ malloc(), calloc(), hoặc realloc()). Vùng nhớ được cấp phát nằm trên heap, và realloc() cho phép tăng hoặc giảm kích thước của vùng nhớ này mà vẫn giữ nguyên nội dung hiện có trong vùng nhớ (đến mức có thể).

Đặc điểm của realloc():

1. Thay đổi kích thước vùng nhớ:
* Nếu kích thước mới lớn hơn kích thước cũ, nội dung của vùng nhớ cũ sẽ được sao chép sang vùng nhớ mới, và phần bổ sung của vùng nhớ mới sẽ có giá trị không xác định (không được khởi tạo).
* Nếu kích thước mới nhỏ hơn kích thước cũ, nội dung ngoài phạm vi mới sẽ bị cắt bỏ.

2. Di chuyển vùng nhớ:
* Nếu vùng nhớ hiện tại không có đủ không gian để mở rộng, realloc() sẽ cấp phát một vùng nhớ mới có kích thước lớn hơn và sao chép nội dung cũ sang vùng mới. Sau đó, vùng nhớ cũ sẽ được giải phóng tự động.

3. NULL như malloc():
* Nếu con trỏ ptr ban đầu là NULL, realloc() hoạt động giống như malloc(), tức là nó cấp phát một vùng nhớ mới có kích thước new_size.

4. Giải phóng bộ nhớ:
* Nếu kích thước mới là 0, realloc() có thể trả về NULL và giải phóng vùng nhớ hiện tại.

ví dụ:

    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int *arr;
        int i, n1, n2;

        // Nhập số phần tử ban đầu
        printf("Enter initial number of elements: ");
        scanf("%d", &n1);

        // Cấp phát bộ nhớ cho n1 phần tử bằng malloc
        arr = (int *)malloc(n1 * sizeof(int));

        // Kiểm tra việc cấp phát bộ nhớ
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Nhập các giá trị ban đầu cho mảng
        printf("Enter %d elements:\n", n1);
        for (i = 0; i < n1; i++) {
            scanf("%d", &arr[i]);
        }

        // Nhập số phần tử mới cần cấp phát
        printf("Enter new size for array: ");
        scanf("%d", &n2);

        // Cấp phát lại bộ nhớ với kích thước mới bằng realloc
        arr = (int *)realloc(arr, n2 * sizeof(int));

        // Kiểm tra việc cấp phát lại bộ nhớ
        if (arr == NULL) {
            printf("Memory reallocation failed!\n");
            return 1;
        }

        // Nếu kích thước mới lớn hơn, nhập thêm giá trị cho các phần tử mới
        if (n2 > n1) {
            printf("Enter %d more elements:\n", n2 - n1);
            for (i = n1; i < n2; i++) {
                scanf("%d", &arr[i]);
            }
        }

        // In mảng sau khi cấp phát lại
        printf("Array elements after realloc:\n");
        for (i = 0; i < n2; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Giải phóng bộ nhớ
        free(arr);

        return 0;
    }


# Stack

khái niệm cấu trúc Stack:

Stack (ngăn xếp) là một cấu trúc dữ liệu tuân theo nguyên tắc "Last In, First Out" (LIFO), nghĩa là phần tử cuối cùng được thêm vào stack sẽ là phần tử đầu tiên được lấy ra. 
Các thao tác cơ bản trên stack bao gồm:
* "push" để thêm một phần tử vào đỉnh của stack
*  "pop" để xóa một phần tử ở đỉnh stack.
* “top” để lấy giá trị của phần tử ở đỉnh stack.

ví dụ:
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct 
{
    int *items;
    int top ;
    int size ;

    /* data */
}Stack;


void initStack(Stack *s, int size)
{
    s->size = size ;
    s->top = -1 ;
    s-> items = (int *)malloc (size *sizeof(int));
    if (s->items == NULL)
    {
        printf(" Memory allocation failled! \n");
        exit(1);
    }

}

int Stack_Empty(Stack *s)
{
    return s->top == - 1 ;
}


int Stack_Full(Stack *s)
{
    return s->top == s->size - 1 ;
}

void push(Stack *s, int value) {
    if (Stack_Full(s)) 
    {
        printf("Stack is full! Cannot push %d\n", value);
    } 
    else 
    {
        s->top++;
        s->items[s->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Lấy phần tử ra khỏi Stack (pop)
int pop(Stack *s) {
    if (Stack_Empty(s)) {
        printf("Stack is empty! Cannot pop\n");
        return -1;
    } else {
        int poppedValue = s->items[s->top];
        s->top--;
        return poppedValue;
    }
}

int peek(Stack *s)
{
    if(Stack_Empty(s))
    {
        printf("Stack is empty!\n");
        return(-1);
    }
    else
    {
        return s->items[s->top];
    }
}

void Display(Stack *s)// hien thi phan tu trong stack
{
    if(Stack_Empty(&s))
    {
        printf("Stack is empty!");
    }

    else
    {
        printf("Stack element: \n");
        
          for (int i = 0; i <= s->top; i++) 
            {
            printf("%d ", s->items[i]);
            }
    }
}


int main(int argc, char const *argv[])
{
    Stack s;
    initStack(&s,3);

    push(&s,25) ;// thêm phần tử vào stack
    push(&s,45) ;
    push(&s,14) ;
    push(&s,28) ;
    
    printf("popped element: %d\n", pop(&s)) ;
    push(&s,10) ;
    printf("Top element is: %d\n", peek(&s));

    
    Display(&s) ;
    
    return 0;

}

# json

Khái niệm:


JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.


ví dụ:

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <ctype.h>
    #include <stdbool.h>

    // Định nghĩa các kiểu dữ liệu trong JSON
    typedef enum 
    {
        JSON_NULL,    // Kiểu null
        JSON_BOOLEAN, // Kiểu boolean (true/false)
        JSON_NUMBER,  // Kiểu số (integer hoặc floating-point)
        JSON_STRING,  // Kiểu chuỗi
        JSON_ARRAY,   // Kiểu mảng
        JSON_OBJECT   // Kiểu đối tượng
    } JsonType;

    // Cấu trúc JsonValue chứa giá trị JSON
    typedef struct JsonValue 
    {
        JsonType type;  // Kiểu dữ liệu của giá trị JSON

        union 
        {
            int boolean;      // Giá trị boolean (true/false)
            double number;    // Giá trị số
            char *string;     // Chuỗi ký tự

            struct 
            {
                struct JsonValue *values; // Mảng các giá trị trong JSON
                size_t count;             // Số lượng phần tử trong mảng
            } array;

            struct 
            {
                char **keys;             // Mảng các khóa của đối tượng
                struct JsonValue *values; // Mảng các giá trị tương ứng với khóa
                size_t count;             // Số lượng cặp khóa-giá trị
            } object;

        } value;

    } JsonValue;

    // Hàm chính để phân tích cú pháp JSON
    JsonValue *parse_json(const char **json);

    // Hàm giải phóng bộ nhớ của giá trị JSON
    void free_json_value(JsonValue *json_value);

    // Bỏ qua khoảng trắng trong chuỗi JSON
    static void skip_whitespace(const char **json) 
    {
        while (isspace(**json)) 
        {
            (*json)++;
        }
    }

    // Hàm phân tích cú pháp giá trị null
    JsonValue *parse_null(const char **json) 
    {
        skip_whitespace(json); // Bỏ qua khoảng trắng
        if (strncmp(*json, "null", 4) == 0) 
        {
            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue)); // Cấp phát bộ nhớ cho giá trị JSON null
            value->type = JSON_NULL; // Thiết lập kiểu dữ liệu là null
            *json += 4; // Dịch con trỏ qua "null"
            return value;
        }
        return NULL;
    }

    // Hàm phân tích cú pháp giá trị boolean
    JsonValue *parse_boolean(const char **json) 
    {
        skip_whitespace(json); // Bỏ qua khoảng trắng
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue)); // Cấp phát bộ nhớ cho giá trị boolean
        if (strncmp(*json, "true", 4) == 0) 
        {
            value->type = JSON_BOOLEAN;
            value->value.boolean = true; // Gán giá trị boolean là true
            *json += 4;
        } else if (strncmp(*json, "false", 5) == 0) 
        {
            value->type = JSON_BOOLEAN;
            value->value.boolean = false; // Gán giá trị boolean là false
            *json += 5;
        } 
        else 
        {
            free(value); // Không phải giá trị hợp lệ, giải phóng bộ nhớ
            return NULL;
        }
        return value;
    }

    // Hàm phân tích cú pháp giá trị số
    JsonValue *parse_number(const char **json) 
    {
        skip_whitespace(json); // Bỏ qua khoảng trắng
        char *end;
        double num = strtod(*json, &end); // Chuyển chuỗi thành số
        if (end != *json) 
        {
            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue)); // Cấp phát bộ nhớ cho số
            value->type = JSON_NUMBER;
            value->value.number = num; // Gán giá trị số
            *json = end; // Di chuyển con trỏ đến phần sau số
            return value;
        }
        return NULL;
    }

    // Hàm phân tích cú pháp chuỗi
    JsonValue *parse_string(const char **json) 
    {
        skip_whitespace(json); // Bỏ qua khoảng trắng
        if (**json == '\"') // Kiểm tra nếu ký tự bắt đầu là dấu "
        {
            (*json)++; // Bỏ qua dấu "
            const char *start = *json; // Lưu vị trí bắt đầu của chuỗi
            while (**json != '\"' && **json != '\0') // Duyệt tới khi gặp dấu "
            {
                (*json)++;
            }

            if (**json == '\"') 
            {
                size_t length = *json - start; // Độ dài chuỗi
                char *str = (char *) malloc((length + 1) * sizeof(char)); // Cấp phát bộ nhớ cho chuỗi
                strncpy(str, start, length); // Sao chép chuỗi
                str[length] = '\0'; // Kết thúc chuỗi

                JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue)); // Cấp phát bộ nhớ cho JsonValue
                
                value->type = JSON_STRING;

                value->value.string = str; // Gán giá trị chuỗi

                (*json)++; // Bỏ qua dấu " kết thúc

                return value;
            }
        }
        return NULL;
    }

    // Hàm phân tích cú pháp mảng
    JsonValue *parse_array(const char **json) 
    {
        skip_whitespace(json); // Bỏ qua khoảng trắng
        if (**json == '[') // Kiểm tra ký tự bắt đầu có phải là '['
        {
            (*json)++; // Bỏ qua dấu '['
            skip_whitespace(json); // Bỏ qua khoảng trắng

            JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue)); // Cấp phát bộ nhớ cho đối tượng JSON kiểu mảng
            array_value->type = JSON_ARRAY;
            array_value->value.array.count = 0; // Khởi tạo số phần tử ban đầu của mảng
            array_value->value.array.values = NULL; // Khởi tạo mảng giá trị rỗng

            // Duyệt qua từng phần tử trong mảng
            while (**json != ']' && **json != '\0') 
            {
                JsonValue *element = parse_json(json); // Gọi đệ quy để phân tích phần tử trong mảng
                if (element) 
                {
                    array_value->value.array.count++; // Tăng số lượng phần tử mảng
                    array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue)); // Cấp phát thêm bộ nhớ cho phần tử mới
                    array_value->value.array.values[array_value->value.array.count - 1] = *element; // Lưu phần tử mới vào mảng
                    free(element); // Giải phóng bộ nhớ tạm thời của phần tử
                } else {
                    break;
                }
                skip_whitespace(json); // Bỏ qua khoảng trắng
                if (**json == ',') 
                {
                    (*json)++; // Bỏ qua dấu phẩy giữa các phần tử
                }
            }
            if (**json == ']') 
            {
                (*json)++; // Bỏ qua dấu ']' kết thúc mảng
                return array_value;
            } else {
                free_json_value(array_value); // Giải phóng bộ nhớ nếu có lỗi
                return NULL;
            }
        }
        return NULL;
    }

    // Hàm phân tích cú pháp đối tượng
    JsonValue *parse_object(const char **json) 
    {
        skip_whitespace(json); // Bỏ qua khoảng trắng
        if (**json == '{') // Kiểm tra ký tự mở đầu đối tượng có phải là '{'
        {
            (*json)++; // Bỏ qua dấu '{'
            skip_whitespace(json); // Bỏ qua khoảng trắng

            JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue)); // Cấp phát bộ nhớ cho đối tượng JSON
            object_value->type = JSON_OBJECT;
            object_value->value.object.count = 0; // Khởi tạo số lượng cặp khóa-giá trị
            object_value->value.object.keys = NULL;    // Khởi tạo mảng khóa rỗng
            object_value->value.object.values = NULL;  // Khởi tạo mảng giá trị rỗng

            // Duyệt qua từng cặp khóa-giá trị trong đối tượng
            while (**json != '}' && **json != '\0') 
            {
                JsonValue *key = parse_string(json); // Phân tích cú pháp khóa là chuỗi
                if (key) 
                {
                    skip_whitespace(json); // Bỏ qua khoảng trắng
                    if (**json == ':') // Kiểm tra có phải dấu ':' giữa khóa và giá trị
                    {
                        (*json)++; // Bỏ qua dấu ':'
                        JsonValue *value = parse_json(json); // Phân tích cú pháp giá trị
                        if (value) 
                        {
                            object_value->value.object.count++; // Tăng số lượng cặp khóa-giá trị
                            object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *)); // Cấp phát thêm bộ nhớ cho khóa
                            object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string; // Gán khóa vào đối tượng

                            object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue)); // Cấp phát thêm bộ nhớ cho giá trị
                            object_value->value.object.values[object_value->value.object.count - 1] = *value; // Gán giá trị vào đối tượng
                            free(value); // Giải phóng bộ nhớ tạm thời của giá trị
                        } 
                        else 
                        {
                            free_json_value(key); // Giải phóng bộ nhớ nếu phân tích giá trị lỗi
                            break;
                        }
                    } else {
                        free_json_value(key); // Giải phóng bộ nhớ nếu phân tích khóa lỗi
                        break;
                    }
                } else {
                    break;
                }
                skip_whitespace(json); // Bỏ qua khoảng trắng
                if (**json == ',') 
                {
                    (*json)++; // Bỏ qua dấu phẩy giữa các cặp khóa-giá trị
                }
            }
            if (**json == '}') 
            {
                (*json)++; // Bỏ qua dấu '}' kết thúc đối tượng
                return object_value;
            } else {
                free_json_value(object_value); // Giải phóng bộ nhớ nếu có lỗi
                return NULL;
            }
        }
        return NULL;
    }

    // Hàm chính để phân tích cú pháp JSON dựa vào ký tự đầu tiên
    JsonValue *parse_json(const char **json) 
    { 
        while (isspace(**json)) {
            (*json)++; // Bỏ qua khoảng trắng
        }

        switch (**json)
        {
            case 'n':
                return parse_null(json); // Phân tích giá trị null
            case 't':
            case 'f':
                return parse_boolean(json); // Phân tích boolean true hoặc false
            case '\"':
                return parse_string(json); // Phân tích chuỗi
            case '[':
                return parse_array(json); // Phân tích mảng
            case '{':
                return parse_object(json); // Phân tích đối tượng
            default:
                if (isdigit(**json) || **json == '-') {
                    return parse_number(json); // Phân tích giá trị số
                } else {
                    return NULL; // Lỗi phân tích cú pháp nếu không phải định dạng JSON hợp lệ
                }
        }
    }

    // Giải phóng bộ nhớ của đối tượng JSON
    void free_json_value(JsonValue *json_value) {
        if (json_value == NULL) {
            return;
        }

        switch (json_value->type) {
            case JSON_STRING:
                free(json_value->value.string); // Giải phóng chuỗi
                break;

            case JSON_ARRAY:
                for (size_t i = 0; i < json_value->value.array.count; i++) {
                    free_json_value(&json_value->value.array.values[i]); // Giải phóng các phần tử trong mảng
                }
                free(json_value->value.array.values); // Giải phóng mảng
                break;

            case JSON_OBJECT:
                for (size_t i = 0; i < json_value->value.object.count; i++) {
                    free(json_value->value.object.keys[i]); // Giải phóng khóa
                    free_json_value(&json_value->value.object.values[i]); // Giải phóng giá trị
                }
                free(json_value->value.object.keys); // Giải phóng mảng khóa
                free(json_value->value.object.values); // Giải phóng mảng giá trị
                break;

            default:
                break;
        }
    }

    // Hàm in nội dung JSON đã phân tích (đệ quy với đối tượng và mảng)
    void test(JsonValue* json_value){
        if (json_value != NULL && json_value->type == JSON_OBJECT) {
            size_t num_fields = json_value->value.object.count; // Lấy số lượng trường trong đối tượng
            for (size_t i = 0; i < num_fields; ++i) {
                char* key = json_value->value.object.keys[i]; // Lấy khóa
                JsonValue* value = &json_value->value.object.values[i]; // Lấy giá trị
                JsonType type = json_value->value.object.values[i].type; // Lấy kiểu giá trị

                if(type == JSON_STRING){
                    printf("%s: %s\n", key, value->value.string); // In chuỗi
                }

                if(type == JSON_NUMBER){
                    printf("%s: %f\n", key, value->value.number); // In số
                }

                if(type == JSON_BOOLEAN){
                    printf("%s: %s\n", key, value->value.boolean ? "True":"False"); // In boolean
                }

                if(type == JSON_OBJECT){
                    printf("%s: \n", key);
                    test(value); // Gọi đệ quy để in đối tượng con
                }

                if(type == JSON_ARRAY){
                    printf("%s: ", key);
                    for (int i = 0; i < value->value.array.count; i++)
                    {
                    test(value->value.array.values + i); // Gọi đệ quy để in các phần tử trong mảng
                    } 
                    printf("\n");
                }
            }
        }
        else 
        {
            if(json_value->type == JSON_STRING){
                printf("%s ", json_value->value.string); // In chuỗi
            }

            if(json_value->type == JSON_NUMBER){
                printf("%f ", json_value->value.number); // In số
            }

            if(json_value->type == JSON_BOOLEAN){
                printf("%s ", json_value->value.boolean ? "True":"False"); // In boolean
            }

            if(json_value->type == JSON_OBJECT){
                printf("%s: \n", json_value->value.object.keys);
                test(json_value->value.object.values); // Gọi đệ quy để in đối tượng con
            }
        }
    }

    // Hàm main để kiểm thử
    int main(int argc, char const *argv[])
    {
        // Chuỗi JSON đầu vào
        const char* json_str = "{"
                            "\"1001\":{"
                            "\"SoPhong\":3,"
                            "\"NguoiThue\":{"
                                "\"Ten\":\"Nguyen Van A\","
                                "\"CCCD\":\"1920517781\","
                                "\"Tuoi\":26,"
                                "\"ThuongTru\":{"
                                "\"Duong\":\"73 Ba Huyen Thanh Quan\","
                                "\"Phuong_Xa\":\"Phuong 6\","
                                "\"Tinh_TP\":\"Ho Chi Minh\""
                                "}"
                            "},"
                            "\"SoNguoiO\":{"
                                "\"1\":\"Nguyen Van A\","
                                "\"2\":\"Nguyen Van B\","
                                "\"3\":\"Nguyen Van C\""
                            "},"
                            "\"TienDien\": [24, 56, 98],"
                            "\"TienNuoc\":30.000"
                            "},"
                            "\"1002\":{"
                            "\"SoPhong\":5,"
                            "\"NguoiThue\":{"
                                "\"Ten\":\"Phan Hoang Trung\","
                                "\"CCCD\":\"012345678912\","
                                "\"Tuoi\":24,"
                                "\"ThuongTru\":{"
                                "\"Duong\":\"53 Le Dai Hanh\","
                                "\"Phuong_Xa\":\"Phuong 11\","
                                "\"Tinh_TP\":\"Ho Chi Minh\""
                                "}"
                            "},"
                            "\"SoNguoiO\":{"
                                "\"1\":\"Phan Van Nhat\","
                                "\"2\":\"Phan Van Nhi\","
                                "\"2\":\"Phan Van Tam\","
                                "\"3\":\"Phan Van Tu\""
                            "},"
                            "\"TienDien\":23.000,"
                            "\"TienNuoc\":40.000"
                            "}"
                        "}";

        // Phân tích cú pháp chuỗi JSON
        JsonValue* json_value = parse_json(&json_str);

        // In kết quả phân tích
        test(json_value);

        // Giải phóng bộ nhớ được cấp phát cho JsonValue
        free_json_value(json_value);
        
        return 0;
    }


# linked lish
 
Khái niệm

Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.


    #include <stdio.h>
    #include <stdlib.h>

    typedef struct node
    {
        int value;
        struct node* next;
    }node;


    node* createNode(int value)
    {
        node* ptr = (node*)malloc(sizeof(node));
        ptr->value = value;
        ptr->next = NULL;
        return ptr;
    }


    void push_back(node** array, int value) //them node cuoi danh sach
    {
        node* temp;
        temp = createNode(value); // khoi tao node
                                // temp = 0xa1
    
        
        if (*array == NULL)   // if array doesn't have any node yet
        {

            *array = temp;
        }
        else                // if array has some node
        {
            node* p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist
            while (p->next != NULL) // which mean the current node is not the last node
            {
                p = p->next;    // check next node until it a last node

            }

            p->next = temp;     // change it next member point to address of new node have just create
        }
    }

    void pop_back(node** array)// xóa 1 node cuoi cung
    {
        node* p, * temp;
        p = *array;

        int i = 0; // to 

        while (p->next->next != NULL)     // free the last node in the list
        {
            p = p->next;
            i++;
        }
        temp = p->next;
        p->next = NULL;
        free(temp);

    }



    int get(node* array, int pos)// lay gia tri cua 1 node tai vi tri bat ky
    {
        int i = 0;
    
        while (array->next != NULL && pos != i)
        {
            array = array->next;
            i++;
        }

        if (pos != i)
        {
            printf("Error: List has less element\n");
            return 0;
        }

        int value = array->value;
        return value;
    }

    void pop_front(node** array) // xoa node dau tien

    {

        node* temp ;
        temp = *array ;

        *array = temp->next;
        free(temp);

    }

    void insert(node **array, int value, int pos) // thêm gia tri cua 1 node 
    {
        node* new = createNode(value) ;
        if (pos==0)
        {
            new->next = *array ; // gan dia chi co node moi
            *array = new ; // cap nhat lai dia chi cho con tro linked list
        }

        node* temp =*array ;
        int i = 0;
        while (i<pos-1 && temp->next!= NULL)
        {

            temp = temp->next ;
            i++;
            /* code */
        }
        new->next = temp->next ;
        temp->next = new ;
        
    }

    void displayList(node* head) {
        node* temp = head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }


    void getListInfo(node* head, int* nodeCount, size_t* totalSize) // lay thong tin cua chuoi
    {
        *nodeCount = 0;  // Khởi tạo biến đếm số lượng phần tử
        *totalSize = 0;  // Khởi tạo tổng kích thước byte

        node* temp = head;  // Biến tạm để duyệt danh sách

        while (temp != NULL) 
        {
            (*nodeCount)++;               // Tăng biến đếm cho mỗi node
            *totalSize += sizeof(node);   // Cộng thêm kích thước của mỗi node
            temp = temp->next;            // Di chuyển sang node kế tiếp
        }
    }


    void deleteAtPosition(node** head, int pos) //xoa 1 node tai vi tri bat ky
    {
        // Kiểm tra nếu danh sách rỗng
        if (*head == NULL) {
            printf("danh sach rong.\n");
            return;
        }

        node* temp = *head;

        // Trường hợp xóa node đầu tiên (vị trí 0)
        if (pos == 0) {
            *head = temp->next;  // Cập nhật head
            free(temp);           // Giải phóng bộ nhớ
            printf("da xoa node %d\n", pos);
            return;
        }

        //tm vi tri node can xoa
        int i = 0;
        while (i<pos-1 && temp->next!= NULL)
        {

            temp = temp->next ;
            i++;
            /* code */
        }

        // vi tri node can xoa nam ngoai danh sach
        if (temp == NULL || temp->next == NULL) {
            printf("node khong co trong danh sach.\n");
            return;
        }

        // Node cần xóa là temp->next
        node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;  // Cập nhật liên kết

        free(nodeToDelete);  // Giải phóng bộ nhớ
        printf("da xoa node %d\n", pos);
    }




    int main()
    {
        node* arr = NULL;
        push_back(&arr, 2);
        push_back(&arr, 7);
        push_back(&arr, 4);
        push_back(&arr, 5);
        push_back(&arr, 3);
        push_back(&arr, 10);

        pop_front(&arr);

        insert(&arr,45,3) ;

        displayList(arr);
        size_t  size =0;
        int count =0;
        getListInfo(arr,&count,&size) ;

        deleteAtPosition(&arr,3);
        displayList(arr);
        printf("so luong phan tu: %d\n",count );
        printf("tong kich thuoc byte: %zu bytes\n", size);

        return 0;
    }



# C++

# I.Class

khái niệm:
Class (lớp) là một khái niệm quan trọng trong lập trình hướng đối tượng (OOP) trong C++. Một class là một bản thiết kế (blueprint) cho một đối tượng (object), định nghĩa các thuộc tính (biến) và phương thức (hàm) mà đối tượng sẽ có. Nó giúp tổ chức dữ liệu và chức năng liên quan thành một đơn vị duy nhất.

Một lớp bao gồm hai thành phần chính:

Thuộc tính (Attributes hay Members): Là các biến dữ liệu được khai báo trong lớp.
Phương thức (Methods hay Functions): Là các hàm định nghĩa các hành vi của lớp, dùng để thao tác với dữ liệu

ví dụ:

    #include <iostream>
    using namespace std;

    // Định nghĩa lớp Car
    class Car 
    {
    private:
        string brand;
        int year;

    public:
        // Hàm khởi tạo (Constructor) để khởi tạo đối tượng
        Car(string b, int y) 
        {
            brand = b;
            year = y;
        }

        // Phương thức hiển thị thông tin xe
        void displayInfo() 
        {
            cout << "Brand: " << brand << ", Year: " << year << endl;
        }

        // Setter: Cập nhật thông tin brand
        void setBrand(string b) 
        {
            brand = b;
        }

        // Getter: Lấy thông tin brand
        string getBrand() 
        {
            return brand;
        }
    };

    int main() {
        // Tạo một đối tượng Car
        Car car1("Toyota", 2020);

        // Gọi phương thức hiển thị thông tin xe
        car1.displayInfo();

        // Thay đổi thuộc tính brand bằng setter
        car1.setBrand("Honda");

        // Hiển thị lại thông tin xe sau khi cập nhật
        car1.displayInfo();

        return 0;
    }

# OOP

## II.Tính đóng gói

Khái niệm: Tính đóng gói (Encapsulation) là một trong những nguyên tắc quan trọng của lập trình hướng đối tượng (OOP). Nó đảm bảo rằng dữ liệu và các phương thức (hàm) của một đối tượng được đóng gói lại với nhau và được bảo vệ khỏi sự can thiệp từ bên ngoài, chỉ có thể truy cập thông qua các phương thức được cho phép. Điều này giúp tăng tính bảo mật, kiểm soát và duy trì tính toàn vẹn của dữ liệu.

Ý nghĩa của tính đóng gói:

+Bảo vệ dữ liệu: Các thuộc tính (biến thành viên) của lớp có thể được khai báo là private hoặc protected để ngăn không cho các đối tượng bên ngoài trực tiếp truy cập hoặc thay đổi chúng.

+Ẩn chi tiết cài đặt: Người dùng đối tượng không cần biết chi tiết cài đặt bên trong của lớp, chỉ cần sử dụng các phương thức công khai (public) để thao tác với đối tượng.

+Kiểm soát truy cập: Việc truy cập và thay đổi dữ liệu được kiểm soát thông qua các phương thức getter và setter, đảm bảo tính hợp lệ và an toàn của dữ liệu.

ví dụ:

    #include <iostream>
    using namespace std;

    class Student {
    private:
        string name;
        int age;
        float gpa;

    public:
        // Constructor để khởi tạo thông tin sinh viên
        Student(string n, int a, float g) {
            name = n;
            age = a;
            gpa = g;
        }

        // Getter để lấy thông tin tên
        string getName() {
            return name;
        }

        // Setter để thay đổi tên
        void setName(string n) {
            name = n;
        }

        // Setter và getter để thay đổi hoặc lấy thông tin GPA
        float getGPA() {
            return gpa;
        }

        void setGPA(float g) {
            if (g >= 0.0 && g <= 4.0) {
                gpa = g;
            } else {
                cout << "Invalid GPA!" << endl;
            }
        }

        // Phương thức hiển thị thông tin sinh viên
        void displayInfo() {
            cout << "Student Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
        }
    };

    int main() {
        // Tạo một đối tượng sinh viên
        Student student1("Alice", 20, 3.5);

        // Hiển thị thông tin ban đầu
        student1.displayInfo();

        // Cập nhật thông tin sinh viên
        student1.setGPA(3.8);
        student1.setName("Alice Nguyen");

        // Hiển thị lại thông tin sau khi cập nhật
        student1.displayInfo();

        return 0;
    }


## III TÍNH KẾ THỪA

 khái niệm:
Nó cho phép một lớp con (subclass) kế thừa các thuộc tính và phương thức của một lớp cha (superclass). Lớp con có thể sử dụng, mở rộng hoặc ghi đè các thuộc tính và phương thức của lớp cha để tạo ra hành vi mới hoặc thêm chức năng.

Ưu điểm:

1.Tái sử dụng mã nguồn: Kế thừa cho phép sử dụng lại các thuộc tính và phương thức từ lớp cha mà không phải viết lại.

2.Mở rộng tính năng: Lớp con có thể thêm hoặc mở rộng các chức năng mới dựa trên những gì đã có từ lớp cha.

3.Dễ bảo trì và mở rộng: Khi có thay đổi, chỉ cần chỉnh sửa trong lớp cha, các lớp con sẽ tự động cập nhật.

Mức truy cập kế thừa (Inheritance Access Specifiers):

## Kế thừa MEMBER

+Các member public của class cha vẫn sẽ là public trong class con.
+Các member protected của class cha vẫn sẽ là protected trong class con.
+Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha

ví dụ

    #include <iostream>
    #include <string>
    using namespace std;

    // Lớp cha Person
    class Person {
    public:
        string name;      // Biến public - có thể truy cập trực tiếp từ bên ngoài
    protected:
        int age;          // Biến protected - chỉ truy cập được từ lớp dẫn xuất hoặc lớp cha
    private:
        string address;   // Biến private - chỉ truy cập được bên trong lớp Person

    public:
        // Constructor
        Person(string n, int a, string addr) : name(n), age(a), address(addr) {}

        // Phương thức public
        void display() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }

    protected:
        // Phương thức protected
        void displayAge() {
            cout << "Age (from protected method): " << age << endl;
        }

    private:
        // Phương thức private - chỉ có thể gọi bên trong lớp Person
        void displayAddress() {
            cout << "Address (from private method): " << address << endl;
        }

    public:
        // Public method to display address using the private method
        void showAddress() {
            displayAddress();
        }
    };

    // Lớp con Employee kế thừa từ Person
    class Employee : public Person {
    public:
        string position;  // Biến public của Employee

        // Constructor của Employee
        Employee(string n, int a, string addr, string pos) : Person(n, a, addr), position(pos) {}

        // Ghi đè phương thức display
        void display() {
            Person::display(); // Gọi phương thức display() của lớp cha
            cout << "Position: " << position << endl;
        }

        // Phương thức sử dụng biến protected của lớp cha
        void showProtected() {
            cout << "Accessing protected age from Person: " << age << endl;
        }

        // Phương thức sử dụng biến và phương thức protected từ lớp cha
        void showDetails() {
            displayAge();  // Gọi phương thức protected từ lớp cha
            cout << "Position: " << position << endl;
        }
    };

    int main() {
        // Tạo đối tượng của lớp Employee
        Employee emp("John Doe", 30, "123 Main St", "Software Engineer");

        // Gọi phương thức display của Employee
        emp.display();

        // Gọi phương thức showProtected để truy cập biến protected từ lớp cha
        emp.showProtected();

        // Gọi phương thức showDetails để sử dụng các biến protected và phương thức protected từ lớp cha
        emp.showDetails();

        // Truy cập biến public của lớp cha trực tiếp
        cout << "Directly accessing public variable from Person: " << emp.name << endl;

        // Truy cập biến public của lớp con
        cout << "Directly accessing public variable from Employee: " << emp.position << endl;

        // Truy cập địa chỉ thông qua phương thức public trong Person (dùng phương thức private)
        emp.showAddress();

        return 0;
    }

## KẾ THỪA METHODS

1.Kế thừa public:

+Các phương thức public của lớp cha sẽ vẫn là public trong lớp con.
+Các phương thức protected của lớp cha sẽ là protected trong lớp con.
+Các phương thức private không thể truy cập trực tiếp trong lớp con.

2.Kế thừa protected:

+Các phương thức public và protected của lớp cha sẽ trở thành protected trong lớp con.
+Các phương thức private của lớp cha vẫn không thể truy cập trực tiếp trong lớp con.

3.Kế thừa private:

+Tất cả các phương thức public và protected của lớp cha sẽ trở thành private trong lớp con.
+Các phương thức private của lớp cha vẫn không thể truy cập trực tiếp trong lớp con.


VÍ DỤ


    #include <iostream>
    using namespace std;

    class Person {
    public:
        void publicMethod() {
            cout << "Public method in Person" << endl;
        }

    protected:
        void protectedMethod() {
            cout << "Protected method in Person" << endl;
        }

    private:
        void privateMethod() {
            cout << "Private method in Person" << endl;
        }

    public:
        // Phương thức ảo để lớp con có thể ghi đè
        virtual void display() {
            cout << "Display method in Person" << endl;
        }
    };

    // Lớp con kế thừa `public` từ Person
    class Student : public Person {
    public:
        void useMethods() {
            publicMethod();        // Có thể gọi được vì kế thừa `public`
            protectedMethod();     // Có thể gọi được vì là `protected` và nằm trong lớp con
            // privateMethod();    // Không thể gọi vì privateMethod là `private` trong Person
        }

        // Ghi đè phương thức display()
        void display() override {
            Person::display();    // Gọi phương thức display() của lớp cha
            cout << "Display method in Student" << endl;
        }
    };

    // Lớp con kế thừa `protected` từ Person
    class Teacher : protected Person {
    public:
        void useMethods() {
            publicMethod();        // Có thể gọi được nhưng thành protected trong Teacher
            protectedMethod();     // Có thể gọi được vì là protected trong Person
        }

        void display() override {
            Person::display();
            cout << "Display method in Teacher" << endl;
        }
    };

    int main() {
        Student student;
        student.useMethods();
        student.display();

        cout << endl;

        Teacher teacher;
        teacher.useMethods();
        teacher.display();
        
        // Không thể gọi publicMethod từ đối tượng teacher vì nó đã thành protected
        // teacher.publicMethod();  // Lỗi biên dịch

        return 0;
    }

## TÍNH ĐA HÌNH

### 1.ĐA HÌNH TẠI THỜI ĐIỂM CHẠY

Khái niệm: Đa hình tại thời điểm chạy (Runtime Polymorphism) trong C++ là một tính năng cho phép gọi phương thức ghi đè của lớp con thông qua con trỏ hoặc tham chiếu của lớp cha trong thời gian chạy (runtime). Đa hình tại thời điểm chạy chủ yếu được thực hiện qua phương thức ảo (virtual functions), giúp C++ quyết định chính xác phương thức nào cần gọi khi chương trình đang chạy.

 + Khi một phương thức trong lớp cha được khai báo là virtual, phương thức này có thể được ghi đè (override) trong lớp con.

 + Khi gọi phương thức qua con trỏ hoặc tham chiếu của lớp cha trỏ đến đối tượng của lớp con, C++ sẽ gọi phương thức của lớp con thay vì của lớp cha.
 
 ưu điểm:

 + Linh hoạt trong việc sử dụng lớp cha và lớp con: Bạn có thể sử dụng cùng một kiểu dữ liệu (con trỏ hoặc tham chiếu của lớp cha) để làm việc với các lớp con khác nhau mà không cần thay đổi mã nguồn.

 + Tăng khả năng mở rộng và bảo trì mã nguồn: Nếu cần thêm lớp con mới, chỉ cần kế thừa lớp cha và ghi đè phương thức mà không cần sửa đổi mã đã có.

 + Đơn giản hóa mã nguồn: Giúp viết các hàm và phương thức linh hoạt hơn khi không cần phải kiểm tra kiểu đối tượng cụ thể.

VÍ DỤ:

    #include <iostream>
    using namespace std;

    // Lớp cha Animal
    class Animal {
    public:
        // Phương thức ảo
        virtual void makeSound() {
            cout << "Animal makes a sound" << endl;
        }

        virtual ~Animal() {}  // Destructor ảo để tránh rò rỉ bộ nhớ khi dùng đa hình
    };

    // Lớp con Dog kế thừa từ Animal
    class Dog : public Animal {
    public:
        // Ghi đè phương thức makeSound của lớp Animal
        void makeSound() override {
            cout << "Dog barks: Woof! Woof!" << endl;
        }
    };

    // Lớp con Cat kế thừa từ Animal
    class Cat : public Animal {
    public:
        // Ghi đè phương thức makeSound của lớp Animal
        void makeSound() override {
            cout << "Cat meows: Meow! Meow!" << endl;
        }
    };

    int main() {
        Animal* animal1 = new Dog();  // Con trỏ lớp cha trỏ tới đối tượng Dog
        Animal* animal2 = new Cat();  // Con trỏ lớp cha trỏ tới đối tượng Cat

        animal1->makeSound();  // Gọi makeSound() của Dog nhờ tính đa hình
        animal2->makeSound();  // Gọi makeSound() của Cat nhờ tính đa hình

        delete animal1;  // Giải phóng bộ nhớ
        delete animal2;

        return 0;
    }

### 2.ĐA HÌNH TẠI THỜI ĐIỂM BIÊN DỊCH

#### Nạp chồng hàm (Function Overloading):

 + Cho phép nhiều hàm cùng tên nhưng khác nhau về tham số (số lượng, kiểu dữ liệu, hoặc thứ tự của tham số) trong cùng một phạm vi.

 + Trình biên dịch sẽ chọn hàm thích hợp để gọi dựa trên danh sách tham số.



VÍ DU:

    #include <iostream>
    using namespace std;

    class Printer {
    public:
        // Hàm in số nguyên
        void print(int i) {
            cout << "Integer: " << i << endl;
        }

        // Hàm in số thực
        void print(double d) {
            cout << "Double: " << d << endl;
        }

        // Hàm in chuỗi ký tự
        void print(string s) {
            cout << "String: " << s << endl;
        }
    };

    int main() {
        Printer p;
        p.print(10);          // Gọi hàm print(int)
        p.print(3.14);        // Gọi hàm print(double)
        p.print("Hello");     // Gọi hàm print(string)

        return 0;
    }


#### Nạp chồng toán tử (Operator Overloading)

+ Cho phép định nghĩa lại các toán tử như +, -, *, == để hoạt động với các kiểu dữ liệu tự định nghĩa (như các lớp).

+ Toán tử được nạp chồng sẽ có thể làm việc trên các đối tượng của lớp tương tự như cách làm việc với các kiểu dữ liệu cơ bản.

VÍ DỤ:

    #include <iostream>
    using namespace std;

    class Complex 
    {
    private:
        double real;
        double imag;

    public:
        // Constructor
        Complex(double r = 0, double i = 0) : real(r), imag(i) {}

        // Nạp chồng toán tử +
        Complex operator + (const Complex& c) 
        {
            return Complex(real + c.real, imag + c.imag);
        }

        // Hàm in số phức
        void display() const 
        {
            cout << real << " + " << imag << "i" << endl;
        }
    };

    int main() 
    {
        Complex c1(3.0, 2.0);
        Complex c2(1.5, 4.5);

        Complex c3 = c1 + c2; // Gọi toán tử + đã nạp chồng
        c3.display();         // Hiển thị kết quả

        return 0;
    }

## TÍNH TRỪ TƯỢNG

KHÁI NIỆM:
Tính trừu tượng trong lập trình hướng đối tượng (OOP) là khái niệm cho phép ẩn đi các chi tiết triển khai bên trong của đối tượng và chỉ hiển thị những thông tin cần thiết để sử dụng đối tượng đó. Trong C++, tính trừu tượng giúp tập trung vào "những gì" một đối tượng làm thay vì "cách" mà nó thực hiện

VÍ DỤ:

    #include <iostream>
    #include <cmath>
    using namespace std;

    // Lớp trừu tượng Shape
    class Shape {
    public:
        // Phương thức thuần ảo
        virtual double area() = 0; // Hàm tính diện tích, chưa có triển khai

        // Phương thức thông thường
        virtual void display() {
            cout << "This is a shape" << endl;
        }
    };

    // Lớp Circle kế thừa từ Shape
    class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r) : radius(r) {}

        // Triển khai phương thức area()
        double area() override {
            return 3.14159 * radius * radius;
        }

        void display() override {
            cout << "Circle with radius: " << radius << ", Area: " << area() << endl;
        }
    };

    // Lớp Rectangle kế thừa từ Shape
    class Rectangle : public Shape {
    private:
        double width, height;

    public:
        Rectangle(double w, double h) : width(w), height(h) {}

        // Triển khai phương thức area()
        double area() override 
        {
            return width * height;
        }

        void display() override
        {
            cout << "Rectangle with width: " << width << ", height: " << height << ", Area: " << area() << endl;
        }
    };

    int main() 
    {
        Shape* shape1 = new Circle(5.0);    // Tạo đối tượng Circle qua con trỏ lớp cha
        Shape* shape2 = new Rectangle(4.0, 6.0);  // Tạo đối tượng Rectangle qua con trỏ lớp cha

        // Gọi hàm display() của mỗi đối tượng
        shape1->display();
        shape2->display();

        // Giải phóng bộ nhớ
        delete shape1;
        delete shape2;

        return 0;
    }

    
## TEMPLATE

 Khái niệm : 
Template trong C++ là một công cụ mạnh mẽ cho phép viết các hàm và lớp chung chung, có thể hoạt động với nhiều kiểu dữ liệu khác nhau mà không cần viết lại mã nguồn cho mỗi kiểu dữ liệu. Template giúp tăng tính linh hoạt và tái sử dụng mã trong C++.

Các loại template trong C++

+ Function Template: Cho phép viết hàm tổng quát, có thể hoạt động với nhiều kiểu dữ liệu khác nhau.

ví dụ :

    #include <iostream>
    using namespace std;

    template <typename T>
    T add(T a, T b) {
        return a + b;
    }

    int main() {
        cout << "Sum of integers: " << add(5, 10) << endl;         // Gọi add với int
        cout << "Sum of doubles: " << add(5.5, 2.3) << endl;       // Gọi add với double
        cout << "Sum of characters: " << add('A', 1) << endl;      // Gọi add với char

        return 0;
    }



+ Class Template: Cho phép định nghĩa các lớp có thể làm việc với nhiều kiểu dữ liệu khác nhau.

ví du:

    #include <iostream>
    using namespace std;

    template <typename T>
    class Calculator {
    private:
        T num1, num2;

    public:
        // Constructor để khởi tạo giá trị cho num1 và num2
        Calculator(T a, T b) : num1(a), num2(b) {}

        // Phép cộng
        T add() {
            return num1 + num2;
        }

        // Phép trừ
        T subtract() {
            return num1 - num2;
        }

        // Phép nhân
        T multiply() {
            return num1 * num2;
        }

        // Phép chia, kiểm tra chia cho 0
        T divide() {
            if (num2 != 0) {
                return num1 / num2;
            } else {
                cout << "Error: Division by zero" << endl;
                return 0; // Giá trị trả về mặc định khi chia cho 0
            }
        }
    };

    int main() {
        // Tạo đối tượng Calculator với kiểu int
        Calculator<int> intCalc(10, 5);
        cout << "Integer calculations:" << endl;
        cout << "10 + 5 = " << intCalc.add() << endl;
        cout << "10 - 5 = " << intCalc.subtract() << endl;
        cout << "10 * 5 = " << intCalc.multiply() << endl;
        cout << "10 / 5 = " << intCalc.divide() << endl;

        // Tạo đối tượng Calculator với kiểu double
        Calculator<double> doubleCalc(5.5, 2.2);
        cout << "\nDouble calculations:" << endl;
        cout << "5.5 + 2.2 = " << doubleCalc.add() << endl;
        cout << "5.5 - 2.2 = " << doubleCalc.subtract() << endl;
        cout << "5.5 * 2.2 = " << doubleCalc.multiply() << endl;
        cout << "5.5 / 2.2 = " << doubleCalc.divide() << endl;

        return 0;
    }


### Advanced template techniques
Metaprogramming
Khái niệm :C++ Template Metaprogramming (TMP) là việc sử dụng các mẫu (templates) của C++ để thực hiện các phép toán hoặc logic tại thời gian biên dịch. Thay vì sử dụng các lệnh thông thường để thực hiện tính toán khi chương trình đang chạy, các mẫu có thể được sử dụng để xây dựng mã mà trình biên dịch xử lý và tối ưu hóa.

ví dụ:

    #include <iostream>

    // Lớp mẫu đệ quy để tính giai thừa
    template <int N>
    class Factorial {
    public:
        static const int value = N * Factorial<N - 1>::value;
    };

    // Trường hợp cơ sở để kết thúc đệ quy
    template <>
    class Factorial<0> {
    public:
        static const int value = 1;
    };

    int main() {
        // Ví dụ sử dụng
        const int number = 5; // Bạn có thể thay đổi giá trị này
        std::cout << "Giai thừa của " << number << " là: " << Factorial<number>::value << std::endl;
        return 0;
    }

### Expression Templates
khái niệm:
Expression Templates là một kỹ thuật lập trình nâng cao trong C++ được sử dụng để tối ưu hóa việc tính toán các biểu thức phức tạp, đặc biệt trong các thư viện tính toán số học và các thư viện xử lý ma trận hoặc vectơ như Eigen hoặc Blitz++. Kỹ thuật này giúp tránh tạo các đối tượng trung gian không cần thiết và giảm thiểu các lần gọi hàm, dẫn đến hiệu suất tốt hơn.


ví dụ:

    #include <iostream>

    // Lớp mẫu biểu diễn một biểu thức cộng
    template <typename L, typename R>
    class Add {
    public:
        // Constructor nhận hai tham chiếu: `lhs` và `rhs` (các thành phần bên trái và bên phải của phép cộng)
        Add(const L& lhs, const R& rhs) : lhs(lhs), rhs(rhs) {}

        // Toán tử gán [] được dùng để tính giá trị của biểu thức tại một chỉ số cụ thể
        double operator[](std::size_t i) const {
            return lhs[i] + rhs[i];
        }

        // Phương thức `size()` trả về kích thước của biểu thức
        std::size_t size() const { return lhs.size(); }

    private:
        const L& lhs; // Tham chiếu đến thành phần bên trái của biểu thức
        const R& rhs; // Tham chiếu đến thành phần bên phải của biểu thức
    };

    // Lớp biểu diễn một vectơ
    class Vector {
    public:
        // Constructor để khởi tạo vectơ với kích thước nhất định
        Vector(std::size_t size) : data(new double[size]), size_(size) {}

        // Destructor để giải phóng bộ nhớ
        ~Vector() { delete[] data; }

        // Toán tử gán [] để truy cập hoặc thay đổi phần tử của vectơ
        double& operator[](std::size_t i) { return data[i]; }
        double operator[](std::size_t i) const { return data[i]; }
        
        // Phương thức trả về kích thước của vectơ
        std::size_t size() const { return size_; }

        // Toán tử cộng sử dụng Expression Templates
        template <typename R>
        Add<Vector, R> operator+(const R& rhs) const {
            return Add<Vector, R>(*this, rhs); // Trả về một đối tượng `Add` thay vì tính ngay
        }

    private:
        double* data; // Mảng động chứa các phần tử của vectơ
        std::size_t size_; // Kích thước của vectơ
    };

    // Hàm để in một vectơ
    template <typename E>
    void print(const E& expr) {
        for (std::size_t i = 0; i < expr.size(); ++i) {
            std::cout << expr[i] << " ";
        }
        std::cout << std::endl;
    }

    int main() {
        Vector a(3), b(3), c(3);
        a[0] = 1; a[1] = 2; a[2] = 3;
        b[0] = 4; b[1] = 5; b[2] = 6;
        c[0] = 7; c[1] = 8; c[2] = 9;

        auto result = a + b + c; // Không tạo đối tượng trung gian
        print(result);

        return 0;
    }

### Variadic Templates

ví dụ:

    #include <iostream>

    // Trường hợp cơ sở: khi không còn tham số nào, trả về 0
    int sum() 
    {
        return 0;
    }

    // Hàm mẫu với variadic templates để tính tổng
    template <typename T, typename... Args>
    int sum(T first, Args... args) 
    {
        return first + sum(args...); // Cộng tham số đầu tiên với kết quả của các tham số còn lại
    }

    int main() 
    {
        std::cout << "Tổng là: " << sum(1, 2, 3, 4, 5) << std::endl; // In ra 15
        return 0;
    }



## NAMESPACE 

KHÁI NIỆM :Namespace trong C++ là một tính năng dùng để nhóm các định danh (như tên lớp, hàm, biến, và hằng số) lại với nhau dưới một tên chung. Mục đích chính của namespace là để tránh xung đột tên trong các chương trình lớn hoặc khi sử dụng nhiều thư viện.

Từ khóa using cho phép bạn sử dụng các phần tử trong namespace mà không cần phải sử dụng toán tử '::' mỗi khi truy cập.

Chỉ sử dụng using namespace khi member muốn truy cập đến là duy nhất.

VÍ DỤ:

#include <iostream>

    // Khai báo namespace
    namespace MathOperations {
        int add(int a, int b) {
            return a + b;
        }

        int subtract(int a, int b) {
            return a - b;
        }
    }

    int main() {
        // Sử dụng các hàm trong namespace MathOperations
        int sum = MathOperations::add(5, 3);
        int difference = MathOperations::subtract(5, 3);

        std::cout << "Tổng: " << sum << std::endl;
        std::cout << "Hiệu: " << difference << std::endl;

        return 0;
    }

### NAMESPACE LỒNG NHAU

C++ cho phép tạo các namespace lồng nhau, nghĩa là một namespace có thể chứa một namespace khác bên trong nó.


ví dụ:

    namespace Algorithms {
        namespace Sorting {
            // Hàm sắp xếp nổi bọt (bubble sort) để sắp xếp mảng đầu vào
            void bubbleSort(std::vector<int>& arr) {
                for (size_t i = 0; i < arr.size() - 1; ++i) {
                    for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                        if (arr[j] > arr[j + 1]) {
                            std::swap(arr[j], arr[j + 1]); // Hoán đổi nếu phần tử trước lớn hơn phần tử sau
                        }
                    }
                }
            }
        }
    }

    int main() {
        std::vector<int> data = {5, 3, 8, 1, 2};
        // Gọi hàm bubbleSort từ namespace Algorithms::Sorting
        Algorithms::Sorting::bubbleSort(data);
        for (int num : data) {
            std::cout << num << " ";
        }
        return 0;
    }


VÍ DU:

    #include <iostream>
    #include <vector>
    #include <algorithm>

    namespace Algorithms {
        // Định nghĩa thuật toán tìm kiếm
        namespace Search {
            bool linearSearch(const std::vector<int>& arr, int target) {
                for (int num : arr) {
                    if (num == target) return true; // Tìm thấy phần tử
                }
                return false; // Không tìm thấy
            }
        }
    }

    // Mở rộng namespace Algorithms để thêm thuật toán sắp xếp
    namespace Algorithms {
        namespace Sorting {
            void bubbleSort(std::vector<int>& arr) {
                for (size_t i = 0; i < arr.size() - 1; ++i) {
                    for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                        if (arr[j] > arr[j + 1]) {
                            std::swap(arr[j], arr[j + 1]); // Hoán đổi nếu cần thiết
                        }
                    }
                }
            }
        }
    }

    int main() {
        std::vector<int> data = {5, 1, 4, 2, 8};
        // Gọi hàm bubbleSort từ namespace mở rộng
        Algorithms::Sorting::bubbleSort(data);

        std::cout << "Sorted array: ";
        for (int num : data) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Gọi hàm linearSearch từ namespace ban đầu
        bool found = Algorithms::Search::linearSearch(data, 4);
        std::cout << "Element found: " << (found ? "Yes" : "No") << std::endl;

        return 0;
    }



### NAMEPASE MỞ RỘNG

KHÁI NIỆM:

Namespace có thể được mở rộng bằng cách khai báo nhiều lần cùng một tên namespace trong các phần khác nhau của chương trình. Các khai báo này sẽ được ghép lại thành một namespace duy nhất.

VÍ DỤ:

    #include <iostream>
    #include <vector>
    #include <algorithm>

    namespace Algorithms {
        // Định nghĩa thuật toán tìm kiếm
        namespace Search {
            bool linearSearch(const std::vector<int>& arr, int target) {
                for (int num : arr) {
                    if (num == target) return true; // Tìm thấy phần tử
                }
                return false; // Không tìm thấy
            }
        }
    }

    // Mở rộng namespace Algorithms để thêm thuật toán sắp xếp
    namespace Algorithms {
        namespace Sorting {
            void bubbleSort(std::vector<int>& arr) {
                for (size_t i = 0; i < arr.size() - 1; ++i) {
                    for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                        if (arr[j] > arr[j + 1]) {
                            std::swap(arr[j], arr[j + 1]); // Hoán đổi nếu cần thiết
                        }
                    }
                }
            }
        }
    }

    int main() {
        std::vector<int> data = {5, 1, 4, 2, 8};
        // Gọi hàm bubbleSort từ namespace mở rộng
        Algorithms::Sorting::bubbleSort(data);

        std::cout << "Sorted array: ";
        for (int num : data) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Gọi hàm linearSearch từ namespace ban đầu
        bool found = Algorithms::Search::linearSearch(data, 4);
        std::cout << "Element found: " << (found ? "Yes" : "No") << std::endl;

        return 0;
    }





