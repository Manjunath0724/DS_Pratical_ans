    #include <iostream>
    using namespace std;

    #define MAX 10

    int n = 5;

    // Adjacency Matrix
    int graph[MAX][MAX] =
    {
        {0,1,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    int stack[MAX];
    int top = -1;

    int status[MAX];

    // Push Operation
    void push(int x)
    {
        if(top == n - 1)
        {
            cout << "Overflow\n";

            return;
        }

        top++;

        stack[top] = x;
    }

    // Pop Operation
    int pop()
    {
        if(top == -1)
        {
            cout << "Underflow\n";

            return -1;
        }

        return stack[top--];
    }

    // DFS Function
    void dfs()
    {
        int start = 0;

        // Mark all nodes unvisited
        for(int i = 0; i < n; i++)
        {
            status[i] = 1;
        }

        push(start);

        status[start] = 2;

        while(top != -1)
        {
            int node = pop();

            cout << node << " ";

            status[node] = 3;

            // Traverse adjacent nodes
            for(int i = n - 1; i >= 0; i--)
            {
                if(graph[node][i] == 1 && status[i] == 1)
                {
                    push(i);

                    status[i] = 2;
                }
            }
        }
    }

    int main()
    {
        cout << "\nDFS Traversal: ";

        dfs();

        return 0;
    }