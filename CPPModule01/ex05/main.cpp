/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:35:44 by dkham             #+#    #+#             */
/*   Updated: 2023/09/19 16:36:56 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harlInstance;
    
    harlInstance.complain("DEBUG");
    harlInstance.complain("INFO");
    harlInstance.complain("WARNING");
    harlInstance.complain("ERROR");

    return 0;
}
