#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strCheck(const char array[], const char subArray[]);
int arraySize(const char* array);

int main(int argc, char** argv)
{
  char stringg[]={"HELLO WORLD"};
  char subString[]={"HELLO"};

  if(strCheck(stringg, subString)==NULL)
  {
    printf("'%s' is not a substring of '%s'\n", subString, stringg);
  }
  else
  {
    printf("'%s' is a substring of '%s'\n", subString, stringg);
  }

  return 0;
}

int arraySize(const char* array)
{
  const char* ptr;
  int i=0;

  for(ptr=array; *(ptr)!='\0'; ptr++)
    i++;

  return i;
}

char* strCheck(const char array[], const char subArray[])
{

  int cmpArray=0, cmpSubArray=0;
  int arrSize=arraySize(array), subArraySize=arraySize(subArray);

  const char *ptr, *qtr;
  char* arrayToReturn=(char*)malloc(sizeof(char)*subArraySize);

  qtr=subArray;

  for(ptr=array; ptr<array+arrSize && *ptr!='\0'; ptr++)
  {
    cmpArray++;
      if(*(ptr)==*(qtr))
      {
        for(qtr=subArray; qtr<subArray+subArraySize && *qtr!='\0'; qtr++)
        {
          if(*(qtr)==*(ptr))
          {
            cmpSubArray++;
            ptr++;
          }
          else
          {
            free(arrayToReturn);
            return NULL;
          }
        }
        if(cmpSubArray==subArraySize)
        {
          strcpy(arrayToReturn, subArray);
          return arrayToReturn;
        }
      }
  }

  free(arrayToReturn);
  return NULL;
}
