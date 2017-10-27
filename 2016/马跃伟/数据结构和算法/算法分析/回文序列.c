#include <stdio.h>
#include <string.h>
int Palindrome(char *Str);
int Palindrome1(char *Str);
int main()
{
    char *s = "abdba";
    char *s1 = "good";
    printf("%d,%d",Palindrome(s), Palindrome(s1));
     printf("%d,%d",Palindrome1(s), Palindrome2(s1));
    return 0;
}
int Palindrome(char *Str)     //直接验证的办法
{
    int len = strlen(Str);
    int i;
    for(i = 0;i < len/2;i++)
        if(Str[i] != Str[len-i-1])
            return 0;
    return 1;

}
//还可以使用翻转然后和原字符串比较是否相同，使用strrev()和strcmp()函数就好
