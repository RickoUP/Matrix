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


	Row& operator[](int n) {return rows[n];}

	void out() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				std::cout << this->operator[](i)[j] << ' ';
			}std::cout << '\n';
		}
	}

	double det() {
		
		if (getSize() == 2) {
			return rows[0][0] * rows[1][1] -
				rows[1][0] * rows[0][1];
		}

		Matrix<double> mat_low(getSize() - 1);
		double res = 0;
		for (int row_iter = 0; row_iter < getSize(); row_iter++) {
			row_swap(0, row_iter);
			mat_low = addition();

			int sign = row_iter % 2 == 0 ? 1 : -1;
			res += sign * rows[0][0] * mat_low.det();

		}
		for (int iter = getSize() - 1; iter >= 0; iter--) {
			row_swap(0, iter);
		}
		return res;
	}

	Matrix<double>& addition() {
		Matrix<double> mat_low(getSize() - 1);

		for (int i = 1; i < getSize(); i++) {
			for (int j = 1; j < getSize(); j++) {
				mat_low[i - 1][j - 1] = rows[i][j];
			}
		}

		return mat_low;
	}

	Matrix<double> & inv() {

		int det_ = det();
		Matrix<double> inversed(getSize());
		Matrix<double> mat_low(getSize()-1);

		for (int colm_iter = 0; colm_iter < getSize(); colm_iter++) {
			colmn_swap(0, colm_iter);
			
			for (int row_iter = 0; row_iter < getSize(); row_iter++) {
				row_swap(0, row_iter);

				mat_low = addition();

				int sign = (row_iter + colm_iter) % 2 == 0 ? 1 : -1;
				double A = mat_low.det() / det_;
				if (A != 0) {
					A *= sign;
				}
				inversed[row_iter][colm_iter] = A;

			}
			for (int iter = getSize() - 1; iter >= 0; iter--) {
				row_swap(0, iter);
			}
		}

		for (int iter = getSize() - 1; iter >= 0; iter--) {
			colmn_swap(0, iter);
		}

		inversed.transpose();
		return inversed;
	}
	


	int getSize() {
		return size;
	}

	void transpose() {
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				std::swap(rows[i][j], rows[j][i]);
			}
		}
	}

	bool is_triangle(int widht) {

		for (int i = 0; i < size; i++) {
			for (int j = i+ widht; j < size; j++) {
				if (rows[j][i] != 0) {

					return false;
				}
			}
		}
		return true;
	}

	bool is_tape() {
		
		bool res = true;
		res &= is_triangle(2);
		transpose();
		res &= is_triangle(2);
		transpose();
		return res;
	}

	void row_swap(int fst, int nd) {
		for (int i = 0; i < getSize(); i++) {
			std::swap(rows[fst][i], rows[nd][i]);
		}
	}

	void colmn_swap(int fst, int nd) {
		for (int i = 0; i < getSize(); i++) {
			std::swap(rows[i][fst], rows[i][nd]);
		}
	}

	void restore(void(*swap)(int, int)) {
		for (int iter = getSize() - 1; iter >= 0; iter--) {
			swap(0, iter);
		}
	}

};


