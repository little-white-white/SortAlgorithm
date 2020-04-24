/*******
归并排序
典型的分治法的。将已有序的子序列合并，得到完全有序的序列；
即先使每个子序列有序，再使子序列段间有序。
*******/

#include <iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high){
    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i = low, j = mid+1, k = 0; //mid+1为第2有序区第1个元素，j指向第1个元素
    int* tem p= new int[high - low + 1]; //temp数组暂存合并的有序序列
    if(!temp){ //内存分配失败
        cout << "error";
        return;
    }
    
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]) //较小的先存入temp中
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++]; 
    }
    while(i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = arr[i++];
    while(j <= high)//同上
        temp[k++] = arr[j++];
        
    for(i = low,k = 0; i <= high; i++,k++)//将排好序的存回arr中low到high这区间
		arr[i] = temp[k];
		
    delete []temp;//删除指针，由于指向的是数组，必须用delete []
}
 
void MergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low+high) / 2;
        
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high); 
    }
}
