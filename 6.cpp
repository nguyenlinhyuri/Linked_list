#include<iostream>
#include<vector>
using namespace std;

// Cho một struct Node biểu diễn một node của 1 danh sách liên kết đơn như sau:

struct Node
{
    int value;
    Node* next;
};
// Viết hàm void printReverse(Node* head); in các giá trị của danh sách liên kết theo chiều ngược.

void printReverse(Node* head)
{
    // Your code here
    if (head == NULL) return;
    printReverse(head->next);
    cout << head->value << " ";
}