close all
fileid = fopen('/home/ravi/Documents/MATLAB/as-caida20071105.txt','r');
formatspec = '%f %f %f';
sizeA = [3 Inf];
A=fscanf(fileid,formatspec,sizeA);
fclose(fileid);
A=A';
prompt='Enter 1 to Compress 2 to Decompress';
x=input(prompt);
if x==1
B=dzip(A);
save('/home/ravi/Documents/MATLAB/sol1.mat','B');

elseif x==2
   C = dunzip(B);
   C=C';
    fileid = fopen('/home/ravi/Documents/MATLAB/decompress.txt','w');
formatspec = '%d %d %d\n';
fprintf(fileid,formatspec,C);
else
    disp('wrong Input');
end
    