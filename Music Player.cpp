#include <iostream>
using namespace std;

class Node
{
public:
    string value;
    Node *next;
    Node(string value)
    {
        this->value = value;
        next = NULL;
    }
};

class LinkedList
{
public:
    int length;
    Node *head;
    LinkedList()
    {
        length = 0;
        head = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void insert(int pos, string name)
    {
        if (isEmpty())
        {
            if (pos < 1 || pos > length + 1)
            {
                cout << "Invalid position" << endl;
            }
            else
            {
                Node *temp = new Node(name);
                temp->next = head;
                head = temp;
                
                length++;
            }
        }
        else
        {
            Node *curr = head;
            for (int i = 2; i < pos; ++i)
            {
                if (curr->next != NULL)
                {
                    curr = curr->next;
                }
                else
                {
                    cout << "Invalid position" << endl;
                    return;
                }
            }
            Node *temp = new Node(name);
            temp->next = curr->next;
            curr->next = temp;
            length++;
        }
    }

    void showList()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << " " << curr->value << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void deleteNode(int pos)
    {
        if (isEmpty() || pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node *prev = NULL;
            Node *curr = head;
            for (int i = 1; i < pos; ++i)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }

        length--;
    }

    void Song_Update(int pos, string newName)
    {
        if (isEmpty() || pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node *curr = head;
        for (int i = 1; i < pos; ++i)
        {
            curr = curr->next;
        }
        curr->value = newName;
    }

    void Song_Play(string songName)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->value == songName)
            {
                cout << "Now playing: " << curr->value << endl;
                return;
            }
            curr = curr->next;
        }

        cout << "Song not found: " << songName << endl;
    }

    bool Song_Search(string songName)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->value == songName)
            {
                cout << "Song found: " << songName << endl;
                return true;
            }
            curr = curr->next;
        }

        cout << "Song not found: " << songName << endl;
        return false;
    }
};

int main()
{
    string newSong;
    string Song_Search;
    string newName;
    string Song_Play;
    cout << "Welcome to the Music Player" << endl;

    LinkedList L;
    L.insert(1, "Jarvis");
    L.insert(2, "Iron");

    int choice;
    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Show Playlist" << endl;
        cout << "2. Add a Song" << endl;
        cout << "3. Remove a Song" << endl;
        cout << "4. Search for a Song" << endl;
        cout << "5. Update a Song" << endl;
        cout << "6. Play a Song" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            L.showList();
            break;
        case 2:
            cout << "Enter song name to add ";
            cin >> newSong;
            L.insert(L.length + 1, newSong);
            break;
        case 3:
            cout << "Enter the number to remove ";
            int remove;
            cin >> remove;
            L.deleteNode(remove);
            break;
        case 4:
            cout << "Enter The Song Name to search ";
           
            cin >> Song_Search;
            L.Song_Search(Song_Search);
            break;
        case 5:
            cout << "Enter the number to update the posiiton ";
            int Update;
            cin >> Update;
            cout << "New Name Please ";
            
            cin >> newName;
            L.Song_Update(Update, newName);
            break;
        case 6:
            cout << "Name of Song Please to Update ";
            
            cin >> Song_Play;
            L.Song_Play(Song_Play);
            break;
        case 7:
            cout << "Good Bye" << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again" << endl;
            break;
        }
    }

    return 0;
}
