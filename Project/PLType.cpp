
#include "PLType.h"

PLType::PLType(const PLType& data)
{
	PlayList = data.PlayList;
	PLname = data.PLname;
	length = data.length;
	
}
void PLType::Printall()
{
	DoublyIter2<ManageType*> Mgiter(PlayList);
	while (Mgiter.NotNull())
	{
		cout << "°î¸í : " << Mgiter.GetCurrentNode().data->getName() << endl;
		cout << "Index : " << Mgiter.GetCurrentNode().data->getIndex() << endl;
		Mgiter.Next();
	}

}