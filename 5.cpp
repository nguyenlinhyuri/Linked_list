#include<iostream>
#include<vector>
using namespace std;

// Cho một struct Node biểu diễn một node của 1 danh sách liên kết đơn như sau:

struct Node
{
    int value;
    Node* next;
};
// Viết hàm Node* concat(vector<Node*> heads); nhận đầu vào là một vector chứa các node đầu tiên của 1 tập các danh sách liên kết
// nối các danh sách liên kết đầu vào thành 1 danh sách liên kết mới và trả về node đầu tiên của danh sách liên kết mới đó.

Node* concat(vector<Node*> heads)
{
    Node* head = NULL;
    for (int i=0, j=-1; i < int(heads.size()); ++i) {
        if (heads[i] == NULL) continue;
        if (j >= 0 && heads[j] != NULL) {
            while (heads[j]->next != NULL) heads[j]=heads[j]->next;
            heads[j]->next = heads[i];
        }
        if (head == NULL) head = heads[i];
        j=i;
    }
    return head;
}