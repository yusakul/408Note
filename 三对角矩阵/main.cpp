
#include "TridiagonalMatrix.h"


int main()
{
	int n = 0;
	cout << "���������ԽǾ���Ľ�����n = ";
	cin >> n;

	TridiagonalMatrix matrix(n);
	if (true == matrix.is_tridiagonal())
	{
		cout << "$ ������ԽǾ���" << endl;
		cout << matrix;//��operator<<(cout, matrix);
	}

	matrix.transpos();
	if (true == matrix.is_tridiagonal())
	{
		cout << "$ ���ת�ú�����ԽǾ���" << endl;
		cout << matrix;//��operator<<(cout, matrix);
	}

	cout << "\n$ ���ѹ���洢���һά����(�������ȷ�ʽ���)��" << endl;
	int* arrayr = matrix.compressed_storage_row();
	for (int i = 0; i < GetTotalLen(matrix.get_order()); i++)
	{
		cout << arrayr[i] << " ";
	}
	cout << endl;
	delete[] arrayr;

	cout << "\n$ ���ѹ���洢���һά����(�������ȷ�ʽ���)��" << endl;
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