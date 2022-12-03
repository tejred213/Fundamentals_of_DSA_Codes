#include <stdio.h>

int mat(int arr[10][10], int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("Enter the %d, %d element of the matrix\n", i, j);
      scanf("%d", &arr[i][j]);
    }
  }
}

int display(int arr[10][10], int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d", arr[i][j]);
      printf("\t");
    }
    printf("\n");
  }
}

int Display(int arr[25][3], int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d", arr[i][j]);
      printf("\t");
    }
    printf("\n");
  }
}

int sparse(int arr[10][10], int r, int c, int spar[25][3]) {
  int k = 1;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (arr[i][j] != 0) {
        spar[k][0] = i;
        spar[k][1] = j;
        spar[k][2] = arr[i][j];
        k++;
      }
    }
  }
  spar[0][0] = r;
  spar[0][1] = c;
  spar[0][2] = k - 1;
  return k;
}

// SIMPLE TRANSPOSE
void simp_transpose(int spar[25][3], int simp[25][3]) {
  int z, k;
  int n = 1;
  for (z = 0; z < spar[0][1] /*total no. of col in orignal mat (max value we are
                                looking for) */
       ;
       z++) {
    for (k = 1; k <= spar[0][2] /*total now of rows in sparse*/; k++) {
      if (spar[k][1] == z) {
        simp[n][0] = spar[k][1];
        simp[n][1] = spar[k][0];
        simp[n][2] = spar[k][2];
        n++;
      }
    }
  }
  simp[0][0] = spar[0][1];
  simp[0][1] = spar[0][0];
  simp[0][2] = spar[0][2];
}

// FAST TRANSPOSE
void fast_transpose(int spar[25][3], int fast[25][3]) {
  int t[spar[0][1]];
  int s[spar[0][1] + 1];
  int n, col_no;
  // INDEX=S, TOTAL =T
  for (int i = 0; i < spar[0][1]; i++) {
    t[i] = 0;
  }
  for (int i = 1; i <= spar[0][2]; i++) {
    col_no = spar[i][1];
    t[col_no]++;
  }
  s[0] = 1;
  for (int i = 1; i <= spar[0][1]; i++) {
    s[i] = s[i - 1] + t[i - 1];
  }

  for (int i = 1; i <= spar[0][2]; i++) {
    col_no = spar[i][1];
    int k = s[col_no];
    fast[k][0] = spar[i][1];
    fast[k][1] = spar[i][0];
    fast[k][2] = spar[i][2];
    s[col_no]++;
  }

  fast[0][0] = spar[0][1];
  fast[0][1] = spar[0][0];
  fast[0][2] = spar[0][2];
}

int main() {
  int r, c;
  int arr[10][10];
  int spar[25][3];
  int simp[25][3];
  int fast[25][3];
  int k, z;
  printf("Enter the no of Rows of the Matrices\n");
  scanf("%d", &r);

  printf("Enter the no of Rows of the Matrices\n");
  scanf("%d", &c);

  if (r <= 10 & c <= 10) {

    printf("\n");
    mat(arr, r, c);

    printf("\n\n");
    printf("The Elements of matrix are:\n");
    display(arr, r, c);

    printf("\n\n");
    printf("The Elements of Sparse matrix are:\n");
    k = sparse(arr, r, c, spar);
    Display(spar, k, 3);

    int choice;
    printf("\n\nEnter 1 for Simple Transpose of Sparse Matrix\nEnter 2 for "
           "Fast Transpose of Sparse Matrix\n");
    scanf("%d", &choice);
  label:
    switch (choice) {
    case 1:
      printf("\n\nThe Simple Transpose of Sparse matrix is as follow:\n");
      simp_transpose(spar, simp);
      Display(simp, k, 3);
      break;

    case 2:
      printf("\n\nThe Fast Transpose of Sparse matrix is as follow:\n");
      fast_transpose(spar, fast);
      Display(fast, k, 3);
      break;

    default:
      printf("You have Enter the Wrong Input");
      break;
    }
    printf("\n\nIf You Wish to Exit Enter 0\nEnter 1 for Simple Transpose of "
           "Sparse Matrix\nEnter 2 for Fast Transpose of Sparse Matrix\n");
    scanf("%d", &choice);
    if (choice != 0) {
      goto label;
    }
  }

  else {
    printf("The value of Rows & Coloumn should be Less than 10");
  }

  printf("The Addition of the sparse matrices is ");
  return 0;
}