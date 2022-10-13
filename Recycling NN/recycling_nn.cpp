#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

class Matrix
{
    public:
        float ** matrix;
        int n_rows;
        int n_cols;
        int shape[2];
        void print_matrix();
        Matrix(int n_rows, int n_cols);
        static float** get_random_matrix(int n_rows, int n_cols);
        Matrix& operator * (const Matrix& other);
        Matrix& operator - (const Matrix& other);
        Matrix& operator * (const int& number);
        Matrix * T();
};

float ** Matrix::get_random_matrix(int n_rows, int n_cols)
{
    srand(time(0));
    float ** matrix = new float*[n_rows];
    for (int row_index = 0; row_index < n_rows; ++row_index)
    {
        matrix[row_index] = new float[n_cols];
        for (int col_index = 0; col_index < n_cols; ++col_index)
        {
            matrix[row_index][col_index] = rand() / 1e8;
        }
    }
    return matrix;
}

Matrix::Matrix(int n_rows, int n_cols)
{
    this->n_rows = n_rows;
    this->n_cols = n_cols;
    this->matrix = this->get_random_matrix(n_rows, n_cols);
    this->shape[0] = n_rows;
    this->shape[1] = n_cols;
}

void Matrix::print_matrix()
{
    for (int row_index = 0; row_index < this->n_rows; ++row_index)
    {
        for (int col_index = 0; col_index < this->n_cols; ++col_index)
        {
            std::cout << this->matrix[row_index][col_index] << " "; 
        }
        std::cout << '\n';
    }
}

Matrix& Matrix::operator*(const Matrix& other_m)
{
    Matrix * result_matrix = new Matrix(this->n_rows, other_m.n_cols);
    for (int first_m_row_index = 0; first_m_row_index < this->n_rows; ++first_m_row_index)
    {
        for (int second_m_col_index = 0; second_m_col_index < other_m.n_cols; ++second_m_col_index)
        {
            float sum_res = 0.;
            for (int first_m_col_index = 0; first_m_col_index < this->n_cols; ++first_m_col_index)
            {
                sum_res += this->matrix[first_m_row_index][first_m_col_index] * other_m.matrix[first_m_col_index][second_m_col_index];
            }
            result_matrix->matrix[first_m_row_index][second_m_col_index] = sum_res;
        }
    }
    return *result_matrix;
}

Matrix& Matrix::operator * (const int& number)
{
    Matrix * result_matrix = new Matrix(this->n_rows, this->n_cols);
    for (int row_index = 0; row_index < this->n_rows; ++row_index)
    {
        for (int col_index = 0; col_index < this->n_cols; ++col_index)
        {
            result_matrix->matrix[row_index][col_index] = this->matrix[row_index][col_index] * number*;
        }
    }
    return result_matrix;
}

Matrix& Matrix::operator-(const Matrix& other_m)
{
    Matrix * result_matrix = new Matrix(this->n_rows, this->n_cols);
    for (int row_index = 0; row_index < this->n_rows; ++row_index)
    {
        for (int col_index = 0; col_index < this->n_cols; ++col_index)
        {
            result_matrix->matrix[row_index][col_index] = this->matrix[row_index][col_index] - other_m.matrix[row_index][col_index];
        }
    }
    return result_matrix;
}


Matrix * Matrix::T()
{
    Matrix * result_matrix = new Matrix(this->n_cols, this->n_rows);
    for (int row_index = 0; row_index < this->n_rows; ++row_index)
    {
        for (int col_index = 0; col_index < this->n_cols; ++col_index)
        {
            result_matrix->matrix[col_index][row_index] = this->matrix[row_index][col_index];
        }
    }
    return result_matrix;
}


class RecyclingNN
{
    private:
        Matrix ** weights;
        int compress_coeff;
        int alpha;
        Matrix * relu(Matrix * X);
        Matrix * relu_der(Matrix * X);
    public:
        RecyclingNN(int img_size = 256, int compress_coeff = 16, float alpha = 1e-2);
        Matrix ** forward(Matrix * X, bool return_cache = false);
        void backprop(Matrix * X);
        float compute_cost(Matrix * X);
        Matrix * operator() (Matrix * X);
};

RecyclingNN::RecyclingNN(int img_size, int compress_coeff, float alpha)
{
    this->compress_coeff = compress_coeff;
    int first_layer_size = pow(img_size, 2) * 3;
    int sec_layer_size = pow(img_size / compress_coeff, 2) * 3;
    this->weights = new Matrix*[2];
    this->weights[0] = new Matrix(first_layer_size, sec_layer_size);
    this->weights[1] = new Matrix(sec_layer_size, first_layer_size);
    this->alpha = alpha;
}

Matrix * RecyclingNN::relu(Matrix * X)
{
    Matrix * res_matrix = new Matrix(X->n_rows, X->n_cols);
    for (int row_index = 0; row_index < X->n_rows; ++row_index)
    {
        for (int col_index = 0; col_index < X->n_cols; ++col_index)
        {
            res_matrix->matrix[row_index][col_index] = X->matrix[row_index][col_index] > 0 ? 1. : 0.;
        }
    }
    return res_matrix;
}


Matrix ** RecyclingNN::forward(Matrix * X, bool return_cache)
{
    Matrix * Z1 = &(*this->weights[0]->T() * *X);
    Matrix * A1 = this->relu(Z1);
    Matrix * Z2 = &(*this->weights[1]->T() * *A1);
    if (return_cache) 
    {
        Matrix ** result = new Matrix * [3];
        result[0] = Z2;
        result[1] = A1;
        result[2] = Z1;
        return result;
    }
    Matrix ** result = new Matrix * [1];
    result[0] = Z2;
    return result;
}

void RecyclingNN::backprop(Matrix * X)
{
    Matrix * W1 = this->weights[0];
    Matrix * W2 = this->weights[1];
    Matrix ** out = this->forward(X, true);
    Matrix * y_pred = out[0];
    Matrix * A1 = out[1];
    Matrix * Z1 = out[2];
    
    Matrix * dZ2 = y_pred - X;
    Matrix * dW2 = dZ2 * A1->T();
    Matrix * dZ1 = (W2 * dZ2) * this->relu_der(Z1);
    Matrix * dW1 = dZ1 * X->T();
    this->weights[0] = W1 - this->alpha * dW1->T();
    this->weights[1] = W2 - this->alpha * dW2->T();
}

Matrix * RecyclingNN::operator()(Matrix * X) 
{
    Matrix ** res = this->forward(X);
    return res[0];
}

int main(){
    Matrix * X = new Matrix(196608, 1);
    RecyclingNN * model_ = new RecyclingNN();
    Matrix * out = (*model_)(X);

    return 0;
}