/*D&#161;óú?èóún·&#182;&#206;§&#196;ú?&#196;&#203;&#216;êy&#182;&#212;*/

main()
{
 int i, j, k, n, s, flag=9;
 scanf("%d", &n);
 s=0;
 
 for (i=2; i<n-1; i++)
 {
  flag=0;   
  for (j=2; j<=i/2; j++)
  {
   if (i%j==0)
      flag++;    
  }  
  if (flag==0)    /*&#212;òi&#206;a&#203;&#216;êy*/
  {
   for (j=2; j<=(i+2)/2; j++)
   {
    if ((i+2)%j==0)
       flag ++;   
   }        
   if (flag==0)
   {   
    printf("%d %d\n", i, i+2);
    s++;
   } 
  }
 }
 if (s==0)
      printf("empty\n");

}
