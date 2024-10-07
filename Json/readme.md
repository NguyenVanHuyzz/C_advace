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
