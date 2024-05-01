#include <iostream>
#include <string>

using namespace std;

int main()
{
  string source, char_stuff, char_destuff;
  int i = 0, j = 0, k = 0;

  cout << "Enter plain text: ";
  getline(cin, source);
  char_stuff = "dlestx";
  j = 6;

  for (k = 0; k < source.length();)
  {
    if (source[k] == 'd' && source[k + 1] == 'l' && source[k + 2] == 'e')
    {
      char_stuff += "dlestx";
      k += 3;
    }
    else
    {
      char_stuff += source[k++];
    }
  }

  char_stuff += "dlestx";
  cout << "After character stuffing: " << char_stuff << endl;

  j = 0;
  for (i = 6; i < char_stuff.length() - 6;)
  {
    if (char_stuff[i] == 'd' && char_stuff[i + 1] == 'l' && char_stuff[i + 2] == 'e')
    {
      i = i + 6;
    }
    else
    {
      char_destuff += char_stuff[i++];
    }
  }

  cout << "After character de-stuffing: " << char_destuff << endl;

  return 0;
}

// character stuffing