function [Y, score] = predictWithNdRegTreeBagger(baggers, X)
% [Function]
%   Predict the response with random regression TREEBAGGERs.
% [Input]
%   baggers         Collection of regression trees as a cell array
%   X               Input values (n * dX)
% [Output]
%   Y               Reponse values (n * dY)
dY = length(baggers);
n = size(X, 1);
Y = zeros(n, dY);
for i = 1 : dY
	Y(:, i) = predict(baggers{i}, X);
end
[tmp, ind] = max(Y, [], 2);
Y = ind;