function [X, Y, W] = generateRegressionTestData(n, dX, dY, sigma, varargin)
% [Function]
%   Generate random data for regression test. W and X are uniformly
% distributed matrices(W: 0 ~ sigma, X: 0 ~ sigma*20), noise ~ N(0, sigma).
% [Input]
%   n           Size of dataset
%   dX          Dimension of input values
%   dY          Dimension of reponse values
%   sigma       Standard deviation of noise
% [Output]
%   X           Input values (n * dX)
%   Y           Reponse values (n * dY)
%   W           Linear transforamtion matrix (dX * dY), eg. Y = X * W + noise

if nargin < 4
    sigma = 1;
end
W = rand(dX, dY) * sigma;
X = rand(n, dX) * 20 * sigma;
Y = X * W + normrnd(0, sigma, n, dY);



