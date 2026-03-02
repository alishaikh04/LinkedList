#include <iostream>
using namespace std;

struct  Node 
{
    int data;
    Node *next;
    Node *previous;
};

Node *list = NULL;

 void InsertData(int value) {
    
    Node *temp;
    temp = (Node*) malloc (sizeof(Node));
    temp -> data = value;
    temp -> next = NULL;
    temp -> previous = NULL; //NULL add for previous;
    if(list == NULL) {
        list =  temp;
    }
    else {
        Node *current = list;
        while (current -> next != NULL) {   
            current = current -> next;
    }
            current -> next = temp;
            temp -> previous = current; // last node sa laka shoro tak ana ka lia mean phali wali node.
    }
 }

 void search (int value) {
    Node *current = list;
    int flag = 0; // ya nicha 1 hogaya tw mtlb value found hogayi agar 0 raha tw value found nhi howi.
      
      while (current != NULL) {
        
        if (value == current->data) {
            flag = 1; // yaha 1 hojaiga agar nhi hota tw uss waqt jab yaha value equal nhi ati tw if condition nhi chalti.
            cout << "Value has been founded." << value << endl;
            break;
        }
        current = current->next;
      }
      if (!flag)  { // flag 0  ha yaha tw not found yaha flag == 0 bhi likh sakta hain.
        cout << "Value not present!." << endl;
      }

    }

  void deleteData (int value) {
    Node *current = list;

    if (list == NULL) {
        cout << "List is empty. NO value present to Delete." << endl;
    }

    //Delete Value which is at Head. Mean yaha phali node joka head ha vo delete hogi.
    if (value == current->data) {
        list = current->next;
        free(current);
        return;
    }

    while (current != NULL) {
        if (value == current->data) {

            current->previous->next = current->next;
            current->next->previous = current->previous;
            free(current);
            cout << "Value successfully deleted.";
            return;
        }
        current = current->next;
    }

    cout << "Value Not Exist." << endl;
  }  

 void display () {
    Node *current = list;
    Node *last;
    if (list == NULL) {
        cout << "List is empty. NO value present to Display." << endl;
        return;
    }
    while (current != NULL) {
        cout << current -> data << " -> ";
        last = current;
        current = current->next;
    }
     while (last != NULL) {  // ulta last node sa laka shoro ki node tak print karna ka lia.
        cout << last->data << " -> ";
        last = last->previous;
     }
    
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
      cout << "Enter Number to Search." << endl;
      cin >> value;
      search(value);
 }
   else if (num == 4) {
      cout << "Enter Number to Delete." << endl;
      cin >> value;
      deleteData(value);  
 }
  else if (num == 5){
    cout << "You  have Exited" << endl;
    break;
  }
 }
 return 0;
}