
//lca

for (int i=1;i<=n;i++)p[i][0]=fa[i];
     for (int j=1;j<24;j++){
         for (int i=1;i<=n;i++){
             p[i][j]=p[p[i][j-1]][j-1];
         }
     }

int lca(int x,int y){
    if (x==y)return x;
    if (dep[x]<dep[y])swap(x,y);
    int j;
    while (dep[x]>dep[y]){
          for (j=1;dep[p[x][j]]>=dep[y];j++);
          x=p[x][j-1];
    }
    while (x!=y){
          for (j=1;p[x][j]!=p[y][j];j++);
          x=p[x][j-1];
          y=p[y][j-1];
    }
    return x;
}
