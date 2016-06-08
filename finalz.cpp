#include<stdio.h>
#include<zlib.h>
int main(){
int n;
printf("1.compress\n2.decompress\n");
scanf("%d",&n);
if (n==1){
   FILE *fp = fopen("/home/ravi/as-caida20071105.txt", "rb");
    gzFile op = gzopen("/home/ravi/compr.txt", "wb");
    if (!fp|| !op) return -1;

    char inbuffer[128];
    int num_read = 0;
    unsigned long total_read = 0, total_wrote = 0;
    while ((num_read = fread(inbuffer, 1, sizeof(inbuffer), fp)) > 0) {
       total_read += num_read;
       gzwrite(op, inbuffer, num_read);
    }
    fclose(fp);
    gzclose(op);

}

else if(n==2){
gzFile op = gzopen("/home/ravi/compr.dat", "rb");
    FILE *fp = fopen("/home/ravi/uncompr.txt", "wb");
   if (!op || !fp) return -1;

    char buffer[128];
    int num_read = 0;
    while ((num_read = gzread(op, buffer, sizeof(buffer))) > 0) {
       fwrite(buffer, 1, num_read, fp);
       }

    gzclose(op);
    fclose(fp);

}
}

