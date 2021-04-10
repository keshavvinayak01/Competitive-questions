// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution
{   
public:     
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m)  {
        int visited[100][100];
        memset(visited, 0, 100*100*sizeof(int));
        vector<int> soln;
        pair<int, int> topLeft, topRight, bottomRight, bottomLeft;
        topLeft = make_pair(0, 0);
        topRight = make_pair(0, m-1);
        bottomRight = make_pair(n-1, m-1);
        bottomLeft = make_pair(n-1, 0);

        while(1) {
            // break if already visited
            if((visited[topLeft.first][topLeft.second] || 
                visited[topRight.first][topRight.second] || 
                visited[bottomRight.first][bottomRight.second] || 
                visited[bottomLeft.first][bottomLeft.second]) == true)
                break;
        
            // Horizontal Right
            for(int i = topLeft.second; i <= topRight.second && !visited[topRight.first][i]; i++) {
                visited[topRight.first][i] = 1;
                soln.push_back(matrix[topRight.first][i]);
            }
            topRight.first++; topRight.second--;

            // Vertical Down
            for(int i = topRight.first; i <= bottomRight.first && !visited[i][bottomRight.second]; i++) {
                visited[i][bottomRight.second] = 1;
                soln.push_back(matrix[i][bottomRight.second]);
            }
            bottomRight.first--; bottomRight.second--;

            // Horizontal Left
            for(int i = bottomRight.second; i >= bottomLeft.second && !visited[bottomLeft.first][i]; i--) {
                visited[bottomLeft.first][i] = 1;
                soln.push_back(matrix[bottomLeft.first][i]);
            }
            bottomLeft.first--; bottomLeft.second++;

            // Vertical Up
            for(int i = bottomLeft.first; i >= topLeft.first && !visited[i][topLeft.second]; i--) {
                visited[i][topLeft.second] = 1;
                soln.push_back(matrix[i][topLeft.second]);
            }
            topLeft.first++; topLeft.second++;
            
        }
        return soln;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends