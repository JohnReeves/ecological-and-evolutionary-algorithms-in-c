#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	clock_t start = clock(); 
	FILE *fi = fopen("./images/lena512.bmp", "r");
	FILE *fo = fopen("./images/lena_inverted.bmp","wb");

 	unsigned char header[54];
	unsigned char colorTable[1024];

  if (fi == (FILE *)0) {
     printf("Error opening file.\n");
     exit(0);
 	}

  fread(header, sizeof(unsigned char), 54, fi);

 	int width = *(int*)&header[18];
 	int height = *(int*)&header[22];
	int colorDepth = *(int*)&header[28];

	printf("width: %d\nheight: %d\ncolor depth: %d\n", width, height, colorDepth);
 	unsigned char imageBuffer[height * width];

	if (colorDepth <= 8) fread(colorTable, sizeof(unsigned char), 1024, fi);
	fread(imageBuffer, sizeof(unsigned char), (height * width), fi);


  // a background inverted lena
	for (int i = 0; i < height; i++){
	    for (int j = 0; j < width; j++){                   
		     imageBuffer[i*width + j] = 255 - imageBuffer[i*width + j]; 
		 }   
	}

  float k;
  // axes, graphs and other stuff
	for (int i = 0; i < height; i++){
	    for (int j = 0; j < width; j++){                   

         // half random noise for fun
         if ((i + j) > 700) imageBuffer[i*width + j] = rand() % 255;

          // horizontal line
          if (i==10) imageBuffer[i*width + j] = 0;
          if (i==11) imageBuffer[i*width + j] = 0;
          if (i==12) imageBuffer[i*width + j] = 0;

          // vertical line
          if (j==10) imageBuffer[i*width + j] = 0;
          if (j==11) imageBuffer[i*width + j] = 0;
          if (j==12) imageBuffer[i*width + j] = 0;

          // linear y = mx + c
          if ((2*i-j)==100) imageBuffer[i*width + j] = 0;
          if ((2*i-j)==101) imageBuffer[i*width + j] = 0;
          if ((2*i-j)==102) imageBuffer[i*width + j] = 0;

          // a parabola
          if ((i*i)==1000) imageBuffer[i*width + j] = 0;

         // an ellipse
         k = ((i*2.0)/500)*((i*2.0)/500) + (j*2.0/500.0)*(j*2.0/500.0);

         if (k>0.98 && k<1.0)
          imageBuffer[i*width + j] = rand() % 25;
		 }   
	}
  fwrite(header, sizeof(unsigned char), 54, fo); 
	if (colorDepth <= 8) fwrite(colorTable, sizeof(unsigned char), 1024, fo);
	fwrite(imageBuffer, sizeof(unsigned char), (height * width), fo);

	printf("Time: %2.3f ms\n",((double)(clock() - start) * 1000.0 )/ CLOCKS_PER_SEC);

	fclose(fo);
 	fclose(fi);
  return 0;
}
