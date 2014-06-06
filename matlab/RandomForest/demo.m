% Y = X * W + noise
[X, Y, W] = generateRegressionTestData(1000, 1, 1, 4);

figure, plot(X, Y, '.')
XX = [0 : 0.1 : 100]';
treenum = 50;

% Use my random forest
tic
trees = getNdRandomForest(X, Y, treenum);
toc
tic
YY = predictWithForest(trees, XX);
toc

% Use the TreeBagger in MATLAB
tic
bagger = TreeBagger(treenum, X, Y, 'oobpred', 'on', 'method', 'regression');
toc
tic
YY2 = predict(bagger, XX);
toc

% Compare regression result with Treebagger
figure, plot(XX, [YY, YY2, XX * W])