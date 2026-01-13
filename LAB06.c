#include <stdio.h>
#include <stdlib.h>

void insert_chaining(int givenKey)
{
    int index=givenKey % m;
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->key=givenKey;
    p->next=first[index];
    first[index]=p;
}
void delete_chaining(int givenKey)
{
    int index=givenKey%m;        // calculăm indexul
    NodeT *current=first[index];   // pointer la începutul listei din slotul respectiv
    NodeT *prev=NULL;              // pentru a păstra nodul anterior

    while (current!=NULL)
    {
        if (current->key==givenKey)   // dacă am găsit cheia
        {
            if (prev==NULL)
            {
                // ștergem primul element din listă
                first[index]=current->next;
            }
            else
            {
                // ștergem un element din interiorul listei
                prev->next=current->next;
            }
            free(current);
            return;
        }
        prev=current;
        current=current->next;
    }
}


void afisare_hash_table_chaining()
{
    for (int i=0;i<m;i++)
    {
        printf("[%d]: ",i);
        NodeT *current=hTable[i];
        while (current!=NULL)
        {
            printf("%d ", current->key);
            current=current->next;
        }
        printf("\n");
    }
}

int main()
{
    insert_chaining(36);
    insert_chaining(14);
    insert_chaining(26);
    insert_chaining(21);
    insert_chaining(5);
    insert_chaining(19);
    insert_chaining(4);
    delete_chaining(26);

    afisare_hash_table_chaining();
    return 0;
}
