#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void splitOddEven(ListNode* head, ListNode*& oddList, ListNode*& evenList) {
    ListNode* oddCurrent = nullptr;
    ListNode* evenCurrent = nullptr;

    ListNode* current = head;

    while (current != nullptr) {
        if (current->val % 2 == 1) {
            // Add to the odd list
            if (oddCurrent == nullptr) {
                oddList = oddCurrent = current;
            } else {
                oddCurrent->next = current;
                oddCurrent = oddCurrent->next;
            }
        } else {
            // Add to the even list
            if (evenCurrent == nullptr) {
                evenList = evenCurrent = current;
            } else {
                evenCurrent->next = current;
                evenCurrent = evenCurrent->next;
            }
        }

        // Move to the next node
        current = current->next;
    }

    // Terminate both lists
    if (oddCurrent != nullptr) {
        oddCurrent->next = nullptr;
    }

    if (evenCurrent != nullptr) {
        evenCurrent->next = nullptr;
    }
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Utility function to free the memory allocated for the linked list
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Example linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Initialize empty lists for odd and even nodes
    ListNode* oddList = nullptr;
    ListNode* evenList = nullptr;

    // Split the linked list into odd and even nodes
    splitOddEven(head, oddList, evenList);

    // Print the odd list: 1 3 5
    std::cout << "Odd List: ";
    printList(oddList);

    // Print the even list: 2 4
    std::cout << "Even List: ";
    printList(evenList);

    // Free the memory allocated for the linked lists
    deleteList(oddList);
    deleteList(evenList);

    return 0;
}
