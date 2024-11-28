#pragma once
#include<iostream>
#include<fstream>

template<typename T>
class Matrix{
private:
	int size = 0;
	struct Row {
		T* row = nullptr;
		Row() {}
		Row(int size) {
			len = size;
			row = new T[size];
		}
		~Row() {
			delete[] row;
		}

		Row& operator=(Row& other) {
			if (this == &other) {
				return *this;
			}

			delete[] row;
			row = new T[other.len];
			for (int i = 0; i < len; i++) {
				row[i] = other[i];
			}
			return *this;
		}

		T& operator[](int n) { return row[n]; }

		int getSize() {
			return len;
		}
		
	private:
		int len = 0;
	};

	Row* rows = nullptr;

public:
	Matrix(int new_size) {
		size = new_size;

		rows = new Row[new_size];
		Row new_row(new_size);
		for (int i = 0; i < new_size; i++) {
			rows[i] = new_row;
		}
	}

	
	//Matrix& operator=(Matrix& other) {
		//delete[] rows;


		/*
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				//rows[i][j] = other[i][j];
			}
		}
		*/
		//return *this;
	//}
	 

	Row& operator[](int n) {return rows[n];}

	void out() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				std::cout << this->operator[](i)[j] << ' ';
			}std::cout << '\n';
		}
	}

	int det() {
		
		if (getSize() == 1) {
			return rows[0][0];
		
		}
		

		if (getSize() % 2 == 0) {
			Matrix low_mat(getSize()/2);
		
			for (int i = 0; i < getSize(); i += 2) {
				for (int j = 0; j < getSize(); j += 2) {
					low_mat[i/2][j/2] = rows[i][j] * rows[i + 1][j + 1] -
						rows[i+1][j] * rows[i][j + 1];

				}
			}
			return low_mat.det();
		}

		/*
		else {
			int res = 0;
			int sign = 1;
			for (int i = 1; i < getSize(); i++) {
				for (int j = 0; j < getSize(); j++) {
					res +=  ;

					sign *= -1;
				}
			}


		}
		*/
		
		

	}

	int getSize() {
		return size;
	}

};