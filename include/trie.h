typedef struct element
{
    char word[17];
    int pts;
    struct element *right;
} element;
void addElement(element * elem);
void printList();
void clearList();