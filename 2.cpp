#include<iostream>
using namespace std;

// Cho một struct Node biểu diễn một node của 1 danh sách liên kết như sau:

struct Node
{
    int value;
    Node *next;
};
// Yêu cầu:
// Viết hàm bool compareLists(Node* headA, Node* headB); so sánh 2 danh sách liên kết. Hai danh sách liên kết giống nhau khi có cùng độ dài và giá trị của các node tại vị trí tương ứng bằng nhau.

// Input:
// Hai con trỏ trỏ đến các node head của 2 danh sách.
// Output:
// Hàm trả về true nếu 2 danh sách liên kết giống nhau, nếu không trả về false
// . 
//----------------------------------------------------------------
// int count(Node* head){
//     int cnt = 0;
//     while (head != NULL){
//         cnt++;
//         head = head->next;
//     }
//     return cnt;
// }

// bool compareLists(Node* headA, Node* headB) {
//     // Your code here
//     Node* pA = headA;
//     Node* pB = headB;
//     if (count(headA) != count(headB)) return false;
//     while (pA != NULL){
//         if (pA->value != pB->value){
//             return false;
//         } else {
//             pA = pA->next;
//             pB = pB->next;
//         }
//     }
//     return true; // Change this line
// }

bool compareLists(Node* headA, Node* headB) {
    // Your code here
    while (headA !=NULL && headB != NULL) {
        if (headA->value != headB->value) return false;
        headA = headA->next;
        headB = headB->next;
    }
    return headA == headB; // both equal NULL
}