#include<stdio.h>

struct Profile
{
    char Name[40];
    int Roll;
    char Panel;
    float Marks;
    char Grade;
} b[10]; 
// B HAS BECOME GLOBAL STRUCTURE NOW

// ACCEPT FOR STRUCTURES
void accept(struct Profile s[10], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Name of student %d\n", i + 1);
        scanf(" %s", &s[i].Name); //  we can do the string without & also
        printf("Enter the Roll no of student %d\n", i + 1);
        scanf(" %d", &s[i].Roll);
        printf("Enter the Panel of student %d\n", i + 1);
        scanf(" %c", &s[i].Panel);
        printf("Enter the Marks of student %d\n", i + 1);
        scanf(" %f", &s[i].Marks);
        printf("Enter the Grade of student %d\n", i + 1);
        scanf(" %c", &s[i].Grade);
        printf("\n\n");
    }
}

// DISPLAY FOR STRUCTIRES
void display(struct Profile s[10], int n)
{
    printf("Name\t\t\ttRoll_no \t Panel \t\t Marks \t\t Grade\t\n");
    for (int i = 0; i < n; i++)
    {
        // printf("%s \t\t %d", s[i].Name, s[i].Roll);
        printf("%s \t\t\t%d \t\t %c \t\t %0.2f \t %c\n", s[i].Name, s[i].Roll, s[i].Panel, s[i].Marks, s[i].Grade);
        printf("\n");
    }
}

// DISPLAY OF SINGLE TARGETED STUDENT
void Display(struct Profile s[10], int i)
{
    // printf("Name of student: %s\tRoll no: %d\tPanel: %c\tMarks: %0.2f\tGrade: %c\n", s[a].Name, s[a].Roll, s[a].Panel, s[a].Marks, s[a].Grade);
    printf("Name\t\tRoll_no \t Panel \t\t Marks \t\t Grade\t\n");
    printf("%s \t\t%d \t\t %c \t\t %0.2f \t %c\n", s[i].Name, s[i].Roll, s[i].Panel, s[i].Marks, s[i].Grade);
    // printf("%s \t\t %d \t\t %c \t\t %0.2f \t\t %c \2n", s[a].Name, s[a].Roll, s[a].Panel, s[a].Marks, s[a].Grade);
    printf("\n");
}

// LINEAR SEARCH
int lin_search(struct Profile s[10], int n, int key)
{
    int pos, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (key == s[i].Roll)
        {
            pos = i;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

// BINARY SEARCH WITHOUT RECURSION
int bin_search(struct Profile s[10], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s[mid].Roll == key)
        {
            return mid;
        }
        else if (key < s[mid].Roll)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (low > high)
    {
        return -1;
    }
}

// BINARY SEARCH WITHOUT RECURSION
int bin_search_rec(struct Profile s[10], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s[mid].Roll == key)
        {
            return mid;
        }
        else if (key < s[mid].Roll)
        {
            return bin_search_rec(s, low, mid - 1, key);
        }
        else
        {
            return bin_search_rec(s, mid + 1, high, key);
        }
    }
    if (low > high)
    {
        return -1;
    }
}

// SENTINEL SEARCH
int sent_search(struct Profile s[10], int n, int key)
{
    s[n].Roll = key;
    int i = 0;
    while (key != s[i].Roll)
    {
        i++;
    }

    if (i < n)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

// SWAP FUNC FOR SWAPPING STRUCTURES
int swap(struct Profile s[10], int i, int j)
{
    struct Profile temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

// BUBBLE SORT
int bubble_sort(struct Profile s[10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (s[j].Roll > s[j + 1].Roll)
            {
                swap(s, j, j + 1);
            }
        }
    }
}

// SELECTION SORT
int selection_sort(struct Profile s[10], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (s[j].Roll < s[min_pos].Roll)
            {
                min_pos = j;
            }
        }
        if (min_pos != i)
        {
            swap(s, i, min_pos);
        }
    }
}

// INSERTION SORT
int insertion_sort(struct Profile s[10], int n)
{
    struct Profile key;
    for (int i = 1; i < n; i++)
    {
        key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].Roll > key.Roll)
        {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}

// SHELL SORT
void shell_sort(struct Profile s[10], int n)
{
    int gap = n;
    int swapped;
    {
        do
        {
            do
            {
                swapped = 0;
                for (int i = 0; i < n - gap; i++)
                {
                    if (s[i].Roll > s[i + gap].Roll)
                    {
                        swap(s, i, i + gap);
                        swapped = 1;
                    }
                }
            } while (swapped == 1);
        } while ((gap = gap / 2) >= 1);
    }
}

// BUCKET SORT
int bucket_sort(struct Profile s[10], int n)
{
    int i, j;
    int max = 100;
    int buck[100];
    // struct Profile bucket;

    for (int i = 0; i < max; i++)
    {
        // bucket= s[i];
        buck[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        ++buck[(s[j].Roll)];
    }

    for (int i = 0, j = 0; i < max; i++)
    {
        for (; buck[i] > 0; --buck[i])
        {
            s[j].Roll = i;
            j = j + 1;
        }
    }
}

// RADIX SORT
int radix_sort(struct Profile s[10], int n)
{
    int count[10];
    int bkt[10][20];
    int large = s[0].Roll;
    int bkt_no;
    for (int i = 0; i < n; i++)
    {
        if (s[i].Roll > large)
        {
            large = s[i].Roll;
        }
    }
    int pass = 0;
    while (large > 0)
    {
        pass++;
        large = large / 10;
    }

    int div = 1;
    for (int i = 1; i <= pass; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            count[j] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            bkt_no = (s[j].Roll / div) % 10;
            bkt[bkt_no][count[bkt_no]] = s[j].Roll;
            count[bkt_no]++;
        }

        int j = 0;
        for (bkt_no = 0; bkt_no <= 9; bkt_no++)
        {
            for (int k = 0; k < count[bkt_no]; k++)
            {
                s[j].Roll = bkt[bkt_no][k];
                j++;
            }
        }
        div = div * 10;
    }
}

