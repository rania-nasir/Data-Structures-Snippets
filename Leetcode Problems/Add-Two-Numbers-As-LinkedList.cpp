// https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* l = new ListNode();
        ListNode* head = l;
        int sum = 0, carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            if (l1 == nullptr && l2 == nullptr) {
                sum = 0 + 0 + carry;
            }
            else if (l1 == nullptr) {
                sum = 0 + l2->val + carry;
            }
            else if (l2 == nullptr) {
                sum = l1->val + 0 + carry;
            }
            else {
                sum = l1->val + l2->val + carry;
            }
            carry = sum / 10;

            l->next = new ListNode(sum % 10);
            l = l->next;

            if (l1 != nullptr) { l1 = l1->next; }
            if (l2 != nullptr) { l2 = l2->next; }
        }

        return head->next;
    }
};

int main() {
    Solution solution;
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;
    ListNode* temp = nullptr;

    // Creating the linked list 
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);
    list1 = new ListNode(9, list1);

    list2 = new ListNode(9, list2);
    list2 = new ListNode(9, list2);
    list2 = new ListNode(9, list2);
    list2 = new ListNode(9, list2);

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

    list1 = solution.addTwoNumbers(list1, list2);

    cout << "\nAddition of Linked Lists:\n";
    temp = list1;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}

