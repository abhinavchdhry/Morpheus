#include "Types.h"
#include "Individual.h"

class Expense {

public:
	static void AddNewExpense(Real amount, std::map<Individual, Real>& percentageSplit);
	static void AddNewExpenseSplitEqually(Real amount, std::vector<Individual>& individualList);

protected:
	Expense(Real amount, std::map<Individual, Real>& percentageSplit):
			_amount(amount), _percentageByIndividual(percentageSplit) { };

private:
	Real _amount;
	std::map<Individual, Real> _shareByIndividual;
}