#include<iostream>
#include<vector>
using namespace std;

// Cho một struct Node biểu diễn một node của 1 danh sách liên kết đơn như sau:

struct Node
{
    int value;
    Node *next;
};
// Biết head là con trỏ trỏ tới một danh sách liên kết đã được sắp xếp tăng dần theo giá trị các node
// , viết các hàm sau:

// Node* deleteDuplicates(Node* head); xoá các node
//  khỏi danh sách liên kết sao cho các giá trị xuất hiện nhiều nhất một lần. Hàm trả về con trỏ trỏ tới vị trí đầu tiên của danh sách liên kết.
// Node* insert(Node* head, int value); chèn một node có giá trị value vào danh sách liên kết sao cho danh sách liên kết vẫn được sắp xếp tăng dần.
//  Hàm trả về con trỏ trỏ tới vị trí đầu tiên của danh sách liên kết.

Node* deleteDuplicates(Node* head)
{
    // Your code here
    if (head == NULL) return head;
    for (Node* it = head; it != NULL; it=it->next) {
        while (it->next && it->next->value == it->value) {
            Node* tmp = it->next;
            it->next = tmp->next;
            delete tmp;
        }
    }
    return head;
}

Node* insert(Node* head, int value)
{
    // Your code here
    if (head != NULL && head->value < value) {
        head->next = insert(head->next, value);
        return head;
    }
    Node* new_node = new Node();
    new_node->value = value;
    
    if (head == NULL) return new_node;
    new_node->next = head;
    return new_node;
}


Node* deleteDuplicates(Node* head)
{
    // Your code here
    if (head == NULL || head->next == NULL){
        return head;
    }
    
    Node* p = head;
    while (p != NULL && p->next != NULL){
        if (p->value == p->next->value){
            Node* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        } else {
            p = p->next;
        }
    }
    return head;
}

// Node* insert(Node* head, int value)
// {
//     // Your code here
//     // tạo node mới có giá trị value
//     Node* tmp = new Node;
//     tmp->value = value;
//     tmp->next = NULL;
    
//     if (head == NULL){
//         return tmp;
//     }
    
//     // nếu value < node đầu tiên, chèn vào đầu dslk
//     if (head->value > value){
//         tmp->next = head;
//         return tmp;
//     }
    
//     // đưa con trỏ p tới vị trí node có giá trị ~ value
//     Node* p = head;
//     while (p->next != NULL && p->next->value < value){
//         p = p->next;
//     }
    
//     // chèn node tmp vào dslk
//     tmp->next = p->next;
//     p->next = tmp;
    
//     return head;
// }