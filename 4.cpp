#include<iostream>
using namespace std;

// Cho một struct Node biểu diễn một node
//  của 1 danh sách liên kết đơn như sau:

struct Node
{
    int value;
    Node* next;
};
// Viết hàm: Node* extractNodes(Node* head, int threshold) tạo và trả về một danh sách liên kết mới từ các node trong danh sách liên kết bắt đầu bằng head, các node trong danh sách liên kết mới đều có giá trị nhỏ hơn threshold
// . Hàm không làm thay đổi danh sách liên kết cũ.

Node* extractNodes(Node* head, int threshold) 
{
    // Your code here
    Node* p = NULL; //khởi tạo danh sách mới
    Node* prev = NULL; // điều khiển con trỏ đầu tiên
    
    while (head != NULL){
        if (head->value < threshold){ // kiểm tra
            Node* tmp = new Node;  // khởi tạo node mới
            tmp->value = head->value;  // sao chép giá trị từ node hiện tại
            tmp->next = NULL;  // đặt next cho node mới
            
            if (p == NULL){ // nếu đây là node đầu tiên đc tạo ra
                p = tmp;  // đặt p trỏ đến node mới
            } else {
                prev->next = tmp;  // nối node mới vào dslk
            }
            prev = tmp;  // di chuyển prev đến sau node mới            
        }
        
        head = head->next;  // di chuyển head đến phần tử tiếp theo trong dslk
    }
    
    return p; // Change this line
}


// Node* extractNodes(Node* head, int threshold) 
// {
//     if (head == NULL) return NULL;
//     if (head->value >= threshold) 
//         return extractNodes(head->next, threshold);
//     // copy a new Node, since we are not allowed to change the original linked-list
//     Node* new_node = new Node();
//     new_node->value = head->value;
//     new_node->next = extractNodes(head->next, threshold);
//     return new_node;
// }