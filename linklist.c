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
} node;

struct node *head = NULL;
struct node *current = NULL;
/*Adds word to the list*/
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

/*Retrieve the length of the list*/
int length()
{
    int length = 0;
    struct node *current;

    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }

    return length;
}

/*Sort the link list from largest to smallest*/
void sort()
{

    int i, j, k, tempCount;
    char* tempWord;
    struct node *current;
    struct node *next;

    int size = length();
    k = size;

    for (i = 0; i < size - 1; i++, k--)
    {
        current = head;
        next = head->next;

        for (j = 1; j < k; j++)
        {
            //Check if current node is large than the next
            if (current->count < next->count)
            {
                tempCount = current->count;
                current->count = next->count;
                next->count = tempCount;

                tempWord = current->word;
                current->word = next->word;
                next->word = tempWord;
            }

            current = current->next;
            next = next->next;
        }
    }
struct node *ptr = head;
    // int i = 0;
    while (ptr != NULL)
    {
        printf("Word: %s, occurance: %d\n", ptr->word, ptr->count);
        ptr = ptr->next;
    }
}

/*Find words that already exist*/
struct node *find(char *str)
{
    struct node *current = head;
    if (current == NULL)
    {
        return NULL;
    }
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
    // int i = 0;
    while (ptr != NULL)
    {
        printf("Word: %s, occurance: %d\n", ptr->word, ptr->count);
        ptr = ptr->next;
    } 
}
/*Finds if words exist and inserts them, branches words to the correct place*/
void branch(char *str)
{
    int temp;
/*Find is the word already exists and simply add to the count*/
    find(str);
    struct node *foundLink = find(str);
    if (find(str) != NULL)
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
        printf("%s,", foundLink->word);
        temp = foundLink->count;
        current = foundLink;
        current->count = temp + 1;
        printf("%d\n", foundLink->count);
    }
    else
    {
        insert(str);
    }
}

int main()
{
    char *hello = "hello";
    char *hello1 = "hello1";

    insert(hello);
    find(hello);
    char *hello21 = "hello1";

    branch(hello21);
    branch(hello21);
    sort();
    // insert("good bye");
    // printList();
}