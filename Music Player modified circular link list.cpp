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

    void insert(string name)
    {
        Node *n = new Node(name);
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
                cout << " " << curr->value << endl;
                curr = curr->next;
            } while (curr != head);
        }
        cout << endl;
    }

    void deleteNode(string songName)
    {
        if (isEmpty())
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *curr = head;
        Node *prev = NULL;
        bool found = false;

        do
        {
            if (curr->value == songName)
            {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (!found)
        {
            cout << "Song not found: " << songName << endl;
            return;
        }

        if (curr == head && length == 1)
        {
            head = NULL;
            tail = NULL;
        }
        else if (curr == head)
        {
            head = head->next;
            tail->next = head;
        }
        else if (curr == tail)
        {
            tail = prev;
            prev->next = head;
        }
        else
        {
            prev->next = curr->next;
        }

        delete curr;
        length--;
    }

    void Song_Update(string songName, string newName)
    {
        if (isEmpty())
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *curr = head;
        bool found = false;

        do
        {
            if (curr->value == songName)
            {
                found = true;
                break;
            }
            curr = curr->next;
        } while (curr != head);

        if (!found)
        {
            cout << "Song not found: " << songName << endl;
            return;
        }

        curr->value = newName;
    }

    void PLay(string songName)
    {
        if (isEmpty())
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *curr = head;
        do
        {
            if (curr->value == songName)
            {
                cout << "Now playing: " << curr->value << endl;
                return;
            }
            curr = curr->next;
        } while (curr != head);

        cout << "Song not found: " << songName << endl;
    }

    void Next_Song()
    {
        if (isEmpty())
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        if (head->next != head)
        {
            head = head->next;
            cout << "Now playing: " << head->value << endl;
        }
        else
        {
            cout << "It's only one song" << endl;
        }
    }

    void Play_Previous()
    {
        if (isEmpty())
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        head = curr;
        cout << "Now playing: " << head->value << endl;
    }
};

int main()
{
    cout << "Welcome to the Music Player" << endl;
    string newSong;
    string removeSong;
    string searchSong;
    string updateSong;
    string newName;
    string playSong;
    CircularLinkedList playlist;
    playlist.insert("Jarvis");
    playlist.insert("Iron");

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
        cout << "7. Play Next" << endl;
        cout << "8. Play Previous" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playlist.showList();
            break;
        case 2:
            cout << "Enter song name to add: ";
            cin.ignore();
            getline(cin,newSong);
            playlist.insert(newSong);
            break;
        case 3:
            cout << "Enter the song name to remove: ";
            
            cin >> removeSong;
            playlist.deleteNode(removeSong);
            break;
     
        case 5:
            cout << "Enter the song name to update: ";
            
            cin >> updateSong;
            cout << "Enter the new name: ";
            
            cin >> newName;
            playlist.Song_Update(updateSong, newName);
            break;
        case 6:
            cout << "Enter the song name to play: ";
           
            cin >> playSong;
            playlist.PLay(playSong);
            break;
        case 7:
            playlist.Next_Song();
            break;
        case 8:
            playlist.Play_Previous();
            break;
        case 9:
            cout << "Goodbye" << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again" << endl;
            break;
        }
    }

    return 0;
}
