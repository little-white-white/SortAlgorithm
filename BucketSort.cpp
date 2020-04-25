/**********
桶排序
计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，
每个桶再分别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序）。
***********/

// 每个桶的容量 
int bucketSort(int* arr, int n, int bucketSize) {
   // 确定最大最小值
    int minVal = arr[0];
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
      	if (arr[i] < minVal) 
          	minVal = arr[i];                // 输入数据的最小值
     	 else if (arr[i] > maxVal)
          	maxVal = arr[i];                // 输入数据的最大值
    }
 
    // 桶的初始化
    int bucketCount = (maxVal - minVal) / bucketSize;       // 计算桶的个数 
    int* buckets = new int[n];	
    int* count = new int[bucketCount];		// 计数器 
    //初始化计数器 
    for (int i = 0; i < bucketCount; i++)		
        count[i] = 0;
    for (int i = 0; i < n; i++){		// 每个桶存放的数据个数 
    	int k = arr[i] / bucketSize;
		count[k]++; 
	}
	for (int i = 1; i < bucketCount; i++)		// 存放每个桶的结束点 
		count[i] = count[i-1] + count[i];
 
    // 将数据分配到各个桶中
    for (int i = 0; i < n; i++) {
        int k = arr[i] / bucketSize;
        buckets[count[k] - 1] = arr[i];
        count[k]--;
    }

	// 对每个桶进行排序
    for (int i = 0; i < bucketCount; i++) {
    	if(count[i] == count[i+1])     // 跳过空桶 
			continue;
		if(i == bucketCount - 1){     // 排序最后一个桶 ,结束循环 
			sort(buckets[count[i]], (n-1));
			break;
		}
			
        sort(buckets[count[i]], buckets[count[i+1]]);        //排序各个桶，参数为待排序序列的半闭区间             
    }
    
    // 把数据从桶中拿出来
	for (int i = 0; i < n; i++)
		arr[i] = buckets[i];
}
