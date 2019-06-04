%Fixed point Image transmission over Wired channel 64-QAM using Zedboard.
clc;
clear variables;
close all;

%% Read Image
f=imread('face.bmp');
%f=imread('camera.bmp');
f=f>0;
b = f(:)';
%% Zero Padding
if rem(length(b),6)~=0
    b = [b zeros(1,6-rem(length(b),6))];
end
dataInMatrix = reshape(b,[],6);

%% Generate Noise
snr_db = 0:2:24;
snr_lin = 10.^(snr_db/10);
N_noise = 1./(snr_lin);
N=length(dataInMatrix);
gnoise = (randn(N,1) + 1j*randn(N,1));


%% Modulation
y = zeros(N,length(N_noise));
y1 = modulate_qam(dataInMatrix);
scatterplot(y1)
title('Scatter Plot')

%% Demodulation
% Initialize all with y1
y = y+y1;
%
fileName = "rec";
err = zeros(1,length(N_noise));
for i = 1:length(N_noise)
    y(:,i) = y(:,i)+gnoise*sqrt(N_noise(i));
    y(:,i) = round(y(:,i));
    dataOutMatrix=demodulate_qam(y(:,i));
    dataOut = logical(dataOutMatrix(:));
    dataOut = dataOut(1:length(dataOut)-rem(length(dataOut),uint64(sqrt(length(dataOut)))));
    im = reshape(dataOut,[],uint64(sqrt(length(dataOut))));
    fileName = "rec";
    fileName = fileName + num2str(i) + ".bmp";
    imwrite(im,fileName);
    err(i) = mse(im(:),f(:));
    
end

figure
semilogy(err)
title('Error Graph')
