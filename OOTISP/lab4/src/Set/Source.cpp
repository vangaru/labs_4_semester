#include "Complex.h"
#include "Set.h"

using namespace std;

int main()
{
	cout << "========== INT ==========" << endl;
	Set<int> set1 = { 4, 2, 7, 11, 0 };
	Set<int> set2 = {7, 0, 4, 1, 2, 3, 4, 5, 8, 11 };
	Set<int> set3;
	set3 = set1;
	Set<int> set4 = {-1, 0, 3, 2, 1, 6, 7 };
	Set<int> set5 = { 3, 6, 7, 2, 1, 9, 10 };
	Set<int> set6 = (set4 * set5);

	cout << "Set1: ";
	while (set1.hasNext())
	{
		cout << set1.next() << " ";
	}
	set1.toStart();
	cout << endl;

	cout << "Set2: ";
	while (set2.hasNext())
	{
		cout << set2.next() << " ";
	}
	set2.toStart();
	cout << endl;

	cout << "Set3: ";
	while (set3.hasNext())
	{
		cout << set3.next() << " ";
	}
	set3.toStart();
	cout << endl;

	cout << "Set4: ";
	while (set4.hasNext())
	{
		cout << set4.next() << " ";
	}
	set4.toStart();
	cout << endl;

	cout << "Set5: ";
	while (set5.hasNext())
	{
		cout << set5.next() << " ";
	}
	set5.toStart();
	cout << endl;

	cout << "======== OPERATOR '>' ========" << endl;
	cout << "Set1 > 0: " << (set1 > 0) << endl << "Set1 > 4: " << (set1 > 4) << endl
		 << "Set2 > 3: " << (set2 > 3) << endl << "Set2 > 6: " << (set2 > 6) << endl
		 << "Set3 > 2: " << (set3 > 2) << endl << "Set3 > 4: " << (set3 > 4) << endl;

	cout << "======== OPERATOR '<' ========" << endl;
	cout << "Set1 < Set2: " << (set1 < set2) << endl << "Set2 < Set1: " << (set2 < set1) << endl
		 << "Set2 < Set3: " << (set2 < set3) << endl << "Set3 < Set2: " << (set3 < set2) << endl
		 << "Set3 < Set1: " << (set3 < set1) << endl << "Set1 < Set3: " << (set1 < set3) << endl;

	cout << "======== OPERATOR '*' ========" << endl;
	
	cout << "Set6(Set4 * Set5): ";
	while (set6.hasNext())
	{
		cout << set6.next() << " ";
	}
	set6.toStart();

	cout << endl << endl << "========== CHAR ==========" << endl;
	Set<char> chset1 = { 'a', 'b', 'e', 'c', 'd' };
	Set<char> chset2 = { 'b', 'e', 'a', 'g', 'f', 'h', 'c', 'd' };
	Set<char> chset3;
	chset3 = chset1;
	Set<char> chset4 = { 'x', 'y', 'z', 'm', 'n', 'a' };
	Set<char> chset5 = { 'z', 'y', 'x', 'k', 'n', 'f', 'i' };
	Set<char> chset6 = (chset4 * chset5);

	cout << "CharSet1: ";
	while (chset1.hasNext())
	{
		cout << chset1.next() << " ";
	}
	chset1.toStart();
	cout << endl;

	cout << "CharSet2: ";
	while (chset2.hasNext())
	{
		cout << chset2.next() << " ";
	}
	chset2.toStart();
	cout << endl;
	
	cout << "CharSet3: ";
	while (chset3.hasNext())
	{
		cout << chset3.next() << " ";
	}
	chset3.toStart();
	cout << endl;
	
	cout << "CharSet4: ";
	while (chset4.hasNext())
	{
		cout << chset4.next() << " ";
	}
	chset4.toStart();
	cout << endl;

	cout << "CharSet5: ";
	while (chset5.hasNext())
	{
		cout << chset5.next() << " ";
	}
	chset5.toStart();
	cout << endl;

	cout << "======== OPERATOR '>' ========" << endl;
	cout << "CharSet1 > a: " << (chset1 > 'a') << endl << "CharSet1 > k: " << (chset1 > 'k') << endl
		 << "CharSet2 > g: " << (chset2 > 'g') << endl << "CharSet2 > y: " << (chset2 > 'y') << endl
		 << "CharSet3 > k: " << (chset3 > 'k') << endl << "CharSet3 > a: " << (chset3 > 'a') << endl;

	cout << "======== OPERATOR '<' ========" << endl;
	cout << "CharSet1 < CharSet2: " << (chset1 < chset2) << endl << "CharSet2 < CharSet1: " << (chset2 < chset1) << endl
		 << "CharSet2 < CharSet3: " << (chset2 < chset3) << endl << "CharSet3 < CharSet2: " << (chset3 < chset2) << endl
		 << "CharSet3 < CharSet1: " << (chset3 < chset1) << endl << "CharSet1 < CharSet3: " << (chset1 < chset3) << endl;
	
	cout << "======== OPERATOR '*' ========" << endl;
	cout << "CharSet6(CharSet4 * CharSet5): ";
	while (chset6.hasNext())
	{
		cout << chset6.next() << " ";
	}
	chset6.toStart();

	cout << endl << endl << "========== COMPLEX ==========" << endl;
	Complex complex1(1, 2);
	Complex complex2(2, 1);
	Complex complex3(3, 4);
	Complex complex4(6, 10);
	Complex complex5(7, 7);
	Complex complex6(5, 3);
	Complex complex7(4, 0);
	Set<Complex> cmset1 = { complex7, complex1, complex2, complex3, complex6 };
	Set<Complex> cmset2 = { complex2, complex3, complex4, complex7, complex1, complex6, complex4, complex5 };
	Set<Complex> cmset3;
	cmset3 = cmset1;
	Set<Complex> cmset4 = (cmset1 * cmset2);
	
	cout << "ComplexSet1: ";
	while (cmset1.hasNext())
	{
		cout << cmset1.next().getComplex() << " ";
	}
	cmset1.toStart();
	cout << endl;

	cout << "ComplexSet2: ";
	while (cmset2.hasNext())
	{
		cout << cmset2.next().getComplex() << " ";
	}
	cmset2.toStart();
	cout << endl;

	cout << "ComplexSet3: ";
	while (cmset3.hasNext())
	{
		cout << cmset3.next().getComplex() << " ";
	}
	cmset3.toStart();
	cout << endl;

	cout << "======== OPERATOR '>' ========" << endl;
	cout << "ComplexSet1 > 1+2i: " << (cmset1 > complex1) << endl << "ComplexSet1 > 7+7i: " << (cmset1 > complex5) << endl
		 << "ComplexSet2 > 5+3i: " << (cmset2 > complex6) << endl << "ComplexSet2 > 3+4i: " << (cmset2 > complex3) << endl
		 << "ComplexSet3 > 6+10i: " << (cmset3 > complex4) << endl << "ComplexSet3 > 4: " << (cmset3 > complex7) << endl;

	cout << "======== OPERATOR '<' ========" << endl;
	cout << "ComplexSet1 < ComplexSet2: " << (cmset1 < cmset2) << endl << "ComplexSet2 < ComplexSet1: " << (cmset2 < cmset1) << endl
		 << "ComplexSet2 < ComplexSet3: " << (cmset2 < cmset3) << endl << "ComplexSet3 < ComplexSet2: " << (cmset3 < cmset2) << endl
		 << "ComplexSet3 < ComplexSet1: " << (cmset3 < cmset1) << endl << "ComplexSet1 < ComplexSet3: " << (cmset1 < cmset3) << endl;

	cout << "======== OPERATOR '*' ========" << endl;
	cout << "ComplexSet4(ComplexSet1 * ComplexSet2): ";
	while (cmset4.hasNext())
	{
		cout << cmset4.next().getComplex() << " ";
	}
	cmset4.toStart();
	cout << endl;

	return 0;
}
