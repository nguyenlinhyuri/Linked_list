#include<iostream>
using namespace std;

// Cho một struct Node biểu diễn một node
//  của 1 danh sách liên kết đơn như sau:

struct Node
{
    int value;
    Node* next;
};
// Biết head là con trỏ trỏ tới node đầu tiên của danh sách liên kết, viết các hàm sau:

// void print(Node* head); in ra giá trị các phần tử của danh sách liên kết trên cùng một dòng, cách nhau bởi 1 dấu cách.
// Node* insertHead(Node* head, int value); thêm một node có giá trị là value
//  vào đầu của danh sách liên kết. Hàm trả về con trỏ trỏ tới đầu danh sách liên kết.
// Node* insertTail(Node* head, int value); thêm một node có giá trị là value
//  vào cuối của danh sách liên kết. Hàm trả về con trỏ trỏ tới đầu danh sách liên kết
// Node* deleteNode(Node* head, int pos); xoá một node tại vị trí thứ pos
//  ra khỏi danh sách liên kết, biết pos luôn lớn hơn hoặc bằng 0
//  và nhỏ hơn độ dài của danh sách liên kết. Hàm trả về con trỏ trỏ tới đầu danh sách liên kết.
// int getValue(Node* head, int pos); trả về giá trị của node tại vị trí thứ pos
//  biết pos luôn lớn hơn hoặc bằng 0 và nhỏ hơn độ dài của danh sách liên kết.


void print(Node* head)
{
    // Your code here
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

Node* insertHead(Node* head, int value)
{
    // Your code here
    Node* new_node = new Node();
    new_node->value = value;
    new_node->next = head;
    return new_node;
}

Node* insertTail(Node* head, int value)
{
    // Your code here
    Node* new_node = new Node();
    new_node->value = value;
    if (head == NULL) return new_node;
    Node* i = head;
    for (; i->next != NULL; i=i->next);
    i->next = new_node;
    return head;
}

Node* deleteNode(Node* head, int pos)
{
    // Your code here
    if (pos == 0) {
        Node* next = head->next;
        delete head;
        return next;
    }
    Node* i = head;
    while (--pos) i = i->next;
    Node* deleted = i->next;
    i->next = deleted->next;
    delete deleted;
    return head;
}

int getValue(Node* head, int pos)
{
    // Your code here
    while (pos--) head = head->next;
    return head->value;
}