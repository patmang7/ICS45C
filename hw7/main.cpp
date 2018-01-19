#include <iostream>
#include "Matrix.h"
using namespace std;

class IndexOutOfBoundsException{};

template
	<typename T>

void fillMatrix(Matrix <T>& m)
{
	int i,j;
	for(i=0;i<m.numRows();i++)
		m[i][0] = T();
	for(j=0;j<m.numCols();j++)
		m[0][j] = T();
	for(i=1;i<m.numRows();i++)
		for(j=1;j<m.numCols();j++)
		{
			m[i][j] = T(i*j);
		}
}

void generate_exception(Matrix<double>& m)
{
	for(int i = 0;i<m.numRows()+2;i++)
	{
		if(i>=m.numRows())
			throw IndexOutOfBoundsException();
	}
}

void test_double_matrix_exceptions()
{
	try
	{
		cout<<"Starting....\n";
		Matrix<double> M(8,10);
		fillMatrix(M);
		cout<<M;
		generate_exception(M);
	}
	catch(const IndexOutOfBoundsException& e)
	{
		cout<<"Index out of bounds."<<endl;
	}
	cout<<"Done\n";
}
template
	<typename T>
void mult_matrix(Matrix<T>& m)
{
	for(int i = 0;i<m.numRows();i++)
	{
		for(int p = 0;p<m.numCols();p++)
		{
			if(i >= m.numRows() or p >= m.numCols())
				throw IndexOutOfBoundsException();
			m[i][p] *= 5;
		}
	} 
}
		
void test_int_matrix()
{
	Matrix <int> m(10,5);
	fillMatrix(m);
	cout << m;
	cout<<"Multiplying matrix by 5..."<<endl;
	mult_matrix(m);
	cout << m;
}

void test_double_matrix()
{
	Matrix<double>M(8,10);
	fillMatrix(M);
	cout<<M;
	cout<<"Multiplying matrix by 5..."<<endl;
	mult_matrix(M);
	cout<<M;
}

int main()
{
	for(int i=0;i<3;i++)
	{
		test_int_matrix();
		test_double_matrix();
		test_double_matrix_exceptions();
	}
	return 0;
}	



