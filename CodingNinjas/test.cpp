#include <bits/stdc++.h> 
using namespace std; 
// int cur=0; 
// int matrix[12][12]; 
// bool visited[12]; 
// deque <int> queue;
 
// void function(int n)
// { 
//     cout<<cur<<" "; 
//     visited[cur]=true; 
//     queue.push_back(cur); 
 
//     do
//         { 
//         for(int j=0;j<n;j++)
//                 { 
//             if(matrix[cur][j]==1 && !visited[j])
//                     { 
//                 queue.push_back(j); 
//                 cout<<j<<" "; 
//                 visited[j]=true; 
//                 } 
 
//                  } 
 
//         queue.pop_front(); 
//         if(!queue.empty()) 
//         cur=queue.front(); 
//      }while(!queue.empty()); 
// }

int main()
{   
    // int num=0; 
    // int n; 
    // cin>>n; 
 	 
    // for(int i=0;i<n;i++) 
    //       for(int j=0;j<n;j++) 
    //         cin>>matrix[i][j]; 
 	
    // for(int i=0;i<n;i++) 
    //     visited[i]=false; 
 
    //     function(n); 
    vector<int> arr = {1,2,3,4,5,6};
    vector<int>::iterator it;
    for(it = arr.begin(); it < arr.end(); it++){
        cout<<*it<<" ";
    }
    return 0; 
} 
 
