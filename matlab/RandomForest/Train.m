%% Convert data into mat file
X = importdata('dataX.txt');
N = size(X, 1);
YY = importdata('dataY.txt');
dY = 9;
Y = zeros(N, 3, dY);
for i = 1 : 9
    Y(:, :, i) = YY(:, i * 3 - 2 : i * 3);
end
save data_train X Y

%% Load data
clear all
load data_train
feature = X;
N = size(X, 1);
M = size(X, 2);
cnt = size(Y, 3);
value = zeros(N, cnt);
for i = 1 : cnt
    [tmp, value(:, i)] = max(Y(:, :, i), [], 2);
end

%% Parameters
useNorm = 1;
usePCA = 1;
treenum = 400;
k = 5;

%% Normalization
if useNorm == 1
    meanX = mean(feature, 1);
    stdX = std(feature, 0, 1);
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
ind = cvpartition(N, 'Kfold', k);
error = zeros(k, 1);
for j = 1 : k
    t = ind.training(j);
    e = ind.test(j);
    baggers = NdTreeBagger(treenum, feature(t), value(t, :));
    YY = predictWithNdTreeBagger(baggers, feature(e));
    error(j) = calError(YY, value(e, :));
    error
end
mean(error)

%% Train with the whole data and save
baggers = NdTreeBagger(treenum, feature, value);
save model baggers usePCA meanX stdX pcaModel