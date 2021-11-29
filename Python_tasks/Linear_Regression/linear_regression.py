from os import sep
from matplotlib import pyplot as plt
from typing import List
import numpy as np
from numpy.linalg import inv
from numpy import matmul


class Linear_regression:
    def __init__(self, X: List[List[float]], y: List[float],
                 learning_rate: float) -> None:
        self.X = [[1] + list(X[x_row_index]) for x_row_index in range(len(X))]
        self.features = [0 for elem_index in range(len(self.X[0]))]      
        self.y = y  
        self.learning_rate = learning_rate

    def calculate_hypothesis(self, X_values_list : List) -> float:
        if not len(self.features) == len(X_values_list):
            raise "Cannot calculate hypothesis value: X and theta lists must be same size."
        result_score = 0.0
        for elem_index in range(len(self.features)):
            result_score += self.features[elem_index] * X_values_list[elem_index]
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
        for train_index in range(1, len(self.X)):
            derivative_value += (
                self.calculate_hypothesis(self.X[train_index]) - self.y[train_index]) * self.X[train_index][x_index]
        return derivative_value / len(self.X)

    def gradient_descent(self,iter_number , show_graphics=False):
        cost_values = []
        for iteration in range(iter_number):
            tmp_feature_list = self.features
            for feature_index in range(len(tmp_feature_list)):
                tmp_feature_list[feature_index] -= self.learning_rate * self.calculate_cost_function_derivative(feature_index)
            self.features = tmp_feature_list
            cost_values.append(self.calculate_cost_function())
        if show_graphics: 
            plt.xlabel("iteration")
            plt.ylabel("Cost function value")
            plt.plot([iteration for iteration in range(iter_number)], cost_values)
            plt.show()

    def normal_equation(self):
        X_trans = [*zip(*(self.X))]
        result = inv(matmul(X_trans, self.X))
        result = matmul(result, X_trans)
        result = matmul(result, self.y)
        self.features = result


    def show_result(self) -> None:
        if not len(self.features) == 2:
            return
        x_values = [x_row[1] for x_row in self.X]
        plt.scatter(x_values, self.y, s=1)
        plt.xlabel("X value")
        plt.ylabel("Y predict value")
        min_x_value, max_x_value = min(x_values), max(x_values)
        plt.plot([min_x_value, max_x_value], [
            self.calculate_hypothesis([1, min_x_value]),
            self.calculate_hypothesis([1, max_x_value])
        ], 'r')
        plt.show()

    def fit(self, tp = 'grad', show_graphic = False) -> None:
        if not tp == 'grad' and not tp == 'normeq':
            raise "Uncorrect tp value"
        if tp == 'grad':
            self.gradient_descent(100, show_graphic)
        else:
            self.normal_equation()
        if show_graphic:
            self.show_result()

    def predict(self, X : List) -> float:
        return self.calculate_hypothesis(X)
        