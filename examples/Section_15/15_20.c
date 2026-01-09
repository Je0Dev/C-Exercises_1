#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

typedef struct 
{
      char name[LEN];
      char category[LEN];
      char singer[LEN];
      int records;
} band; 

int read_text(char str[], int size, int flag);

int main(void)
{
      FILE *fp;
      band *band_arr;
      char found, name[LEN], singer[LEN];
      int i, band_num;

      fp = fopen("test.bin", "r+b"); 
      if(fp == NULL)
      {
            printf("Error: fopen() failed\n");
            exit(EXIT_FAILURE);
      }
      if(fread(&band_num, sizeof(int), 1, fp) != 1) 
      {
		fclose(fp);
            printf("Error: fread() failed\n");
		exit(EXIT_FAILURE);
      }
      band_arr = (band*) malloc(sizeof(band) * band_num); 
      if(band_arr == NULL)
      {
		fclose(fp);
            printf("Error: Not available memory\n");
            exit(EXIT_FAILURE);
      }
      if(fread(band_arr, sizeof(band), band_num, fp) == band_num) 
      {
            printf("Enter band name: ");
		read_text(name, sizeof(name), 1);

            printf("Enter new singer: ");
		read_text(singer, sizeof(singer), 1);

            found = 0;
            for(i = 0; i < band_num; i++)
                  if(strcmp(band_arr[i].name, name) == 0)
                  {
                        fseek(fp, i*sizeof(band), SEEK_SET); /* If the band is found, move the file pointer to the beginning of the structure. */
                        strcpy(band_arr[i].singer, singer); /* Change the singer and write the structure in the current position. */
                        fwrite(&band_arr[i], sizeof(band), 1, fp);
				printf("\n%Singer of band %s is changed to %s\n", name, singer);
                        found = 1;
                        break;
                  }
      }
      else 
            printf("Error: fread() failed to read bands\n");

      if(found == 0)
            printf("\n%s band isn't found\n\n", name);

      free(band_arr);
      fclose(fp); 
      return 0;
}
