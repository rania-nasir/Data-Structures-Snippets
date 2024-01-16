//https://leetcode.com/problems/reorder-list/description/

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

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newhead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newhead;
    }
    void reorderList(ListNode* head) {

        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            return;
        }

        // divide into to lists
        ListNode* temp = head;
        int len = 0;
        int mid;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        mid = len / 2;

        ListNode* list1 = nullptr;
        ListNode* list2 = nullptr;

        temp = head;

        list1 = temp;  // 1st half added to list 1
        for (int i = 1; i < mid; i++)
        {
            temp = temp->next;
        }
        list2 = temp->next; // remaining half added to list 2
        temp->next = nullptr;

        // reverse the list 2
        list2 = reverseList(list2);

        // reorder the list by merging each by 1
        ListNode* reorder = new ListNode;
        ListNode* list = reorder;

        while (list1 != nullptr && list2 != nullptr) {
            list->next = list1;
            list1 = list1->next;
            list = list->next;
            list->next = list2;
            list2 = list2->next;
            list = list->next;
        }

        //remaining odd val from list 2 if any 
        while (list2 != nullptr) {
            list->next = list2;
            list2 = list2->next;
            list = list->next;
        }

        head = reorder->next;
    }
};

int main() {
    Solution solution;
    ListNode* head = nullptr;

    // Creating the linked list 
    head = new ListNode(8, head);
    head = new ListNode(7, head);
    head = new ListNode(6, head);
    head = new ListNode(5, head);
    head = new ListNode(4, head);
    head = new ListNode(3, head);
    head = new ListNode(2, head);

    cout << "\nLINKED LIST :\n";
    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    solution.reorderList(head);

    cout << "\nREORDER LINKED LIST:\n";
    temp = head;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}
