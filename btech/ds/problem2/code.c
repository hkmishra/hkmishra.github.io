#include <stdio.h>
#include <string.h>

int bubble(char a[25],char b[25]);

int main()
{
    int n,m,k,v,i,y1;
    char name[10];
    char fans[11][51];
    
    for(i=0;i<=50;i++)
    {   
        strcpy(fans+i,"0000");
    }
  
    scanf("%d %d",&n,&m);
    
    for(i=0;i<n;i++){
        scanf("%s %d",name,&v);
       

       if(strcmp(fans[v],"0000")==0) //no entry
       {
           strcpy(fans + v, name);
       }
       else{
           if(bubble(name,fans[v]) == 1 ) // new name is leical minimum
                strcpy(fans + v, name);
            //else do nothing.
       }
       
      
        
        
    }//end of for
    
    printf("\n====\n");
    k = 0;
    for(i=50;i>=0;i--){
        if(strcmp(fans[i],"0000")!=0)
        {   
            printf("%s\n",fans[i]);
            if(++k == m) break;
        }
    }
    
    
    return 0;
}



int bubble(char a[25],char b[25])
{
  char name[25][50],temp[25];
  int n,i,j;
  

  
  strcpy(name[0],a);
  strcpy(name[1],b);
  n = 2;
  

     for(i=1;i<=n;i++)
	for(j=0;j<=n-i;j++)
	  if(strcmp(name[j],name[j+1])>0)
	  { 
            strcpy(temp,name[j]);
	    strcpy(name[j],name[j+1]);
	    strcpy(name[j+1],temp);
	  }
//   printf("The strings appears after sorting :\n");
	      
	      for(i=0;i<=n;i++) {
//		        printf("%s\n",name[i]);
	      }
	      
	      
	      
		 if(strcmp(name[1],a)==0)   //return which no is lexical minimum
		    return (1);
		 else if(strcmp(name[1],b)==0)
		    return (2);
        
}
