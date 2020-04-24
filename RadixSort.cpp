/*********
基数排序
基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；
依次类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，
再按高优先级排序。最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。
**********/

//求数据的最大位数,决定排序次数
int maxbit(int data[], int n) {
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i){
        while(data[i] >= p){
            p *= 10;
            ++d;
        }
    }
    return d;
}

void RadixSort(int data[], int n) {
    int d = maxbit(data, n);
    int tmp[n];
    int count[10]; //计数器
    int i, j, k;
    int radix = 1;
    
    //进行d次排
    for(i = 1; i <= d; i++){    
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
            
        for(j = 0; j < n; j++){
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
            
        for(j = n - 1; j >= 0; j--){ //将所有桶中记录依次收集到tmp中
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];
            
        radix = radix * 10;
    }
}

