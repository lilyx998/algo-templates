// returns (0-indexed) [target]'th smallest number in arr 
private int quickSelect(int[] arr, int target){
  int l = 0, r = arr.length-1, pivot = -1; 
  while(pivot != target){
    pivot = partition(arr, l, r); 
    if(pivot < target)
      l = pivot+1; 
    else if(pivot > target)
      r = pivot-1;
  }
  return arr[pivot]; 
}

private int partition(int[] arr, int l, int r){
  swap(arr, l + (r-l)/2, r); 
  int pivot = l, target = arr[r]; 
  while(l < r){
    if(arr[l] < target)
      swap(arr, pivot++, l); 
    l++;
  }
  swap(arr, pivot, r); 
  return pivot; 
}

private void swap(int[] arr, int i, int j){
  if(i == j)
    return; 
  int temp = arr[i]; 
  arr[i] = arr[j]; 
  arr[j] = temp; 
}