#include <iostream>
#include <string>

using namespace std;

string t, cs, g;
int a, e, b;

void xorOperation()
{
  for (int c = 1; c < g.length(); c++)
    cs[c] = (cs[c] == g[c]) ? '0' : '1';
}

void crc()
{
  cs = t;
  do
  {
    if (cs[0] == '1')
      xorOperation();
    for (int c = 0; c < g.length() - 1; c++)
      cs[c] = cs[c + 1];
    cs[g.length() - 1] = t[e++];
  } while (e <= a + g.length() - 1);
}

int main()
{
  int flag = 0;
  string options[] = {"1100000001111", "11000000000000101", "10001000000100001"};

  do
  {
    cout << "\n1. CRC12\n2. CRC16\n3. CRC CCIT\n4. Exit\n\nEnter your option: ";
    cin >> b;

    if (b < 1 || b > 4)
    {
      cout << "Invalid option.\n";
      continue;
    }
    if (b == 4)
      return 0;

    g = options[b - 1];

    cout << "\nEnter data: ";
    cin >> t;

    cout << "\nGenerating polynomial: " << g;
    a = t.length();

    for (e = a; e < a + g.length() - 1; e++)
      t += '0';

    cout << "\nModified data is: " << t << "\n\n";
    crc();

    cout << "Checksum is: " << cs << "\n";

    for (e = a; e < a + g.length() - 1; e++)
      t[e] = cs[e - a];

    cout << "\nFinal codeword is: " << t << "\n";

    cout << "\nTest error detection? (0: Yes, 1: No): ";
    cin >> e;

    if (e == 0)
    {
      do
      {
        cout << "\nEnter the position where error is to be inserted: ";
        cin >> e;
      } while (e == 0 || e > a + g.length() - 1);

      t[e - 1] = (t[e - 1] == '0') ? '1' : '0';
      cout << "\nErroneous data: " << t << "\n";
    }

    crc();

    for (e = 0; (e < g.length() - 1) && (cs[e] != '1'); e++)
      ;

    cout << (e < g.length() - 1 ? "Error detected.\n\n" : "No error detected.\n\n");

    cout << "\n";
  } while (flag != 1);

  return 0;
}
