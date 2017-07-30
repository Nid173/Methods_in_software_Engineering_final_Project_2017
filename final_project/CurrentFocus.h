#include "source\Control.h"
class CurrentFocus {
	static Control* current;
	CurrentFocus();
public:
	~CurrentFocus();
	static Control* getInstance();
};