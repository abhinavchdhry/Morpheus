#include "Types.h"
#include "Expense.h"
#include "Individual.h"

void Expense::AddNewExpense(Real amount, std::map<Individual, Real>& percentageSplit)
{

}

void Expense::AddNewExpenseSplitEqually(Real amount, std::vector<Individual>& individualList)
{
	Real individualCount = (Real) individualList.size();
	std::map<Individual, Real> individualShareMap;

	for (auto& individual : individualList)
	{
		individualShareMap.insert(IndividualSharePair(individual, amount/individualCount));
	}

	SHARED_PTR<Expense> newExpense = make_shared(Expense(amount, individualShareMap));
	ExpenseManager::RegisterNewExpense(newExpense);
}
