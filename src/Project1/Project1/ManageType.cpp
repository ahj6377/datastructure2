#include"ManageType.h"

bool ManageType::PrintNameNIndex()
{
	if (Isdeleted == false) {

		cout << "\t��� : " << mptr->GetName() << endl;
		cout << "\tIndex : " << mptr->GetNum() << endl;
		//cc
		return true;
	}
	return false;
}
