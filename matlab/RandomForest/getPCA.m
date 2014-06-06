function [featPCA,pca_model,cut_id] = getPCA(featOri,cut_id)
%[featPCA,pca_model,cut_id] = getPCA(featOri,cut_id)
% pca_model: coeff(n*keep) and meanFeatOri

pca_model.meanFeatOri = double(mean(featOri,1));
assert(size(featOri,1)>=size(featOri,2));
%-----------------------------------------------
if size(featOri,2)>5000
    featOri = single(featOri);
end
[n,p] = size(featOri);
featOri = bsxfun(@minus,featOri,mean(featOri,1));
% parfor i = 1:size(featOri,1),featOri(i,:) = featOri(i,:) - pca_model.meanFeatOri; end;
[U,sigma,coeff] = svd(featOri,0);
clear featOri
sigma = diag(sigma);
score = bsxfun(@times,U,sigma');
clear U;
sigma = sigma ./ sqrt(n-1);
latent = sigma.^2;
clear sigma;
[~,maxind] = max(abs(coeff),[],1);
d = size(coeff,2);
colsign = sign(coeff(maxind + (0:p:(d-1)*p)));
clear maxind;
coeff = bsxfun(@times,coeff,colsign);
score = bsxfun(@times,score,colsign);
clear colsign;
% [coeff,score,latent] = princomp(featOri);

if nargin<2 || isempty(cut_id)
    cut_id = find(cumsum(latent)>sum(latent)*0.98,1);
end


pca_model.coeff = double(coeff(:,1:cut_id));
featPCA = double(score(:,1:cut_id));

end

