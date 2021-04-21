
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FSIZE 1000


int main(void){



  int character=0,words=0,lines=0,upper_caseL=0,lower_caseL=0,digits=0,shift=0,symbols=0,spaces=0,allleters=0;
    FILE* file ,*output;
    char filename[FSIZE];
    printf("Please enter the filepath of a file to analyze:");
    
    scanf("%s",filename);
  
    file= fopen(filename,"r");
    
    if (file==NULL) {
    printf("File is not available.");
    return 0;
  }
    
    
    
  // characters
while((character=fgetc(file))!=EOF) {
    symbols++;
 //lines
    if (character=='\n') {
        lines++;
        words++;
    }
    
 //lowercase letters
   if (islower(character)) {
      lower_caseL++;
      allleters++;
     }

 //uppercase letters
   if(isupper(character)){
      upper_caseL++;
          allleters++;
      }
    

 //digits
   if(isdigit(character)) {
          digits++;
       allleters++;
    }

//spaces
    if (isspace(character)) {
        spaces++;
        allleters++;
    }
    
//words
    if(character==' '){
        character--;
    if (character!=' ') {
        words++;
        }

        
   
    }
        
}

    printf("File has %d lowercase letters\n",lower_caseL);
    printf("File has %d uppercase letters\n",upper_caseL);
    printf("File has %d digits\n",digits);
    printf("File has %d characters\n",allleters);
    printf("File has %d spaces\n",spaces);
    printf("File has %d words\n",words);
    printf("File has %d lines\n",lines);
    char choise[1];
    printf("Do you want to encrypt(e) or decrypt(d) your file:%s",choise);
    scanf("%s",choise);
    if (*choise=='e'||*choise=='E'){
        }

            do {
                printf("Choose shift number (1-26): ");
                scanf("%d", &shift);
            }
            while (shift <= 1 && shift >= 26);
            if (file == NULL) {
                printf("The input file could not be opened, exiting...\n");
                return EXIT_FAILURE;
            }

    if (*choise=='e') {
                if (file == NULL) {
                    printf("The output file could not be opened, exiting...\n");
                    return EXIT_FAILURE;
                }

                printf("Encrypted text: ");
                while (character != EOF) {
                    if (isalpha(character)) {
                        if (islower(character)) {
                            char temp = (((character - 97)+shift)%26)+97;
                            if(temp > 122) {
                                temp -= 26;
                            }
                            fputc(temp, file);
                            fputc(temp, stdout);
                        }
                        else if (isupper(character)) {
                            char temp = (((character - 65)+shift)%26)+65;
                            if(temp > 90){
                                temp -= 26;
                            }
                            fputc(temp,file);
                            fputc(temp, stdout);
                        }
                    }
                    else {
                        fputc(character,file);
                        fputc(character, stdout);
                    }
                }
                printf("\n");
            }

            else {
                output = fopen("decrypted.txt", "w");
                if (output == NULL) {
                    printf("The output file could not be opened, exiting...\n");
                    return EXIT_FAILURE;
                }

                printf("Decrypted text: ");
                while (character!= EOF) {
                    if (isalpha(character)) {
                        if (islower(character)) {
                            char temp = (((character - 97)-shift)%26)+97;
                            if(temp < 97) {
                                temp += 26;
                            }
                            fputc(temp, file);
                            fputc(temp, stdout);
                        }
                        else if (isupper(character)) {
                            char temp = (((character - 65)-shift)%26)+65;
                            if(temp < 65){
                                temp += 26;
                            }
                            fputc(temp, file);
                            fputc(temp, file);
                        }
                    }
                    else {
                        fputc(character, file);
                        fputc(character, stdout);
                    }
                }
                printf("\n");
            }

    fclose(file);
            return 0;



}

