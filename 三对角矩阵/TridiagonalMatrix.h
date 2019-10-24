#pragma once

#include <iostream>


using namespace std;

//压缩存储后，存储对称方阵时最多只需存储n*(n+1)/2个元素

#define GetTotalLen(n) 3 * n - 2                


//按行优先方式存放三对角矩阵，矩阵元素下标对应的一维数组的下标

#define GetIndexRow(i, j) 2 * i + j 


//按列优先方式存放三对角矩阵，矩阵元素下标对应的一维数组的下标

#define GetIndexCol(i, j) 2 * j + i



class TridiagonalMatrix
{
public:
	TridiagonalMatrix(int order);

	~TridiagonalMatrix();

public:
	void create();                      //创建矩阵

	void destroy();                     //销毁矩阵

	void transpos();                    //矩阵转置

	int get_order();                    //获取矩阵阶数

	int* compressed_storage_row();      //压缩存储特殊矩阵——三对角矩阵，按行优先方式存放

	int* compressed_storage_col();      //压缩存储特殊矩阵——三对角矩阵，按列优先方式存放

	bool is_tridiagonal();              //判断矩阵是否为三对角矩阵

public:
	friend ostream& operator<<(ostream& os, TridiagonalMatrix& m);    //输出矩阵

private:
	int _order;
	int** _matrix;
};