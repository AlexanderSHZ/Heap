#include <iostream>
#pragma warning(disable : 4996)

char* sort(int n, char* textPtr);      //Посимвольно сортирует строку.
double upper(int i, char* text);       //Приводит к нижнему регистру. Ф-ция для sort.
struct DataText textFromUser(struct DataText dataText);


struct DataText
{
    int quantity;
    char* textPtr;
};

int main(void)
{
    DataText dataText;

    dataText.textPtr = NULL;

   
   
    dataText = textFromUser(dataText);

  



                         //Сортируем символы.
                            
    printf("%s", dataText.textPtr);                    //Выводим отсортированную строку на консоль.
    printf("\n"); 

 //sort(quantity, textPtr);   

 printf("%s", dataText.textPtr);                    //Выводим отсортированную строку на консоль.
 printf("\n");
    free(dataText.textPtr);
    return 0;
}

DataText textFromUser(DataText dataText)

{
    char* textPtrAccessory = NULL;
    int capacity = 1;
    char ch;

    fflush(stdout);

    dataText.textPtr = (char*)malloc(sizeof(char) * capacity);

    while (((ch = getchar()) != '\n') && (ch != EOF))       //Получение указателя на строку из консоли.
    {
        if (capacity - dataText.quantity < 2)                             //По необходимости увеличиваем размер массива.
        {
            capacity *= 2;
            textPtrAccessory = dataText.textPtr;
            dataText.textPtr = (char*)realloc(dataText.textPtr, sizeof(char) * capacity);
            if (dataText.textPtr == NULL)
            {
                printf("Program operation failed! \n");
               
            }
        }
        dataText.textPtr[dataText.quantity] = ch;
        dataText.quantity++;
    }

    textPtrAccessory = dataText.textPtr;
    dataText.textPtr = (char*)realloc(dataText.textPtr, sizeof(char) * (dataText.quantity + 1)); //Приводим массив к реальному размеру.

    if (dataText.textPtr == NULL)
    {
        printf("Program operation failed! \n");
       
    }

    dataText.textPtr[dataText.quantity] = '\n';
    return dataText;
}

double upper(int i, char* textPtr)            //Приведение к нижнему регистру.
{
    double a;

    if (textPtr[i] < 97)
    {
        a = textPtr[i] + 31.5;
    }
    else
    {
        a = textPtr[i];
    }
    return a;
}

char* sort(int n, char* textPtr)                     //Cортировка массива.
{
    char tmp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n ; j++)
        {

            if (upper(j, textPtr) < upper(i, textPtr))
            {
                tmp = textPtr[i];
                textPtr[i] = textPtr[j];
                textPtr[j] = tmp;
            }
        }
    }
    return textPtr;
}
