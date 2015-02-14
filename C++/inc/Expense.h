#include "Types.h"
#include "Individual.h"

using namespace std;

class Expense {

	enum ExpenseStatus {
		Outstanding,
		Resolved
	};

public:
	static void AddNewExpense(Real amount, std::map<Individual, Real>& percentageSplit);
	static void AddNewExpenseSplitEqually(Real amount, std::vector<Individual>& individualList);

protected:
	Expense(Real amount, std::map<Individual, Real>& percentageSplit):
			_amount(amount), _percentageByIndividual(percentageSplit), _status(Active) { };

private:
	/* The expense amount */
	Real 						_amount;

	/* List of individuals who paid the amount, and the corresponding amounts paid */
	map<Individual, Real>		_individualContribution;

	/* List of individuals who will share the expense, along with corresponding contributions */
	map<Individual, Real> 		_shareByIndividual;


	ExpenseStatus 				_status;
}