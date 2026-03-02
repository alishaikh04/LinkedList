#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* list = NULL;


void InsertData(int value)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;

    if (list == NULL)
    {
        list = temp;
        temp->next = list;  
    }
    else
    {
        Node* current = list;

        while (current->next != list)
        {
            current = current->next;
        }

        current->next = temp;
        temp->next = list;   
    }
}


void search(int value)
{
    if (list == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = list;
    int found = 0;

    do
    {
        if (value == current->data)
        {
            found = 1;
            cout << value << " -> Value found." << endl;
            return;
        }

        current = current->next;

    } while (current != list);

    if (!found)
    {
        cout << "Value is not present in linked list." << endl;
    }
}


void display()
{
    if (list == NULL)
    {
        cout << "List is having no data to print." << endl;
        return;
    }

    Node* current = list;

    do
    {
        cout << current->data << " -> ";
        current = current->next;

    } while (current != list);

    cout << endl;
}


void deleteData(int value)
{
    if (list == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* curr = list;
    Node* pre = NULL;

    
    if (list->data == value)
    {
        free(list);
        list = NULL;

        cout << "Node deleted." << endl;
        return;
    }

  
    if (list->data == value)
    {
        Node* last = list;

        while (last->next != list)
        {
            last = last->next;
        }

        last->next = list->next;

        Node* temp = list;
        list = list->next;

        free(temp);

        cout << "First node deleted." << endl;
        return;
    }

    pre = list;
    curr = list->next;

    while (curr != list)
    {
        if (value == curr->data)
        {
            pre->next = curr->next;

            free(curr);

            cout << "Value deleted successfully." << endl;
            return;
        }

        pre = curr;
        curr = curr->next;
    }

    cout << "Value not found." << endl;
}


int main()
{
    int num;
    int value;

    while (true)
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Insert value" << endl;
        cout << "2. Display values" << endl;
        cout << "3. Search value" << endl;
        cout << "4. Delete value" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> num;

        if (num == 1)
        {
            cout << "Insert the Data: ";
            cin >> value;

            InsertData(value);
        }

        else if (num == 2)
        {
            cout << "Display all Data." << endl;
            display();
        }

        else if (num == 3)
        {
            cout << "Search value: ";
            cin >> value;

            search(value);
        }

        else if (num == 4)
        {
            cout << "Delete value: ";
            cin >> value;

            deleteData(value);
        }

        else if (num == 5)
        {
            cout << "You have Exited." << endl;
            break;
        }

        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}