#include <stdio.h>
# define ll long long int
int main()
{
    
ll n1,n2;
printf("Enter two number: ");
scanf("%lld %lld",&n1,&n2);
ll a[1000]={0};
ll ans[1000]={0};
ll cp=n1>n2?n1:n2;
ll x=n1<n2?n1:n2;
 ll i=0,k=x,j=0;
 while(k!=0){
 k=k/10;
 j++;
 }
while(cp!=0){
    a[i++]=cp%10;
    cp= cp/10;
}
ll limit=i+j;
i=0;
ll carry=0;
for(ll i=0;i<limit;i++){
    ll fun =x*a[i]+carry;
    carry=0;
    ans[i]=fun%10;
    carry=fun/10;
}

for(ll i=0;i<limit/2;i++){
    ll t=ans[limit-i-1];
    ans[limit-i-1]=ans[i];
    ans[i]=t;
}
 printf("Product of above numbers is: ");
for(int i=0;i<limit;i++){
    
printf("%lld",ans[i]);
}
    return 0;
}
