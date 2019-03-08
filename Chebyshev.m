
n=16
xi=zeros(1,n+1);
pi=3.1415926;
for i=1:n+1,
    xi(i)=cos((2*(i-1)+1)/(2*(n+1))*pi);
end
Y=ones(1,length(x));
for i=1:n+1
    Y=Y.*(x-xi(i));
end
Y=abs(Y);
1/(2^n)
Ym=max(Y)
Ym;
figure(5);
plot([-1,1],[1/(2^n),1/(2^n)]);
hold on;
plot(x,Y);
hold on;
