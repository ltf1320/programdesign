function baggers = NdRegTreeBagger(treenum, X, Y)
% [Function]
%   Create N dimension random regression forest with TREEBAGGER.
% [Input]
%   X               Input values (n * dX)
%   Y               Reponse values (n * dY)
%   treenum         Number of trees
% [Output]
%   baggers         Collection of regression trees as a cell array
dY = size(Y, 2);
baggers = cell(dY, 1);
for i = 1 : dY
    baggers{i} = TreeBagger(treenum, X, Y(:, i), 'method', 'regression');
end