clc;
clear variables;
close all;

M = 64;                     % Size of signal constellation
k = log2(M);

snr_db = 0:2:24;
snr_lin = 10.^(snr_db/10);
N0 = 1./(snr_lin);

f=imread('rec.bmp');
f=f>0;
b = f(:)';
if rem(length(b),6)~=0
    b = [b zeros(1,6-rem(length(b),6))];
end
dataInMatrix = reshape(b,[],6);

%% Using In-built
b1 = bi2de(dataInMatrix); 
y = qammod(b1,M,'bin');
scatterplot(y)
title('Scatter plot using In-built')
%----------------------------------------
% Generate Noise
N=length(b1);
gnoise = (randn(N,1) + 1j*randn(N,1));
% subplot(3,1,2)
% stem(gnoise)
% title('Noise')
y = y+gnoise*sqrt(N0(10)); % lower the value more destroted the image
y = round(y);
%-----------------------------------
b11 = qamdemod(y,M,'bin');
dataOutMatrix = de2bi(b11,k);
dataOut = logical(dataOutMatrix(:));
dataOut = dataOut(1:length(dataOut)-rem(length(dataOut),80));
im = reshape(dataOut,[],80);
imwrite(im,'rec0.bmp');

%% Made By Us
y1 = modulate_qam(dataInMatrix);
scatterplot(y1)
title('Scatter plot using function made by us')
y1 = y1+gnoise*sqrt(N0(8)); % lower the value more destroted the image
y1 = round(y1);
dataOutMatrix1=demodulate_qam(y1);
dataOut1 = logical(dataOutMatrix1(:));
dataOut1 = dataOut1(1:length(dataOut1)-rem(length(dataOut1),1962));
im1 = reshape(dataOut1,[],80);
imwrite(im1,'rec1.bmp');