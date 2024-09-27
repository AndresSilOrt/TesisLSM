%dymamic time warping
clc;
clear;

%Example [3x3]
%matriz1 = [1,2,3; 4,5,6; 7,8,9;]
%matriz2 = [7,8,9; 1,2,3; 4,5,6;]

matriz1 = []
matriz2 = []

ma1=double(matriz1);
ma2=double(matriz2);

[n1,m1]=size(ma1);
[n2,m2]=size(ma2);

matriz(1:m1,1:m2)=0;

j=m1;
suma=0;
for i=1:1:m1
    matriz(j,1)=suma+sqrt(sum((ma1(:,i)-ma2(:,1)).^2));
    suma=matriz(j,1);
    j=j-1;
end
suma=0;
for i=1:1:m2
    matriz(m1,i)=suma+sqrt(sum((ma1(:,1)-ma2(:,i)).^2));
    suma=matriz(m1,i);
end

dij(1:3)=0;
l=2;
for i=m1-1:-1:1
    for j=2:1:m2
        suma=sqrt(sum((ma1(:,l)-ma2(:,j)).^2));
        dij(1)=suma+2*matriz(i+1,j-1);
        dij(2)=suma+matriz(i+1,j);
        dij(3)=suma+matriz(i,j-1);
        matriz(i,j)=min(dij(:));
    end
    l=l+1;
end      

distancia=matriz/(m1+m2);
mati=uint8(distancia);
figure(1);subplot(2,1,1);imagesc(mati)
figure(2);subplot(2,1,2);plot(matriz1);hold on;plot(matriz2);