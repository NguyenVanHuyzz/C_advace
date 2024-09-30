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





