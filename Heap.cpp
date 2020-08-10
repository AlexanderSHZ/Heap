#include <iostream>
#pragma warning(disable : 4996)

char* sort(int n, char* textPtr);      //Посимвольно сортирует строку.
double upper(int i, char* text);       //Приводит к нижнему регистру. Ф-ция для sort.


int main(void)
{
    char* textPtrAccessory = NULL;
    char* textPtr = NULL;
    int n=0;
    int available = 20;
    char ch = 0;
    
    fflush(stdout);

    textPtr = (char*)malloc(sizeof(char) * available);

    while (((ch = getchar()) != '\n') && (ch != EOF))       //Получение указателя на строку из консоли.
    {
        if (available - n < 2)                             //По необходимости увеличиваем размер массива.
        {
            available *= 2;
            textPtrAccessory = (char*)realloc(textPtrAccessory, sizeof(char) * available);
            if (textPtrAccessory != NULL)
            {
                textPtr = textPtrAccessory;
            }
            else
            {
                printf("Program operation failed! \n");
            }
        }
        textPtr[n] = ch;
        n++;
        textPtr[n] = '\0';
    }

    textPtrAccessory = (char*)realloc(textPtrAccessory, sizeof(char) * (n+1));   //Приводим массив к реальному размеру.
    if (textPtrAccessory != NULL)
    {
        textPtr = textPtrAccessory;
    }
    else
    {
        printf("Program operation failed! \n");
    }
    free(textPtrAccessory);
    
    sort(n, textPtr);                    //Сортируем символы.
                            
    printf("%s", textPtr);                   //Выводим отсортированную строку на консоль.
    printf(" \n");

    free(textPtr);
    return 0;
}
double upper(int i, char* textPtr)   //Приведение к нижнему регистру.
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
