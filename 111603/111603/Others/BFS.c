#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define SIZE 100

typedef struct node
       {
       struct node *parent;
       char color; //using g for gray,w fo white and b for black
       int data;
       int d;
       }node;

typedef struct adjNode
{
    int data;
    struct adjNode *link;
}adjNode;

typedef struct graph{
    node *vertices[SIZE];
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

    typedef struct queue
    {
        int top,bottom;
        node nodelist[SIZE];
    }queue;

    void enqueue(queue *q,node s)
    {
        if( ((q->top)) != q->bottom)
        {
			q->nodelist[q->top]=s;
			 printf("Adding to Queue a node: %d at index %d\n", s.data,q->top);
            q->top = ((q->top)+1)%SIZE ;
           
            
        }
        else
        {
            printf("No SPACE AVALIALE FOR ENQUEING");
        }
    }

    node dequeue(queue *q)
    {
        if((q->bottom +1)%SIZE != q->top )
        {
            q->bottom = (q->bottom + 1)%SIZE;
            printf("Removing from Queue Node %d index = %d\n",q->nodelist[(q->bottom)].data,q->bottom);
            return q->nodelist[(q->bottom)];
        }
        else
        {
			printf("NullNode Returned");
			node nullnode;
			nullnode.data=-1;
			return nullnode;
        }
    }

     void BFS(graph *g,node *u,adjNode *adj[])
     {
         int i;
         node *v;
         //making and initialising queue
         queue q;
         q.top=0;
         q.bottom = -1;
         adjNode *av;

         //printf("Starting BFS Visit with Vertices =%d  \n",g->verticesNumber);
         for(i=0; i<g->verticesNumber ;i++)
         {
             printf("Getting vertex at i = %d\n",i);
             v = g->vertices[i];
             printf("Initailsing Vertice %d\n",v->data);
                 v->color='w';
                 v->parent=NULL;
                 v->d=0;
         }
         //enqueue(&q,*u);
        printf("While computing from source Vertex = %d ,BFS Traversal Gives :\n",u->data);
       while(u->data != -1)
       {
           printf("Node Dequeued is %d \n",u->data);
          for(av=adj[u->data]->link;av!=NULL;av=av->link)
          {
              if(g->vertices[av->data]->color=='w')
              {
              v = g->vertices[av->data];
              v->color='g';
              v->d = u->d +1;
              enqueue(&q,*v);
              }
          }
          u->color='b';
          printf("Node =%d & distance = %d\n",u->data,u->d);
          *u=dequeue(&q);
       }
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
		   printf("Enter the vertices connected serially in order ! \n");
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
           BFS(g,g->vertices[0],adj);
           getch();
       }
