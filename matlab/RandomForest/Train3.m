%% Load data
clear all
load data_train
N = size(X, 1);
M = size(X, 2);
cnt = size(Y, 3);
feature = zeros(N * 9, M / 9);
for i = 1 : 9
    feature((i - 1) * N + 1 : i * N, 1 : 28) = X(:, (i - 1) * 28 + 1 : i * 28);
    feature((i - 1) * N + 1 : i * N, 29 : end) = X(:, 28 * 9 + (i - 1) * 4 + 1 : 28 * 9 + i * 4);
end

value = zeros(N * cnt, 3);
for i = 1 : cnt
    value((i - 1) * N + 1 : i * N, :) = Y(:, :, i);
end
[tmp, ind] = max(value, [], 2);
N = N * 9;
M = M / 9;

%% Parameters
useNorm = 1;
usePCA = 1;
treenum = 300;
k = 5;

%% Normalization
if useNorm == 1
    %meanX = mean(feature, 1);
    %stdX = std(feature, 0, 1);
    meanX = min(feature, [], 1);
    stdX = max(feature, [], 1) - meanX;
    feature = (feature - repmat(meanX, N, 1))./ repmat(stdX, N, 1);
else
    meanX = zeros(1, M);
    stdX = ones(1, M);
end

%% PCA
if usePCA == 1
    [feature, pcaModel] = getPCA(feature);
else
    pcaModel = 0;
end

%% Training and testing with K-fold
for j = 1 : 9
    tmp = [1 : N]';
    t = (tmp <= j * (N / 9)) & (tmp > (j - 1) * (N / 9));
    e = ~t;
    baggers = NdRegTreeBagger(treenum, feature(t), value(t, :));
    YY = predictWithNdRegTreeBagger(baggers, feature(e));
    error(j) = calError(YY, ind(e, :));
    error
end
mean(error)

%% Train with the whole data and save
baggers = NdRegTreeBagger(treenum, feature, value);
save model3 baggers usePCA meanX stdX pcaModel error