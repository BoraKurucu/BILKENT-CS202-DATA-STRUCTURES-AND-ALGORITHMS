#include "OpenHashTable.h"

OpenHashTable::OpenHashTable()
{
    tableSize = 199;
    ar = new Node [tableSize];
    currentSize = 0;
}

OpenHashTable::~OpenHashTable()
{
    //dtor
}
int OpenHashTable::hashF(string name)
{
    int hashVal = 0;

   for (int i = 0; i < name.length(); i++)
   {
    if(name[i] != '\0' && name[i] != ' ')
	hashVal = 37 * hashVal + name[i];
   }

   hashVal %=tableSize;

   if (hashVal < 0)
	hashVal += tableSize;

   return hashVal;
}
void OpenHashTable::insert(string name,int amount,double & time,int & collision)
{
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;
    startTime = std::chrono::system_clock::now();

    if(currentSize < tableSize)
    {

    Node * node = new Node(name,amount);
    int hashIndex = hashF(name);
    int i = 1;
    bool noCol = false;
    while(ar[hashIndex].getName() != "null" && ar[hashIndex].getName() != "deleted")
    {
        if(noCol == false)
        {
        collision += 1;
        noCol = true;
        }
        hashIndex = hashIndex + i * i;
        i = i + 1;
        hashIndex = hashIndex % tableSize;
    }
    ar[hashIndex] = *node;
    currentSize += 1;
    }
    elapsedTime = std::chrono::system_clock::now() - startTime;
    time = time + elapsedTime.count();
}
void OpenHashTable::search(string name)
{
    int hashIndex = hashF(name);
    int i = 1;
    while(!(comp(ar[hashIndex].getName(),name)) && ar[hashIndex].getName() != "null")
    {
        hashIndex = hashIndex + i * i;
        i = i + 1;
        hashIndex = hashIndex % tableSize;
    }
    if((comp(ar[hashIndex].getName(),name)))
    {
       ar[hashIndex].printNode();
       cout<<""<<endl;
    }

}
void OpenHashTable::retrieve(string name,int & comparison)
{
     int hashIndex = hashF(name);
    int i = 1;
    while(!(comp(ar[hashIndex].getName(),name)) && ar[hashIndex].getName() != "null")
    {
        comparison += 1;
        hashIndex = hashIndex + i * i;
        i = i + 1;
        hashIndex = hashIndex % tableSize;
    }
    if((comp(ar[hashIndex].getName(),name)))
    {
         comparison += 1;
       return;
    }
}

bool OpenHashTable::comp(string s1,string s2)
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
void OpenHashTable::deleteN(string name)
{
    int hashIndex = hashF(name);

    int i = 1;


    while(!(comp(ar[hashIndex].getName(),name)) && ar[hashIndex].getName() != "null")
    {
        hashIndex = hashIndex + i * i;
        i = i + 1;
        hashIndex = hashIndex % tableSize;
    }

    if((comp(ar[hashIndex].getName(),name)))
    {

       ar[hashIndex].setName("deleted");
       currentSize = currentSize - 1;
    }

}
void OpenHashTable::timeAnalyser(double elapsed,int collision)
{
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Part a - Analysis of Open Addressing Hash Table"<<endl;
    cout<<"Parameter                       Time Elapsed"<<endl;
    double ret = 0;
    string strar[100] = {"alfalfa sprouts",
"apple fuji",
"apple gala",
"apple granny smith",
"apricots",
"asparagus",
"avocado large hass",
"avocado small",
"banana leaf",
"banana",
"banana baby",
"banana burro",
"banana macho",
"basil",
"bean sprouts",
"beans black",
"beans black eye",
"beans garbanzo",
"beans greenf",
"beans haba dry",
"beans haba fresh",
"beans lentils",
"beans peruano",
"beans pinto",
"beans red",
"beets bunch",
"beets loose",
"bell pepper green",
"bell pepper red",
"black berries",
"bok choy",
"broccoli",
"brussel sprouts",
"cabbage green",
"cabbage Napa",
"cabbage red",
"camote de cerro",
"carrots",
"cauliflower",
"celery",
"cherries red",
"chile de arbol fresco",
"chile anaheim",
"chile habanero",
"chile hungaro",
"chile jalapeño",
"chile pasilla",
"chile serrano",
"chile yellow",
"chile dry california",
"chile dry arbol",
"chile dry guajillo",
"chile dry japanese",
"chile dry pasilla",
"coconut white",
"corn white",
"corn yellow",
"cucumber",
"cucumber persian",
"duritos",
"eggplant",
"garlic",
"ginger root",
"grapefruit",
"grapes globe",
"grapes green",
"grapes red seedless",
"green collard",
"green kale",
"green turnip",
"guajes",
"guasanas",
"guayabas",
"cilantro",
"epazote",
"mint",
"oregano",
"parsley",
"jamaica",
"jicama",
"leeks",
"lemons yellow",
"lettuce",
"lettuce green leaf",
"lettuce red leaf",
"lettuce romaine",
"limes",
"limes mex key",
"limes sweet",
"malanga",
"mamey",
"mango",
"melon cantaloupe",
"melon honeydew",
"mushroom bulk",
"mushroom pack",
"nectarines",
"nectarines white","nuts brazil"};

int searchComp = 0;
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;
    startTime = std::chrono::system_clock::now();

    for(int i =0; i < 100;i++)
        retrieve(strar[i],searchComp);

    elapsedTime = std::chrono::system_clock::now() - startTime;
    ret = ret + elapsedTime.count();

    double del = 0;

    std::chrono::time_point< std::chrono::system_clock > startTime2;
    std::chrono::duration< double, milli > elapsedTime2;
    startTime = std::chrono::system_clock::now();

     for(int i =0; i < 100;i++)
        deleteN(strar[i]);

    elapsedTime2 = std::chrono::system_clock::now() - startTime2;
    del = del + elapsedTime.count();

    cout<<"Average Insertion Time         "<<(elapsed)/100.0<<" ms "<<endl;
    cout<<"Average Retrieval Time         "<<ret/100.0<< " ms "<<endl;
    cout<<"Average Deletion Time           "<<del/100.0<<" ms "<<endl;
    cout<<""<<endl;
    cout<<"Number of comparisons in Retrieval = "<<searchComp<<endl;
    cout<<"Number of collisions in Insertion ="<<collision<<endl;
    cout<<"----------------------------------------------------"<<endl;


}
void OpenHashTable::print()
{
    int k = 0;
    string checker = "";
    for(int i = 0; i < tableSize;i++)
    {
        checker = ar[i].getName();
         if(checker != "deleted" && checker != "null")
         {
             cout<<k<<" : ";
             ar[i].printNode();
             cout<<", ";
             k++;
             cout<<""<<endl;
         }

    }
}
