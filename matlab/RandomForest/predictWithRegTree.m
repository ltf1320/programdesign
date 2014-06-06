function [Y] = predictWithRegTree(tree, X)
% [Function]
%   Predict the response with a regression tree.
% [Input]
%   tree            Regression tree
%   X               Input values (n * dX)
% [Output]
%   Y               Reponse values (n * dY)

n = size(X, 1);
dY = tree.outd;
Y = zeros(n, dY);
for i = 1 : n
    j = 1;
    while tree.child(j, 1) ~= tree.child(j, 2)
        if X(i, tree.var(j)) < tree.cut(j)
            j = tree.child(j, 1);
        else
            j = tree.child(j, 2);
        end
    end
    Y(i, :) = tree.val(j, :);
end