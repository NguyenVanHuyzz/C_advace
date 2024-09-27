# Struct

Khái niệm Struct trong lập trình C
Trong ngôn ngữ lập trình C, struct (viết tắt của "structure") là một kiểu dữ liệu do người dùng định nghĩa, cho phép gộp nhiều kiểu dữ liệu khác nhau lại với nhau dưới một tên duy nhất. Cấu trúc này giúp tổ chức dữ liệu liên quan đến nhau thành một nhóm logic, giúp việc quản lý và xử lý dữ liệu trở nên dễ dàng hơn.

Cú pháp định nghĩa struct:

    struct TenStruct 
    {
        kieu_du_lieu1 ten_bien1;
        kieu_du_lieu2 ten_bien2;
        // Các thành phần khác
    };
    
TenStruct: Tên của struct.
kieu_du_lieu1, ten_bien1: Kiểu dữ liệu và tên biến của từng thành phần trong struct.

ví dụ

    #include <stdio.h>
    #include <string.h>

    // Định nghĩa struct SinhVien
    struct Student
    {
        char name[50];  // 4x13 = 52 b (2 byte panding)
        char studentID[15]; // 4x4 16 b (1 byte panding)
        float gpa; // 4 b
    };

    // Hàm tìm sinh viên có điểm cao nhất
    struct Student findTopStudent(struct Student sv[], int n)
    {
        struct Student topStudent = sv[0];  // Giả định sinh viên đầu tiên có điểm cao nhất
        for (int i = 1; i < n; i++) 
        {
            if (sv[i].gpa > topStudent.gpa) 
            {
                topStudent = sv[i];  // Cập nhật sinh viên có điểm cao hơn
            }
        }
        return topStudent;
    }

    int main() 
    {
        int n =0 ;

        // Khai báo mảng 
        struct Student s[3]=
        {
            {"Tim","12",8.5},
            {"Tom","15",8.2},
            {"Ales","165",5.1}
        };

        printf("Size of struct: %d\n", sizeof(Student)); // kích thước của struct 72 B
        printf("Size of struct s: %d\n", sizeof(s)); // kích thước của struct 72x3 = 216 B

    
        // Tìm sinh viên có điểm trung bình cao nhất
        struct Student Top_s = findTopStudent(s, n);

        // In thông tin sinh viên có điểm cao nhất
        printf("Top student:\n");
        printf("Name student : %s\n", Top_s.name);
        printf("ID student: %s\n", Top_s.studentID);
        printf("Average score (GPA): %.2f\n", Top_s.gpa);

        return 0;
    }


Lợi ích của việc sử dụng struct:
* Tổ chức dữ liệu: Dễ dàng gộp nhóm nhiều kiểu dữ liệu liên quan lại với nhau.
* Quản lý dễ dàng: Giúp việc xử lý, truyền dữ liệu trở nên dễ dàng và ngắn gọn hơn.
* Tính mở rộng: Có thể mở rộng bằng cách thêm các trường dữ liệu mới mà không làm ảnh hưởng đến các phần khác của chương trình.

# Union

Khái niệm Union trong lập trình C:

Trong ngôn ngữ lập trình C, union là một kiểu dữ liệu do người dùng định nghĩa, tương tự như struct, nhưng có một điểm khác biệt quan trọng: các thành phần của union chia sẻ cùng một vùng nhớ. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng. Điều này được ứng dụng nhằm tiết kiệm bộ nhớ


Cú pháp định nghĩa union:

    union TenUnion 
    {
        kieu_du_lieu_1 ten_bien_1;
        kieu_du_lieu_2 ten_bien_2;
        // Các thành phần khác
    };

* TenUnion: Tên của union.
* Kieu_du_lieu_1, ten_bien_1: Kiểu dữ liệu và tên biến của từng thành phần trong union

ví dụ.


    #include <stdio.h>

    // Union lưu trữ dữ liệu cảm biến
    union SensorData 
    {
        int intValue;
        float floatValue;
        char charValue;
    };

    // Cấu trúc để lưu thông tin cảm biến
    struct Sensor 
    {
        int sensorID;
        union SensorData data;
        int dataType;  // 0: int, 1: float, 2: char
    };

    void printSensorData(struct Sensor sensor) 
    {
        printf("ID sensor: %d\n", sensor.sensorID);
        switch (sensor.dataType) {
            case 0:
                printf("value (int): %d\n", sensor.data.intValue);
                break;
            case 1:
                printf("value (float): %.2f\n", sensor.data.floatValue);
                break;
            case 2:
                printf("value (char): %c\n", sensor.data.charValue);
                break;
            default:
                printf("value invalid.\n");
        }
    }

    int main() 
    {
        struct Sensor sensor1 = {1, .data.intValue = 100, 0};
        struct Sensor sensor2 = {2, .data.floatValue = 36.5, 1};
        struct Sensor sensor3 = {3, .data.charValue = 'A', 2};

        printSensorData(sensor1);
        printSensorData(sensor2);
        printSensorData(sensor3);

        return 0;
    }

Giả sử có một hệ thống nhúng với một số cảm biến, mỗi cảm biến gửi về một loại dữ liệu khác nhau.Muốn sử dụng một cấu trúc dữ liệu gọn nhẹ để tiết kiệm bộ nhớ.Ở đây, union được sử dụng để lưu trữ các loại dữ liệu khác nhau (int, float, char) trong cùng một bộ nhớ, giúp tiết kiệm bộ nhớ trong hệ thống nhúng. Điều này rất hữu ích khi làm việc với các cảm biến có loại dữ liệu khác nhau.
   


