function [Y, score] = predictWithNdTreeBagger(baggers, X)
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
score = zeros(n, 3, dY);
for i = 1 : dY
	[tmp, tmps] = predict(baggers{i}, X);
    score(:, :, i) = tmps;
    Y(:, i) = cell2mat(tmp) - 48;
end