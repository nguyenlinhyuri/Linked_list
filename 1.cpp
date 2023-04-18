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
    Node* p = head;
    while (p != NULL){
        cout << p->value << " ";
        p = p->next;
    }
}

Node* insertHead(Node* head, int value)
{
    // Your code here
    Node* tmp = new Node;
    tmp->value = value;
    tmp->next = head;
    head = tmp;
    return head;
}

Node* insertTail(Node* head, int value)
{
    // Your code here
    Node* p = head;
    if (head == NULL){
        Node* tmp = new Node;
        tmp->next = NULL;
        tmp->value = value;
        return tmp;
    }
    while (p->next != NULL){
        p = p->next;
    }
    Node* tmp = new Node;
    tmp->value = value;
    tmp->next = NULL;
    p->next = tmp;
    return head;
}

Node* deleteNode(Node* head, int pos)
{
    // Your code here
    if (pos == 0){
        Node* tmp = head;
        head = head->next;
        delete(tmp);
        return head;
    }
    Node* p = head;
    for (int i=0; i<pos-1; i++){
        p = p->next;
    }
    Node* tmp = p->next;
    p->next = tmp->next;
    delete(tmp);
    return head;
}

int getValue(Node* head, int pos)
{
    // Your code here
    Node* p = head;
    for (int i=0; i<pos; i++){
        p = p->next;
    }
    return p->value;
    //return 0; // Change this line
}