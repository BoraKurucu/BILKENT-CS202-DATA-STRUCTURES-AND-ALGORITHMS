    #include <iostream>
    #include "MedianHeap.h"
    #include "HuffmanQueue.h"
    #include "HuffmanCode.h"
    #include<fstream>
    #include<string>
    using namespace std;
/**
* Title : Heaps and AVL Trees
* Author : Mehmet Bora Kurucu
* ID: 21703404
* Section : 2
* Assignment : 3
* Description : main to read and write
*/

    void printHuffman(MinHeapNode * root)
    {
        if(root == NULL)
            return;
        //cout<<" node char "<<root->character<<" freq is "<<root->freq<<endl;
        printHuffman(root->left);
        printHuffman(root->right);
    }
    bool isChar(char ch)
    {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
                  return true;
              return false;
    }
    bool isNumber(char ch)
    {
        if(ch =='0' || ch =='2'|| ch =='3' || ch =='4' ||ch =='5'
        || ch =='6' ||ch =='7'|| ch =='8' ||
        ch =='9' || ch == '1')
        return true;

        return false;
    }

    void writer(MinHeapNode * node,string theway,string & result,int level)
    {
        if(node == NULL)
            return;
        if(node->left != NULL)
        {
            theway = theway + '0';
            if(isChar(node->left->character))
            result = result + " " + node->left->character + " " + theway;
            writer(node->left,theway,result,level + 1);
            if(theway.size() > 0)
            theway.erase(theway.size() - 1);
        }
        if(node->right != NULL)
        {
            theway = theway + '1';
            if(isChar(node->right->character))
            result = result + " " + node->right->character + " " + theway;
            writer(node->right,theway,result,level + 1);
            if(theway.size() > 0)
            theway.erase(theway.size() - 1);

        }

    }
     int main(int argc,char * argv[])
    {
     if( argc <= 2)
     {
         cout<<"not enough inputs"<<endl;
         return 0;
     }
     string inputName = argv[1];
     string outputName = argv[2];
     //cout<<"in name is "<<inputName<<endl;
     //cout<<"out name is "<<outputName<<endl;
     ifstream read;
     read.open(inputName.c_str());
     string ln;
     HuffmanQueue * qu = new HuffmanQueue;
     int size = 0;
     if(read)
     {
     while (getline(read,ln))
        {
            int charIndex = 0;
            char ch = ' ';
            int freq = 0;
            bool first = true;
            int exponent = 1;
            bool charFound = false;
            bool numberFinished = false;
            bool entered = false;
        for(charIndex = 0; charIndex < ln.size();charIndex++)
        {
            while( isNumber(ln[charIndex]))
            {
                if(first == true)
                {
                    freq = ln[charIndex] - '0';
                    first = false;
                }
                else
                {
                    freq = freq * exponent + (ln[charIndex] - '0');
                }
                exponent = exponent * 10;
                numberFinished = true;
                charIndex++;
                entered = true;
            }
            if(entered)
            {
                charIndex--;
                entered = false;
            }
            if(isChar(ln[charIndex]) && charFound == false)
            {
                ch = ln[charIndex];

                charFound = true;
                numberFinished == false;
            }
            else if( charFound == true && numberFinished == true && freq != 0)
            {
                  MinHeapNode * node = new MinHeapNode();
                  node->character = ch;
                  node->freq = freq;
                  //cout<<"in insert freq is "<<node->freq<<" char is "<<node->character<<endl;
                  size++;
                  qu->insert(node);
                  freq = 0;
                  ch = ' ';
                  first = true;
                  exponent = 1;
                  charFound = false;
                  numberFinished == false;
            }
        }
     }
     }
     else
     {
         cout<<"input file not found."<<endl;
     }
     HuffmanCode huff;
     string myway = "";
     string result = "";
     int level = 0;
     MinHeapNode * root = huff.buildHuffman(qu,size);
     printHuffman(root);
     writer(root,myway,result,level);
     //cout<<"result is "<<result<<endl;
      ofstream myfile;
      myfile.open (outputName.c_str());
      if(!myfile)
      {
          cout<<"output file not found"<<endl;
      }
      myfile << result;
    return 0;
    }

