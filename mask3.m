clear all
close all
direc='FVC2002/Dbs/Db1_a/';
% for user=1:100
%     for iter=1:7
for user=1:100
    user
    for iter=1:8
	mask1=ones(374,388);
    	file=horzcat(direc,int2str(user),'_',int2str(iter),'.tif')
	im=imread(file);
	blksze = 8; thresh = 0.1;
	[normim, mask] = ridgesegment(im, blksze, thresh);
	mask1(365:374,1:388)=0;
	mask1(1:374,380:388)=0;
	st=strel('disk',14);
	mask=imerode(mask1.*mask,st);
	fid=fopen(horzcat('minutia/',int2str(user),'_',int2str(iter),'.xyt'),'r');
	C=textscan(fid,'%d %d %d %d');
	x=C{1};
	y=C{2};
	t=C{3};
	fop=fopen(horzcat('cleanedminutia/',int2str(user),'_',int2str(iter),'.xyt'),'w');
	for i=1:size(C{1},1)
		if(mask(y(i),x(i)))~=0
			fprintf(fop,'%d %d %d\n',x(i),y(i),t(i));
		end
	end
	fclose(fid);
	fclose(fop);
    end
end
