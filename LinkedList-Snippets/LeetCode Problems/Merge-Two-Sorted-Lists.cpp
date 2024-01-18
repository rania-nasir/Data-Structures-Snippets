//https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* merge = new ListNode;
        ListNode* temp = merge;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        
        while (list1 != nullptr) {
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }
        while (list2 != nullptr) {
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        return merge->next;
    }
};

int main() {
    Solution solution;
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;
    ListNode* head = nullptr;
    ListNode* temp = nullptr;

    // Creating the linked list 1
    list1 = new ListNode(9, list1);
    list1 = new ListNode(7, list1);
    list1 = new ListNode(5, list1);
    list1 = new ListNode(4, list1);
    list1 = new ListNode(2, list1);

    // Creating the linked list 2
    list2 = new ListNode(8, list2);
    list2 = new ListNode(4, list2);
    list2 = new ListNode(3, list2);
    list2 = new ListNode(1, list2);
    list2 = new ListNode(0, list2);

    cout << "\nLINKED LIST 1:\n";
    temp = list1;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "\nLINKED LIST 2:\n";
    temp = list2;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    head = solution.mergeTwoLists(list1, list2);

    cout << "\nMERGED LINKED LIST:\n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
