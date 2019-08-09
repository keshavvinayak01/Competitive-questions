// int findAllIndices(int *input, int size, int x, int &output[], int i, int count=0){
//     if(input[0] == x){
//         for(int j = 0; output[j] != '\0'; j++){
//             output[j+1] = output[j]; 
//         }
//         output[0] = i;
//         count++;
//     }
//     if(size == 1){
//         return count;
//     }
//     return findAllIndices(input, size-1, x, output, ++i);
// }

// int allIndexes(int input[], int size, int x, int output[]) {
// 	return findAllIndices(input, size, x, output, 0, 0);
    
// }

// void findIndexes(int input[], int currIndex, int size, int x, int output[], int &k){
// 	if(currIndex == size)
// 		return;
// 	if(input[currIndex] ==x){
// 		output[k] = currIndex;
// 		k++;
// 	}
// 	findIndexes(input, ++currIndex, size, x, output, k);
// }

// int allIndexes(int input[], int size, int x, int output[]){
// 	int k = 0;
// 	findIndexes(input, 0, size, x, output, k);
// 	return k
// }


// Kadane's algorithm
// Max sum of subarray

// #include <iostream>
// using namespace std;

// typedef long long ll;

// ll kadane(int *arr, int n){
// 	ll curr_sum = 0;
// 	ll max_so_far = INT_MIN;
// 	for(int i=0; i< n; i++){
// 		curr_sum += arr[i];
// 		if(curr_sum > max_so_far){
// 			max_so_far = curr_sum;
// 		}
// 		if(curr_sum < 0){
// 			curr_sum = 0;
// 		}
// 	}
// 	return max_so_far
// }

// ll maxSubarraySum(int arr[], int n, int k){
// 	ll kadanes_sum = kadane(arr,n);
// 	if(k == 1) return kadanes_sum;

// 	ll curr_prefix_sum = 0, curr_suffix_sum = 0;
// 	ll max_prefix_sum = INT_MIN, max_suffix_sum = INT_MIN;

// 	for(int i=0; i<n; i++){
// 		curr_prefix_sum = curr_prefix_sum + arr[i];
// 		max_prefix_sum = max(curr_prefix_sum, max_prefix_sum);
// 		curr_suffix_sum = curr_suffix_sum + arr[n-i-1];
// 		max_suffix_sum = max(curr_suffix_sum, max_suffix_sum);
// 	}
// 	totalSum = curr_prefix_sum;
// 	ll ans;
// 	cout<<max(max_suffix_sum + max_prefix_sum, kadane_sum);
// 	if(totalSum < 0){
// 		ans = max(max_suffix_sum +  max_prefix_sum, kadanes_sum);
// 	}
// 	else{
// 		ans = max(max_suffix_sum + max_prefix_sum + totalSum*(k-2), kadanes_sum);
// 	}
// }


// Maximum subarray product

// int maxSubarrayProduct(int arr[], int n){


// 	int max_ending_here = 1;
// 	int min_ending_here = 1, max_so_far = 0;

// 	for(int i=0; i< n; i++){
// 		if(arr[i] > 0){
// 			max_ending_here *= arr[i];
// 			min_ending_here = min(min_ending_here*arr[i], 1)
// 		}
// 		else if(arr[i] == 0){
// 			max_ending_here = 1;
// 			min_ending_here = 0;
// 		}
// 		else{
// 			int temp = max_ending_here;
// 			max_ending_here = max(min_ending_here*arr[i],1);
// 			min_ending_here = temp*a[i];
// 		}
// 		max_so_far = max(max_so_far, max_ending_here);
// 	}
// 	return max_so_far;
// } 

//  MindBending product = find multiplication of all elements except a[i], don't use division.

using namespace std;

// int main(){
// int t;
// cin>>t;
// while(t--){
// 	int n;
// 	cin>>n;
// 	int arr[n];
// 	long prod[n];
// 	for(int i=0; i< n; i++){
// 		cin>>arr[i];
// 	}
// 	long lp = 1;
// 	for(int i=0;i<n;i++){
// 		prod[i] = lp;
// 		lp = lp*arr[i];
// 	}
// 	long rp = 1;
// 	for(int i=n-1; i>=0; i--){
// 		prod[i] *= rp;
// 		rp *= arr[i];
// 	}
// 	for(int i=0;i<n;i++){
// 	cout<< prod[i] << " ";
// 	}
// 	cout<<endl;
// }

// return 0;
// }


// int main(){
// 	vector<int> v(5);
// 	for(int i=0; i<v.size(); i++){
// 		v.push_back(i+1)
// 	}

