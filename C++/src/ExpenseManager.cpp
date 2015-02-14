#include "ExpenseManager.h"

void ExpenseManager::RegisterNewExpense(SHARED_PTR<Expense>& expense)
{
	_expenseList.push_back(expense);
}