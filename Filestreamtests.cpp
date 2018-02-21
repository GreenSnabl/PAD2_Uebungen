#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void filestreamtests()
{
 ofstream ascii("ascii.txt");
 ofstream binary("bin.dat", ios::binary);
 double d = 3.14159265359;
 int i = 1025, j = 1024;
 ascii << setprecision(12) << d << " " << i << " " <<  j;
 binary.write(reinterpret_cast<char*>(&d), sizeof(d));
 binary.write(reinterpret_cast<char*>(&i), sizeof(i));
 binary.write(reinterpret_cast<char*>(&j), sizeof(j));

 ascii.close();
 binary.close();

 double di;
 int ii;
 int ji;
 
 double da;
 int ia;
 int ja;
 ifstream asciiIn("ascii.txt");
 ifstream inFile("bin.dat", ios::binary);
 
 asciiIn >> setprecision(12) >> da >> ia >> ja;
 inFile.read(reinterpret_cast<char*>(&di), sizeof(di));
 inFile.read(reinterpret_cast<char*>(&ii), sizeof(ii));
 inFile.read(reinterpret_cast<char*>(&ji), sizeof(ji));
 cout << "d = " << setprecision(12) << di << "\t ascii d: " << da <<  endl;
 cout << "i = " << ii << "\t\t ascii i: " << ia << endl;
 cout << "j = " << ji << "\t\t ascii j: " << ja << endl;
 inFile.close();
}