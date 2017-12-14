/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractVM.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:38:50 by jguyet            #+#    #+#             */
/*   Updated: 2017/12/14 16:38:52 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

// External Libraries ##############################
# include <unistd.h>
# include <string>
# include <string.h>
# include <iostream>
# include <fstream>
# include <vector>
# include <exception>
# include <stack>
# include <memory>
# include <sstream>
// #################################################

// Enum of Operande types ##########################
enum eOperandType
{
	t_Float = 1,
	t_Double = 2,
	t_Int8 = 3,
	t_Int16 = 4,
	t_Int32 = 5,
	t_Int64 = 6,
	eOperandType_max
};
// #################################################

// Class includes ##################################
#include "IOperand.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Int64.hpp"
#include "OperandFactory.hpp"
#include "AbstractVmHandler.hpp"
// #################################################

#endif
