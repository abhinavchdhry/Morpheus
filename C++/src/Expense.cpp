#include "CommonIncludes.h"
#include "Expense.h"
#include "Individual.h"
#include "ExpenseManager.h"

void Expense::AddNewExpense(double amount, std::map<Individual, double>& percentageSplit)
{

}

void Expense::AddNewExpenseSplitEqually(double amount, std::vector<Individual>& individualList)
{
	double individualCount = (double) individualList.size();
	std::map<Individual, double> individualShareMap;

	for (auto& individual : individualList)
	{
		individualShareMap.insert(IndividualSharePair(individual, amount/individualCount));
	}

	shared_ptr<Expense> newExpense = make_shared(Expense(amount, individualShareMap));
	ExpenseManager::RegisterNewExpense(newExpense);
}
