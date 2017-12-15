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
# include <algorithm>
# include <limits>
# include <string>
# include <string.h>
# include <iostream>
# include <fstream>
# include <vector>
# include <exception>
# include <list>
# include <memory>
# include <sstream>
# include <map>
# include <cmath>
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

// Enum of VM Operation types ######################
enum eVmOperationType
{
	VmOperation_push = 0,
	VmOperation_pop = 1,
	VmOperation_dump = 2,
	VmOperation_assert = 3,
	VmOperation_add = 4,
	VmOperation_sub = 5,
	VmOperation_mul = 6,
	VmOperation_div = 7,
	VmOperation_mod = 8,
	VmOperation_print = 9,
	VmOperation_exit = 10,
	eVmOperationType_max
};
// #################################################

std::string		strtoupper(std::string str);

// Class includes ##################################
#include "IOperand.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Int64.hpp"
#include "AbstractVmExceptions.hpp"
#include "OperandFactory.hpp"
#include "AbstractVmHandler.hpp"
#include "AbstractVmParser.hpp"
// #################################################

#endif
