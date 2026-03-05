#include <iostream>
#include <string.h>

typedef struct {
    char *nama;
    int size;
} DynamicArr;

void ubah_nama(DynamicArr *arr, char *nama_baru) {
  char *new_arr = (char*) malloc(strlen(arr->nama) + strlen(nama_baru) + 1);
  int last = 0;
  for(int i = 0; i < strlen(arr->nama); i++) {
    new_arr[last++] = arr->nama[i];
  }
  for(int i = 0; i < strlen(nama_baru); i++) {
    new_arr[last++] = nama_baru[i];
  }
  new_arr[++last] = '\0';
  arr->nama = new_arr;
  arr->size = strlen(new_arr);
};

int main() {
  DynamicArr *new_arr = (DynamicArr*) malloc(sizeof(DynamicArr));
  
}


