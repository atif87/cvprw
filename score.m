
for testuser=1:100
	testuser
	for testiter=7:8
		for trainuser=1:100
			for trainiter=1:6
				command = horzcat('bozorth3 -m1 -p minutia/',int2str(testuser),'_',int2str(testiter),'.xyt ','minutia/',int2str(trainuser),'_',int2str(trainiter),'.xyt >> dataset/score.txt');
				system(command);
			end
		end
	end
end
