clc
close all
t=1:9600;
xy=2+15*sin(2*pi*t/24);
noisy_xy=xy+8*rand(1,length(xy));
m=1;  
A=noisy_xy- xy;
B = zeros(1,9624);
B(1:24) = xy(1:24);
B(25:9624) = A(1:9600);
dlmwrite('/home/ravi/Downloads/output.txt',B);
dlmwrite('/home/ravi/Downloads/noisy.txt',noisy_xy);
n=25;
C = zeros(size(A));
while(n<=length(B))
for i = 1:24 
    C(1,m)=B(1,i)+B(1,n);
end
n=n+1;
m=m+1;
end
    

