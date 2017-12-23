// start and end mean the numerical order in the array.
//example : merge_sort(arr, reg, 0, len - 1);
void merge_sort(int arr[], int reg[],int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort(arr, reg, start1, end1);
    merge_sort(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    /* cal inverse number :
     while (start1 <= end1 && start2 <= end2)
     {
         if(arr[start1] > arr[start2])
             cnt1 += end1 - start1 + 1, reg[k++] = arr[start2++];
         else
             reg[k++] = arr[start1++];
     }
     */
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
