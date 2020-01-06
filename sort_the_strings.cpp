#include<bits/stdc++.h>
using namespace std;

int edge;
string reversed, sortType;

bool compare(vector<string> a, vector<string> b) {
    if(sortType == "numeric") {
        int aint, bint;
        stringstream a1(a[edge]);
        stringstream b1(b[edge]);
        a1 >> aint;
        b1 >> bint;
        if(reversed == "false")
            return aint < bint;
        else
            return aint > bint;
    }
    else {
        if(reversed == "false")
            return a[edge] < b[edge];
        else
            return a[edge] > b[edge];
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<string>> input(n);
    string* temp = new string[n+1];
    for(int i = 0 ; i <= n ; i++) {
        getline(cin, temp[i]);
    }
    int j;
    for(int i = 1 ; i <= n ; i++) {
        j = 0;
        while(j < temp[i].size()) {
            string word = "";
            while(temp[i][j] != ' ' && temp[i][j] != '\0') {
                word += temp[i][j];
                j++;
            }
            j++;
            input[i-1].push_back(word);
        }
    }

    string params;
    getline(cin, params);
    vector<string> broke_params;
    string word;

    for(int i = 0 ; i < params.size() ; i++) {
        word = "";
        while(params[i] != ' ' && params[i] != '\0') {
            word += params[i];
            i++;
        }
        broke_params.push_back(word);
    }

    stringstream geek(broke_params[0]);
    geek >> edge;
    edge -= 1;
    reversed = broke_params[1];
    sortType = broke_params[2];


    sort(input.begin(), input.end(), compare);
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < input[i].size(); j++) {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}