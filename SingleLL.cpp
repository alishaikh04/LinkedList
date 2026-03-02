
#include <iostream>
using namespace std;

struct  Node 
{
    int data;
    Node *next;
};

Node *list = NULL;

 void InsertData(int value) {
    
    Node *temp;
    temp = (Node*) malloc (sizeof(Node));
    temp -> data = value;
    temp -> next = NULL;
    if(list == NULL) {
        list =  temp;
    }
    else {
        Node *current = list;
        while (current -> next != NULL) {
            current = current -> next;
        }

         current -> next = temp;
    }
 }

void search(int value) {
    int found = 0;
    Node *current = list;
      while (current != NULL) {
          
        if  (value == current->data)
        {
            found = 1;
           cout << value << "-> Value founded." << endl;
        }
        current = current->next;   
      }
      if (!found)  {
             cout << "Value is not present in linked list." << endl;
      }
 }
 void display () {
    if (list == NULL) {
        cout << "List is having no data to print." << endl;
    }
      Node *current = list;
        while (current -> next != NULL) {
            
            cout << current -> data << " -> ";
            current = current -> next;
        }
         cout << current -> data  << " ";
 }

 void  deleteData(int value) {
    if (list == NULL) {
        cout << "List is empty.";
        return;
    }

    // Delete head.
    Node *curr = list;
        if (value == curr->data){
            list = curr->next;
            free (curr);
            cout << "Frist is deleted.";
            return;
        }

        curr = curr->next;
        Node *pre = curr;

      while (curr != NULL)
     {
        if (value == curr-> data){
            pre->next = curr->next;
            free(curr);
            cout << "value deleted successfully.";
            return;
        }
        pre = curr;
        curr = curr->next;
        
     }   

    cout << "Value not found.";
 }
  
 int main() {
 
int num;
int value;

while (true) {
     cout << "\n===== MENU =====" << endl;
        cout << "1. Insert value" << endl;
        cout << "2. Display values" << endl;
        cout << "3. Search value" << endl;
        cout << "4. Delete value" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
 
    cin >> num;
    
 if (num == 1) { 
 cout << "Insert the Data you want to enter." << endl;
     cin >> value;
     InsertData(value);
    
}
 else if (num == 2) {
   cout << "Display all Data. " << endl;
   cout << endl;
   display() ;
   cout << endl;
 }
else if (num == 3) {
 cout << "Search for value." << endl;
  cin >> value;
  search(value);
  cout << endl;
  }
  else if (num == 4){
    cout << "Delete the value ." << endl;
    cin >> value;
    deleteData(value);
    cout << endl;
  }
else if (num == 5){
  cout << "You  have Exited" << endl;
 break;
  }
 }
 return 0;
}