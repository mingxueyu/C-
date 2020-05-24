int zrk(int x,int y)
{
    if(x%y==0)
        return y;
    zrk(y,x%y);
}
