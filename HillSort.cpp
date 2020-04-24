/******
希尔排序
简单插入排序的改进版。它与插入排序的不同之处在于，
它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
*******/

void HillSort(int* a, int n){
	for(int gap = n/2; gap > 0; gap = n/2){
		for(int i = gap; i < n; i++){
			int j = i;
			int val = a[i];
			
			while(j-gap >= 0 && val < a[j-gap]){
				a[j] = a[j-gap];
				j = j - gap;
			}
			a[j] = val;
		}
	}
}
