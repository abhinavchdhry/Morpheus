#ifndef _ExpenseManager_h_
#define _ExpenseManager_h_

#include "CommonIncludes.h"
#include "Expense.h"

class ExpenseManager {

public:

	ExpenseManager();
	~ExpenseManager();

	unique_ptr<ExpenseManager> GetInstance();
	void RegisterNewExpense(const shared_ptr<Expense>& expense);

private:
	vector<shared_ptr<Expense>> _expenseList;
};

#endif /* _ExpenseManager_h_ */