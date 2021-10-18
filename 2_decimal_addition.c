#include<stdio.h>
#include<string.h>
int getcharval(char *s,int idx){
    if(idx>=strlen(s))
    return 0;
    return s[strlen(s)-idx-1]-48;
}
int main(){
char a[1000]="0";
char b[1000]="0";
char ans[10000]="0";
printf("Enter two number: ");
scanf("%s %s",a,b);
int wa=strlen(a),wb=strlen(b),width;
width=wa>wb?wa:wb;

int carry=0;
int i=0;
for( i=0;i<width;i++){
int ca,cb,sum;
ca=getcharval(a,i);
cb=getcharval(b,i);
sum=ca+cb+carry;
carry=0;
if(sum>9){
carry=1;
sum=sum-10;
}
ans[i]=sum+48;

}

if(carry)
ans[i++]=carry+48;
for (i = 0; i < strlen(ans) / 2; i++) {
        char t = ans[i];
        ans[i] = ans[strlen(ans) - i - 1]; 
        ans[strlen(ans) - i - 1] = t;
    } 
    printf("Sum of above numbers is: ");
    printf("%s",ans);
}
