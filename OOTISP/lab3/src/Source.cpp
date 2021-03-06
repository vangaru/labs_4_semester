#include <iostream>
#include "Receipt.h"
#include "Waybill.h"

using namespace std;

int main() {
	Document* check = new Check("12.12.2012", 10, 10);
	Document* waybill = new Waybill("12.12.2012", 10, "tuesdaydude", "kreativnvp", "website");
	Document* receipt = new Receipt("10.10.2010", 11, 10.19, "tinkoff");

	Document* check2 = new Check();
	Document* waybill2 = new Waybill();
	Document* receipt2 = new Receipt();

	Document::printListOfDocuments();
	
	return 0;
}





