#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void getWord(char* word)
{
    printf("Enter Word: ");
    scanf("%48s",word);

}
void enterLetter(char *word,char *wordCheck,char*letterList,char *wrongLetterList,char* rightLetterList)
{
    getchar();
    char temp;
    int wordExists=0;
    int i=0;
    printf("Please Enter Letter: \n");
    scanf("%c",&temp);
    
    for(int j=0;letterList[j]!='\0';++j)
    {
        if(letterList[j]==temp){
            printf("Please enter new letter\n");
            return;
        }
    }
    for (int i=0;i<strlen(word);++i)
    {
        if(word[i]==temp)
        {
            wordCheck[i]=temp;
            wordExists=1;
        }
    }

    while(letterList[i]!='\0')
    {
        ++i;
    }
    letterList[i]=temp;
    letterList[i+1]='\0';
    i=0;
    if(wordExists)
    {
        while(rightLetterList[i]!='\0')
        {
            ++i;
        }
        rightLetterList[i]=temp;
        rightLetterList[i+1]='\0';        
        i=0;
    }else
    {
        while(wrongLetterList[i]!='\0')
        {
            ++i;
        }
        wrongLetterList[i]=temp;
        wrongLetterList[i+1]='\0';
    }
    i=0;
    printf("%s\n",wordCheck);
    printf("all letters: %s\n",letterList);
    printf("all correct letters: %s\n",rightLetterList);
    printf("all wrong letters: %s\n",wrongLetterList);

}

void checkWin(char word[],char wordCheck[])
{
    for(int i=0;i<strlen(word);++i)
    {
        if(wordCheck[i]=='_')
        {
            return;
        }
    }
    printf("congrats you win\n");
    exit(0);
}
void checkLoss(char* wrongLetterList)
{
    if(strlen(wrongLetterList)>=6)
    {
        printf("Aw you lose");
        exit(1);
    }
}
int main()
{
    char correctLetterList[27]="";
    char wrongLetterList[27]="";
    char letterList[27]="";
    char word[50];
    getWord(word);

    char wordCheck[strlen(word)];
    for (int i=0;i<strlen(word);i++)
    {
        wordCheck[i]='_';
    }
    wordCheck[strlen(word)]='\0';

    while(1)
    {
        enterLetter(word,wordCheck,letterList,wrongLetterList,correctLetterList);
        checkWin(word,wordCheck);
        checkLoss(wrongLetterList);
    }
}