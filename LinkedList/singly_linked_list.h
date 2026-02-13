#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node(int v)
    {
        value = v;
        next = NULL;
    }

};

class singly_linked_list
{
private:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;

public:
    void insertAtFirst(int v)
    {
        Node* temp = new Node(v);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }

        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
        //delete temp; /// temp is part of the list now
    }
    void print_list()
    {
        Node* temp = head;
        for (int i = 0; i < size; i++)
        {
            cout << temp->value << "  ";
            temp = temp->next;

        }
        cout << endl;
    }

    void insertAtLast(int v)
    {
        if (size == 0) { insertAtFirst(v); }
        else
        {
            Node* temp = new Node(v);
            tail->next = temp;
            temp->next = NULL;
            tail = temp;
            size++;
        }
    }
    void insertAt(int v, int pos)
    {
        if (pos > size || pos < 0) { cout << "ERROR" << endl; }
        else if (pos == 0) { insertAtFirst(v); }
        else if (pos == size) { insertAtLast(v); }
        else
        {
            Node* temp = new Node(v);
            Node* temp2 = head;

            for (int i = 1; i < pos; i++)
            {
                temp2 = temp2->next;
            }

            temp->next = temp2->next;
            temp2->next = temp;
            size++;
        }
    }

    void deleteFirst()
    {
        if (head == NULL) { cout << "empty list " << endl; }
        else
        {
            Node* temp = head;
            if (size == 1)
            {
                delete temp;
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                delete temp;
            }
            size--;
        }
    }

    void deleteLast()
    {
        if (head == NULL) { cout << "empty list " << endl; }
        else
        {
            Node* temp = tail;
            if (size == 1)
            {
                delete temp;
                head = NULL;
                tail = NULL;
            }
            else
            {
                Node* current = head;
                for (int i = 0; i < size - 2; i++)
                {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = NULL;
                //delete temp;


            }
            size--;
        }

    }

    void deleteAt(int pos)
    {
        if (pos == 0) { deleteFirst(); }
        else if (pos == size - 1) { deleteLast(); }
        else if (pos<0 || pos>size - 1) { cout << "invalied possition" << endl; }
        else
        {
            Node* current = head;

            for (int i = 1; i < pos; i++)
            {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }
    void search(int v)
    {
        Node* temp = head;

        for (int i = 0; i < size; i++)
        {
            if (v == temp->value)
            {
                cout << "this value is in " << i + 1 << " possition" << endl;
            }
            temp = temp->next;
        }

    }
    singly_linked_list(int v)
    {
        insertAtLast(v);
    }
    singly_linked_list() {}
};

