#include <iostream>
using namespace std;

class arraylist
{
    int *arr;
    int *curr;
    int size;
    int length;

    void next()
    {
        curr++;
    }

    void prev()
    {
        curr--;
    }

    void start()
    {
        curr = arr;
    }

    void end()
    {
        curr = arr + length - 1;
    }

public:
    arraylist(int size)
    {
        this->size = size;
        arr = new int[size];
        curr = arr;
        length = 0;
    }

    ~arraylist()
    {
        delete[] arr;
    }

    void insert(int val, int index)
    {
        if (length == size)
        {
            cout << "List is full" << endl;
            return;
        }
        if (index < 1 || index > size)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        end();
        for (int i = length; i >= index; i--)
        {
            *(curr + 1) = *curr;
            prev();
        }
        *(curr + 1) = val;
        length++;
    }

    bool is_empty()
    {
        return length == 0;
    }

    void remove(int index)
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        if (index < 1 || index > length)
        {
            cout << "Invalid Index" << endl;
            return;
        }
        curr = arr + index - 1;
        for (int i = index; i < length; i++)
        {
            *curr = *(curr + 1);
            next();
        }
        length--;
    }

    int find(int val)
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
            return -1;
        }
        start();
        for (int i = 1; i <= length; i++)
        {
            if (val == *curr)
            {
                return i;
            }
            next();
        }
        return -1;
    }

    void swap(int index1, int index2)
    {
        if (is_empty())
        {
            cout << "List is empty" << endl;
            return;
        }
        if (index1 < 1 || index1 > length || index2 < 1 || index2 > length)
        {
            cout << "Invalid Indices" << endl;
            return;
        }

        int *temp1 = arr + index1 - 1;
        int *temp2 = arr + index2 - 1;

        int temp = *temp1;
        *temp1 = *temp2;
        *temp2 = temp;
    }

    void print()
    {
        start();
        for (int i = 0; i < length; i++)
        {
            cout << *curr << " ";
            next();
        }
        cout << endl;
    }

 void rearrange_list()
{
    start();
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (i % 2 == 0)
            {
                if (i % j == 0)
                {
                    continue;
                }
                else
                {
                    swap(i, j);
                }
            }
        }
    }
}
};

int main()
{
    arraylist list(5);
    list.insert(1, 1);
    list.insert(2, 2);
    list.insert(3, 3);
    list.insert(4, 4);
    list.insert(5, 5);

    cout << "Original List: ";
    list.print();

    list.rearrange_list();

    cout << "List after rearranging: ";
    list.print();

    return 0;
}
