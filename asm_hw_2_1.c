/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_hw_2_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:37:26 by ioleinik          #+#    #+#             */
/*   Updated: 2023/01/18 00:33:55 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc asm_hw_2_1.c -Wall -Wextra -Werror

#include <stdio.h>

// Some C compilers won’t accept keyword __asm__
// If we want to compile with compiler other than GCC, we do
// define alternative keyword as macro to replace it with the custom keyword.

#ifndef __GNUC__
#define __asm__ asm
#endif

int main(void)
{
	int d1 = 10;
	int d2 = 20;
	int res;

	__asm__(
		"   mov   %[myd1], %[myres]\n"
		"   imul  %[myd2], %[myres]\n"
		: [myres] "=&r"(res)
		: [myd1] "r"(d1), [myd2] "r"(d2));

	printf("The result is %d\n", res);

	return 0;
}