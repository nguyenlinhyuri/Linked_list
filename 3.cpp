#include<iostream>
#include<vector>
using namespace std;

// Cho một struct Node biểu diễn một node
//  của 1 danh sách liên kết đơn như sau:

struct Node
{
    int value;
    Node* next;
};
// Viết các hàm:

// vector<int> linkedListToVector(Node* head) chuyển đổi một danh sách liên kết thành một vector.
// Node* vectorToLinkedList(vector<int> values) chuyển đổi một vector thành một danh sách liên kết.

vector<int> linkedListToVector(Node* head)
{
    // Your code here
    vector<int> ret;
    while (head) {
        ret.push_back(head->value);
        head = head->next;
    }
    return ret;
}

Node* vectorToLinkedList(const vector<int> &values, int i) {
    if (i >= int(values.size())) return NULL;
    Node* new_node = new Node();
    new_node->value = values[i];
    new_node->next = vectorToLinkedList(values, i+1);
    return new_node;
}

Node* vectorToLinkedList(vector<int> values)
{
    return vectorToLinkedList(values, 0);
}