//
//  main.c
//  proghw01
//  CSCI 356
//
//  Created by Jorden Hodges on 2/27/20.
//  Copyright © 2020 Jorden Hodges. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    char content;
    FILE *file1, *file2;
    int comparison = strncmp("copy", argv[1], 4);
    if(comparison == 0)
    {
        if(access(argv[3], W_OK) == 1)
        {
            file1 = fopen(argv[2], "r");
            file2 = fopen(argv[3], "w");
            if(file1 != NULL)
            {
                content = fgetc(file1);
                while(content != EOF)
                {
                    fputc(content, file2);
                    content = fgetc(file1);
                }
            }
            else
            {
                printf("\"%s\" This file does not exist\n", argv[2]);
                exit(0);
            }
        }
        else
        {
            printf("\"%s\" You do not have permisions to write in this location\n", argv[3]);
            exit(0);
        }
        return 0;
    }
    else
    {
        printf("Command %s not supported", argv[1]);
        exit(0);
    }
}
