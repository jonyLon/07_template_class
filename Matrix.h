#pragma once
#include <iostream>
using namespace std;





template<typename T = int>
class Matrix
{
public:
	Matrix() = default;
	Matrix(const T& value) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				arr[i][j] = value;
			}
		}
	};
	friend ostream& operator<<(ostream& out, const Matrix<T>& data) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				out << data.arr[i][j] << "\t";
			}
			out << "\n";
		}
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, const Matrix<T>& data) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				in >> data.arr[i][j];
			}
		}
		return in;
	}
	Matrix<T> operator+(const Matrix<T>& other) const {
		Matrix<T>tmp(*this);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				tmp.arr[i][j] += other.arr[i][j];
			}
		}
		return tmp;
	}
	bool operator ==(const Matrix<T>& other) const {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				if (arr[i][j] != other.arr[i][j]) return false;
			}
		}
		return true;
	}
	bool operator !=(const Matrix<T>& other) const {
		return !operator ==(other);
	}
	Matrix<T> operator+(const T& value) const {
		Matrix<T>tmp(*this);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				tmp.arr[i][j] += value;
			}
		}
		return tmp;
	}
	Matrix<T> operator-(const T& value) const {
		Matrix<T>tmp(*this);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				tmp.arr[i][j] -= value;
			}
		}
		return tmp;
	}
	void operator+=(const T& value) {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				arr[i][j] += value;
			}
		}
	}

	T max() const {
		T max = arr[0][0];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				if (max < arr[i][j]) {
					max = arr[i][j];
				}
			}
		}
		return max;
	}
	T min() const {
		T min = arr[0][0];
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				if (min > arr[i][j]) {
					min = arr[i][j];
				}
			}
		}
		return min;
	}
	T sum() const {
		T sum = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				sum += arr[i][j];
			}
		}
		return sum;
	}
	int* indexesOf(const T& value) const {
		int* res = new int[2];
		res[0] = -1;
		res[1] = -1;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				if (arr[i][j] == value) {
					res[0] = i;
					res[1] = j;
					return res;
				};
			}
		}
		return res;
	}
	bool find(const T& value) const {
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) {
				if (arr[i][j] == value) {
					return true;
				};
			}
		}
		return false;
	}

	T& operator()(const int& r, const int& c){
		return arr[r][c];
	}
private:
	const static int rows = 3, cols = 4;
	T arr[rows][cols];
};

