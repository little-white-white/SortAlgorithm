/***************
冒泡排序：
重复的走访要排序的队列，一次比较两个元素，如果顺序错误就交换。 
****************/ 

void bubbleSort(int* a, int len)    //len是数组大小 
{
	for (int i = 0; i < len-1 ; i++)    //遍历循环n-1次 
	{
		for (int j = 0; j < len-1-i; j++)  //两两比较 
		{
			if (a[j] > a[j+1])
			{
				int val = a[j];
				a[j] = a[j+1];
				a[j+1] = val;
			}
		}
	}
}

