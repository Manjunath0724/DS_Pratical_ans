#include<iostream>
using namespace std;

#define MAX 10

int n = 5;

// Adjacency Matrix
int g[5][5] =
{
    {0,1,1,0,0},
    {0,0,0,1,0},
    {0,0,0,0,1},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

int status[MAX];
int queue[MAX];

int front = -1;
int rear = -1;

// Insert into Queue
void insert(int item)
{
    if(rear == MAX - 1)
    {
        cout << "Queue is Full";
    }
    else
    {
        rear++;

        queue[rear] = item;
    }

    if(front == -1)
    {
        front = 0;
    }
}

// Delete from Queue
int delet()
{
    if(front == -1)
    {
        cout << "Queue is Empty";

        return -1;
    }

    int item = queue[front];

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }

    return item;
}

// BFS Function
void bfs()
{
    int start = 0;

    // Mark all nodes unvisited
    for(int i = 0; i < n; i++)
    {
        status[i] = 1;
    }

    insert(start);

    status[start] = 2;

    while(front != -1)
    {
        int node = delet();

        cout << node << " ";

        status[node] = 3;

        for(int i = 0; i < n; i++)
        {
            if(g[node][i] == 1 && status[i] == 1)
            {
                insert(i);

                status[i] = 2;
            }
        }
    }
}

int main()
{
    cout << "BFS Traversal: ";

    bfs();

    return 0;
}