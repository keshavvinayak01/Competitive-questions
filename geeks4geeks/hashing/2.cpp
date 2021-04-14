/*
Quadratic probing is a collision handling technique in hashing. Quadratic probing says that whenever a collision occurs, 
search for i2 position.

Given an array of integers and a Hash table. Fill the elements of the array into the hash table by using 
Quadratic Probing in case of collisions.
*/
// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int n) {
        for(int i = 0 ; i < hashSize; i++) hash[i] = -1;
        
        int h1, h2, j = 0;
        for(int i = 0 ; i < n ; i++) {
            h1 = arr[i] % hashSize;
            if(hash[h1] >= 0) {
                j = 0;
                do {
                    h2 = (arr[i] + j*j) % hashSize;
                    j++;
                } while(hash[h2] >= 0);
                
                hash[h2] = arr[i];
            }
            else 
                hash[h1] = arr[i];
        }
        //Your code here
    }


};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    
	    
	    int  N;
	    cin>>N;
	    int arr[N];
	    
	    for(int i=0;i<N;i++)
	    cin>>arr[i];
	    
	    vector<int> hash (hashSize);
	    Solution obj;
	    obj.QuadraticProbing (hash, hashSize, arr, N);
	    
	    for(int i = 0;i < hashSize; i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	}
	return 0;
}


  // } Driver Code Ends