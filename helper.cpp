/*
 Boost Software License - Version 1.0 - August 17th, 2003

 Permission is hereby granted, free of charge, to any person or organization
 obtaining a copy of the software and accompanying documentation covered by
 this license (the "Software") to use, reproduce, display, distribute,
 execute, and transmit the Software, and to prepare derivative works of the
 Software, and to permit third-parties to whom the Software is furnished to
 do so, all subject to the following:

 The copyright notices in the Software and this entire statement, including
 the above license grant, this restriction and the following disclaimer,
 must be included in all copies of the Software, in whole or in part, and
 all derivative works of the Software, unless such copies or derivative
 works are solely in the form of machine-executable object code generated by
 a source language processor.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 */

#include "helper.h"

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
using std::cout;
using std::cin;
using std::istringstream;
using std::vector;
using std::string;
using std::shared_ptr;

namespace Faculty {


double Helper::Probability()
{
  return rand() * 1.0 / RAND_MAX;
}

/*
 * TODO: This function doesn't handle every wrong error.
 *  E.g.: 10.23
 *    In these examples, we read the integer part and return
 */
int Helper::ReadInt(int low, int high) {
  // let's read it as string to avoid any stream problems...and validate it.
  string input;

  cin >> input;

  istringstream stringstreamObj(input);

  // TIP: Always define variables as close as to their first usage
  int value;
  stringstreamObj >> value;

  if (stringstreamObj.fail()) {
    cout << "ERROR: Expected integer input...Try again - Enter number ";
    return ReadInt(low, high);
  }

  if (low <= value && value <= high)
    return value;

  cout << "ERROR: Expected range is low = " << low << ", high = " << high << "...Try again - Enter number ";
  return ReadInt(low, high);
}

string Helper::ToString(int val, int length) {
  ostringstream oss;

  oss << val;

  string ret = oss.str();

  while ((int) ret.size() < length)
    ret = "0" + ret;

  return ret;
}

int Helper::RunMenu(vector<string> &menu) {
  cout << "\n\nPlease make a choice:\n";

  for (int i = 0; i < (int) menu.size(); ++i)
    cout << "\t" << i + 1 << " - " << menu[i] << "\n";

  cout << "\tEnter Choice: ";

  return Helper::ReadInt(1, menu.size());
}

}
;
