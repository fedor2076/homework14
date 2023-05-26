#include "trie.h"


int main()
{	//use only 'a' through 'z'
	TrieTree trie;
	
	string out_key[10];
	string keys[] = { "adaptative","adaptor","add","adding",
		"addict", "answer", "addition",
		"any", "anybody","by", "bye", 
		"change","changeable","changeover",
		"fiction","file", "files",
	   "first","the","their", "there", };
	
	int n = sizeof(keys) / sizeof(keys[0]);

	for (int i = 0; i < n; i++)
	{
		trie.insert(keys[i],i);
	}
	
	//trie.printAll();

	int k = 1;
	string str="";
	while (true)
	{
		cout << "0-exit, input prefix: ";
		cin >> str;
		if (str == "0")
			return 0;
		
		trie.printPre(str);
				
		cout << trie.prefixNumbers(str)<<"\n";
	    str = "";
	}

}

