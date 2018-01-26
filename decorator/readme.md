"The Decorator Pattern attaches additional responsibilities to an object dynamically."

This isn't a perfect example because BudgetBrakes, for example, shouldn't have to provide an interface to the go() function, but, it works to demonstrate how functionality can be added/changed to an object at runtime.

If BudgetBrakes *didn't* override go(), then Car::go() would be called, instead of whatever decorated Engine is currently assigned.