#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <strings.h>

struct node
{
    /* word */
    char *word;
    int count;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void insert(char *word)
{
    // create link
    struct node *link = (struct node *)malloc(sizeof(struct node));
    // struct node *foundLink = find(word);
    link->word = word;
    link->count = 1;

    //point to old node
    link->next = head;
    // point to new node
    head = link;
}

struct node *find(char *str)
{
    struct node *current = head;
    while (strcasecmp(current->word, str))
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            current = current->next;
        }
    }
    return current;
}

// print linklist
void printList()
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("Word: %s, occurance: %d\n", ptr->word, ptr->count);
        ptr = ptr->next;
    }
}

void branch(char *str)
{
    int temp;
    struct node *foundLink = find(str);
    if (foundLink != NULL)
    {
        struct node *current = head;
        while (strcasecmp(current->word, str))
        {
            if (current->next == NULL)
            {
                break;
            }
            else
            {
                temp = current->count;
                current->count = temp + 1;
            }
        }
        // printf("%s,", foundLink->word);
        // temp = foundLink->count;
        // current = foundLink;
        // current->count = temp + 1;
        // printf("%d\n", foundLink->count);
    }
    else
    {
        printf("no\n");
        insert(str);
    }
}
int main()
{
    char *hello = "hello";
    branch(hello);

    // insert("good bye");
    printList();
}