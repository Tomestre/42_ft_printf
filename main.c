#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int main(void)
{
    int ft_printf_result;
    int printf_result;

    // Função auxiliar para exibir resultados
    void show_results(const char *test_name, int ft_result, int std_result) {
        printf("%s\n", test_name);
        printf("ft_printf retornou: %d\n", ft_result);
        printf("printf retornou: %d\n\n", std_result);
    }

    // Teste 1: Caractere ('c')
    ft_printf_result = ft_printf("Caractere: %c\n", 'A');
    printf_result = printf("Caractere: %c\n", 'A');
    show_results("Teste de caractere ('c')", ft_printf_result, printf_result);

    // Teste 2: String ('s')
    ft_printf_result = ft_printf("String: %s\n", "Hello, world!");
    printf_result = printf("String: %s\n", "Hello, world!");
    show_results("Teste de string ('s')", ft_printf_result, printf_result);

    // Teste 3: Ponteiro ('p')
    void *ptr = (void *)0x12345678;
    ft_printf_result = ft_printf("Ponteiro: %p\n", ptr);
    printf_result = printf("Ponteiro: %p\n", ptr);
    show_results("Teste de ponteiro ('p')", ft_printf_result, printf_result);

    // Teste 4: Inteiro positivo ('d' e 'i')
    ft_printf_result = ft_printf("Inteiro positivo: %d\n", 42);
    printf_result = printf("Inteiro positivo: %d\n", 42);
    show_results("Teste de inteiro positivo ('d')", ft_printf_result, printf_result);

    // Teste 5: Inteiro negativo ('d' e 'i')
    ft_printf_result = ft_printf("Inteiro negativo: %i\n", -42);
    printf_result = printf("Inteiro negativo: %i\n", -42);
    show_results("Teste de inteiro negativo ('i')", ft_printf_result, printf_result);

    // Teste 6: Número sem sinal ('u')
    ft_printf_result = ft_printf("Número sem sinal: %u\n", 123456);
    printf_result = printf("Número sem sinal: %u\n", 123456);
    show_results("Teste de número sem sinal ('u')", ft_printf_result, printf_result);

    // Teste 7: Hexadecimal minúsculo ('x')
    ft_printf_result = ft_printf("Hexadecimal minúsculo: %x\n", 255);
    printf_result = printf("Hexadecimal minúsculo: %x\n", 255);
    show_results("Teste de hexadecimal minúsculo ('x')", ft_printf_result, printf_result);

    // Teste 8: Hexadecimal maiúsculo ('X')
    ft_printf_result = ft_printf("Hexadecimal maiúsculo: %X\n", 255);
    printf_result = printf("Hexadecimal maiúsculo: %X\n", 255);
    show_results("Teste de hexadecimal maiúsculo ('X')", ft_printf_result, printf_result);

    // Teste 9: Porcentagem ('%')
    ft_printf_result = ft_printf("Porcentagem: %%\n");
    printf_result = printf("Porcentagem: %%\n");
    show_results("Teste de porcentagem ('%%')", ft_printf_result, printf_result);

    // Teste 10: Combinação de formatos
    ft_printf_result = ft_printf("Combinação: %c %s %d %x %p %%\n", 'B', "Test", 123, 456, ptr);
    printf_result = printf("Combinação: %c %s %d %x %p %%\n", 'B', "Test", 123, 456, ptr);
    show_results("Teste de combinação de formatos", ft_printf_result, printf_result);

    // Teste 11: String nula ('s')
    ft_printf_result = ft_printf("String nula: %s\n", NULL);
    printf_result = printf("String nula: %p\n", NULL);
    show_results("Teste de string nula ('s')", ft_printf_result, printf_result);

    // Teste 12: Ponteiro nulo ('p')
    ft_printf_result = ft_printf("Ponteiro nulo: %p\n", (void *)NULL);
    printf_result = printf("Ponteiro nulo: %p\n", (void *)NULL);
    show_results("Teste de ponteiro nulo ('p')", ft_printf_result, printf_result);

    return 0;
}