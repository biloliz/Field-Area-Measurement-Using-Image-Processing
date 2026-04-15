🌾 Field Area Measurement Using Image Processing

clc;
clear;
close all;

%% Step 1: Load Image
img = imread('field.jpg');
figure;
imshow(img);
title('Original Image');

%% Step 2: Convert to Grayscale
gray = rgb2gray(img);
figure;
imshow(gray);
title('Grayscale Image');

%% Step 3: Edge Detection (Boundary Extraction)
edges = edge(gray, 'Canny');
figure;
imshow(edges);
title('Detected Edges');

%% Step 4: Fill Field Region
filled = imfill(edges, 'holes');
figure;
imshow(filled);
title('Filled Field Region');

%% Step 5: Remove Noise
cleaned = bwareaopen(filled, 500);
figure;
imshow(cleaned);
title('Cleaned Field Mask');

%% Step 6: Pixel Area Calculation
pixel_area = sum(cleaned(:));
disp(['Pixel Area: ', num2str(pixel_area)]);

%% Step 7: Convert Pixels to Real-World Area
% Example scale: 1 meter = 50 pixels
scale = 1/50;  % meters per pixel

area_m2 = pixel_area * (scale^2);

disp(['Estimated Field Area (m^2): ', num2str(area_m2)]);
