#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    int length;
    Node *head;
    Node *tail;

    CircularLinkedList()
    {
        length = 0;
        head = NULL;
        tail = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void insert(int value)
    {
        Node *n = new Node(value);
        if (isEmpty())
        {
            head = n;
            tail = n;
            n->next = head;
        }
        else
        {
            tail->next = n;
            tail = n;
            tail->next = head;
        }
        length++;
    }

    void showList()
    {
        Node *curr = head;
        if (!isEmpty())
        {
            do
            {
                cout << " " << curr->value;
                curr = curr->next;
            } while (curr != head);
        }
        cout << endl;
    }

    void reverse()
    {
        if (isEmpty())
        {
            cout << "List is empty, cannot reverse." << endl;
            return;
        }

        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;

        do
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head = prev;
        tail = current->next;
    }

    void split(CircularLinkedList &list1, CircularLinkedList &list2)
    {
        if (isEmpty())
        {
            cout << "List is empty, cannot split." << endl;
            return;
        }

        int middle = length / 2;
        Node *current = head;
        Node *prev = NULL;

        for (int i = 0; i < middle; i++)
        {
            prev = current;
            current = current->next;
        }

        list1.head = head;
        list1.tail = prev;
        list1.tail->next = list1.head;
        list1.length = middle;

        list2.head = current;
        list2.tail = tail;
        list2.tail->next = list2.head;
        list2.length = length - middle;

        head = NULL;
        tail = NULL;
        length = 0;
    }

    bool isPalindrome()
    {
        if (isEmpty())
        {
            cout << "List is empty." << endl;
            return false;
        }

        CircularLinkedList f, s;
        split(f, s);
        cout<<"List Number 1"<<endl;
        f.showList();
        cout<<"List Number 2"<<endl;
        s.showList();
        
        s.reverse();

        Node *FirstHalf = f.head;
        Node *SecondHalf = s.head;

        while (FirstHalf != NULL && SecondHalf != NULL)
        {
            if (FirstHalf->value != SecondHalf->value)
            {
                return false;
            }
            FirstHalf = FirstHalf->next;
            SecondHalf = SecondHalf->next;
        }

        return true;
    }
};

int main()
{
    CircularLinkedList C;
    C.insert(1);
    C.insert(2);
    C.insert(3);
    C.insert(3);
    C.insert(2);
    C.insert(1);
    
    cout << "Original Playlist:" << endl;
    C.showList();

    if (C.isPalindrome())
    {
        cout << "The list is a palindrome." << endl;
    }
    else
    {
        cout << "The list is not a palindrome." << endl;
    }
CircularLinkedList C2;
    C2.insert(1);
    C2.insert(2);
    C2.insert(3);
    C2.insert(2);
    C2.insert(1);
    C2.insert(3);
     cout << "Original Playlist:" << endl;
    C2.showList();

    if (C2.isPalindrome())
    {
        cout << "The list is a palindrome." << endl;
    }
    else
    {
        cout << "The list is not a palindrome." << endl;
    }
    return 0;
}
