#include "Expense.h"
#include <memory>

class ExpenseManager {

public:
	UNIQUE_PTR<ExpenseManager> GetInstance();
	static void RegisterNewExpense();

private:
	std::vector<Expense> expenseList;
};