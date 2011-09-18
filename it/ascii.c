#include<stdio.h>
#include<stdlib.h>
    int main(){
  
    char string[]="123\0";
    int i =0;
    char j,k;
    int m;

    i = string[0]-'0';
    printf("char to integer cnversion i = %d\n",i);

    j='0'+1;
    printf("integer to char cnversion j = %c\n",j);

    k = 'a'-'0'+'1';
    printf("Ascii value manipulation k(char) = %c, k(int) = %d\n", k , k);
    
    m = 'a'-'0'+'1';
    printf("Ascii value manipulation m(char) = %c, m(int) = %d\n", m , m);

    printf("Acscii value - a = %d, A=%d 0=%d \n",'a','A','0');
   
    return 0;
}
