function [J, grad] = costFunction(theta, X, y)
%COSTFUNCTION Compute cost and gradient for logistic regression
%   J = COSTFUNCTION(theta, X, y) computes the cost of using theta as the
%   parameter for logistic regression and the gradient of the cost
%   w.r.t. to the parameters.

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta
%
% Note: grad should have the same dimensions as theta
%


for iter = 1:m
	h_x = sigmoid(X(iter,:)*theta);
	J = J + (-y(iter) * log(h_x) - (1 - y(iter))*log(1 - h_x));


endfor

J = J / m;

for j = 1:size(theta)(1)
	for i = 1:m
		h_x = sigmoid(X(i,:)*theta);
		grad(j) = grad(j) + (h_x - y(i))*X(i,j);

	endfor
	grad(j) = grad(j) / m;
endfor



% =============================================================

end
