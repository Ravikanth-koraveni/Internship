#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<zlib.h>
//#pragma comment (lib,"zlibdll/lib/zdll.lib")

int main()
{
srand(time(0));
bool showOutput;
printf("show textual output? [y/n]\n");
if(getchar()=='y'||getchar()=='Y')
showOutput = true;
else
showOutput = false;

#pragma region _make some data to compress_
const int NUM_WORDS = 8938;



FILE *f = fopen("/home/ravi/as-caida20071106.txt ","rb");
fseek(f,0,SEEK_END);
long fsize = ftell(f);
fseek(f,0,SEEK_SET);

char * randomWords = (char *)malloc(fsize + 1);
fread(randomWords,fsize,1,f);
fclose(f);

randomWords[fsize] = 0;
dataOriginal [sizeDataOriginal-1] = NULL;
printf("\n here is what we generated for you");
if(showOutput)
{
    for(int i =0 ; i<sizeDataOriginal;i++)
    {
        putchar(dataOriginal[i]);
    }
    printf("\n--\n\n");

    }
else
 printf("(supressed)\n--\n\n");
    #pragma endregion
    #pragma region compress the data

ULONG sizeDataCompressed = (sizeDataOrginal * 1.1)+12;
BYTE * dataCompressed = (BYTE*)malloc(sizeDataCompressed);

int z_result = compress(dataCompressed,&sizeDataCompressed,dataOriginal,sizeDataOriginal);

switch(z_result){
case Z_OK:
    printf("*****SUCCESS!******");
    break;

   case Z_MEM_ERROR:
        printf("out of memory\n");
        exit(1);    // quit.
        break;

    case Z_BUF_ERROR:
        printf("output buffer wasn't large enough!\n");
        exit(1);    // quit.
        break;
}


#pragma endregion

#pragma region sacve compressed data to disk
FILE * out = fopen("/home/ravi/compr.dat","wb");

if(out=NULL){
    pritnf("Couldn't open outputfile for writing\n");
    exit(1);


}
fwrite(dataCompressed,sizeDataCompressed,1,out);
fclose(out);
out = NULL;
#pragma endregion


}
