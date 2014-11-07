#include<stdio.h>
#include<stdlib.h>

typedef struct node
       {
       struct node *parent;
       char color; //using g for gray,w fo white and b for black
       int data;
       int tDiscovered,tFinished;
       }node;

typedef struct adjNode
	{
	    int data;
	    struct adjNode *link;
	}adjNode;

typedef struct graph{
    node *vertices[10];
    int verticesNumber;
}graph;
       void createAdjList(graph *g,adjNode **st)
       {
           adjNode *tt;
           *st=(adjNode*)malloc(sizeof(adjNode));
           tt=*st;
           int counter=0;
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

//using a global variable time to account for Discovery and Fininsh of a vertex
    int time;

     void DFS_Visit_Controller(graph *g,node *u,adjNode *adj[])
     {
         time =0;
         int i;
         node *v;
         printf("Starting DFS Visit with Vertices =%d  \n",g->verticesNumber);
         for(i=0;i<g->verticesNumber;i++)
         {
             printf("Getting vertex at i = %d\n",i);
             v = g->vertices[i];
             printf("Initailsing Vertice %d\n",v->data);
                 v->color='w';
                 v->parent=NULL;
                 v->tDiscovered=0;
                 v->tFinished=0;
         }

         for(i=0;i<g->verticesNumber;i++)
         {
             v=g->vertices[i];
             if(v->color=='w')
             {
                 printf("Giving a DFS at node %d",v->data);
            DFS(g,v,adj);
             }
         }
     }

     DFS(graph *g,node *u,adjNode *adj[])
     {
        adjNode *av;
        time++;
        u->tDiscovered = time;
        u->color = 'g';
        for(av=adj[u->data]->link;av!=NULL;av=av->link)
        {
            if(g->vertices[av->data]->color=='w')
            {
            g->vertices[av->data]->parent=u;
            DFS(g,g->vertices[av->data],adj);
            }
        }
        time++;
        u->tFinished=time;
        u->color='b';
        printf("%d ",u->data);
     }

       main()
       {
       graph *g;
       g = (graph*)malloc(sizeof(graph));
       int n,i;
           printf("Enter the number of nodes in the graph :\n");
           scanf("%d",&n);
           adjNode *adj[n];
           g->verticesNumber=n;
           //create(&s);
           //t=s;
           for(i=0;i<n;i++)
           {
           createAdjList(g,&(adj[i]));
           }
          // display(s);

           for(i=0;i<n;i++)
           {
           display(adj[i]);

           }

           //s=t;
           //display(s);
           DFS_Visit_Controller(g,g->vertices[0],adj);
       }
