import random
from typing import Any


def get_random_matrix(shape : tuple) -> list:
    if len(shape) != 2:
        raise ValueError("Matrix should be two-dimensional")
    matrix = [[random.random() * 10 for _ in range(shape[1])] for _ in range(shape[0])]
    return matrix

class Matrix():
    def __init__(self, raw_matrix : list = None, shape : tuple = None, for_transp=False, *args: Any, **kwds: Any) -> None:
        if shape is not None:
            raw_matrix = get_random_matrix(shape)
        self.M = raw_matrix
        self.__n_rows__ = len(raw_matrix)
        self.__n_columns__ = len(raw_matrix[0])
        self.shape = (self.__n_rows__, self.__n_columns__)
        transp_matrix = [[0] * self.__n_rows__ for _ in range(self.__n_columns__)]
        for row_index in range(self.__n_rows__):
            for column_index in range(self.__n_columns__):
                transp_matrix[column_index][row_index] = self.M[row_index][column_index]
        if for_transp:
            self.T = None
        else:
            self.T = Matrix(transp_matrix, for_transp=True)

    def __mul__(self, second_matrix):
        first_m = self.M
        second_m = second_matrix.M
        result_m = list()
        for first_m_row in first_m:
            result_m_row = list()
            if len(first_m_row) != len(second_m):
                raise(ValueError(f"Incorrect matrix shapes - {self.shape} and {second_matrix.shape}"))
            for second_m_col_index in range(len(second_m[0])):
                sum_res = 0
                for el_index in range(len(first_m_row)):
                   sum_res += first_m_row[el_index] * second_m[el_index][second_m_col_index]
                result_m_row.append(sum_res)
            result_m.append(result_m_row)
        return Matrix(result_m)

    def __rmul__(self, number : float):
        res_row_matrix = get_random_matrix(self.shape)
        for row_index in range(self.shape[0]):
            res_row_matrix[row_index] = list(map(lambda el: el * number, self.M[row_index]))
        return Matrix(res_row_matrix) 

    def __sub__(self, sec_matrix):
        if self.shape != sec_matrix.shape:
            raise ValueError(f"Incorrect matrix shapes - {self.shape} and {sec_matrix.shape}")
        res_raw_matrix = get_random_matrix(self.shape)
        for row_index in range(self.shape[0]):
            for col_index in range(self.shape[1]):
                res_raw_matrix[row_index][col_index] = self.M[row_index][col_index] - sec_matrix.M[row_index][col_index]
        return Matrix(res_raw_matrix)

    def __str__(self) -> str:
        result = ""
        for row_index in range(self.shape[0]):
            result += str(self.M[row_index]) + '\n'
        return result

    def element_wise_mult(self, other_matrix):
        res_raw_matrix = get_random_matrix(self.shape)
        for row_index in range(self.shape[0]):
            for col_index in range(self.shape[1]):
                res_raw_matrix[row_index][col_index] = self.M[row_index][col_index] * other_matrix.M[0][col_index]
        return Matrix(res_raw_matrix)

    def sum(self) -> float:
        sum_res = 0.
        for row_index in range(self.shape[0]):
            sum_res += sum(self.M[row_index])
        return sum_res
    
class RecyclingNN():
    def __init__(self, input_neuron_n : int, compression_factor : int, alpha : float = .001, *args: Any, **kwds: Any) -> None:
        self.compression_factor = compression_factor
        sec_layer_size = int(input_neuron_n / compression_factor)
        self.weights = {
            "W1" : Matrix(shape=(input_neuron_n, sec_layer_size)), 
            "W2" : Matrix(shape=(sec_layer_size, input_neuron_n))
        }
        self.alpha = alpha
        self.activation_function = lambda x: self.__relu__(x)

    def __relu__(self, X : Matrix) -> Matrix:
        res_row_matrix = get_random_matrix(X.shape)
        for row_index in range(X.shape[0]):
            for col_index in range(X.shape[1]):
                input_ = X.M[row_index][col_index]
                res_row_matrix[row_index][col_index] = input_ if input_ >= 0. else 0.
        return Matrix(res_row_matrix)

    def __relu_der__(self, X : Matrix) -> Matrix:
        res_row_matrix = get_random_matrix(X.shape)
        for row_index in range(X.shape[0]):
            for col_index in range(X.shape[1]):
                res_row_matrix[row_index][col_index] = 1 if X.M[row_index][col_index] > 0 else 0
        return Matrix(res_row_matrix)

    def backprop(self, X, y, *args: Any, **kwds: Any):
        W1, W2 = self.weights.values()
        y_pred, A1, Z1 = self.forward(X, return_cache=True)
        dZ2 = y_pred - y    # (100, 1)
        dW2 = dZ2 * A1.T    # (100, 1) x (1, 50) = (100, 50)

        dZ1 = (W2 * dZ2).element_wise_mult(self.__relu_der__(Z1))   # (50, 100) @ (100, 1) = (50, 1)
        dW1 = dZ1 * X.T      # (50, 1) @ (1, 100) = (50, 100)
        W1_new = W1 - self.alpha * dW1.T
        W2_new = W2 - self.alpha * dW2.T
        self.weights['W1'] = W1_new
        self.weights['W2'] = W2_new

    def forward(self, X, return_cache=False, *args: Any, **kwds: Any):
        Z1 = self.weights["W1"].T * X
        A1 = self.activation_function(Z1)
        Z2 = self.weights["W2"].T * A1
        A2 = self.activation_function(Z2)
        if return_cache:
            return A2, A1, Z1
        return A2
    
    def compute_cost(self, X, func='MAE'):
        y_pred = self.forward(X)
        cost = y_pred - X
        return cost.sum()
 
    def __call__(self, X : list, *args: Any, **kwds: Any) -> Any:
        return self.forward(X)


model = RecyclingNN(100, 2)
X = Matrix(shape=(100, 1))
model.backprop(X, X)