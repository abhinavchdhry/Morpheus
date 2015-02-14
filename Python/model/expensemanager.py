import expense

class ExpenseMgr:
	# Maintains a list of all expenses created
	expenseList = []

	@classmethod
	def CreateNewExpense(cls, amount, percentageSplit):
		e = Expense(amount, percentageSplit)
		cls.expenseList.append(e)
		return e

	@classmethod
	def RemoveExpense(cls, expense):
		cls.expenseList.remove(expense)

