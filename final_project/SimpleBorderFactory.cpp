#include "stdafx.h"
#include "SimpleBorderFactory.h"


SimpleBorderFactory::SimpleBorderFactory() {

}

SimpleBorderFactory& SimpleBorderFactory::instance(){

	static SimpleBorderFactory instance;
	return instance; 
}