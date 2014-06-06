%% Convert data into mat file
X = importdata('dataX_test.txt');
N = size(X, 1);
M = size(X, 2);
feature = zeros(N * 9, M / 9 + 1);
for i = 1 : 9
    feature((i - 1) * N + 1 : i * N, 1 : 28) = X(:, (i - 1) * 28 + 1 : i * 28);
    feature((i - 1) * N + 1 : i * N, 29 : end - 1) = X(:, 28 * 9 + (i - 1) * 4 + 1 : 28 * 9 + i * 4);
    feature((i - 1) * N + 1 : i * N, end) = X(:, end);
end
X = feature;
save data_test X

%% Load model and data
clear all
load model2
load data_test
dY = 9;
N = size(X, 1);
X = (X - repmat(meanX, N, 1))./ repmat(stdX, N, 1);

%% PCA
if usePCA == 1
    X = usePCA2(X, pcaModel);
end

%% Predict with model
[Y, score] = predictWithNdRegTreeBagger(baggers, X);

%% Save
save('result.txt', 'score', '-ascii');