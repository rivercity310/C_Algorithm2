#ifndef __SORT_H
#define __SORT_H

void prt_arr(const int a[], int n);
void histo(int n);

static int* memalloc(int n);
static void Sort(void(*fp)(int*, int), int ch);

/* Sort.c */

void bubble_sort(int a[], int n);
void bubble_sort2(int a[], int n);
void bubble_sort3(int a[], int n);

void insertion_sort(int a[], int n);
void selection_sort(int a[], int n);

void shell_sort(int a[], int n);
void shell_sort2(int a[], int n);

void quick_sort(int a[], int left, int right);
int merge_sort(int a[], int n);

void struct_ary();
#endif