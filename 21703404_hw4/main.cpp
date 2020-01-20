#include <iostream>
#include "OpenHashTable.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <iomanip>
#include <fstream>.
#include "ChainHashTable.h"

using namespace std;

int main( int argc , char ** argv )
{

    string filename = argv[1];
    string line;
    OpenHashTable table;
    double timeOpen = 0;
    int collisionOpen = 0;
    double timeChain = 0;
    ChainHashTable cTable;
    string text;

   ifstream input;
    input.open(filename.c_str());

     while(getline(input,text))
    {
        istringstream ss(text);
        int amount = -5;
        string name1 = "";
        do
        {
            string word;
            ss >> word;
            if(amount == -5)
                istringstream(word) >> amount;
            else if(word != "" && word != " ")
                name1 = name1 + " " + word;

        }while(ss);
        table.insert(name1,amount,timeOpen,collisionOpen);
        cTable.insert(name1,amount,timeChain);

    };



    table.print();
    cout<<""<<endl;
    cout<<""<<endl;
    table.search("lettuce red leaf");
    table.search("black berries");
    table.search("broccoli" );
    cout<<""<<endl;
    cout<<""<<endl;
    table.deleteN("lettuce red leaf");
    table.deleteN("basil");
    table.deleteN("alfalfa sprouts");
    cout<<""<<endl;
    cout<<""<<endl;
    table.print();




    cout<<""<<endl;
    cout<<""<<endl;
    cTable.print();
    cout<<""<<endl;
    cout<<""<<endl;
    cTable.search("grapes globe");
    cTable.search("black berries");
    cTable.search("yucca" );
    cout<<""<<endl;
    cTable.deleteC("lettuce red leaf");
    cTable.deleteC("banana leaf");
    cTable.deleteC("squash acorn");
    cout<<""<<endl;
    cout<<""<<endl;
    cTable.print();
    cout<<""<<endl;
    cout<<""<<endl;




    table.timeAnalyser(timeOpen,collisionOpen);
    cTable.timeAnalyser(timeChain);


    return 0;
}
