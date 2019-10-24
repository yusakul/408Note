
#include "TridiagonalMatrix.h"


#include <math.h>


TridiagonalMatrix::TridiagonalMatrix(int order)
	: _order(order), _matrix(new int* [order])
{
	create();
}

TridiagonalMatrix::~TridiagonalMatrix()
{
	destroy();
}

void TridiagonalMatrix::create()
{
	for (int i = 0; i < _order; i++)
	{
		_matrix[i] = new int[_order];
		for (int j = 0; j < _order; j++)
		{
			if (abs(i - j) > 1)
			{
				_matrix[i][j] = 0;
			}
			else
			{
				_matrix[i][j] = 1;
			}
		}
	}
}

void TridiagonalMatrix::destroy()
{
	for (int i = 0; i < _order; i++)
	{
		delete[] _matrix[i];
	}
	delete[] _matrix;
	_matrix = NULL;
}

void TridiagonalMatrix::transpos()
{
	int temp = 0;
	for (int i = 0; i < _order; i++)
	{
		for (int j = 0; j < _order; j++)
		{
			temp = _matrix[i][j];
			_matrix[i][j] = _matrix[j][i];
			_matrix[j][i] = temp;
		}
	}
}


int TridiagonalMatrix::get_order()
{
	return _order;
}

int* TridiagonalMatrix::compressed_storage_row()
{
	int index = 0;
	int total_count = GetTotalLen(_order);
	int* a = new int[total_count];
	for (int i = 0; i < _order; i++)
	{
		for (int j = 0; j < _order; j++)
		{
			if (abs(i - j) <= 1)
			{
				index = GetIndexRow(i, j);
				a[index] = _matrix[i][j];
			}
		}
	}
	return a;
}

int* TridiagonalMatrix::compressed_storage_col()
{
	int index = 0;
	int total_count = GetTotalLen(_order);
	int* a = new int[total_count];
	for (int j = 0; j < _order; j++)
	{
		for (int i = 0; i < _order; i++)
		{
			if (abs(i - j) <= 1)
			{
				index = GetIndexCol(i, j);
				a[index] = _matrix[i][j];
			}
		}
	}
	return a;
}

bool TridiagonalMatrix::is_tridiagonal()
{
	for (int i = 0; i < _order; i++)
	{
		for (int j = 0; j < _order; j++)
		{
			if ((abs(i - j) > 1) && (_matrix[i][j] != 0))
			{
				return false;
			}
		}
	}
	return true;
}

ostream& operator<<(ostream& os, TridiagonalMatrix& m)
{
	os << "Èý¶Ô½Ç¾ØÕó£º" << endl;
	for (int i = 0; i < m._order; i++)
	{
		for (int j = 0; j < m._order; j++)
		{
			os << m._matrix[i][j] << " ";
		}
		os << endl;
	}
	return os;
}