//#include<iostream>
//using namespace std;
//int** AllocateMemory(int rows, int cols)
//{
//	int** matrix = new int* [rows];
//	for (int i = 0;i < rows;i++)
//	{
//		matrix[i] = new int[cols];
//	}
//	return matrix;
//}
//void DisplayMatrix(int** matrix, int rows, int cols)
//{
//	cout << "The data in matrix is\n";
//	for (int i = 0;i < rows;i++)
//	{
//		for (int j = 0;j < cols;j++)
//		{
//			cout << matrix[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//void InputMatrix(int** matrix, int rows, int cols)
//{
//	cout << "Getting input\n";
//	for (int i = 0;i < rows;i++)
//	{
//		for (int j = 0;j < cols;j++)
//		{
//			cin >> matrix[i][j];
//
//		}
//		cout << endl;
//	}
//}
//int* MaxMatrix(int** matrix, int  rows, int cols)
//{
//	int max = 0;
//	int* max1 = new int[cols];
//	int a = 0;
//	for (int i = 0;i < cols;i++)
//	{
//		max = matrix[0][i];
//		for (int j = 1;j < rows;j++)
//		{
//			if (matrix[j][i] > max)
//			{
//				max = matrix[j][i];
//			}
//		}
//		max1[a++] = max;
//		max = 0;
//		cout << endl;
//	}
//	cout << "Maximum is\n";
//	for (int i = 0;i < cols;i++)
//	{
//		cout << max1[i] << " ";
//	}
//	return max1;
//}
//void de_allocatingMatrix(int** matrix, int rows, int cols)
//{
//	for (int i = 0;i < rows;i++)
//	{
//		for (int j = 0;j < cols;j++)
//		{
//			delete[] matrix[i];
//
//		}
//delete[]matrix;
//		cout << endl;
//	}
//}
//int main()
//{
//	int rows = 2, cols = 2;
//	int** matrix = AllocateMemory(rows, cols);
//	DisplayMatrix(matrix, rows, cols);
//	InputMatrix(matrix, rows, cols);
//	DisplayMatrix(matrix, rows, cols);
//	int* array = MaxMatrix(matrix, rows, cols);
//}