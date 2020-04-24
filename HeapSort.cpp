/*********
堆排序
利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，
并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。 
**********/
 
#include <algorithm>
using namespace std;

// 递推方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void Heap(int* arr, int len, int index)
{
    int left = 2*index + 1; 	// index的左子节点
    int right = 2*index + 2;	// index的右子节点
    int maxIdx = index;
    
    if(left < len && arr[left] > arr[maxIdx])     
		maxIdx = left;
    if(right < len && arr[right] > arr[maxIdx])    
		maxIdx = right;
 
    if(maxIdx != index){
        swap(arr[maxIdx], arr[index]);
        Heap(arr, len, maxIdx);
    }
 
}
 
// 堆排序
void heapSort(int* arr, int size)
{
    // 构建大根堆（从最后一个非叶子节点向上）
    for(int i = size/2 - 1; i >= 0; i--){
        Heap(arr, size, i);
    }
 
    // 调整大根堆
    for(int i = size - 1; i >= 1; i--){
        swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
        Heap(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
    }
}
