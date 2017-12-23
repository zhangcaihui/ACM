void swap_(int arr[], int x, int y){
    int tem = arr[x];
    arr[x] = arr[y];
    arr[y] = tem;
}
// note : start and end mean the numerical order in the array.
void quick_sort(int arr[], int start, int end) {
    if (start >= end)
        return;
    int x = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < x && left < right)
            left++;
        while (arr[right] >= x && left < right)
            right--;
        swap_(arr, left, right);
    }
    if (arr[left] >= arr[end])
        swap_(arr, left, end);
    else
        left++;
    if(left)
        quick_sort(arr, start, left - 1);
    quick_sort(arr, left + 1, end);
}

