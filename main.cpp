#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
} *head, *tail;
class List
{
    // declaration of necessary pointers

public:
    // declaration of functions                      // buttons below:
    void appendToEnd(int data);                          // a
    void insertToSpecificPosition(int data1, int inydex); // i
    void removeItemByValue(int data1);                   // r
    void removeItemByIndex(int position);                // d
    void printListItems();                               // p
    void printFromTail();                                // t
    void printLength(int len);                           // l
    void reverseItemsIntList();                          // v
    void eraseAllItems();                                // e
};

int main(){
    List list2;                   // create a new list called "list2"
    char input;                   // character input declaration
    int data, index = 0, len = 0; // integer variables declaration
    while (input != 'x')          // if the input by the user not equal to 'x', keep the loop;
    {
        cin >> input; // getting user input inside the loop
        switch (input)
        {
        case 'a':
            cin >> data;
            list2.appendToEnd(data);
            break;
        case 'r':
            cin >> data;
            list2.removeItemByValue(data);
            break;
        case 'd':
            cin >> index;
            list2.removeItemByIndex(index);
            break;
        case 'p':
            list2.printListItems();
            break;
        case 't':
            list2.printFromTail();
            break;
        case 'l':
            list2.printLength(len);
            break;
        case 'v':
            list2.reverseItemsIntList();
            break;
        case 'e':
            list2.eraseAllItems();
            break;
        case 'i':
            cin >> data >> index;
            list2.insertToSpecificPosition(data, index);
            break;
        default:
            break;
        }
    }
    return 0;
};

void List::printLength(int len){
    node *curr = head;
    if (curr != NULL)
    {
        while (curr != NULL)
        {
            curr = curr->next;
            len++;
        }
        cout << len << endl;
    }
    else
    {
        if (len > 0)
            cout << len;
        else
            cout << "Not exist";
    }
    cout << endl;
}
void List::eraseAllItems(){
    node *temp = head;
    node *temp2 = NULL;
    while (temp != NULL)
    {
        temp2 = temp->next;
        delete (temp);
        temp = temp2;
    }
    head = NULL;
}
void List::reverseItemsIntList(){
    node *curr = head; // we need three extra variables in this process
    node *prev = NULL, *after = NULL;
    while (curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    head = prev;
}
void List::printFromTail(){
    node *temp0 = head;
    while (temp0 != NULL)
    {
        temp0 = temp0->next; // we find the last node and
    }
    tail = temp0; // assign it to tail variable for the usage
    while (tail != NULL)
    {
        cout << tail->data << " "; // using tail we print the list items from back towards(head)
        tail = tail->prev;
    }
    cout << endl;
}
void List::printListItems(){
    node *tem = head; // creating temporary node pointing to head
    // while temp node is not equal null, keep the loop and print all elemnts
    while (tem != NULL)
    {
        cout << tem->data << " ";
        tem = tem->next;
    }
    cout << endl;
};

void List::appendToEnd(int data){
    struct node *newNode = new node; // memory allocation for node
    newNode->data = data;            // assign data to new node
    newNode->next = NULL;            // assign NULL to the next of newnode
    node *anotherTemp = head;        // store head node temporarily(for later use)
    // if the linked list is empty, assign the newnode as head node
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    // if the linked list is not empty, traverse to the end of the list
    while (anotherTemp->next != NULL)
    {
        anotherTemp = anotherTemp->next;
    }
    // after above, temp is the last node of the linked list
    //  point the next of the last node (temp) to newNode
    anotherTemp->next = newNode;
    newNode->prev = anotherTemp; // assign prev of newNode to another temp
} // a
void List::insertToSpecificPosition(int data1, int index)
{
    node *newNode = new node; // allocate node for the new element
    node *cur = new node;     // creating an extra variable to find the required place to put the list item
    newNode->data = data1;
    newNode->next = NULL;
    newNode->prev = NULL;
    // check if the position is > 0
    if (index < 1)
    {
        cout << "Position should be >= 1.";
    }
    else if (index == 1)
    { // if the position is 1, make new node as head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else
    {
        cur = head;
        // now assign temp to the node previous to the given position
        for (int i = 0; i < index - 1; i++)
        {
            if (cur != NULL)
            {
                cur = cur->next;
            }
        }
        if (cur != NULL)
        {
            newNode->next = cur->next;
            newNode->prev = cur;
            cur->next = newNode;
            if (newNode->next->prev != NULL)
                newNode->next->prev = newNode;
        }
    }
}
void List::removeItemByIndex(int position)
{
    if (position < 1)
    {
        cout << "Not exist";
    }
    else if (position == 1 && head != NULL)
    {
        // if the position is 1 and head is not equal null, make head next as head and delete previous head
        node *nodeForDeleting = head;
        head = head->next;
        free(nodeForDeleting);
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        node *temp = head;
        // traverse to the node previous to the position
        for (int i = 1; i < position - 1; i++)
        {
            if (temp != NULL)
                temp = temp->next;
        }
        // If the previous node and next of the previous is not null, adjust links
        if (temp != NULL && temp->next != NULL)
        {
            node *temp2 = temp->next;
            temp->next = temp->next->next;
            if (temp->next->next != NULL)
                temp->next->next->prev = temp->next;
            free(temp2);
        }
        else
        {
            cout<<"Not exist";
        }
    }
}

// remove list item by value

void List::removeItemByValue(int data1)
{
    node *temporaryNode;
    temporaryNode = head;
    while(temporaryNode->data != data1){
        temporaryNode=temporaryNode->next;
    }
    if(temporaryNode->data != data1){
        cout <<"Not exist";
    }
    else{
        temporaryNode->prev->next = temporaryNode->next;
        temporaryNode->next->prev = temporaryNode->prev;
        delete temporaryNode;
    }
    cout<<endl;
}
