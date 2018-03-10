#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//разложение числа на простые сомножители

#define STEP 10 // шаг расширения динамического массива

int check(){
    char c;
    while( isspace(c = getchar()) );
    if(c == '-')
        return 0;
    else
        ungetc(c, stdin);
    return 1;
}

long long* decompose(long long n) // разложение на простые множители
{
    long long  i = 2;
    size_t size = STEP;
    long long* mas = (long long*) calloc(size, sizeof(long long));
    size_t j = 0;
    mas[0] = 1;
    while (n>1){
        while (n % i == 0){
            n /= i;
            mas[++j] = i;
            if ( j == size-1){
                size +=STEP;
                mas = realloc(mas, sizeof(long long)*size);
            }
        }
        ++i;
    }
    mas = realloc(mas, (j+2)*sizeof(long long)); //+1 т.к j-это индекс. и ещё +1 чтобы последний элемент был 0
    mas[j+1] = 0; // добавляем ноль в качестве последнего элемента массива
    return mas;
}

int main() {
    long long  n = 0;
    char string[20];
    char* p;
    scanf("%s", string);
    for(p = string; isdigit(*p) && *p != '\0';++p)
        ;
    if (*p != '\0'){
        printf("[error]");
        return 0;
    }
    char* end;
    if( (n = strtoull(string, &end, 10)) == 0 ){
        printf("[error]");
        return 0;
    }

//    int status = check();
//    if( status==0 ){
//        printf("[error]");
//        return 0;
//    }
//    if(!scanf("%llu", &n) || n == 0) {
//        printf("[error]");
//        return 0;
//    }
    //printf("%llu ", n);
    size_t i = 0;
    long long* mas = decompose(n);
    while(mas[i] != 0){
        printf("%llu ", mas[i]);
        ++i;
    }
    free(mas);
    return 0;
}
