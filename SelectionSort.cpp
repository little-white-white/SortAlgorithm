/***************
选择排序：
循环在未排序序列中找到最小元素，存放到已排序序列。 
****************/

void SelectionSort(int* a, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int minIndex = i;   //记录未排序序列最小元素下标
		 
		for (int j = i+1; j < len; j++)   //遍历未排序序列 
		{
			if (a[j] < a[minIndex])
				minIndex = j;
		}
		
		int val = a[i];
		a[i] = a[minIndex];
		a[minIndex] = val;
	}
} 

