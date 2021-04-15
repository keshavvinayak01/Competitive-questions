/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.
*/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort() {
    int size = s.size();
    int arr[size];
    int curr, i = 0, j;
    while(!s.empty()) {
        curr = s.top();
        s.pop();
        arr[i] = curr;
        j = i;
        while(j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j], arr[j-1]);
            j--;
        }

        i++;
    }
    i = 0;
    while(i != size)
        s.push(arr[i++]);
    
}