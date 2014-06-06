function featPCA = usePCA2(featOriginal,pca_model)

featPCA = (featOriginal - repmat(pca_model.meanFeatOri,size(featOriginal,1),1))...
    * pca_model.coeff;

end

