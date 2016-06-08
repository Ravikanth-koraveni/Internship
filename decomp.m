function M = decomp(z)
M = dunzip(z);
fileid = fopen('/home/ravi/Downloads/decompress.txt','w');
formatspec = '%f %f %f';
fprinf(fileid,formatspec,M);
