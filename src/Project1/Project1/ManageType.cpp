#include"ManageType.h"

void ManageType::PrintNameNIndex()
{
	if (Isdeleted == false) {

		cout << "��� : " << mptr->GetName() << endl;
		cout << "Index : " << mptr->GetNum() << endl;
		//cc
	}
}
