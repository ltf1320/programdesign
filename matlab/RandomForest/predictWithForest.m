function [Y] = predictWithForest(trees, X)
% by Guo Hengkai, guohengkaighk@gmail.com
% [Function]
%   Predict the response with a random forest.
% [Input]
%   trees           Collection of regression trees as a cell array
%   X               Input values (n * dX)
% [Output]
%   Y               Reponse values (n * dY)

treenum = length(trees);
n = size(X, 1);
dY = trees{1}.outd;
Y = zeros(n, dY);
for i = 1 : treenum
    Y = Y + predictWithRegTree(trees{i}, X);
end
Y = Y / treenum;