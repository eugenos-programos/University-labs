from os import linesep
from typing import List
from PIL.Image import linear_gradient
from matplotlib import scale
from numpy import linspace
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier, KNeighborsRegressor
from sklearn.model_selection import KFold, cross_val_score
from sklearn.preprocessing import scale
import matplotlib.pyplot as plt
from sklearn.datasets import load_boston

"""
Zhenya Samchuk 27.10.2021
Coursera "Introduction in machine learning" tasks.
"""

#first task

columns = [
    "Class",
    "Alcohol",
    "Malic acid",
    "Ash",
    "Alcalinity of ash",
    "Magnesium",
    "Total phenols",
    "Flavanoids",
    "Nonflavanoid phenols",
    "Proanthocyanins",
    "Color intensity",
    "Hue",
    "OD280/OD315 of diluted wines",
    "Proline",
]


data = pd.read_csv("wine.data", sep=',', index_col=False, names=columns)
classes = data["Class"]
signs = data.loc[:, data.columns != "Class"]


__cross_validator =  KFold(n_splits=5,shuffle=True,random_state=42)

def get_best_score(X: pd.DataFrame , Y: pd.Series, cv) -> List:
    score_list = []

    for k in range(1,51):
        __klassifier = KNeighborsClassifier(n_neighbors=k)
        tmp_score = cross_val_score(__klassifier, X.values, Y.values, cv=cv, scoring="accuracy").mean()
        score_list.append(tmp_score)
    return score_list

def get_best_score_with_scalling(X: pd.DataFrame, Y: pd.Series, cv) -> List:
    X = scale(X.values)
    score_list = []

    for k in range(1,51):
        __klassifier = KNeighborsClassifier(n_neighbors=k)
        tmp_score = cross_val_score(__klassifier, X, Y.values, scoring="accuracy", cv=cv).mean()
        score_list.append(tmp_score)
    return score_list

def draw_list(list) -> None:
    plt.plot([k for k in range(len(list))], list)
    plt.show()

draw_list(get_best_score(X=signs, Y=classes, cv=__cross_validator))
draw_list(get_best_score_with_scalling(X=signs, Y=classes, cv=__cross_validator))

#second_task

data = load_boston()
signs,target_values = data.data, data.target
signs = scale(signs)
cv = KFold(n_splits=5, shuffle=True, random_state=42)

def get_best_score_for_regression(X, y, cv):

    result_scores = []
    for p in linspace(1,10,200):
        __regressor = KNeighborsRegressor(n_neighbors=5, weights='distance')
        score = cross_val_score(__regressor, X, y, cv=cv, scoring='neg_mean_squared_error').mean()
        result_scores.append(score)
    return result_scores

draw_list(get_best_score_for_regression(signs, target_values, cv))
