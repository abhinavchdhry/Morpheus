#include "CommonIncludes.h"
#include "Expense.h"

class ExpenseManager {

public:

	ExpenseManager();
	~ExpenseManager();

	unique_ptr<ExpenseManager> GetInstance();
	static void RegisterNewExpense(const shared_ptr<Expense>& expense);

private:
	vector<shared_ptr<Expense>> _expenseList;
};