import random
from typing import Any


def get_random_matrix(shape : tuple) -> list:
    if len(shape) != 2:
        raise ValueError("Matrix should be two-dimensional")
    matrix = [[random.random() for _ in range(shape[1])] for _ in range(shape[0])]
    return matrix

class Matrix():
    def __init__(self, raw_matrix : list, *args: Any, **kwds: Any) -> None:
        self.__matrix__ = raw_matrix
        self.__n_rows__ = len(raw_matrix)
        self.__n_columns__ = len(raw_matrix[0])
        self.shape = (self.__n_rows__, self.__n_columns__)
        transp_matrix = [[0] * self.__n_rows__ for _ in range(self.__n_columns__)]
        for row_index in range(self.__n_rows__):
            for column_index in range(self.__n_columns__):
                transp_matrix[column_index][row_index] = self.__matrix__[row_index][column_index]
        self.T = transp_matrix

    def __mul__(self, second_matrix):
        first_m = self.__matrix__
        second_m = second_matrix.M
        result_m = list()
        for first_m_row in first_m:
            result_m_row = list()
            if len(first_m_row) != len(second_m):
                raise(ValueError("Incorrect matrix shapes"))
            for second_m_col_index in range(len(second_m[0])):
                sum_res = 0
                for el_index in range(len(first_m_row)):
                   sum_res += first_m_row[el_index] * second_m[el_index][second_m_col_index]
                result_m_row.append(sum_res)
            result_m.append(result_m_row)
        return result_m

    
class RecyclingNN():
    def __init__(self, input_neuron_n : int, compression_factor : int, *args: Any, **kwds: Any) -> None:
        self.compression_factor = compression_factor
        sec_layer_size = int(input_neuron_n / compression_factor)
        self.weights = {
            "W1" : get_random_matrix((input_neuron_n, sec_layer_size)),
            "W2" : get_random_matrix((sec_layer_size, input_neuron_n))
        }
        self.activation_function = lambda x: x

    def backprop(self, *args: Any, **kwds: Any):
        W1, W2 = self.weights.values()
        print(W1.si, W2)

    def forward(self, X, *args: Any, **kwds: Any):
        Z1 = matrix_mult(transpose(self.weights["W1"]), X)
        A1 = self.activation_function(Z1)
        Z2 = matrix_mult(transpose(self.weights["W2"]), A1)
        A2 = self.activation_function(Z2)
        return A2

    def __call__(self, X : list, *args: Any, **kwds: Any) -> Any:
        return self.forward(X)


model = RecyclingNN(100, 2)
model.backprop()