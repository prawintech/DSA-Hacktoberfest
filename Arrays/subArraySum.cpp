#include <bits/stdc++.h>
using namespace std;
// 1.
// Prblem : Print largest subarray sum of a given array
// Brute force approach T(n) = O(n^3) 
// space Complexity is O(1)

int subArraySum_1(int *arr, int n){
    // largest Sum 
    int largestSum = 0; 
    for(int i = 0; i<n; i++){ 
        for(int j = i; j<n; j++){

            // Individual subarray sum 
            int subarraySum = 0;
            for(int k = i; k<=j; k++){
                subarraySum += arr[k];
            }
            // Put a check is subarraySum > largest sum 
            largestSum = max(subarraySum, largestSum);
        }
    }
    return largestSum;
}

// Finding out the larget sum of subarray
// Brute Force
int main(){

    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Max Sum: "<< subArraySum_1(arr, n);

    return 0;
}


// 2.
#include <bits/stdc++.h>
using namespace std;

// Problem : Print largest subarray sum of a given array
// Algotithm approach T(n) = Inner Loops O(n^2) + prefix loop:O(n) = O(n^2) 
// space Complexity is O(1)

int subArraySum_2(int *arr, int n){
    int prifix[n] = {0};
    prifix[0] = arr[0];
    for(int i = 1; i<n; i++){
        prifix[i] = prifix[i-1] + arr[i];
    }
    // largest Sum 
    int largestSum = 0; 
    for(int i = 0; i<n; i++){ 
        for(int j = i; j<n; j++){
            
            int subarraySum = i>0? prifix[j] - prifix[i-1] : prifix[j]; 
            // false condition : if i = 0 then 0 to J sum i.e exact = J // 0 1 2 5 6
            //         i=0     j=4 i.e sum = 6

            // Put a check is subarraySum > largest sum 
            largestSum = max(subarraySum, largestSum);
        }
    }
    return largestSum;
}

// Finding out the larget sum of subarray
int main(){

    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Max Sum: "<< subArraySum_2(arr, n);

    return 0;
}


// 3.
#include <bits/stdc++.h>
using namespace std;

// Problem : Print largest subarray sum of a given array
// Algotithm: Kadane's Algorithm [T(n) = O(n) Optimal Solution]
// Space Complexity is O(1)

int kadanes_algo(int *arr, int n){
  // initial current_sum and max sum
  int cur_sum = 0;
  int max_sum = 0; 
    for(int i = 0; i<n; i++){ 
        cur_sum += arr[i];
        if(cur_sum < 0){
            cur_sum = 0;
        }
        max_sum = max(cur_sum,max_sum);
    }
    return max_sum;
}


// apprach is
//          [-2, 3, 4, -1, 5, -12, 6, 1, 3, 2]
//                      at idx 3 (7+-1 = 6 >0) = 6
//                           at idx 6 (11+-12 = -1<0) = 0
// cs =      0  3   7   6  11  0   6   7  10  12
// ms =      0  3   7   7  11  11  11  11  11  12 = 12
// Finding out the larget sum of subarray
int main(){

    int arr[] = {-2,3,4,-1,5,-12,6,1,3};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Max Sum: "<< kadanes_algo(arr, n);

    return 0;
}