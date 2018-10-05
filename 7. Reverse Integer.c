int reverse(int x) {
    int z=(x<0),y=0,pre=0;
    x=z?-x:x;
    while(x>0)
    {
        y=y*10+x%10;
        if(y/10<pre)return 0;
        pre=y;
        x/=10;
    }
    return z?-y:y;
}  