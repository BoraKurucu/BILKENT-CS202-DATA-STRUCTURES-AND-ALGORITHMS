#ifndef NODE_H
#define NODE_H
using namespace std;
#include <iostream>
#include <string>

class Node
{
    public:
        Node();
        Node(string name1,int amount1);
        virtual ~Node();
        string getName();
        int getAm();
        void setName(string x);
        void printNode();

    protected:

    private:
        string name;
        int amount;
};

#endif // NODE_H
