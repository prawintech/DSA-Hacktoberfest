// A Simple Demonstration Of How We Can Sort An Array In C++
// Time Complexity => O(n^2)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array: "; 
    cin >> n;
    
    int a[n];
    
    cout << "\nEnter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << "\nArray Before Sorting: ";
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    
    for(int i=0; i < n; i++) {
        for(int j = i+1; j < n; j++) { 
            if(a[i]>a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    cout << "\nArray After Sorting: ";
   
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
