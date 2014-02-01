#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX 32767


typedef struct node
       {
       struct node *parent;
       int key;
       int data;
       int tDiscovered,tFinished;
       }node;
       
typedef struct edge{
		int v1;
		int v2;
		//int weigth;
}edge;

typedef struct adjNode
{
    int data;
    struct adjNode *link;
}adjNode;

typedef struct graph{
    node *vertices[10];
    edge edge[100];
    int w[10][10];
    int verticesNumber;
}graph;
       void createAdjList(graph *g,adjNode **st)
       {
           adjNode *tt;
           *st=(adjNode*)malloc(sizeof(adjNode));
           tt=*st;
           int counter=0,edge_count=0;
        char c;
        adjNode *t;
        t=(adjNode*)malloc(sizeof(adjNode));
        printf("Enter the node data..\n");
        scanf("%d",&(tt->data));
        g->vertices[tt->data]=(node*)malloc(sizeof(node));
        g->vertices[tt->data]->data=tt->data;
        printf("Vertex with node data = %d made !\n",g->vertices[tt->data]->data);
        fflush(stdin);
        printf("Connected to other node?");
        scanf("%c",&c);
        if(c=='y')
        {
            tt->link=t;
        while(c=='y')
       {
       printf("Enter the Connected Node : ");
         scanf("%d",&(t->data));
         printf("Enter the Weight of edge : ");
         scanf("%d",&(g->w[tt->data][t->data]));
         counter++;
         fflush(stdin);
         printf("Connected to more nodes???\n");
        scanf("%c",&c);
        if(c=='y')
           {
            t->link=(adjNode*)malloc(sizeof(adjNode));
            t=t->link;}
        else
            t->link=NULL;
       }}
       else
       {
           tt->link=NULL;
       }
       }

       void display(adjNode *temp)
       {
           adjNode *p;
            p=temp->link;
           printf("The node %d is connected to....\n",temp->data);
           while(p!=NULL)
           {
               printf("%d  ",p->data);
               p=p->link;
           }

       }
       
  int prims(graph *g,adjNode *adjList[],int rootdata,int n)
  {
   	   int i,min_key=MAX,min_key_index,minpath=MAX,visited[n],traversed_nodes=0,path_length=0;
   	   adjNode *temp;
   	   printf("Initialing the graph :\n");
   	   //Initailising g
   	   for(i=0;i<n;i++)
   	   {
           g->vertices[i]->parent=NULL;
           g->vertices[i]->key=MAX;
           visited[i]=0;
   	   }
   	   printf("Initialing the root :\n");
   	   //initialising the parent node
   	   g->vertices[rootdata]->key=0;
   	   //prev_min_key_index=r;
   	   printf("Starting to find mins :\n");
   	   while(traversed_nodes <n)
   	   {
        //selecting vertex with min_key..
   	   for(i=0;i<n;i++)
   	   {
            if(visited[i]!=1 && min_key > g->vertices[i]->key)
            {
			 		   min_key = g->vertices[i]->key;
			 		   min_key_index=i;
            }
   	   }
   	   printf("min node selected is : %d\n",min_key_index);
   	   
   	   //setting the new key values
   	   for(temp=adjList[min_key_index]->link; temp!=NULL ;temp=temp->link)
   	   {
	   			if(visited[temp->data]!=1 && g->vertices[temp->data]->key > g->w[min_key_index][temp->data])
	   			{
                   g->vertices[temp->data]->parent = g->vertices[min_key_index];
                   g->vertices[temp->data]->key  = g->w[min_key_index][temp->data];
                   if(minpath > g->vertices[temp->data]->key )
                   {
 						minpath=g->vertices[temp->data]->key ;
 						printf("Edge Chosen is : %d\n",minpath);
                   }
	   			}
   	   }
   	   if(minpath==MAX)
   	   minpath=0;
   	   
   	   visited[min_key_index]=1;
   	   //taking the path and incrementing path_length
   	   
   	   path_length = path_length + minpath;
   	   min_key=MAX;
   	   minpath=MAX;
   	   traversed_nodes++;
	   }
   	   return path_length;
  }

   
       main()
       {
       graph *g;
       g = (graph*)malloc(sizeof(graph));
       int n,i,j;
           printf("Enter the number of nodes in the graph :\n");
           scanf("%d",&n);
           adjNode *adj[n];
           g->verticesNumber=n;
           printf("Enter the vertices in the graph IN Order : \n");
           for(i=0;i<n;i++)
           {
           createAdjList(g,&(adj[i]));
           }
          // display(s);
         /* for(i=0;i<n;i++)
          {
		   		  for(j=0;j<n;j++)
		   		  {
   				   g->w[i][j]=-1;
		   		  }
          }*/

           for(i=0;i<n;i++)
           {
           display(adj[i]);

           }
           
           printf("%d",prims(g,adj,0,n));
           getch();
       }
