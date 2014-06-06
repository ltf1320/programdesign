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
N = size(X, 1);
M = size(X, 2);
cnt = size(Y, 3);
feature = zeros(N * 9, M / 9 + 1);
for i = 1 : 9
    feature((i - 1) * N + 1 : i * N, 1 : 28) = X(:, (i - 1) * 28 + 1 : i * 28);
    feature((i - 1) * N + 1 : i * N, 29 : end - 1) = X(:, 28 * 9 + (i - 1) * 4 + 1 : 28 * 9 + i * 4);
    feature((i - 1) * N + 1 : i * N, end) = X(:, end);
end

value = zeros(N, cnt);
for i = 1 : cnt
    [tmp, value(:, i)] = max(Y(:, :, i), [], 2);
end
value = value(:);

N = N * 9;
M = M / 9 + 1;

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
    baggers = NdTreeBagger(treenum, feature(t, :), value(t, :));
    YY = predictWithNdTreeBagger(baggers, feature(e, :));
    error(j) = calError(YY, value(e, :));
    error
end
mean(error)

%% Train with the whole data and save
baggers = NdTreeBagger(treenum, feature, value);
save model2 baggers usePCA meanX stdX pcaModel error