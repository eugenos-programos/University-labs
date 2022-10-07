
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

print(matrix_mult([[2, 2], [2, 2]], [[2, 2], [2, 2]]))

class RecyclingNN():
    def 