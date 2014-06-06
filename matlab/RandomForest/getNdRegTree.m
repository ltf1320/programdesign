function tree = getNdRegTree(X, Y, maxdepth, samplenum, minleaf, varargin)
% by Guo Hengkai, guohengkaighk@gmail.com
% [Function]
%   Create a regression tree as struct.
% [Input]
%   X               Input values (n * dX)
%   Y               Reponse values (n * dY)
%   samplenum       Column number to be used for regression
%   maxdepth        Maximum depth of regression tree
%   minleaf         Minimal number of observations per tree leaf
% [Output]
%   tree            Regression tree
%   tree.child      Children of node
%   tree.parent     Parent of node
%   tree.val        Response value of node
%   tree.var        Column to be split, or 0 for a leaf node
%   tree.cut        Cutoff point of node
%   tree.outd       Dimension of response

[n, dX] = size(X);
dY = size(Y, 2);
if nargin < 5
    minleaf = 5;
    if nargin < 4
        samplenum = ceil(dX / 3);
        if nargin < 3
            maxdepth = inf;
        end
    end
end

m = min(2 * ceil(n / minleaf) - 1, 2 ^ maxdepth);
child = zeros(m, 2);
var = zeros(m, 1);
cut = zeros(m, 1);
parent = zeros(m, 1);
depth = zeros(m, 1);
yfit = zeros(m, dY);
childidx = zeros(m, 1);

assignednode = cell(m, 1);
assignednode{1} = 1 : n;
depth(1) = 1;
tnode = 1;
nextnode = 2;
childcnt = 0;

while (tnode < nextnode)
    noderows = assignednode{tnode};
    Nt = length(noderows);
    Ynode = Y(noderows, :);
    yfit(tnode, :) = mean(Ynode);
    
    if (depth(tnode) < maxdepth) && (Nt >= 2 * minleaf)
        Xnode = X(noderows, :);
        if samplenum < dX
            varmap = randsample(dX, samplenum);
        else
            varmap = 1 : dX;
        end
        varmap = varmap(:)';
        
        [bestvar, bestcut] = mex_calOptimumCut(Xnode(:, varmap), Ynode, minleaf);
        
        % Split the node
        if bestvar ~= 0
			bestvar = varmap(bestvar); 
            x = Xnode(:, bestvar);
            var(tnode) = bestvar;
            left = x < bestcut;
            right = x >= bestcut;
            cut(tnode) = bestcut;
            child(tnode, :) = nextnode + (0 : 1);
            parent(nextnode + (0 : 1)) = tnode;
            depth(nextnode + (0 : 1)) = depth(tnode) + 1;
            
            assignednode{nextnode} = noderows(left);
            assignednode{nextnode + 1} = noderows(right);

            nextnode = nextnode + 2;
        end
    end
    if child(tnode, 1) == 0
        childcnt = childcnt + 1;
        childidx(tnode) = childcnt;
    end
    tnode = tnode + 1;
end

topnode = nextnode - 1;
tree.parent = parent(1 : topnode);
tree.var = var(1 : topnode);
tree.cut = cut(1 : topnode);
tree.child = child(1 : topnode, :);
tree.val = yfit(1 : topnode, :);
tree.childidx = childidx(1 : topnode);
tree.childcnt = childcnt;
tree.outd = dY;