class Solution{
    public:
    
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    
    //return pivot element's index
    return (i + 1); 
} 

    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1) 
    {
        // Partition the array around last element and get
        // position of pivot element in sorted array
        int pos = partition(arr, l, r);
 
 
        /*
        element agar sahi jagah pe gir raha hai partition ke time to ye vaisa hi hoga jaise 
        sort karne ke baad ith element (i+1)th largest element hota hai
        
        ex: arr[]   =>  7 8 9 10
            index   =>  0 1 2 3
           
        second smallest element => 1st index element
        
        */ 
        
        
        
        // If position is same as k
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1) // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos - 1, k);
 
        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
 
    // If k is more than number of elements in array
    return INT_MAX;
        
    }
};
