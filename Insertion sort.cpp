Insertion sort 
TC:o(n^2) SC:O(1)
class Solution {
  public:
    void insertionSort(vector<int>& a) {
        // code here
        int n=a.size();
        for(int i=1;i<n;i++){
            int j=i;
            while(j>0 && a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                j--;
            }
        }
        
    }
};
