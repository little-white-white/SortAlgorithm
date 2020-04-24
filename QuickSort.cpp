/**********
快速排序
通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比
另一部分的关键字小，则可分别对这两部分记录继续进行排序，以达到整个序列有序。
************/

void quickSort(int left, int right, int* a)
{
	if(left >= right)
		return;
		
	int l = left;
	int r = right;
	int base = a[left];  //取最左边的数为基准数
	
	while (l < r)
	{
		while (a[r] >= base && l < r)
			r--;
		while (a[l] <= base && l < r)
			l++;
		if(l < r)
		{
			int val = a[r];
			a[r] = a[l];
			a[l] = val;
		}
	}
	//基准数归位
	a[left] = a[l];
	a[l] = base;
	
	quickSort(left, l - 1, a);//递归左边
	quickSort(l + 1, right, a);//递归右边
}









