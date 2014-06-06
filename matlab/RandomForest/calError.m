function error = calError(YY, Y)
    error = length(find(YY ~= Y)) / (size(Y, 1) * size(Y, 2));
end