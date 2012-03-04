/**
    Copyright (C) 2012 Edward Chernysh

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

**/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef SUCCESS
#define SUCCESS (0)
#endif

const char alphabet[] = {
                              'a', 'b','c','d',
                              'e', 'f', 'g', 'h',
                              'i', 'j', 'k', 'l', 
                              'm', 'n', 'o', 'p',
                              'q', 'r', 's', 't',
                              'u', 'v', 'w', 'x',
                              'y', 'z', '1', '2',
                              '3', '4', '5', '6',
                              '7', '8', '9', '{', '}',
                   };
int count = 0;
int buffer = 0;
int i = 0;

int main(int argc, char *argv[]) {
    if (argc < 2) {             
             printf("-d <string>\tDecrypt a string\n");
             printf("-e <string>\tEncrypt a string\n");
             printf("\nerror: not input\n");
  } else {
    
      int c;
      while (--argc > 0 && (*++argv)[0] == '-')
            c = *++argv[0];
      switch (c) {             
             case 'd':    
                      printf("...\n");                      
                      char data[strlen(argv[0])];
                      strcpy(data, argv[0]);                      
                      char decrypted[strlen(argv[0])];
                      decrypted[strlen(argv[0])] = '\0';
                      for (count = 0; count < sizeof(data); count++)
                      {
                          
                          for (buffer = 0; buffer < (sizeof(alphabet) - 2); buffer++) {
                              if (data[count] == alphabet[buffer])
                                 decrypted[count] = alphabet[buffer - 2];
                          }
                      }
                     
                      for (i = 0; i < sizeof(decrypted); i++)
                          printf("%c", decrypted[i]);
                      printf("\n");    
                      break;
            case 'e':
                     printf("...\n");
                     char edata[strlen(argv[0])];
                     strcpy(edata, argv[0]);
                     char encrypted[strlen(argv[0])];
                     
                     for (count = 0; count < sizeof(edata); count++)
                     {                          
                          for (buffer = 0; buffer < (sizeof(alphabet) - 2); buffer++) {
                              if (edata[count] == alphabet[buffer])
                                 encrypted[count] = alphabet[buffer + 2];
                          }
                     }
                     for (i = 0; i < sizeof(encrypted); i++)
                          printf("%c", encrypted[i]);
                     printf("\n");   
            break;
            default:
                    printf("segmentation fault\n");
            break;
      }
  }     
    
    
    printf("...\n");
    getchar();  
    return SUCCESS; 
}
