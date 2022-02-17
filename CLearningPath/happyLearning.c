/*
    practical set: https://blog.csdn.net/fjinhao/article/details/46853171
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void q2_1(void) {
    int cm = 0;
    int foot = 0;
    int inch = 0;

    scanf("%d", &cm);

    foot = cm / 30.48;
    inch = (cm / 30.48 - foot) * 12;

    printf("%d %d\n", foot, inch);
}

void q2_2(void) {
    int time;
    int increment;

    scanf("%d%d", &time, &increment);

    int hour = time / 100;
    int resultMinutes = hour * 60 + (time % 100) + increment;

    int result = (resultMinutes / 60) * 100 + resultMinutes % 60;

    printf("%d", result);
}

void q2_3(void) {
    int num;
    scanf("%d", &num);

    int a = num / 100;
    int b = num % 100 / 10;
    int c = num % 10;

    int result = c * 100 + b * 10 + a;

    printf("%d", result);
}

void q2_4(void) {
    int wrong;
    scanf("%d", &wrong);

    int result = wrong / 16 * 10 + wrong % 16;

    printf("%d", result);
}

void q3_1(void) {
    int n;
    scanf("%d", &n);

    if(n % 5 == 4 || n % 5 == 0) {
        printf("Drying in day %d\n", n);
    }
    else {
        printf("Fishing in day %d\n", n);
    }
}

void q3_2(void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if(a == b) {
        printf("C");
    }
    else if(a == c) {
        printf("B");
    }
    else {
        printf("A");
    }
}

void q3_3(void) {
    int hour_24;
    int minute;

    scanf("%d:%d", &hour_24, &minute);

    if(hour_24 == 12) {
        printf("12:%d PM\n", minute);
    }
    else if(hour_24 < 12) {
        printf("%d:%d PM\n", hour_24, minute);
    }
    else {
        printf("%d:%d PM\n", hour_24 - 12, minute);
    }
}

void q3_4(void) {
    int score;
    char tier;

    scanf("%d", &score);
    int state = score / 10;

    switch(state) {
        case 10:
        case 9:
            tier = 'A';
            break;
        case 8:
            tier = 'B';
            break;
        case 7:
            tier = 'C';
            break;
        case 6:
            tier = 'D';
            break;
        default:
            tier = 'E';
    }

    printf("%c\n", tier);
}

// select 4 contiguous digits from 1 - 9,
// print all numbers consisting of 3 different digits in format
void q4_0(void) {
    int a;
    scanf("%d", &a);

    int m1, m2, m3;
    int cnt = 0;

    for(m1 = a; m1 < a + 4; m1++)
        for(m2 = a; m2 < a + 4; m2++)
            for(m3 = a; m3 < a + 4; m3++) {
                if(m1 != m2 && m1 != m3 && m2 != m3) {
                    cnt++;
                    printf("%d", m1 * 100 + m2 * 10 + m3);
                    if(cnt % 6 != 0) {
                        printf(" ");
                    }
                    else {
                        printf("\n");
                    }
                }
            }

}

// ˮ�ɻ���
void q4_1(void) {
    int N;
    scanf("%d", &N);

    int begin = 1;
    for(int i = 1; i < N; i++) {
        begin *= 10;
    }
    int end = begin * 10 - 1;

    while(begin <= end) {
        int t = begin;
        int result = 0;
        for(int i = N; i > 0; i--) {
            int last = t % 10;
            int tmp = 1;
            for(int j = N; j > 0; j--) {
                tmp *= last;
            }
            result += tmp;
            t /= 10;
        }

        if(result == begin) {
            printf("%d\n", begin);
        }
        begin++;
    }
}

void q4_3(void) {
    int m, n;
    int num;
    int cnt = 0;
    int sum = 0;

    scanf("%d%d", &m, &n);

    for(num = m; num <= n; num++) {
        // check a number is a prime number or not
        int isPrime = 1;
        for(int i = 2; i < num; i++) {
            if(num % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime) {
            cnt++;
            sum += num;
        }
    }

    printf("%d %d", cnt, sum);
}

void q4_4(void) {
    srand(time(0));
    int num  = rand() % 100 + 1;
    int guess;
    int roll = 0;
    const int N = 7;

    while(1) {
        scanf("%d", &guess);
        roll++;
        if(roll > N) {
            printf("Game Over\n");
            break;
        }
        else if(guess < 0) {
            printf("Game Over\n");
            break;
        }

        if(guess == num) {
            if(roll == 1) {
                printf("Bingo!\n");
            }
            else if (roll <= 3) {
                printf("Lucky You!\n");
            }
            else {
                printf("Good Guess!\n");
            }
            break;
        }
        else {
            if(guess < num) {
                printf("Small\n");
            }
            else {
                printf("Big\n");
            }
        }
    }
}

void q5_0(void) {
    int n;
    double result = 0.0;
    double num = 2.0;
    double deno = 1.0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        result += num / deno;
        double tmp = num;
        num += deno;
        deno = tmp;
    }
    printf("%.2lf\n", result);
}

int euclid(int a, int b) {
    int remain = 0;

    if(a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    do {
        remain = a % b;
        a = b;
        b = remain;
    }while(remain != 0);

    return a;
}

void q5_1(void) {
    int num;
    int deno;

    scanf("%d/%d", &num, &deno);
    int remain = euclid(num, deno);

    printf("%d/%d\n", num / remain, deno / remain);

}

void q5_2() {
    // refer to the solution of the resource
}

void q5_3(void) {
    int a, n;
    int sum = 0;
    int num = 0;
    int j = 1;

    scanf("%d%d", &a, &n);

    for(int i = 0; i < n; i++) {
        num += a * j;
        sum += num;
        j *= 10;
    }

    printf("%d\n", sum);
}

void q6_2() {
    // finish after string learning
}

void q6_3(void) {
    char prev = ' ';
    char curr;
    int ret[30] = {0};
    int cntWord = 0;
    int cntLetter = 0;

    scanf("%c", &curr);
    while(curr != '.') {
        if(curr != ' ') {
            if(prev == ' ') {
                cntLetter = 1;
                cntWord++;
            }
            else {
                cntLetter++;
            }
        }
        else {
            if(prev != ' ') {
                ret[cntWord - 1] = cntLetter;
                cntLetter = 0;
            }
        }
        prev = curr;
        scanf("%c", &curr);
    }
    ret[cntWord - 1] = cntLetter;

    for(int i = 0; i < cntWord; i++) {
        printf("%d\t", ret[i]);
    }
    printf("\n");
}

void q7_0(void) {
    // finish after string
}

void q7_1(void) {
    int a;
    char ret[50];
    int index = 0;
    int digits[3] = {0};
    const int maxDigitsNum = 3;

    scanf("%d", &a);

    for(int i = 0; i < maxDigitsNum; i++) {
        digits[i] = a % 10;
        a /= 10;
    }

    for(int i = 0; i < digits[2]; i++) {
        ret[index++] = 'B';
    }

    for(int i = 0; i < digits[1]; i++) {
        ret[index++] = 'S';
    }

    for(int i = 0; i < digits[0]; i++) {
        ret[index++] = '1' - 1 + (i + 1);
    }

    for(int i = 0; i < index; i++) {
        printf("%c", ret[i]);
    }

    printf("\n");
}

void q8_0(void) {
    int N;
    int X;
    scanf("%d%d", &N, &X);

    int nums[N];
    int ret = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
        if(nums[i] == X)
            ret = i;
    }

    if(ret)
        printf("%d\n", ret);
    else
        printf("NOT FOUND\n");
}

void q8_1(void) {
    int N;
    int num;
    int digit[10] = {0};

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &num);

        if(num == 0)
            digit[0]++;
        else {
            while(num != 0) {
                digit[num % 10]++;
                num /= 10;
            }
        }
    }

    int max = digit[0];
    for(int i = 1; i < 10; i++) {
        if(max < digit[i])
            max = digit[i];
    }
    printf("%d:", max);
    for(int i = 0; i < 10; i++) {
        if(max == digit[i])
            printf(" %d", i);
    }
}

int main() {
    q8_1();

    return 0;
}