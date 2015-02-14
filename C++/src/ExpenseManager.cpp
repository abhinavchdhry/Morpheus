#include "ExpenseManager.h"

ExpenseManager::ExpenseManager()
{

}

ExpenseManager::~ExpenseManager()
{

}

void ExpenseManager::RegisterNewExpense(const shared_ptr<Expense>& expense)
{
	_expenseList.push_back(expense);
}