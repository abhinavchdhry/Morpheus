#include "Types.h"
#include "Expense.h"
#include <memory>

class ExpenseManager {

public:
	UNIQUE_PTR<ExpenseManager> GetInstance();
	static void RegisterNewExpense(SHARED_PTR<Expense>& expense);

private:
	std::vector<SHARED_PTR<Expense>> _expenseList;
};