// 	vector<int>::iterator it;
// 	for(it = v.begin(); it != v.end(); it++){
// 		cout<<*it<<" ";
// 	}
// 	cout<<endl;
// 	return 0;
// }

// int main(){

// 	string s = "Keshav";
// 	string s1(s,2,4);
// 	// cout<<s<<s1<<endl;
// 	string s2 = s.substr(1,4);
// 	cout<<endl<<s2<<endl;
// 	if(s1.compare(s2) == 0){
// 		cout<<s1 << " is equal to "<<s2<<endl;
// 	}
// 	else{
// 		cout<<s1<<" is not equal to "<<s2<<endl;
// 	}
// 	return 0;
// }

// int lengthOfLongestSubstring(string s) {
//         // s.to_lower()
//         vector<int> alpha_arr(128);
        
//         string largest_curr = "",ans="";
//         for(int i=0; i < s.length(); i++){
//             if(alpha_arr[int(s[i])] == 1){
//             	alpha_arr.clear();
//                 if(largest_curr.length() > ans.length())
//                     ans = largest_curr;
//                 int k=0;
//                 for(k=0;largest_curr[k] != s[i];k++);
//                 try{
//             		largest_curr = largest_curr.substr(k+1, largest_curr.length() - 1);
//                 }
//             	catch(...){
//             		largest_curr = "";
//             	}
//             }
//             largest_curr += s[i];
//             alpha_arr[int(s[i])] = 1;
//         }
//         if(largest_curr.length() > ans.length()) ans=largest_curr;
//         return ans.length();
// }

// int main()
// {
// 	string s;
// 	cin>>s;
// 	cout<<lengthOfLongestSubstring(s)<<endl;
// }
// struct Interval{
// 	int st;
// 	int et;
// }
// bool compare(Interval i1, Interval i2){
// 	return i1.st < i2.st
// }

	// pair<int,char> p;
	// pair<int,char> p2(1,'a');

	// p = make_pair(2,'b');

	// cout<<p2.first<< " "<<p2.second<<endl;

	// SET

	// set<int> s;	
	// int arr[] = {1,2,3,4,5,6,5};
	// for(int i=0;i<7;i++){
	// 	s.insert(arr[i]);
	// }
	// set<int>::iterator it;

	// for(it = s.begin(); it != s.end(); it++){
	// 	cout<<*it<<endl;
	// }
	// if(s.find(6) == s.end()){
	// 	cout<<"Element not found";
	// }
	// else{
	// 	cout<<"Element found"
	// }

	// MAP

	// int arr[] = {1,2,3,4,5,6,5};
	// map<int, int> m;
	// for(int i=0;i<7;i++){
	// 	m[arr[i]] = m[arr[i]] + 1;
	// }

	// map<int, int>::iterator it;
	// for(it = m.begin(); it< m.end(); it++){
	// 	cout<<it->first<<" "<<it->second;
	// }
	// cout<<endl;
	// Can also use unordered map
	// There is list, stack, queue, priority queue as well

// 	int arr[] = {1,3,4,6,0,2,3};
// 	sort(arr,arr+6);
// 	sort(arr,arr+6, greater<int>()) // Decreasing order
// 	for(int i=0; i<6; i++){
// 		cout << arr[i] << " ";
// 	}
// 	Interval arr[] = {{6,4}, {3,5}, {4,6}, {8,13}};
// 	sort(arr, arr+4, compare);


// 	for(int i=0;i < 4; i++){
// 		cout<<arr[i].st<<" : " << arr[i].et << endl;
// 	}
// 	return 0;
// 	// binary_search() is also there
// 	cout<<lower_bound(arr, arr+6, 2) - arr;
// 	// upper_bound() finds the element just to the right
// 	cout<<endl;
// 	cout<<__gcd(10,6)<<endl;

// 	cout<<pow(2,5)<<endl; //cmath
// 	int x = 10;
// 	int y =12;
// 	swap(x,y); // utility
// }



// typedef long long ll;
// int main(){
// 	int n,m;
// 	cin>>n>>m;
// 	ll arr[n];
// 	for(int i=0; i<n;i++)
// 		cin>>arr[i];
// 	queue<ll> q;
// 	sort(arr,arr+n);
// 	int count_m = 0;
// 	int end_p = n-1;
	
// 	while(m--){
// 		int curr_n;
// 		cin>>curr_m;
// 		ll ans;
// 		for(;count_m<curr_m;count_m++)
// 			if(end_p > 0 && (q.empty || arr[end_p] >= q.front())){
// 				ans = arr[end_p];
// 				end_p --;
// 			}
// 			else{
// 				ans = q.front();
// 				q.pop();
// 			}
// 			q.push(ans/2);
// 		cout<<ans<<endl;
// 	}

// 	return 0;
// } 


