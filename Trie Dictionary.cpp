// As i am using Dev C++ 5.11 , i hv 2 choose NULL instead of nullptr
// Also i added two words in hw6a.txt file,in pos 3rd nd 6th pos just for confirmation 2 myself.
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Trie
{
private:
	class Node
	{
	public:
		char aToZ;
		bool isWord;
		Node* alpha[26];
		Node()
		{
			aToZ = 0;
			for (int i = 0; i < 26; i++)
				alpha[i] = NULL;
			isWord = false;
		}

		void addchar(char c, Node* node, int i)
		{
			int pos = c - i;
			if (node->alpha[pos] != NULL)
				return;
			Node* temp = new Node();
			temp->aToZ = c;
			node->alpha[pos] = temp;
		} 
	};
	Node* root;
public:
	Trie()
	{
		root = new Node();
	}

	int define(char c)
	{
		int i;
		if (c >= 65 && c <= 90) i = 65;
		if (c >= 97 && c <= 122) i = 97;
		return i;
	}

	void addWord(const string& s)
	{
		Node* current;
		int t;
		current = root;
		for (int i = 0; i < s.size(); i++)
		{
			t = define(s[i]);
			current->addchar(s[i], current, t);
			current = current->alpha[s[i] - t];
		}
		current->isWord = true;
	} 

	bool isWord(const string& s)
	{
		Node* current;
		int t;
		current = root;
		for (int i = 0; i < s.size(); i++)
		{
			t = define(s[i]);
			if (current->alpha[s[i] - t] == NULL)
				return false;
			current = current->alpha[s[i] - t];
		}
		if (current->isWord) return true;
		else 
			return false;
	}

};

int main()
{
	Trie word;
	string line, line1;
	fstream file, file1;
	file.open("dict.txt", ios::in);
	if (!file.is_open()) {
		cout << "Unable to open Dictionay :)" << endl;
	}
	
	while (getline(file, line)) {
	   word.addWord(line);
	}
	file.close();
	
	file1.open("hw6a.txt", ios::in);
	if (!file1.is_open()) {
		cout << "Unable to open hw6a file, sorry :) " << endl;
	}
	while (getline(file1, line1)) {
		if (word.isWord(line1))
		{
			cout << line1;
			cout<<":    YES" << endl;
		}
		else {
			cout << line1;
			cout << ":    No" << endl;
		}
	}
	file1.close();
}
