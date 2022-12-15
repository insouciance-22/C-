#include<iostream>
using namespace std;
class String {
      private:
		  char* Str;
		  int len;
      public:
		  void showstr() {
			  cout << "string:" << Str << ",length:" << len << endl;
		  }
		  String() {
			  len = 0;
			  Str = NULL;
		  }
		  String(const char* p) {
			  len = strlen(p);
			  Str = new char[len + 1];
			  strcpy(Str, p);
		  }
		  ~String()
		  {
			  if (Str != NULL)
			  {
				  delete[]Str;
				  Str = NULL;
			  }
		  }
};
int main()
{
	String s1("abcde");
	String s2 = s1;
	return 0;
}