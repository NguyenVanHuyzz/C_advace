#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 2024 
 

// Định nghĩa cấu trúc Node cho danh sách liên kết
typedef struct Node {
    char name[10];
    char add[20];
    int age;
    int phone_num;
    struct Node *next;
} Node;

// Định nghĩa cấu trúc CenterPoint cho cây nhị phân
typedef struct CenterPoint {
    char name[10];
    char add[20];
    int age;
    int phone_num;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

// Hàm tạo cây từ danh sách liên kết (theo cách chia đôi danh sách)
CenterPoint *buildTree(Node *head, int start, int end) 
{
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;

    // Di chuyển tới điểm giữa của danh sách
    for (int i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }

    // Tạo một nút trong cây từ node tại vị trí giữa
    CenterPoint *root = (CenterPoint *) malloc(sizeof(CenterPoint));
    strcpy(root->name, node->name);
    strcpy(root->add, node->add);
    root->age = node->age;
    root->phone_num = node->phone_num;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}

// Hàm xác định độ dài của danh sách và gọi `buildTree` để tạo cây
CenterPoint *centerPoint(Node *head) 
{
    int length = 0;
    Node *node = head;

    // Tính độ dài của danh sách liên kết
    while (node != NULL) {
        node = node->next;
        length++;
    }
    
    return buildTree(head, 0, length - 1);
}

// Hàm tìm kiếm nhị phân tên trong cây nhị phân
CenterPoint *binarySearch(CenterPoint *root, const char *name) 
{
    static int loop = 0;
    loop++;
    printf("\ntime loop: %d\n", loop);

    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(name, root->name);

    if (cmp == 0) {
        return root; // Tìm thấy tên
    }

    if (cmp < 0) {
        return binarySearch(root->left, name);
    } else {
        return binarySearch(root->right, name);
    }
}

// Hàm thêm nút mới vào danh sách liên kết có sắp xếp theo tên
void addNodeSorted(Node **head, char name[10], int age, char add[20], int phone_num) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    strcpy(new_node->add, add);
    new_node->age = age;
    new_node->phone_num = phone_num;
    new_node->next = NULL;

    if (*head == NULL || strcmp(name, (*head)->name) < 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && strcmp(current->next->name, name) < 0) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Hàm in cây nhị phân (inorder traversal để kiểm tra)
void inOrderPrint(CenterPoint *root) 
{
    if (root == NULL) return;

    inOrderPrint(root->left);
    printf("name: %s, add: %s, age: %d, phone number: %d\n", 
           root->name, root->add, root->age, root->phone_num);
    inOrderPrint(root->right);
}



int main() 
{
    Node *head = NULL;
    FILE *file = fopen("Book2.csv", "r"); // Mở file .csv để đọc
    if (file == NULL) 
    {
        perror("Không thể mở file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];

    // Đọc từng dòng trong file
    while (fgets(line, MAX_LINE_LENGTH, file)) 
    {
        int age;
        char add[60];
        char name[50];
        long long phone;

        // Phân tích cú pháp dòng với định dạng name, age, adds, phone
        if (sscanf(line, "%49[^,],%d,%59[^,],%lld", name, &age, add, &phone) == 4) 
        {
            addNodeSorted(&head,name,age,add,phone);
            
        } 
        else 
        {
            printf("error read line - %s", line);
        }
    }

   

    // Xây dựng cây nhị phân từ danh sách liên kết
    CenterPoint *root = centerPoint(head);

    // In cây để kiểm tra
    printf(":buildTree with name\n");
    inOrderPrint(root);

    // Tìm kiếm tên trong cây
    const char *search_name = "Emily";

    CenterPoint *result = binarySearch(root, search_name);

    if (result != NULL) {
        printf("\nsee it:\n");
        printf("name: %s, add: %s, age: %d, phone number: %d\n", 
               result->name, result->add, result->age, result->phone_num);
    } else {
        printf("not name: %s\n", search_name);
    }

    return 0;
}
