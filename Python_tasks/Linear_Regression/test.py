from matplotlib.markers import MarkerStyle
from linear_regression import Linear_regression
from sklearn import datasets
from matplotlib import pyplot as plt

if (__name__ == '__main__'):
    X_training, y_training = datasets.make_regression(n_samples=1000,
                                                      n_features=1,
                                                      noise=5)
    #first case
    linregr = Linear_regression(X = X_training, y =  y_training, learning_rate = 0.1)
    linregr.fit(show_graphic = True)

