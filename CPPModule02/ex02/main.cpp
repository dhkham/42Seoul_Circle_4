/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:59:59 by dkham             #+#    #+#             */
/*   Updated: 2023/10/05 11:58:21 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    
    // make new variables and test arithmetic operators
    Fixed c(10);
    Fixed d(20);
    Fixed d_2(0);
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "c + d = " << c + d << std::endl;
    std::cout << "c - d = " << c - d << std::endl;
    std::cout << "c * d = " << c * d << std::endl;
    std::cout << "c / d = " << c / d << std::endl;
    //std::cout << "c / d_2 = " << c / d_2 << std::endl;
    
    // make new variables and test comparison operators
    Fixed e(10);
    Fixed e_2(10);
    Fixed f(20);
    std::cout << "e = " << e << std::endl;
    std::cout << "f = " << f << std::endl;
    std::cout << "e > f = " << (e > f) << std::endl;
    std::cout << "e < f = " << (e < f) << std::endl;
    std::cout << "e >= f = " << (e >= f) << std::endl;
    std::cout << "e <= f = " << (e <= f) << std::endl;
    std::cout << "e >= e_2 = " << (e >= e_2) << std::endl;
    std::cout << "e <= e_2 = " << (e <= e_2) << std::endl;
    std::cout << "e == f = " << (e == f) << std::endl;
    std::cout << "e != f = " << (e != f) << std::endl;
    std::cout << "e == e_2 = " << (e == e_2) << std::endl;
    std::cout << "e != e_2 = " << (e != e_2) << std::endl;
    
    // make new variables and test increment/decrement operators
    Fixed g(10);
    Fixed h(20);
    std::cout << "g = " << g << std::endl;
    std::cout << "h = " << h << std::endl;
    std::cout << "++g = " << ++g << std::endl;
    std::cout << "g = " << g << std::endl;
    std::cout << "g++ = " << g++ << std::endl;
    std::cout << "g = " << g << std::endl;
    std::cout << "--h = " << --h << std::endl;
    std::cout << "h = " << h << std::endl;
    std::cout << "h-- = " << h-- << std::endl;
    std::cout << "h = " << h << std::endl;

    // test min/max functions
    Fixed i(10);
    Fixed j(20);
    std::cout << "i = " << i << std::endl;
    std::cout << "j = " << j << std::endl;
    std::cout << "min(i, j) = " << Fixed::min(i, j) << std::endl;
    std::cout << "max(i, j) = " << Fixed::max(i, j) << std::endl;
    //for const objects
    const Fixed k(10);
    const Fixed l(20);
    std::cout << "k = " << k << std::endl;
    std::cout << "l = " << l << std::endl;
    std::cout << "min(k, l) = " << Fixed::min(k, l) << std::endl;
    std::cout << "max(k, l) = " << Fixed::max(k, l) << std::endl;
    
    return 0;
}

/*
5.05   = 101.00001100110011001101(2)
1292.8 = 101 00001100.11001100110011001101(2)
value는 roundf 후 1293으로 저장.

2 = 10(2)
512 = 1000000000(2)
value는 roundf 후 512로 저장.

1293/256 * 512/256 (-> * 연산 시 toFloat로 변환되고, 이 과정에서 다시 /256 실행)
= 1293/256*2
= 10.1015625
*/