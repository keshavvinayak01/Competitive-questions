#include<bits/stdc++.h>
using namespace std;
#define N 10
void print(char board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
 //   cout<<endl;
}
//reset right
void resetHorizontal(char board[N][N],int row,int col,string s,int *freq){
   // cout<<"resetHorizontal"<<endl;
    for(int i=col,k=0;k<s.length();i++,k++){
        if(freq[k]==1){
            board[row][i]='-';
        }
    }
  //  print(board);
}
// reset down
void resetVertical(char board[N][N],int row ,int col,string s,int *freq){
  //  cout<<"resetVertical"<<endl;
    for(int i=row,k=0;k<s.length();i++,k++){
        if(freq[k]==1){
            board[i][col]='-';
        }
    }
  //  print(board);
}
// set right
void setHorizontal(char board[N][N],int row,int col,string s,int*freq){
   // cout<<"setHorizontal"<<endl;
    for(int i=col,k=0;k<s.length();i++,k++){
        if(board[row][i]=='-'){
            board[row][i]=s[k];
            freq[k]=1;
        }
    }
  //  print(board);
}
// set down
void setVertical(char board[N][N],int row, int col,string s,int *freq){
  //  cout<<"setVertical"<<endl;
    for(int i=row,k=0;k<s.length();i++,k++){
        if(board[i][col]=='-'){
            board[i][col]=s[k];
            freq[k]=1;
        }
    }
 //   print(board);
}
///down
bool isVertical(char board[N][N],int row,int col,string s){
    int i=row,k=0;
    while(k<s.length()&&i<N){
        if(board[i][col]=='+'){
            return false;
        }else if(board[i][col]!='-'&&board[i][col]!=s[k]){
            return false;
        }
        i++;k++;
    }
    if(k<s.length()){
        return false;
    }else{
        return true;
    }
}
///right
bool isHorizontal(char board[N][N],int row ,int col,string s){
    int i=col,k=0;
    while(k<s.length()&&i<N){
        if(board[row][i]=='+'){
            return false;
        }else if(board[row][i]!='-'&&board[row][i]!=s[k]){
            return false;
        }
        i++;k++;
    }
    if(k<s.length()){
        return false;
    }else{
        return true;
    }
}
bool crossword(char board[N][N],string word,int index){
    if(index>=word.length()){
        return true;
    }
    string s="";
    int curr=index;
    while(word[index]!=';'&&word[index]!='\0'){
        index++;
    }
    s=word.substr(curr,index-curr);
   // cout<<s<<endl;
    for(int r=0;r<10;r++){
        for(int c=0;c<10;c++){
            if(board[r][c]=='-'||board[r][c]==s[0]){
                if(isVertical(board,r,c,s)){
                    int freq[s.length()]={0};
                    setVertical(board,r,c,s,freq);
                    if(crossword(board,word,index+1)){
                       // cout<<"hello"<<endl;
                        return true;
                    }else{
                        resetVertical(board,r,c,s,freq);
                    }
                }else if(isHorizontal(board,r,c,s)){
                    int freq[s.length()]={0};
                    setHorizontal(board,r,c,s,freq);
                    if(crossword(board,word,index+1)){
                        return true;
                    }else{
                        resetHorizontal(board,r,c,s,freq);
                    }
                }
            }
        }
    }
    return false;
}
int main(){
    char board[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
        }
    }
    string s;
    cin>>s;
    bool ans= crossword(board,s,0);
    print(board);
}