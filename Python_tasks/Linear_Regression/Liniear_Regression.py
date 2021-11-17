import random
from matplotlib import pyplot as plt
from typing import List


class Linear_regression:
    def __init__(self, X: List[List[float]], y: List[float],
                 learning_rate: float) -> None:
        self.features = [0 for elem_index in range(len(X[0]))]
        self.X = X
        self.y = y
        self.learning_rate = learning_rate

    def calculate_hypothesis(self, x_elements: List[float]) -> float:
        result_score = 0.0
        for elem_index in range(len(self.features)):
            result_score += self.features[elem_index] * x_elements[elem_index]
        return result_score

    def calculate_cost_function(self) -> float:
        cost_func_value = 0.0
        for train_index in range(len(self.X)):
            cost_func_value += (
                self.calculate_hypothesis(self.X[train_index]) -
                self.y[train_index])**2
        return cost_func_value / (2 * len(self.X))

    def calculate_cost_function_derivative(self, x_index: int) -> float:
        derivative_value = 0.0
        for train_index in range(len(self.X)):
            derivative_value += (
                self.calculate_hypothesis(self.X[train_index]) - self.y[train_index]) * self.X[train_index][x_index]
        return derivative_value / len(self.X)

    def gradient_descent(self, show_graphics=False):
        cost_values = []
        for iter in range(300):
            tmp_feauters_list = self.features
            for feature_index in range(len(tmp_feauters_list)):
                tmp_feauters_list[feature_index] -= self.learning_rate * self.calculate_cost_function_derivative(feature_index)
            self.features = tmp_feauters_list
            cost_values.append(self.calculate_cost_function())
        if show_graphics:
            plt.plot([iter for iter in range(300)], cost_values)
            plt.show()

    def show_result(self):
        if not len(self.features) == 2:
            return
        plt.scatter([x_row[1] for x_row in self.X], self.y)
        plt.plot([1, 5], [
            self.calculate_hypothesis([1, 1]),
            self.calculate_hypothesis([1, 5])
        ])
        plt.show()
