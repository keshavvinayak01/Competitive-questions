#include <bits/stdc++.h>
using namespace std;

void swap(vector<int>& v,int a,int b){
    int temp= v[a];
    v[a]=v[b];
    v[b]=temp;
}

void buildMinHeapUtil(vector<int>& v,int index,int size){
  int l = 2*index+1;
  int r = 2*index+2;

  int smallest = index;
  if(l<=size && v[l] < v[smallest])
    smallest=l;

  if(r<=size && v[r] < v[smallest])
    smallest = r;

  if(smallest != index)
  {
      swap(v,smallest,index);
      buildMinHeapUtil(v,smallest,size);
  }

}

 void buildMinHeap(vector<int>& v){
     int parent =(v.size()-2)/2;
     int child =v.size()-1;
       while(parent >=0 && v[parent] > v[child]){
        swap(v,parent,child);
        buildMinHeapUtil(v,child,v.size()-1);
        child= parent;
        parent = (child-1)/2;
       }


 }

void buildMaxHeapUtil(vector<int>& v,int index,int size){
  int l = 2*index+1;
  int r = 2*index+2;

  int largest = index;
  if(l<=size && v[l] > v[largest])
    largest=l;

  if(r<=size && v[r]> v[largest])
    largest = r;

  if(largest != index)
  {
      swap(v,largest,index);
      buildMaxHeapUtil(v,largest,size);
  }

}

 void buildMaxHeap(vector<int>& v){
     int parent =(v.size()-2)/2;
     int child = v.size()-1;
    //   cout << "size count is " << v.size() << endl;
     //  cout << "parent element " << v[parent] << endl;
     //  cout << "child element  " << v[child] << endl;
       while(parent >=0 && v[parent] < v[child]){
        swap(v,parent,child);
     //   cout << "parent element " << v[parent] << endl;
     //  cout << "child element  " << v[child] << endl;
        buildMaxHeapUtil(v,child,v.size()-1);
        child= parent;
        parent = (child-1)/2;
       }


 }

 void pushData(vector<int>& v,int num,string validate){
    v.push_back(num);
//    cout << "vector size is " << v.size() << endl;
//    cout << "element value after : " << v[0] << endl;
//    if(size > 1)
//    cout << "element value after : " << v[1] << endl;
//    if(size>2)
//    cout << "element value after : " << v[2] << endl;
    if(validate == "1")
        buildMaxHeap(v);
    else
        buildMinHeap(v);
}

void popData(vector<int>& v,string validate){
    v[0] = v[v.size()-1];
    v.pop_back();
    int index=0;
    if(validate == "1")
        buildMaxHeapUtil(v,index,v.size()-1);
    else
        buildMinHeapUtil(v,index,v.size()-1);

}

void adjustElement(vector<int>& v1,vector<int>& v2){
   if(v1.size() > v2.size()){
    //    cout << "adjust element if condition " << endl;
    pushData(v2,v1[0],"0");
    popData(v1,"1");

   }else{
     //  cout << "adjust element else condition " << endl;
     //  cout << "data to be pushed is : " << v2[0] << endl;
     pushData(v1,v2[0],"1");
     popData(v2,"0");
   }

}

int printMedian(vector<int>& v1,vector<int>& v2,int num){

   if(v1.empty()){                                      // v1 is Empty
     v1.push_back(num);
   }else {
     if(num <=v1[0]){
        pushData(v1,num,"1");
     }else{

        pushData(v2,num,"0");
     }

      if(abs(v1.size()-v2.size()) >1){
         adjustElement(v1,v2);
         }
   }

   if(v1.size() == v2.size()){
      //  cout << "in if condition " << v1.size() << endl;
    return (v1[0] + v2[0])/2 ;
   }else if(v1.size() > v2.size()){
   //    cout << "in else if condition " << size1 << " " << size2 << endl;
   return v1[0];
   }
   else{
   // cout << "in else condition " << size1 << " " << size2 << endl;
    return v2[0];

   }
}

int main(){
  int n,num;
  vector<int> v1;
  vector<int> v2;
  cin >> n;
  for(int i=0;i<n;i++){
     cin >> num;
     cout << printMedian(v1,v2,num) << endl;

  }

 return 0;
}