#include<stdio.h>
int main()
{
int n=1,m=1,i,j,t,r,p,q;
int a[200],b[200],c[200],d[10],e[10],f[10],s[10];
while(n!=0||m!=0)
{
  scanf("%d%d",&n,&m);for(i=1;i<=n;i++) {d[i]=i;s[i]=0;e[i]=0;f[i]=0;}
  if(n==0&&m==0) break;

  for(j=1;j<=m;j++)
  {scanf("%d%d%d",&a[j],&b[j],&c[j]);
   if(c[j]==1)
   {s[a[j]]=s[a[j]]+3;s[b[j]]=s[b[j]]-1;e[a[j]]++;f[b[j]]++;}
   else if(c[j]==-1)
   {s[a[j]]=s[a[j]]-1;s[b[j]]=s[b[j]]+3;e[b[j]]++;f[a[j]]++;}
   else if(c[j]==0)
   {s[a[j]]=s[a[j]]+1;s[b[j]]=s[b[j]]+1;}
  }

  for(j=1;j<=n-1;j++)
  for(i=1;i<=n-j;i++)
  if(s[i]<s[i+1])
  {t=s[i];s[i]=s[i+1];s[i+1]=t;r=d[i];d[i]=d[i+1];d[i+1]=r;
   p=e[i];e[i]=e[i+1];e[i+1]=p;q=f[i];f[i]=f[i+1];f[i+1]=q;}

  for(j=1;j<=n-1;j++)
  for(i=1;i<=n-j;i++)
  if(s[i]==s[i+1]&&e[i]<e[i+1])
  {t=s[i];s[i]=s[i+1];s[i+1]=t;r=d[i];d[i]=d[i+1];d[i+1]=r;
   p=e[i];e[i]=e[i+1];e[i+1]=p;q=f[i];f[i]=f[i+1];f[i+1]=q;}

  for(j=1;j<=n-1;j++)
  for(i=1;i<=n-j;i++)
  if(s[i]==s[i+1]&&e[i]==e[i+1]&&f[i]>f[i+1])
  {t=s[i];s[i]=s[i+1];s[i+1]=t;r=d[i];d[i]=d[i+1];d[i+1]=r;
   p=e[i];e[i]=e[i+1];e[i+1]=p;q=f[i];f[i]=f[i+1];f[i+1]=q;}

  for(j=1;j<=n-1;j++)
  for(i=1;i<=n-j;i++)
  if(s[i]==s[i+1]&&e[i]==e[i+1]&&f[i]==f[i+1]&&d[i]>d[i+1])
  {t=s[i];s[i]=s[i+1];s[i+1]=t;r=d[i];d[i]=d[i+1];d[i+1]=r;
   p=e[i];e[i]=e[i+1];e[i+1]=p;q=f[i];f[i]=f[i+1];f[i+1]=q;}

  for(i=1;i<=n;i++)printf("%d ",d[i]);printf("\n");
}
return 0;
}
