//https://leetcode.com/problems/reverse-linked-list/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;

    // Creating the linked list
    head = new ListNode(25, head);
    head = new ListNode(45, head);
    head = new ListNode(23, head);
    head = new ListNode(67, head);
    head = new ListNode(54, head);

    cout << "\nLINKED LIST:\n";
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    head = solution.reverseList(head);

    cout << "\nREVERSED LINKED LIST:\n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
