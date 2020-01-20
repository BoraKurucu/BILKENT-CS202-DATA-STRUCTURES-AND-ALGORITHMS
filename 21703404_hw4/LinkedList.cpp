#include "LinkedList.h"

LinkedList::LinkedList()
{
  root = NULL;
  size = 0;
}
bool LinkedList::comp(string s1,string s2)
{
    string w1 = "";
    string w2 = "";
    for(int i = 0; i < s1.length();i++)
        if(s1[i] != '\0' && s1[i] != ' ')
        w1 = w1 + s1[i];

     for(int i = 0; i < s2.length();i++)
        if(s2[i] != '\0' && s2[i] != ' ')
        w2 = w2 + s2[i];

    return (w1 == w2);
}
void LinkedList::insert(string name,int amount)
{
    Node * node = new Node(name,amount);
    ItemNode * item = new ItemNode;
    //item->next = NULL;
    item->data = *node;

    if(root == NULL)
    {
        root = item;
        tail = root;
    }
    else
    {
        item->next = root;
        root = item;
    }
    size += 1;

}
Node  LinkedList::search2(string name,int & comparison,bool & found)
{
    found = false;
     ItemNode * temp = root;
     for(int i = 0; i < size;i++)
     {
         comparison += 1;
         if(comp((temp->data).getName(),name) )
         {
             found = true;

            return temp->data;
         }
        temp = temp->next;
     }
     //return NULL;
     found = false;
     Node node;
     return node;
}
bool LinkedList::isEmpty()
{
    return (size == 0);
}
void LinkedList::deleteI(string name)
{
 ItemNode * prev = NULL;
 ItemNode * temp = root;
 bool found = false;
    for(int i = 0; i < size;i++)
    {
        if(comp((temp->data).getName(),name) )
        {
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

if(found == false)
{
    return;
}
if(temp == root && temp == tail)
{

    root = NULL;
    tail = NULL;
    size--;
}
else if( temp == root)
{

    root = root->next;
    size--;
}
else if( temp != tail)
{

    prev->next = prev->next->next;
    //delete temp;
    size--;
}
else if(temp == tail)
{
    tail = prev;
    size--;
}
else
{

}
}
void LinkedList::print()
{
    if(size > 0)
    {
    ItemNode * temp = root;
    int k = 0;
    for(int i = 0; i <size;i++)
    {
        temp->data.printNode();
        cout<<", ";
        temp = temp->next;
    }
    cout<<""<<endl;
    }
}
LinkedList::~LinkedList()
{
    //dtor
}
