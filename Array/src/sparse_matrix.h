#pragma once CYBER_DASH_SPARSE_MATRIX_H
#define CYBER_DASH_SPARSE_MATRIX_H

#include <iostream>
#include <cstdlib>//��������һϵ�к����ͺ꣬��ʵ�ֿ��Ŷӡ���ƽ̨�ĸ�Ч�Ҿ���׿Խ���ֵı�׼�� C++ ���롣
using namespace std;


//ϡ�������Ԫ��ṹ��
template<class T>
struct TriTuple {
	int row;
	int col;
	T value;

/*
* ��ֵ��������غ���
* tri_tuple ϵ��������Ԫ������
* return ��ǰ������
*/
TriTuple<T>& operator=(TriTuple<T>& tri_tuple) {
	row = tri_tuple.row;
	col = tri_tuple.col;
	value = tri_tuple.value;

	return *this;
}
};

//ϡ�����ģ����
template<class T>
class SparseMatrix {
public:
	//���캯��(����Ϊϡ��������Ԫ�ظ���)
	SparseMatrix(int max_size=100);

	//���ƹ��캯��(����Ϊϡ�����)
	SparseMatrix(SparseMatrix<T>& sparse_matrix);

	//��������
	virtual ~SparseMatrix() { delete[] sparse_matrix_array_; }

	//��ȡ����
	int Rows() { return this->rows_; }
	//��������
	void setRows(int rows) { return this->rows_ = rows; }

	//��ȡ����
	int Cols() { return this->cols_; }
	//��������
	void setCols(int cols) { this->cols_ = cols; }

	//��ȡԪ����
	int Terms() { return this->terms_; }
	//����Ԫ����
	void setTerms(int terms) { this->terms_ = terms; }

	//��ȡ���Ԫ����
	int maxTerms() { return this->max_terms_; }
	//�������Ԫ����
	void setmaxTerms(int maxTerms) { this->max_terms_ = maxTerms; }

	//��ȡԪ��
	bool getElement(int row,int col,T& value);
	//���(�滻)Ԫ��
	bool addorreplaceElement(int row,int col,T value);

	//��ȡԪ��������ʼ��ַ
	TriTuple<T>* SparseMatrixArray() { return this->sparse_matrix_array_; }

	//��ֵ���������
	SparseMatrix<T>& operator=(SparseMatrix<T>& sparse_matrix);

	//ת������
	SparseMatrix<T>* Transpose();
	//����ת������
	SparseMatrix<T>* FastTranspose();
private:
	int rows_;
	int cols_;
	int terms_;
	int max_terms_;
	TriTuple<T>* sparse_matrix_array_;
};