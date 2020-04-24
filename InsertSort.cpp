/********
插入排序
通过构建有序序列，对于未排序数据，在已排序序列中
从后向前扫描，找到相应位置并插入。
*********/

void InsertSort(int* a, int n){
	int preInd = 0;
	int val  = 0;
	
	for(int i = 0; i < n; i++){
		preInd = i-1;
		val = a[i];
		while (preInd >= 0 && val < a[preInd]){
			a[preInd + 1] = a[preInd];
			preInd--; 
		}
		a[preInd + 1] = val;
	}
} 

