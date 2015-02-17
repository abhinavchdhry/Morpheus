#ifndef _Expense_h_
#define _Expense_h_

#include "CommonIncludes.h"
#include "Individual.h"

class Expense {

	enum ExpenseStatus {
		Outstanding,
		Resolved
	};

public:
	Expense(double amount, std::map<Individual, double>& percentageSplit);

	static void AddNewExpense(double amount, map<Individual, double>& percentageSplit);
	static void AddNewExpenseSplitEqually(double amount, std::vector<Individual>& individualList);

private:
	/* The expense amount */
	double 						_amount;

	/* List of individuals who paid the amount, and the corresponding amounts paid */
	map<Individual, double>		_individualContribution;

	/* List of individuals who will share the expense, along with corresponding contributions */
	map<Individual, double> 	_shareByIndividual;


	ExpenseStatus 				_status;
};

#endif /* _Expense_h_ */