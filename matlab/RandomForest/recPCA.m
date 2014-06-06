function featOri = recPCA(featPCA,pca_model)

featOri = repmat(pca_model.meanFeatOri,size(featPCA,1),1) + featPCA * pca_model.coeff';

end

