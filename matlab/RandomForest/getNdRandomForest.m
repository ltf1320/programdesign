function trees = getNdRandomForest(X, Y, treenum, maxdepth, samplenum, minleaf, fboot, varargin)
% by Guo Hengkai, guohengkaighk@gmail.com
% [Function]
%   Create random forest.
% [Input]
%   X               Input values (n * dX)
%   Y               Reponse values (n * dY)
%   treenum         Number of trees
%   samplenum       Column number to be used for regression
%   maxdepth        Maximum depth of regression tree
%   minleaf         Minimal number of observations per tree leaf
%   fboot           Fraction of data for regression
% [Output]
%   trees           Collection of regression trees as a cell array

[n, dX] = size(X);
if nargin < 7
    fboot = 1;
    if nargin < 6
        minleaf = 5;
        if nargin < 5
            samplenum = ceil(dX / 3);
            if nargin < 4
                maxdepth = inf;
            end
        end
    end
end

trees = cell(treenum, 1);

parfor i = 1 : treenum
    idx = datasample((1 : n)', ceil(n * fboot)); % Sample with replacement
    trees{i} = getNdRegTree(X(idx, :), Y(idx, :), maxdepth, samplenum, minleaf);
end
