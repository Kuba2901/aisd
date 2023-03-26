#include <iostream>
#define T 8
#define MAX_ARRAY_SIZE 128
#define MAX_NAME_SIZE 64
using namespace std;


struct Attribute {
    char value[MAX_NAME_SIZE];
    char name[MAX_NAME_SIZE];
};

struct Selector {
    Attribute attributes[MAX_ARRAY_SIZE];
};
struct Section {
    Selector selectors[MAX_ARRAY_SIZE];
};

struct Block {
    Section sections[T];
    int freeStructs = 0;
} block;



struct ListNode {
    char *value;
    struct ListNode* previousNode;
    struct ListNode* nextNode;
};

void getLine();
void printAttribute(char* valueType, char *buffer, int begin, int end);


int main() {
    getLine();

    return 0;
}

void getLine() {
    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength]; 
    char nameBuffer[MAX_NAME_SIZE];

    filePointer = fopen("test.txt", "r");

    // Sections
    int sectionOpened = 0;    

    int i = 0;

    // Attribute name
    int nameBegin = 0;
    int nameEnd = 0;

    // Attribute value
    int valBegin = 0;
    int valEnd = 0;

    // Selector name
    int selBegin = 0;
    int selEnd = 0;
    int selSet = 0;

    while(fgets(buffer, bufferLength, filePointer)) {
        while (buffer[i] != '\0') {
            char character = buffer[i];

            switch (character) {
                case ',':
                    if (sectionOpened) {
                        printf("Next value\n\n");
                    } 
                    else {
                        selEnd = i;
                        printAttribute("Selector: ", buffer, selBegin, selEnd);
                        selBegin = 0;
                        selSet = 0;
                        printf("Next selector\n\n");
                    }
                    break;
                case '{':
                    // Count the last selector before section
                    selEnd = i;
                    printAttribute("Selector: ", buffer, selBegin, selEnd);
                    selBegin = 0;
                    selSet = 0;
                    
                    // Open the section
                    printf("Section opened\n\n");
                    sectionOpened = 1;
                    break;
                case '}':
                    printf("Section closed\n\n");
                    sectionOpened = 0;
                    break;
                case ' ':
                    printf("Space - ignoring\n\n");
                    break;
                case '\n':
                    printf("New line - ignoring\n\n");
                    break;
                case '\t':
                    printf("Tab - ignoring\n\n");
                    break;
                case ':':
                    printf(": - value value\n\n");
                    nameEnd = i;
                    valBegin = i+2;
                    break;
                case ';':
                    printf("; - end of value\n\n");
                    valEnd = i;

                    // Print name
                    printAttribute("Name:", buffer, nameBegin, nameEnd);

                    // Print value
                    printAttribute("Value:", buffer, valBegin, valEnd);
                    break;
                default:
                    printf("Character: %c[%d]\n\n", character, character);

                    if (sectionOpened) {
                        if (int(character) >= 97 && int(character) <= 122 && nameBegin == 0) {
                            nameBegin = i;
                        }
                    } else {
                        if (selSet == 0) {
                            selBegin = i;
                            selSet = 1;
                        }
                    }
                    break;
            }

            i++;
        }
        printf("\n--- New line ---\n");

        // Reset the values
        i = 0;
        nameBegin = 0;
        nameEnd = 0;

        valBegin = 0;
        valEnd = 0;
        
        selBegin = 0;
        selEnd = 0;
        selSet = 0;

    }

    fclose(filePointer);
}

void printAttribute(char* valueType, char *buffer, int begin, int end) {
    printf("%s", valueType);

    for (int i = begin; i < end; i++)
    {
        printf("%c", buffer[i]);
    }

    printf("\n\n");
    
}

void insert_front(struct ListNode** head, char* newValue)
{
   //allocate memory for New node
   struct ListNode* newNode = new ListNode;
  
   //assign data to new node
   newNode->value = newValue;
  
   //new node is head and previous is null, since we are adding at the front
   newNode->nextNode = (*head);
   newNode->previousNode = NULL;
  
   //previous of head is new node
   if ((*head) != NULL)
   (*head)->previousNode = newNode;
  
   //head points to new node
   (*head) = newNode;
}

void insert_After(struct ListNode* previousNode, char* newValue)
{
   //check if prev node is null
   if (previousNode == NULL) {
   return;
    }
   //allocate memory for new node
   struct ListNode* newNode = new ListNode;
  
   //assign data to new node
   newNode->value = newValue;
  
   //set next of newnode to next of prev node
   newNode->nextNode = previousNode->nextNode;
  
   //set next of prev node to newnode
   previousNode->nextNode = newNode;
  
   //now set prev of newnode to prev node
   newNode->previousNode = previousNode;
  
   //set prev of new node's next to newnode
   if (newNode->nextNode != NULL)
   newNode->nextNode->previousNode = newNode;
}


  
  
//insert a new node at the end of the list
void insert_end(struct ListNode** head, char* newData)
{
   //allocate memory for node
   struct ListNode* newNode = new ListNode;
  
   struct ListNode* last = *head; //set last node value to head
  
   //set data for new node
   newNode->value = newData;
  
   //new node is the last node , so set next of new node to null
   newNode->nextNode = NULL;
  
   //check if list is empty, if yes make new node the head of list
   if (*head == NULL) {
    newNode->previousNode = NULL;
    *head = newNode;
        return;
    }
    
    //otherwise traverse the list to go to last node
    while (last->nextNode != NULL)
    last = last->nextNode;
    
    //set next of last to new node
    last->nextNode = newNode;
    
    //set last to prev of new node
    newNode->previousNode = last;
    return;
}
