/**
* Title: Graphs
* Author : Moin Khan
* ID: 22101287
* Section : 1
* Homework : 4
* Description : MolGraph main Code
*/

#include "MolGraph.h"
MolGraph::MolGraph(const std::string &filename)
{
    ifstream file(filename);
    string line;
    getline(file,line);
    size = stoi(line);
    documents = new int*[size];
    degree = new int[size];
    int t = 0;
    while(getline(file,line))
    {

        stringstream ss(line);
        int input;
        int i = 0;
        int j=0;
        while(ss>>input)
        {
            if(i==0)
            {
                i++;
            }
            else if(i==1)
            {
                documents[t] = new int[input];
                degree[t] = input;
                i++;
            }
            else
            {
                documents[t][j] = input;
                j++;

            }



        }
        t++;
    }

}
MolGraph::~MolGraph()
{
    for(int i=0; i<size; i++)
    {
        delete[] documents[i];
        documents[i] = nullptr;
    }
    delete[] degree;
    degree = nullptr;
    delete[] documents;
    documents = nullptr;
}

void MolGraph::minBondPath(int source, int destination)
{
    Queue q;
    int parentArray[size];
    bool visited[100001] = {false};
    visited[source] = true;
    q.push(source);
    while(!q.isEmpty())
    {
        int currentNode = q.pop();
        if(currentNode == destination ) {
            break;
        }
        else
        {
            int deg = this->degree[currentNode];
            for(int i=0; i<deg; i++)
            {
                int child = documents[currentNode][i];
                if(!visited[child])
                {
                    visited[child] = true;
                    parentArray[child] = currentNode;
                    q.push(child);
                }
            }
        }
    }
    int pathArray[size];
    pathArray[0] = destination;
    int t = 0;
    int curr = destination;
    while(curr!=source)
    {
         curr = parentArray[curr];
         t++;
         pathArray[t] = curr;

    }
    cout<<"Minimum number of bonds to traverse from atom "<<source<<" to atom "<<destination<<": "<<t<<endl;
    cout<<"Path: ";
    for(int i =t; i>=0; i--)
    {
        cout<<pathArray[i];
        if(i>0)
        {
            cout<<" -> ";
        }
        else
        {
            cout<<endl;
        }
    }



}

int MolGraph::farthestNode(int source, int& maxD)
{
    Queue q;
    int parentArray[size];
    for(int i=0; i<size;i++)
    {
        parentArray[i] = -1;
    }
    int target = -1;
    maxD = 0;
    q.push(source);
    parentArray[source] = 0;
    while(!q.isEmpty())
    {
        int currentNode = q.pop();
        int deg = this->degree[currentNode];
        for(int i=0; i<deg; i++)
        {
            int child = documents[currentNode][i];
            if(parentArray[child]==-1)
            {
                parentArray[child] = parentArray[currentNode]+1;
                q.push(child);

                if(parentArray[child]>maxD)
                {
                    maxD = parentArray[child];
                    target = child;
                }
            }
        }

    }
    return target;



}

void MolGraph::getDiameter()
{
    int d;
    int x = farthestNode(0,d);
    x = farthestNode(x,d);
    cout<<"Diameter of the molecule: "<<d<<endl;

}

void MolGraph::getMST()
{
    edges shape[size];
    int eSize = 0;
    Queue q;
    bool visited[100001] = {false};
    q.push(0);
    visited[0] = true;
    while(!q.isEmpty())
    {
        int currentNode = q.pop();
        int deg = this->degree[currentNode];
        for(int i=0; i<deg; i++)
        {
            int child = documents[currentNode][i];
            if(!visited[child])
            {
                visited[child] = true;
                shape[eSize].start = currentNode;
                shape[eSize].end = child;
                eSize++;
                q.push(child);
            }
        }

    }
    cout<<"Minimum Spanning Tree:"<<endl;
    cout<<"Cost: " <<eSize<<endl;
    cout<<"Edges:"<<endl;
    for(int i = 0; i<eSize; i++)
    {

        cout<<shape[i].start<<" - "<<shape[i].end<<endl;
    }
}