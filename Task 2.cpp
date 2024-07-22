//#include<iostream>
//using namespace std;
//
//template <typename T>
//class Matrix
//{
//	T** ptr;
//	int rows, columns;
//
//public:
//	Matrix(int rows = 0, int cols = 0)
//	{
//		this->rows = rows;
//		this->columns = cols;
//		ptr = new T * [rows];
//		for (int i = 0; i < rows; i++)
//		{
//			ptr[i] = new T[cols];
//		}
//	}
//
//	Matrix(Matrix const& sample)
//	{
//		this->rows = sample.rows;
//		this->columns = sample.columns;
//		ptr = new T * [rows];
//		for (int i = 0; i < rows; i++)
//		{
//			ptr[i] = new T[columns];
//			for (int j = 0; j < columns; j++)
//			{
//				ptr[i][j] = sample.ptr[i][j];
//			}
//		}
//	}
//	void insertElement(T const& element, int rowNo, int colNo)
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < columns; j++)
//			{
//				if (i == rowNo && j == colNo)
//				{
//					ptr[i][j] = element;
//				}
//			}
//		}
//	}
//	Matrix<T> operator+(Matrix const& obj)
//	{
//		if (this->rows == obj.rows && this->columns == obj.columns)
//		{
//			Matrix<T> result(rows, columns);
//			for (int i = 0; i < rows; i++)
//			{
//				for (int j = 0; j < columns; j++)
//				{
//					result.ptr[i][j] = this->ptr[i][j] + obj.ptr[i][j];
//				}
//			}
//			return result;
//		}
//		else
//		{
//			cout << "Unequal row or col number\n";
//			return Matrix<T>();
//		}
//	}
//	void print()
//	{
//		cout << "\nData is\n";
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < columns; j++)
//			{
//				cout << ptr[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	void transpose()
//	{
//		cout << "\nTranspose data is\n";
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < columns; j++)
//			{
//				cout << ptr[j][i] << " ";
//			}
//			cout << endl;
//		}
//	}
//	~Matrix()
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			delete[] ptr[i];
//		}
//		delete[] ptr;
//	}
//};
//
//int main()
//{
//	Matrix<char> m1(2, 3);
//	m1.insertElement('c', 0, 0);
//	m1.insertElement('a', 0, 1);
//	m1.insertElement(' ', 0, 2);
//	m1.insertElement('h', 1, 0);
//	m1.insertElement('_ ', 1, 1);
//	m1.insertElement('i', 1, 2);
//	m1.transpose();
//	Matrix<int>m2(2, 3);
//	m2.insertElement(-1, 0, 0);
//	m2.insertElement(-1, 0, 1);
//	m2.insertElement(-1, 0, 2);
//	m2.insertElement(10, 1, 0);
//	m2.insertElement(5, 1, 1);
//	m2.insertElement(1, 1, 2);
//	m2.transpose();
//	Matrix<int>m3(m2);
//	Matrix<int>m4(m2 + m3);
//	m4.transpose();
//	m4.print();
//	return 0;
//}
