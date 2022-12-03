#include <stdio.h>
int i, j, arr;

int func(int arr[5][5], int a, int b) {
  for (i = 0; i < a; i++) {
    for (j = 0; j < b; j++) {
      printf("Enter %d, %d element of matrix \n", i, j);
      scanf("%d", &arr[i][j]);
    }
  }
}

// For displaying the matrix stored in a,b
int display(int arr[5][5], int a, int b) {
  for (i = 0; i < a; i++) {
    for (j = 0; j < b; j++) {
      printf("%d\t", arr[i][j]);
    }
    printf("\n");
  }
}

// Function for Addition
int add(int m1[5][5], int m2[5][5], int a, int b) {
  int sum[5][5];
  for (i = 0; i < a; i++) {
    for (j = 0; j < b; j++) {
      sum[i][j] = m1[i][j] + m2[i][j];
    }
  }
  printf("\n");
  display(sum, a, b);
}

// For subtraction
int sub(int m1[5][5], int m2[5][5], int a, int b) {
  int sub[5][5];
  {
    for (i = 0; i < a; i++) {
      for (j = 0; j < b; j++) {
        sub[i][j] = m1[i][j] - m2[i][j];
      }
    }
  }
  printf("\n");
  display(sub, a, b);
}

// For Multiplication
int mul(int m1[5][5], int m2[5][5], int a, int b, int d) {

  int mul = 0;
  int res[5][5];
  for (i = 0; i < a; i++) {
    for (j = 0; j < d; j++) {
      for (int k = 0; k < b; k++) {
        mul = mul + m1[i][k] * m2[k][j];
        // (Cij = ai0*b0j+ ai1*b1j+.....)       k is increasing only
      }
      res[i][j] = mul;
      mul = 0;
    }
  }
  printf("\n");
  display(res, a, d);
}

// For Transpose
int trans(int m1[5][5], int a, int b) {
  int trans[5][5];
  {
    for (i = 0; i < a; i++) {
      for (j = 0; j < b; j++) {
        trans[j][i] = m1[i][j];
      }
    }
  }
  printf("\n");
  display(trans, a, b);
}

int main() {

  int a, b, c, d, sum[5][5];

  int m1[5][5];
  int m2[5][5];
  int res[5][5];

  printf("Enter the no of rows, coloumn of matrix 1\n");
  scanf("%d %d", &a, &b);

  printf("Enter the no of rows, coloumn of matrix 2\n");
  scanf("%d %d", &c, &d);

  if (a < 5 && b < 5 && c < 5 && d < 5 && (b == c)) {
    printf("\nEnter the elements of matrix 1 are\n");
    func(m1, a, b);
    printf("\nEnter the elements of matrix 2 are\n");
    func(m2, c, d);

    printf("\nThe elements of matrix 1 are\n");
    display(m1, a, b);

    printf("\nThe elements of matrix 2 are\n");
    display(m2, c, d);

    int choice;

  label:
    printf("Enter 1 for addition\nEnter 2 for Subtraction\nEnter 3 for "
           "Multiplication\nEnter 4 for Transpose\nEnter 0 to Exit!!\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("\n\nThe addition of matrix is as follow:\n");
      add(m1, m2, a, b);
      break;

    case 2:
      printf("\n\nThe subtraction of matrix is as follow:\n");
      sub(m1, m2, a, b);
      break;
    case 3:
      printf("\n\nThe multiplication of matrix is as follow:\n");
      mul(m1, m2, a, b, d);

      break;
    case 4:
      printf("\n\nFor Matrix 1 Press 1\nFor Matrix 2 Press 2\n");
      scanf("%d", &choice);
      if (choice == 1) {
        printf("\n\nThe Transpose of matrix 1 is as follow:\n");
        trans(m1, a, b);
      } else if (choice == 2) {
        printf("\n\nThe Transpose of matrix 2 is as follow:\n");
        trans(m2, a, b);
      }

      break;
    case 0:
      goto end;
    }

    goto label;
  } else {
    printf("The value of all rows & coloumn should be less than 5\nThe value "
           "of row and coloum should be equal should be equal to zero");
  }
end:

  return 0;
}