// MERGE
int merge(struct Profile s[10], int low, int mid, int high)
{
    int h = low;
    int i = low;
    int j = mid + 1;
    while ((h <= mid && j <= high))
    {
        if (s[h].Roll <= s[j].Roll)
        {
            // COMPARISON WITH ROLL
            // ASSIGN WITH WHOLE STRUCTRURE
            b[i] = s[h];
            h = h + 1;
        }
        else
        {
            b[i] = s[j];
            j = j + 1;
        }
        i = i + 1;
    }
    if (h > mid)
    {
        for (int k = j; k < high; k++)
        {
            b[i] = s[k];
            i = i + 1;
        }
    }
    else
    {
        for (int k = h; k < mid; k++)
        {
            b[i] = s[k];
            i = i + 1;
        }
    }

    // FOR RETURNING THE VALUE TO ORIGNAL STRUCTURE
    for (int k = low; k < high; k++)
    {
        s[k] = b[k];
    }
}

// MERGE SORT
int merge_sort(struct Profile s[10], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(s, low, mid);
        merge_sort(s, mid + 1, high);
        merge(s, low, mid, high);
    }
}

int main()
{
    int n;                // no of students entry
    int key;              // roll no to find
    int r;                // to repeat the finding process
    struct Profile s[10]; // Array of Structures (LOCAL STRUCTURE)

    printf("Enter the no of students you wish to Enter\n");
    scanf("%d", &n);

    accept(s, n);
    display(s, n);

    // TEMPORARY STRUCT TO STORE INTIAL UNSORTED VALUES
    struct Profile temp[10];
    for (int i = 0; i < n; i++)
    {
        temp[i] = s[i];
    }

    int low = 0;
    int high = n - 1;
    int a; // Value returned by Functn
    int choice;
    int select;

label:
    printf("\nEnter 1 for Searching the Roll\nEnter 2 for Sorting the Roll\nENTER 0 TO UNSORT THE STRUCTURE\n");
    scanf("%d", &select);

    if (select == 1)
    {
        printf("Enter the Roll no. you wish to find\n");
        scanf("%d", &key);

        printf("\n\nEnter 1 for Linear Search\nEnter 2 for Non-rec Binary Search (I/P MUST BE SORTED)\nEnter 3 for Rec Binary Search (I/P MUST BE SORTED)\nEnterv 4 for Sentinel Search\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            a = lin_search(s, n, key);
            break;
        case 2:
            a = bin_search(s, low, high, key);
            break;
        case 3:
            a = bin_search_rec(s, low, high, key);
            break;
        case 4:
            a = sent_search(s, n, key);

            break;

        default:
            printf("You have entered Wrong Entry\n");
            break;
        }

        if (a == -1)
        {
            printf("Opps.... Sorry the Students record not found\n");
        }
        else
        {
            Display(s, a);
        }
    }

    else if (select == 2)
    {
        printf("\n\nEnter 1 For Bubble Sort\nEnter 2 For Selection Sort\nEnter 3 For Insertion Sort\nEnter 4 For Shell Sort\nEnter 5 for Bucket Sort\nEnter 6 for Radix Sort\nEnter 7 for Merge Sort\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubble_sort(s, n);
            printf("\nYeaaa!! the Students Roll no are sorted using Bubble Sort\n");
            break;

        case 2:
            selection_sort(s, n);
            printf("\nYeaaa!! the Students Roll no are sorted using Selection Sort\n");
            break;

        case 3:
            insertion_sort(s, n);
            printf("\nYeaaa!! the Students Roll no are sorted using Insertion Sort\n");
            break;

        case 4:
            shell_sort(s, n);
            printf("\nYeaaa!! the Students Roll no are sorted using Shell Sort\n");
            break;

        case 5:
            printf("\nYeaaa!! the Students Roll no are sorted using Bucket Sort\n");
            bucket_sort(s, n);
            break;

        case 6:
            printf("\nYeaaa!! the Students Roll no are sorted using Radix Sort\n");
            radix_sort(s, n);
            break;

        case 7:
            // // 0 , N-1 REPLACED BY LOW, HIGH
            merge_sort(s, low, high);
            printf("\nYeaaa!! the Students Roll no are sorted using Merge Sort\n");
            break;

        default:
            printf("Enter the Correct Entry\n");
            break;
        }
        display(s, n);
    }

    else if (select == 0)
    {
        for (int i = 0; i < n; i++)
        {
            s[i] = temp[i];
        }
        printf("\nYeaaa!! the Structure is Unsorted Again\n");
        display(s, n);
    }

label_2:
    printf("Enter 1 to continue & 0 zero to stop the program\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        goto label;
    }

    else if (choice == 0)
    {
        goto end;
    }

    else
    {
        printf("Enter the correct value\n");
        goto label_2;
    }

end:
    return 0;
}
