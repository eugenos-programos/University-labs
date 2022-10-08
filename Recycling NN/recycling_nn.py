import random

def matrix_mult(first_m: list, second_m: list) -> list:
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

def transpose(matrix : list) -> list:
    n_rows = len(matrix)
    n_columns = len(matrix[0])
    transp_matrix = [[0] * n_rows for _ in range(n_columns)]
    for row_index in range(n_rows):
        for column_index in range(n_columns):
            transp_matrix[column_index][row_index] = matrix[row_index][column_index]
    return transp_matrix

def get_random_matrix(shape : tuple) -> list:
    if len(shape) != 2:
        raise ValueError("Matrix should be two-dimensional")
    matrix = [[random.random() for _ in range(shape[1])] for _ in range(shape[0])]
    return matrix

def get_shape(matrix : list) -> tuple:
    shape = (len(matrix), len(matrix[0]))
    return shape

class RecyclingNN():
    def __init__(self, input_neuron_n : int, compression_factor : int) -> None:
        self.compression_factor = compression_factor
        sec_layer_size = int(input_neuron_n / compression_factor)
        self.weights = {
            "W1" : get_random_matrix((input_neuron_n, sec_layer_size)),
            "W2" : get_random_matrix((sec_layer_size, input_neuron_n))
        }
        self.activation_function = lambda x: x

    def backprop(self):
        pass

    def forward(self, X):
        Z1 = matrix_mult(transpose(self.weights["W1"]), X)
        A1 = self.activation_function(Z1)
        Z2 = matrix_mult(transpose(self.weights["W2"]), A1)
        A2 = self.activation_function(Z2)
        return A2

model = RecyclingNN(100, 2)
print(get_shape(model.forward(get_random_matrix([100, 1]))))