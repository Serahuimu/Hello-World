四頁玫瑰數，得到每一位，每一位求四次方再相加
```c
#include <stdio.h>
#include <math.h>
int main(void)
{
    int i, j;
    for (i = 1000; i < 10000; i++)
    {
        int sum = 0;
        for (j = 1; j <= i; j *= 10)
        {
            sum += pow(i / j % 10, 4);
        }
        if (sum == i)
            printf("%d\n", i);
    }

    return 0;
}
```


輸入10個數，冒泡排序
```c
#include <stdio.h>
#define N 10
void sort(int arr[], int len)
{
    int i, j;
    for (i = 0; i < len - 1; i ++)
    {
        for (j = 0; j < len - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main(void)
{
    int arr[N];
    int i, j;
    for (i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, N);

    for (j = 0; j < N; j++)
    {
        printf("%d ", arr[j]);
        if (j == 4)             //這裏錯寫成了n == 4
            putchar('\n');
    }
    return 0;
}
```

輸入正整數，求位數，且順序和逆序打印出各位
```c
#include <stdio.h>
//正序
void f(int n)
{
    if (n > 9)
        f(n / 10);
    printf("%d ", n % 10);
}
//逆序
void g(int n)
{
    if (n == 0)
        return;
    printf("%d ", n % 10);
    g(n / 10);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    f(n);
    putchar('\n');
    g(n);

    return 0;
}
```

輸入體重w和身高h，輸出身體體重指數BIM = w / (h * h)；
若BMI < 18.5 判斷偏輕；18.5 <= BMI <= 23.9判斷正常；
23.9 < BMI <= 27.9，判斷超重；BMI > 27.9判斷肥胖

```c
#include <stdio.h>
int main(void)
{
    double w, h, bmi;
    scanf("%lf%lf", &w, &h);        //這個scanf()又踩坑了，裏面怎麽寫就怎麽輸入
    bmi = w / (h * h);
    if (bmi < 18.5)
        puts("偏輕");
    else if (18.5 <= bmi && bmi < 23.9)
        puts("正常");
    else if (23.9 < bmi && bmi<= 27.9)
        puts("超重");
    else if (bmi > 27.9)
        puts("肥胖");
    return 0;
}
```