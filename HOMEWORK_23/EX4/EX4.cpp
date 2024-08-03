#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

bool has_cycle(Node* head) 
{
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

void append(Node*& head, int value) 
{
    if (!head) {
        head = new Node(value);
        return;
    }

    Node* current = head;
    while (current->next != nullptr) 
    {
        current = current->next;
    }
    current->next = new Node(value);
}

void create_cycle(Node* head, int pos) 
{
    if (!head) return;

    Node* cycle_node = nullptr;
    Node* tail = head;
    int count = 0;

    while (tail->next != nullptr) 
    {
        if (count == pos) {
            cycle_node = tail;
        }
        tail = tail->next;
        count++;
    }

    if (cycle_node) 
    {
        tail->next = cycle_node;  
    }
}

void print_list(Node* head, int limit = 10) 
{
    Node* current = head;
    int count = 0;
    while (current != nullptr && count < limit) 
    {
        std::cout << current->data << " -> ";
        current = current->next;
        count++;
    }
    std::cout << "nullptr" << std::endl;
}

int main() 
{
    Node* head = nullptr;

    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 4);
    append(head, 5);

    std::cout << "List without cycle: ";
    print_list(head);

    std::cout << "Is there a cycle in the list? " << (has_cycle(head) ? "Yes" : "No") << std::endl;

    create_cycle(head, 2); 

    std::cout << "Is the cycle in the list after creating the cycle? " << (has_cycle(head) ? "Yes" : "No") << std::endl;
}
