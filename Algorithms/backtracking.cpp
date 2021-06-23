#include<iostream>

int cnt;

void printgrid(int **grid,int nrow,int ncol)
{
    for(int i=0;i<nrow;i++)
    {
        for(int j=0;j<ncol;j++)
        {
            std::cout<<grid[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}
int getval(int **grid,int nrow,int ncol,int row,int col)
{
    if((row<0)||(row>=nrow)||(col<0)||(col>=ncol)) return -1;
    else return grid[row][col];   
}

void findmx(int **grid,int row,int col,int *cmax,int nrow,int ncol,bool **vis)
{
    cnt++;
    if(row<0||row>=nrow||col<0||col>=ncol) return;
    (*cmax)++;
    std::cout<<row<<" "<<col<<" "<<*cmax<<"\n";
    vis[row][col]=true;
    int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int rowi,coli,val{0};

    for(int i=0;i<8;i++)
    {
        rowi=dir[i][0]+row;
        coli=dir[i][1]+col;
        val=getval(grid,nrow,ncol,rowi,coli);
        if(val==1){
            if(vis[rowi][coli]==false)
            {
                findmx(grid,rowi,coli,cmax,nrow,ncol,vis);
                //std::cout<<rowi<<" "<<coli<<"\n";
            }
        } 
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/pavan/cp_problems/a.in", "r", stdin);
    freopen("/home/pavan/cp_problems/a.out", "w", stdout);
#endif
    int nrow,ncol;
    std::cin>>nrow>>ncol;
    int **grid= new int *[nrow];
    bool **vis= new bool *[nrow];
    for(int i=0;i<nrow;i++)
    {
        vis[i]=new bool[ncol];
        grid[i]=new int[ncol];
        for(int j=0;j<ncol;j++)
        {
            vis[i][j]=false;
            std::cin>>grid[i][j];
        }
    }
    //printgrid(grid,nrow,ncol);
    //std::cout<<std::endl;
    int gmax{},cmax{};
    for(int i=0;i<nrow;i++)
    {
        for(int j=0;j<ncol;j++){
            if((vis[i][j]==false)&&(grid[i][j]==1))
            {
                cmax=0;
                findmx(grid,i,j,&cmax,nrow,ncol,vis);
                if(gmax<cmax) gmax=cmax;
            }
        }
    }
    //findmx(grid,r,c,0,nrow,ncol,&gmax);// 0  is current max
    std::cout<<gmax<<" "<<cnt;
    for(int i=0;i<nrow;i++){
        delete [] grid[i];
        delete [] vis[i];
    }
    delete [] grid;
    delete [] vis;
}