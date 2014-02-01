#include <stdio.h>
 #include <string.h>
  #include<conio.h>
   #include<math.h>
    main()
	{
		        int n;
				        scanf("%d",&n);
						      n=n|(n>>1);
							        n=n|(n>>2);
									      n=n|(n>>4);
										        n=n|(n>>8);
												      n=(n+1)>>1;
													        printf("%d",n);
															      getch();      }
