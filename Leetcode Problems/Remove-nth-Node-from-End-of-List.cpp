// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0 || head == nullptr) {
            return head;
        }

        // Calculate the length of the list
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // If n exceeds the length OR any negative value, do nothing
        if (n > len || n < 0) {
            return head;
        }

        // Reverse the list
        head = reverseList(head);

        // If removing the first node
        if (n == 1) {
            head = head->next;
        }
        else {
            // Find the index before node to be find
            ListNode* prev = head;
            for (int i = 1; i < n - 1; i++) {
                prev = prev->next;
            }

            // Remove the nth node
            if (prev->next->next != nullptr) {
                prev->next = prev->next->next;
            }
            else {
                prev->next = nullptr;
            }
        }

        // Reverse the list again to get the original order
        head = reverseList(head);

        return head;
    }
};

int main() {
    Solution solution;
    ListNode* list1 = nullptr;
    ListNode* temp = nullptr;

    // Creating the linked list 
    list1 = new ListNode(9, list1);
    list1 = new ListNode(7, list1);
    list1 = new ListNode(5, list1);
    list1 = new ListNode(4, list1);
    list1 = new ListNode(2, list1);

    cout << "\nLINKED LIST 1:\n";
    temp = list1;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    cout << "\nEnter Nth Number of Node from End of the list ? ";
    int n;
    cin >> n;
    list1 = solution.removeNthFromEnd(list1, n);

    cout << "\nAfter Removing Nth Node from End of the Linked List:\n";
    temp = list1;
    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}

