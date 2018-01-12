#include <iostream>
#include <fstream>

#include "Poco/TextIterator.h"
#include "Poco/UTF8Encoding.h"
#include "Poco/Unicode.h"

using namespace std;
using namespace Poco;

int main(int argc, char** argv) {
  if (2 != argc) {
    cout << "Usage: enc <input file>" << endl;
    return EXIT_FAILURE;
  }

  cout << "Start to process: " << argv[1] << endl;

  ifstream in;
  in.open(argv[1], ios_base::in);

  string line;
  UTF8Encoding utf8;

  while (getline(in, line)) {
    TextIterator it(line, utf8);
    TextIterator end(line);
    Unicode::CharacterProperties props;

    for (; it != end; ++it) {
      int unicode = *it;

      Unicode::properties(unicode, props);

      cout << unicode;

      if (props.script == Unicode::Script::UCP_HAN) {
        cout << " is an Chinese character." << endl;
      }
    }

    cout << endl;
  }

  in.close();

  return EXIT_SUCCESS;
}
