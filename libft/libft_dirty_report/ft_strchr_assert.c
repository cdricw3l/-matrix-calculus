#include "assertion.h"

void ft_strchr_test(int test_nb, char *s, int c)
{
    char *p1;
    char *p2;
    printf("Test %d:\n", test_nb);
    p1 = strchr(s,c);
    p2 = ft_strchr(s,c);
    if(p1 == p2)
        printf("\toriginal function -> %p\n\tft fonction -> %p\n\tresult -> " TEST_OK "\n", p1, p2);
    else
        printf("\toriginal function -> %p\n\tft fonction -> %p\n\tresult -> " TEST_NOK "\n", p1, p2);
    

}


void ft_strchr_assert(void)
{

    TEST_STAR("ft_strchr");

    char *str;
    int test_nb;

    test_nb = 1;
    str = ft_strdup("hello_berlin");
    assert(str);
    // Test 1
    ft_strchr_test(test_nb++, str, 'x');
    // Test 2
    ft_strchr_test(test_nb++, str, 'h');
    // Test 3
    ft_strchr_test(test_nb++, str, 'l');
    // Test 4
    ft_strchr_test(test_nb++, str, 'b');
    // Test 5
    ft_strchr_test(test_nb++, str, '\0');
    free(str);
    str = ft_strdup("");
    assert(str);
    // Test 6
    ft_strchr_test(test_nb++, str, '\0');
    // Test 7
    ft_strchr_test(test_nb++, str, 'A');
    free(str);
    // Test 8
    char s[] = "tripouille"; 
    ft_strchr_test(test_nb++, s, 't' + 256);

    char s0[] = {-10, -12, -127, 32, 97, 98};
    // Test 9
    // attention  bien caster la source en unsigned char -> man : Here "character" means "byte"; these functions do not work with wide or multibyte characters.
    ft_strchr_test(test_nb++, s0, -127);
    char s1[] = {-10, -12, -127, 32, 97, 98,'\0'};
    // Test 10
    ft_strchr_test(test_nb++, s1, INT_MAX);

    NL;
    TEST_END("ft_strchr");
    SEP;
    NL;

}