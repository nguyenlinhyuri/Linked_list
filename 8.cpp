#include<iostream>
#include<vector>
using namespace std;

// Cho một danh sách liên kết như sau:

// a1→a2→...→an→b1→b2→...→bn

// Không sử dụng thêm mảng phụ, hãy viết hàm Node* convert(Node* head); để chuyển đổi danh sách liên kết trên thành:

// a1→b1→a2→b2→...→an→bn

struct Node
{
    int value;
    Node *next;
};

Node* convert(Node* head)
{
    // Your code here
    if (head == NULL){
        return NULL;
    }
    
    Node* fast = head, *slow = head;
    Node* prev_slow = NULL;
    while (fast != NULL){
        prev_slow = slow;
        fast = fast->next->next;  // fast đi 2 bước
        slow = slow->next;   // slow đi 1 bước
    }
    // sau vòng lặp, fast ở cuối danh sách (NULL), slow ở giữa danh sách
    
    Node* a = head, *b = slow; // a bắt đầu từ đoạn an, b bắt đầu từ đoạn bn
    prev_slow->next = NULL; // cắt thành 2 dslk, phần tử trước giữa dslk thành node cuối của đoạn a
    
    // nối phần tử b vào giữa 2 phần tử liên kết của a
    while (b != NULL){
        Node* a2 = a->next;  // a2 trỏ đến phần tử tiếp theo của a
        a->next = b;  // gán node tiếp theo trong a bằng con trỏ b
        b = b->next;  // b di chuyển tới node tiếp theo
        a = a->next;  // di chuyển a sang phần tử tiếp theo của a, sau khi đã nối b
        a->next = a2; // gán node kế tiếp trong a bằng con trỏ a2
        a = a->next;  // di chuyển a sang phần tử tiếp theo của a, sau khi đã nối vào phần tử tiếp theo của a
    }
    return head;
}