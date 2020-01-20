/** @file graph.cpp
 * An adjacency list representation of an undirected weighted graph.
*/

#include "graph.h"
/*Do not add new libraries or files*/

Graph::Graph()
{
}

void Graph::addAirport(const string& airportName)
{
list<node> lis;
adjList[airportName] = lis;
}  // end addPerformer

void Graph::addConnection(const string& airport1, const string& airport2, int numOfPassengers)
{   /*YOUR IMPLEMENTATION*/

node * nNode = new node;
nNode->airportName = airport2;
nNode->numOfPassengers = numOfPassengers;

adjList[airport1].push_front(*nNode);

node * nNode2 = new node;
nNode2->airportName = airport1;
nNode2->numOfPassengers = numOfPassengers;

adjList[airport2].push_front(*nNode2);


}  // end addConnection
list<string> Graph::getAdjacentAirports(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
list<string> names;
for(std::list<node>::iterator it = adjList[airportName].begin();it != adjList[airportName].end();++it)
    {
        names.push_front(it->airportName);
     }
return names;
} // end getAdjacentAirports

int Graph::getTotalPassengers(const string& airportName)
{   /*YOUR IMPLEMENTATION*/
    int total = 0;
    for(std::list<node>::iterator it = adjList[airportName].begin();it != adjList[airportName].end();++it)
    {
       total = total + it->numOfPassengers;
    }
    return total;


}  // end getTotalPassengers


list<string> Graph::findShortestPath(const string& airport1, const string& airport2)
{   /*YOUR IMPLEMENTATION*/
// end findShortestPath
list<string> visList;
queue<string> q;
q.push(airport1);
visList.push_back(airport1);
list<int> weights;
while(!(q.empty()))
{
    string top = q.front();
   q.pop();
   int min = 99999;
   string miner;
  for(auto iter = adjList[top].begin();iter != adjList[top].end();++iter)
  {
      bool found = false;
      for(std::list<string>::iterator itList = visList.begin();itList != visList.end();++itList)
      {
          if(*itList == iter->airportName)
            found = true;
      }
      if(iter->airportName != airport2)
      {
      if(found == false)
      {
          if(iter->numOfPassengers < min)
          {
             miner = iter->airportName;
             min = iter->numOfPassengers;
          }
         visList.push_back(iter->airportName);
      }
      if(found == false){
        q.push(miner);
      }
      }
      else
      {
          q.push(airport2);
          iter = adjList[top].end();
          break;
      }

  }
}
list<string> result;
while(!(q.empty()))
{
    string top = q.front();
    result.push_back(top);
    q.pop();

}
return result;
}
list< pair<string, string> > Graph::findMST()
{   /*YOUR IMPLEMENTATION*/

list<string> visList;

list<pair<string,string>   > pairs;

map<string,list<node>>::iterator it = adjList.begin();
string name = it->first;

visList.push_back(name);


node * nNode = new node;
string name1 = "";
string name2 = "";
while( it != adjList.end())
{
    int min = 99999;
     for(std::list<string>::iterator iterar = visList.begin();iterar != visList.end();++iterar)
    {
        string temp = *iterar;
     for(auto iter = adjList[temp].begin();iter != adjList[temp].end();++iter)
    {
        bool visited = false;

        for(std::list<string>::iterator itList = visList.begin();itList != visList.end();++itList)
        {
           if(*itList == iter->airportName)
                visited = true;
        }

        if(visited == false)
        {
        if(iter->numOfPassengers < min)
        {
            name1 = *iterar;
            min = iter->numOfPassengers;
            name2 = iter->airportName;
        }
        }
    }
    }
    visList.push_back(name2);
    pair<string,string> pi;
    pi.first = name1;
    pi.second = name2;
    pairs.push_back(pi);
    ++it;
}
return pairs;
}  // end findMST

void Graph::deleteAirport(const string& airportName)
{   /*YOUR IMPLEMENTATION*/

 for (map<string,list<node>>::iterator it = adjList.begin(); it != adjList.end(); it++)
 {
     string name = it->first;
            if(name == airportName)
            {
                adjList.erase(it);

            }
     }

 }


// end deleteAirport

