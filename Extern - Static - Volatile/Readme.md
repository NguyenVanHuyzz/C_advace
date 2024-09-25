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












