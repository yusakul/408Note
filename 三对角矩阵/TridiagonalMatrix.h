#pragma once

#include <iostream>


using namespace std;

//ѹ���洢�󣬴洢�ԳƷ���ʱ���ֻ��洢n*(n+1)/2��Ԫ��

#define GetTotalLen(n) 3 * n - 2                


//�������ȷ�ʽ������ԽǾ��󣬾���Ԫ���±��Ӧ��һά������±�

#define GetIndexRow(i, j) 2 * i + j 


//�������ȷ�ʽ������ԽǾ��󣬾���Ԫ���±��Ӧ��һά������±�

#define GetIndexCol(i, j) 2 * j + i



class TridiagonalMatrix
{
public:
	TridiagonalMatrix(int order);

	~TridiagonalMatrix();

public:
	void create();                      //��������

	void destroy();                     //���پ���

	void transpos();                    //����ת��

	int get_order();                    //��ȡ�������

	int* compressed_storage_row();      //ѹ���洢������󡪡����ԽǾ��󣬰������ȷ�ʽ���

	int* compressed_storage_col();      //ѹ���洢������󡪡����ԽǾ��󣬰������ȷ�ʽ���

	bool is_tridiagonal();              //�жϾ����Ƿ�Ϊ���ԽǾ���

public:
	friend ostream& operator<<(ostream& os, TridiagonalMatrix& m);    //�������

private:
	int _order;
	int** _matrix;
};