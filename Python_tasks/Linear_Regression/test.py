from linear_regression import Linear_regression 
from sklearn import datasets
from matplotlib import pyplot as plt

if (__name__ == '__main__'):
    X_training, y_training = datasets.make_regression(n_samples=15, n_features=20, effective_rank=2, noise=1)
    print(f"len x - {len(X_training)} ,  len y - {len(y_training)}")
    for i in range(len(X_training)):
        plt.scatter(X_training[i], y_training[i])
    plt.show()
    #linregr = Linear_regression(X_training, y_training,
     #                           0.1)
    #linregr.gradient_descent()
    #linregr.show_result()
