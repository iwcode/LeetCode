char* convert(char* s, int numRows) {
     int len = strlen(s);
     if(len == 0||numRows==1) return s;
     int ss[len];
     int j=0;
     for(int i = 0 ; i < numRows ; i++){
         if(i == 0){
             int tmp  = 2 * numRows - 2 ;
             for(int k = 0 ; k < len ; k = k + tmp ){
                 ss[j++] = k ;
             }
         }else if( i == numRows - 1 ){
             int tmp  = 2 * numRows - 2 ;
             for(int k = numRows - 1 ; k < len ; k = k + tmp ){
                 ss[j++] = k ;
             }
         }else{
            int  l1 = 2 * numRows - 2 - 2*i,l2 = 2 * numRows-2;
            for(int k = i ; k < len ;k = k + l2){
                ss[j++]=k;
                int kk = k + l1 ; 
                if(kk < len){
                    ss[j++] = kk ;
                }else{
                    break;
                }
            }
         }
     }
     char *st = malloc(len+1);
     st[len] = '\0';
     for(int i = 0 ; i < len ; i++ ){
         st[i] = s[ss[i]];
     }
     return  st;
}