#include "ChainHashTable.h"

ChainHashTable::ChainHashTable()
{
    tableSize = 199;
    ar = new LinkedList [tableSize];
    currentSize = 0;
}
int ChainHashTable::hashF(string name)
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
void ChainHashTable::insert(string name,int amount,double & time)
{
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;
    startTime = std::chrono::system_clock::now();

    int hashIndex = hashF(name);
    if(ar[hashIndex].isEmpty())
        currentSize += 1;
    ar[hashIndex].insert(name,amount);

    elapsedTime = std::chrono::system_clock::now() - startTime;
    time = time + elapsedTime.count();
}
void ChainHashTable::retrieve(string name, int & comparison)
{

      int hashIndex = hashF(name);
      bool found;
     Node  node = ar[hashIndex].search2(name,comparison,found);
}
void ChainHashTable::deleteC(string name)
{
     int hashIndex = hashF(name);
     ar[hashIndex].deleteI(name);
}
void ChainHashTable::search(string name)
{
    bool found;
    int comp = 0;
     int hashIndex = hashF(name);
     Node  node = ar[hashIndex].search2(name,comp,found);

     if(found == true)
     {
     node.printNode();
     cout<<""<<endl;
     }
     return;
}
void ChainHashTable::print()
{
    int k = 0;
    for(int i = 0; i < tableSize;i++)
    {
        if(!(ar[i].isEmpty()))
           {
               cout<<k<<" : ";
               k++;
                ar[i].print();
           }

    }
}
void ChainHashTable::timeAnalyser(double elapsed)
{
 cout<<"----------------------------------------------------"<<endl;
    cout<<"Part b - Analysis of Separate Chain Hash Table"<<endl;
    cout<<"Parameter                       Time Elapsed"<<endl;
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
"nectarines white","nuts brazil","nuts peanuts"};
double ret = 0;
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

    cout<<"here2"<<endl;
     for(int i =0; i < 100;i++)
        deleteC(strar[i]);

     elapsedTime2 = std::chrono::system_clock::now() - startTime2;
    del = del + elapsedTime.count();

    cout<<"Average Insertion Time         "<<(elapsed)/100.0<<" ms "<<endl;
    cout<<"Average Retrieval Time         "<<ret/100.0<< " ms "<<endl;
    cout<<"Average Deletion Time           "<<del/100.0<<" ms "<<endl;
    cout<<""<<endl;
    cout<<"Number of comparisons in Retrieval = "<<searchComp<<endl;
    cout<<"----------------------------------------------------"<<endl;


}
ChainHashTable::~ChainHashTable()
{
    //dtor
}
