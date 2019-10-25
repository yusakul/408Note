
#include <stdio.h>


/*

��֪��n��n��2�������������ɵļ���A={ak|0��k��n}�����仮��Ϊ�������ཻ���Ӽ�A1��A2��
Ԫ�ظ����ֱ���n1��n2��A1��A2��Ԫ��֮�ͷֱ�ΪS1��S2��
���һ�������ܸ�Ч�Ļ����㷨������|n1-n2|��С��|S1-S2|���Ҫ��
��1�������㷨�Ļ������˼�롣
��2���������˼�룬����C��C++���������㷨���ؼ�֮������ע�͡�
��3��˵����������㷨��ƽ��ʱ�临�ӶȺͿռ临�Ӷȡ�
*/

int setPartition(int a[], int n) {
	int pivotkey, low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2, i;
	int s1 = 0, s2 = 0;
	while (flag) {
		pivotkey = a[low];              //ѡ������
		while (low < high) {             //������������ݽ��л���
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
		if (low == k - 1)              //��������ǵ�n/2СԪ�أ����ֳɹ�
		{
			flag = 0;
		}
		else {                     //�Ƿ��������
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
		//�����ӡ�������
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

		pivotkey = a[low];              //ѡ������
		while (low < high) 
		{             
			//�������һλ����low,���������һλ����high
			//������������ݽ��л���,��ֹ������ѭ���������Լ���������ײ��Ҫÿ���ж�low < high
			while (low < high && pivotkey <= a[high])//����������һλ�������ᣬ�����һλ���ֲ��䣬���������һλǰ�ƣ��±��Լ�
			{
				high--;
			}
			//����������һλС�����ᣬ��������һλ��ֵΪ��Сֵ�����������һλ���治��ȴ�������ֵ
			a[low] = a[high];
			//��low��ʼ�жϴ����������Ƿ������С��С�ľͲ��ܣ���������С����������ֱ�����ݴ�������ģ���������ֵ������������һ���±�
			while (low < high && a[low] < pivotkey)
			{
				low++;
			}
			//�������˵���������ݴ�������ģ���������ֵ������������һ���±꣬���ˣ������һ�ֽ�������ʼ��һ��
			if (low < high)
			{
			a[high] = a[low];

			}
		
			
		}  //end of while(low<high)
		a[low] = pivotkey;
		if (low == k - 1)              //��������ǵ�n/2СԪ�أ����ֳɹ�
		{
			break;
		}
		else {                     //��������
			if (low < k - 1) {			//��������࣬˵���ұ����ݽ϶࣬�����ԱȽϣ�������������С��������
										//��ԭ����������������ٴ�����Ƚ�
				low0 = ++low;
				high = high0;//��ԭ
			}
			else {
				high0 = --high;		//�������Ҳ࣬˵��������ݽ϶࣬�����ԱȽϣ����������������������
				low = low0;//��ԭ
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