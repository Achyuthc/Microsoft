/*Binary search is a search algorithm usually used on a sorted sequence to quickly find an element with a given value. In this problem we will evaluate how binary search performs on data that isn't necessarily sorted. An element is said to be binary searchable if, regardless of how the pivot is chosen the algorithm returns true.
For example:

[2, 1, 3, 4, 6, 5] and target = 5, we cannot find 5. Because when the pivot is 4, we get element 6, then right pointer will move left, so we'll lose the opportunity to find target 5.
[2, 1, 3, 4, 5, 6] and target = 5, we can find 5. Because wherever we choose the pivots, we'll find target at last.
Given an unsorted array of n distinct integers, return the number of elements that are binary searchable.*/
https://practice.geeksforgeeks.org/problems/binary-searchable-elements/1?page=7&difficulty[]=1&status[]=unsolved&company[]=Microsoft&sortBy=submissions

class Solution {
  public:
    int binarySearchable(int arr[], int n) {
        // code here
        vector<int> right(n,0);
        right.push_back(INT_MAX);
        for(int i=n-1;i>=0;i--)
        {
            right[i]=min(right[i+1],arr[i]);
        }
        int maxi=INT_MIN;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>right[i+1]||arr[i]<maxi)
            {
                ans++;
            }
            maxi=max(maxi,arr[i]);
        }
        return n-ans;
    }
};
