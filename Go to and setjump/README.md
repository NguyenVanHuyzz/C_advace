

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

            










