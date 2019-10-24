
#include "TridiagonalMatrix.h"


int main()
{
	int n = 0;
	cout << "请输入三对角矩阵的阶数，n = ";
	cin >> n;

	TridiagonalMatrix matrix(n);
	if (true == matrix.is_tridiagonal())
	{
		cout << "$ 输出三对角矩阵：" << endl;
		cout << matrix;//或operator<<(cout, matrix);
	}

	matrix.transpos();
	if (true == matrix.is_tridiagonal())
	{
		cout << "$ 输出转置后的三对角矩阵：" << endl;
		cout << matrix;//或operator<<(cout, matrix);
	}

	cout << "\n$ 输出压缩存储后的一维数组(按行优先方式存放)：" << endl;
	int* arrayr = matrix.compressed_storage_row();
	for (int i = 0; i < GetTotalLen(matrix.get_order()); i++)
	{
		cout << arrayr[i] << " ";
	}
	cout << endl;
	delete[] arrayr;

	cout << "\n$ 输出压缩存储后的一维数组(按列优先方式存放)：" << endl;
	int* arrayc = matrix.compressed_storage_col();
	for (int i = 0; i < GetTotalLen(matrix.get_order()); i++)
	{
		cout << arrayc[i] << " ";
	}
	cout << endl;
	delete[] arrayc;

	system("pause");
	return 0;
}