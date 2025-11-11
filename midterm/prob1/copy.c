#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    
    FILE *source_fp, *dest_fp;
    int ch;
    
    char *option;
    char *source_path;
    char *dest_path;
    char *open_mode;
    int convert_flag = 0; 
    
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [option] <sourcefile> <destfile>\n", argv[0]);
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "  0: Simple copy (overwrite)\n");
        fprintf(stderr, "  1: Uppercase copy (overwrite)\n");
        fprintf(stderr, "  2: Uppercase copy (append)\n");
        exit(1);
    }
    
    
    option = argv[1];
    source_path = argv[2];
    dest_path = argv[3];
    
    
    if (strcmp(option, "0") == 0) {
        
        open_mode = "w";
        convert_flag = 0;
    } else if (strcmp(option, "1") == 0) {
        open_mode = "w";
        convert_flag = 1;
    } else if (strcmp(option, "2") == 0) {
        open_mode = "a";
        convert_flag = 1;
    } else {

        fprintf(stderr, "Error: Invalid option '%s'. Must be 0, 1, or 2.\n", option);
        exit(1);
    }
    
    
    if ((source_fp = fopen(source_path, "r")) == NULL) {
        fprintf(stderr, "Error: Cannot open source file '%s'\n", source_path);
        exit(1);
    }
    
    
    if ((dest_fp = fopen(dest_path, open_mode)) == NULL) {
        fprintf(stderr, "Error: Cannot open destination file '%s'\n", dest_path);
        fclose(source_fp);
        exit(1);
    }
    
    
    while ((ch = fgetc(source_fp)) != EOF) {
        
        
        if (convert_flag == 1) {
            ch = toupper(ch);
        }
        
        fputc(ch, dest_fp);
    }
    
   
    printf("Task complete.\n");
    fclose(source_fp);
    fclose(dest_fp);
    
    return 0;
}
