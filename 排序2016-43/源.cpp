
#include <stdio.h>


/*

已知由n（n≥2）个正整数构成的集合A={ak|0≤k＜n}，将其划分为两个不相交的子集A1和A2，
元素个数分别是n1和n2，A1和A2中元素之和分别为S1和S2。
设计一个尽可能高效的划分算法，满足|n1-n2|最小且|S1-S2|最大。要求：
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C或C++语言描述算法，关键之处给出注释。
（3）说明你所设计算法的平均时间复杂度和空间复杂度。
*/

int setPartition(int a[], int n) {
	int pivotkey, low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2, i;
	int s1 = 0, s2 = 0;
	while (flag) {
		pivotkey = a[low];              //选择枢轴
		while (low < high) {             //基于枢轴对数据进行划分
			while (low < high && a[high] >= pivotkey)
			{
				--high;
			}
			if (low != high)
			{
				a[low] = a[high];
			}
			while (low < high && a[low] <= pivotkey)
			{
				++low;
			}
			if (low != high)
			{
				a[high] = a[low];
			}
		}  //end of while(low<high)
		a[low] = pivotkey;
		if (low == k - 1)              //如果枢轴是第n/2小元素，划分成功
		{
			flag = 0;
		}
		else {                     //是否继续划分
			if (low < k - 1) {
				low0 = ++low;
				high = high0;
			}
			else {
				high0 = --high;
				low = low0;
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		s1 += a[i];
	}
	for (i = k; i < n; i++) 
	{ 
		s2 += a[i]; 
	}
	return s2 - s1;
}


int setPartition11111(int a[], int n) {
	int pivotkey, low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2, i;
	int s1 = 0, s2 = 0;
	while (1) 
	{
		//这里打印排序过程
		for (int i = 0; i < n; i++)
		{  
			if (i == low)
			{
				printf("(%d) ", a[i]);
			}
			else
			{
				printf("%d ", a[i]);
			}
		}
		printf("\n");

		pivotkey = a[low];              //选择枢轴
		while (low < high) 
		{             
			//待排序第一位索引low,待排序最后一位索引high
			//基于枢轴对数据进行划分,防止索引在循环中自增自减到相遇碰撞需要每次判断low < high
			while (low < high && pivotkey <= a[high])//待排序的最后一位大于枢轴，则最后一位保持不变，待排序最后一位前移：下标自减
			{
				high--;
			}
			//待排序的最后一位小于枢轴，则待排序第一位赋值为较小值，待排序最后一位保存不变等待后续赋值
			a[low] = a[high];
			//从low开始判断待排序数据是否比枢轴小，小的就不管，待排序最小索引自增，直到数据大于枢轴的，将该数赋值给待排序的最后一个下标
			while (low < high && a[low] < pivotkey)
			{
				low++;
			}
			//到了这里，说明遇到数据大于枢轴的，将该数赋值给待排序的最后一个下标，至此，完成了一轮交换，开始下一轮
			if (low < high)
			{
			a[high] = a[low];

			}
		
			
		}  //end of while(low<high)
		a[low] = pivotkey;
		if (low == k - 1)              //如果枢轴是第n/2小元素，划分成功
		{
			break;
		}
		else {                     //继续划分
			if (low < k - 1) {			//枢轴在左侧，说明右边数据较多，还可以比较，则将完成排序的最小索引保存
										//还原待排序最大索引，再次排序比较
				low0 = ++low;
				high = high0;//还原
			}
			else {
				high0 = --high;		//枢轴在右侧，说明左边数据较多，还可以比较，则将完成排序的最大索引保存
				low = low0;//还原
			}
		}

		

	}
	for (i = 0; i < k; i++)
	{
		s1 += a[i];
	}
	for (i = k; i < n; i++)
	{
		s2 += a[i];
	}
	return s2 - s1;
}


int main()
{
	int testArray[] = { 8,5,2,89,4,45,46,3,4,49,65,48,45,65,15,123,1,46,187,24,18,6,56,26,122,2,6,3,1,5,4,89,34 };
	int result = setPartition11111(testArray, sizeof(testArray) / 4);
	printf("%d\n", result);
	//for (int i = 0; i < sizeof(testArray) / 4; i++)
	//{
	//	printf("%d", testArray[i]);
	//}
	//printf("\n");
}