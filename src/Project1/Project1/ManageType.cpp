#include"ManageType.h"

bool ManageType::PrintNameNIndex()
{
	if (Isdeleted == false) {

		cout << "��� : " << mptr->GetName() << endl;
		cout << "Index : " << mptr->GetNum() << endl;
		//cc
		return true;
	}
	return false;
}
