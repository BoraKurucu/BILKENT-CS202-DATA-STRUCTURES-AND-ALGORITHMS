#include "Node.h"
Node::Node()
{
    name = "null";
    amount = -1;
}
Node::Node(string name1 = "null",int amount1 = -1)
{
    name = name1;
    amount = amount1;
}
int Node::getAm()
{
    return amount;
}
string Node::getName()
{
    return name;
}
void Node::setName(string x)
{
    name = x;
}
void Node::printNode()
{
    if(name != "deleted" && name != "null")
    {
        cout<<name<<" = "<<amount;

    }

}
Node::~Node()
{
    //dtor
}
