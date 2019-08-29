#include<bits/stdc++.h>
using namespace std;

int num_codes(int *n, int size){
    if(size == 1){
        return 1;
    }
    if(size == 0){
        return 1;
    }
    int output = num_codes(n, size-1);
    if(n[size-2]*10 + n[size-1] <= 26)
        output += num_codes(n, size-2);
    return output;
}

int num_codes_2(int *n, int size, int* arr){
    if(size == 1){
        return 1;
    }
    if(size == 0){
        return 1;
    }
    if(arr[size] > 0){
        return arr[size];
    }
    int output = num_codes(n, size-1);
    if(n[size-2]*10 + n[size-1] <= 26)
        output += num_codes(n, size-2);
    arr[size] = output;
    return output;
}

int num_codes_iterative(string input, int size){
    int* output = new int[size+1];
    if(input[0] != 0)
        output[0] = 1;
    else
        output[0] = 0;
    if(input[1] != 0)
        output[1] = 1;
    else
        output[1] = 0;
    for(int i= 2; i <=size; i++){
        output[i] = output[i-1];
        if((input[i-2] - '0')*10 + (input[i-1] - '0') <= 26 && input[i-2] != '0'){
            output[i] += output[i-2];
        }
    }
    int ans = output[size];
    delete[] output;
    return ans;
}


int main(){
    string input;
    while(cin >> input){
        cout << num_codes_iterative(input, input.length()) << endl;
    }
    return 0;
}