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
        }

//spaces
        if (isspace(character)) {
            spaces++;
        }

//words
        if(character==' ') {
            character--;
        }
        if (character!=' ') {
            words++;
        }
    }

    printf("File has %d lowercase letters\n",lower_caseL);
    printf("File has %d uppercase letters\n",upper_caseL);
    printf("File has %d digits\n",digits);
    printf("File has %d characters\n",allleters);
    printf("File has %d spaces\n",spaces);
    printf("File has %d words\n",words);
    printf("File has %d lines\n",lines);
    fseek(file, 0, SEEK_SET);
    char choise;
    do {
        printf("Do you want to encrypt(e) or decrypt(d) your file:");
        choise = getchar();
    }
    while (choise != 'e' && choise != 'E' && choise != 'd' && choise != 'D');

    do {
        printf("Choose shift number (1-26): ");
        scanf("%d", &shift);
    }
    while (shift <= 1 && shift >= 26);


    if (choise =='e' || choise == 'E') {
        output = fopen("decrypted.txt", "w");
        if (output == NULL) {
            printf("The output file could not be opened, exiting...\n");
            return EXIT_FAILURE;
        }

        printf("Encrypted text: ");
        while ((character = fgetc(file)) != EOF) {
            if (isalpha(character)) {
                if (islower(character)) {
                    char temp = (((character - 97)+shift)%26)+97;
                    if(temp > 122) {
                        temp -= 26;
                    }
                    fputc(temp, output);
                    fputc(temp, stdout);
                }
                else if (isupper(character)) {
                    char temp = (((character - 65)+shift)%26)+65;
                    if(temp > 90){
                        temp -= 26;
                    }
                    fputc(temp,output);
                    fputc(temp, stdout);
                }
            }
            else {
                fputc(character,output);
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
        while ((character = fgetc(file)) != EOF) {
            if (isalpha(character)) {
                if (islower(character)) {
                    char temp = (((character - 97)-shift)%26)+97;
                    if(temp < 97) {
                        temp += 26;
                    }
                    fputc(temp, output);
                    fputc(temp, stdout);
                }
                else if (isupper(character)) {
                    char temp = (((character - 65)-shift)%26)+65;
                    if(temp < 65){
                        temp += 26;
                    }
                    fputc(temp, output);
                    fputc(temp, stdout);
                }
            }
            else {
                fputc(character, output);
                fputc(character, stdout);
            }
        }
        printf("\n");
    }

    fclose(file);
    fclose(output);
    return 0;
}
