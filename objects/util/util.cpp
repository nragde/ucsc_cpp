/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
Filename: util.cpp
-----------------------------------------------------------------*/
#include "util.h"

/*----------------------------------------------------------------
duplicate array a to b
-----------------------------------------------------------------*/
void util::swap(int* a, int i, int j) {
  if (i != j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
}

/*----------------------------------------------------------------
duplicate array a to b
-----------------------------------------------------------------*/
int* util::duplicate_array(const int* a, int size) {
  int* b = new int[size];
  for (int i = 0; i < size; ++i) {
    b[i] = a[i];
  }
  return b;
}

/*----------------------------------------------------------------
is a == b
Assumes array a and b is sorted
-----------------------------------------------------------------*/
bool util::is_array_equal(const int* a, const int* b, int as, int bs) {
  if (as != bs) {
    return false;
  }
  for (int i = 0; i < as; ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;;
}

/*----------------------------------------------------------------
is a == b
Assumes array a and b is sorted
-----------------------------------------------------------------*/
bool util::is_array_equal(const int* a, const int* b, int as) {
  return is_array_equal(a, b, as, as);
}

/*----------------------------------------------------------------
ascending order func
-----------------------------------------------------------------*/
int ascending_order_func(const void* va, const void* vb) {
  int* pa = (int*)va;
  int* pb = (int*)vb;
  int a = *(pa);
  int b = *(pb);
  return (a - b);
}

/*----------------------------------------------------------------
descending order func
-----------------------------------------------------------------*/
int descending_order_func(const void* va, const void* vb) {
  int* pa = (int*)va;
  int* pb = (int*)vb;
  int a = *(pa);
  int b = *(pb);
  return (b - a);
}

/*----------------------------------------------------------------
Sort a in ascending order
-----------------------------------------------------------------*/
void util::sort_array_in_ascending_order(int* a, int s) {
  qsort(a, s, sizeof(int), ascending_order_func);
}

/*----------------------------------------------------------------
Sort a in descending order
-----------------------------------------------------------------*/
void util::sort_array_in_descending_order(int* a, int s) {
  qsort(a, s, sizeof(int), descending_order_func);
}

/*----------------------------------------------------------------
print array indices
-----------------------------------------------------------------*/
void util::print_array_indices(int s, int ie, int width) const {
  for (int i = s; i <= ie; ++i) {
    cout << left << setw(width) << i;
  }
  cout << endl;
}

/*----------------------------------------------------------------
print array content
-----------------------------------------------------------------*/
void util::print_array_contents(const int* a, int s, int ie, int width) const {
  bool first = true;
  for (int i = s; i <= ie; ++i) {
    if (i == s) {
      first = false;
    } else {
      //cout << left << "," ;
    }
    cout << left << setw(width) << a[i];
  }
  cout << endl;
}

/*----------------------------------------------------------------
print array indices and contents
-----------------------------------------------------------------*/
void util::print_array_indices_and_contents(const int* a, int s, int ie, int width) const {
  print_array_indices(s, ie, width);
  print_array_contents(a, s, ie, width);
}

/*----------------------------------------------------------------
print array indices and contents with title
-----------------------------------------------------------------*/
void util::print_array_indices_and_contents(const string& t, const int* a, int s, int ie, int width) const {
  cout << t << endl;
  print_array_indices(s, ie, width);
  print_array_contents(a, s, ie, width);
}

/*----------------------------------------------------------------
print array indices and contents
-----------------------------------------------------------------*/
void util::print_array_indices_and_contents(const int* a, int n, int width) const {
  print_array_indices(0, n - 1, width);
  print_array_contents(a, 0, n - 1, width);
}

/*----------------------------------------------------------------
print array indices and contents with title
-----------------------------------------------------------------*/
void util::print_array_indices_and_contents(const string& t, const int* a, int n, int width) const {
  cout << t << endl;
  print_array_indices_and_contents(a, n, width);
}

/*----------------------------------------------------------------
print two array's indices and contents with title
-----------------------------------------------------------------*/
void util::print_array_indices_and_contents(const string& t, const int* a, const int* b, int n, int width) const {
  print_array_indices_and_contents(t, a, n, width);
  print_array_contents(b, 0, n - 1, width);
}

/*----------------------------------------------------------------
is array in ascending order
-----------------------------------------------------------------*/
bool util::is_array_sorted_in_ascending_order(const int* a, int s) {
  if (s == 0) {
    return true;
  }
  int m = a[0];
  for (int i = 1; i < s; ++i) {
    if (a[i] < m) {
      return false;
    }
    m = a[i];
  }
  return true;
}

/*----------------------------------------------------------------
is array in ascending order
-----------------------------------------------------------------*/
bool util::is_array_sorted_in_strict_ascending_order(const int* a, int s) {
  if (s == 0) {
    return true;
  }
  int m = a[0];
  for (int i = 1; i < s; ++i) {
    if (a[i] <= m) {
      return false;
    }
    m = a[i];
  }
  return true;
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
void util::generate_random_numbers(int n, int* a, int min, int max) const {
  Random r;
  for (int i = 0; i < n; ++i) {
    a[i] = r.get_random_number(min, max);
  }
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
void util::generate_numbers_in_ascending_order(int n, int* a, int start, int steps) const {
  int s = start;
  for (int i = 0; i < n; ++i) {
    a[i] = s;
    s = s + steps;
  }
}

/*----------------------------------------------------------------

-----------------------------------------------------------------*/
void util::generate_numbers_in_descending_order(int n, int* a, int start, int steps) const {
  int s = start;
  for (int i = 0; i < n; ++i) {
    a[i] = s;
    s = s - steps;
  }
}

/*----------------------------------------------------------------
Shuffle an array
-----------------------------------------------------------------*/
void util::shuffle_an_array(int* a, int max) {
  Random r;
  for (int i = 0; i < max; ++i) {
    int x = r.get_random_number(0, max);
    assert(x >= 0 && x < max);
    int y = r.get_random_number(0, max);
    assert(y >= 0 && y <= max);
    int t = a[x];
    a[x] = a[y];
    a[y] = t;
  }
}

/*----------------------------------------------------------------
is s = "jag" ;
c = 'k'
s = "jagk"
-----------------------------------------------------------------*/
void util::appendString(string& s, char c) {
  s = s + c;
}

/*----------------------------------------------------------------
is s = "jag" ;
n = 1986
s = "jag1986"
-----------------------------------------------------------------*/
void util::appendString(string& s, int n) {
  if (n == 0) {
    appendString(s, '0');
  } else {
    if (n < 0) {
      appendString(s, '-');
      n = -n;
    }
    string t;
    while (n) {
      char c = (n % 10) + '0';
      t = t + c;
      n = n / 10;
    }
    std::reverse(t.begin(), t.end());
    s = s + t;
  }
}

/*--------------------------------------------------------
strcmp
----------------------------------------------------------*/
int util::strcmp(const char* s1, const char* s2) {
  for (; *s1 == *s2; ++s1, ++s2)
    if (*s1 == 0) {
      return 0;
    }
  return *(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1;
}

/*--------------------------------------------------------
strcpy
----------------------------------------------------------*/
void util::strcpy(char* s1, const char* s2) {
  int i = 0;
  while (1) {
    s1[i] = s2[i];
    if (s2[i] == '\0') {
      return;
    }
    i++;
  }
}

/*----------------------------------------------------------------
Print an integer
-----------------------------------------------------------------*/
void util::print_integer(const int& x) {
  cout << x << " ";
}

/*----------------------------------------------------------------
Print an integer
-----------------------------------------------------------------*/
void util::print_integer(const int*& x) {
  cout << *x << " ";
}

/*----------------------------------------------------------------
Print an integer
-----------------------------------------------------------------*/
void util::print_integer(int& x) {
  cout << x << " ";
}

/*----------------------------------------------------------------
Print an integer
-----------------------------------------------------------------*/
void print_integer(int*& x) {
  cout << *x << " ";
}

/*----------------------------------------------------------------
7 9 1
9 7 -1
-----------------------------------------------------------------*/
int util::int_ascending_order(const int& c1, const int& c2) {
  if (c1 == c2) {
    return 0;
  }
  if (c1 < c2) {
    return 1;
  }
  return -1;
}

/*----------------------------------------------------------------
pointer
-----------------------------------------------------------------*/
int util::int_ascending_order(int* const& c1, int* const& c2) {
  return int_ascending_order(*c1, *c2);
}

/*----------------------------------------------------------------
7 9 -1
9 7  1
-----------------------------------------------------------------*/
int util::int_descending_order(const int& c1, const int& c2) {
  int x = int_ascending_order(c1, c2);
  return -x;
}

/*----------------------------------------------------------------
pointer
-----------------------------------------------------------------*/
int util::int_descending_order(int* const& c1, int* const& c2) {
  return int_descending_order(*c1, *c2);
}

/*----------------------------------------------------------------
Delete a int object
-----------------------------------------------------------------*/
void util::delete_int(int*& c) {
  delete(c);
}

/*----------------------------------------------------------------
Delete a char * object
-----------------------------------------------------------------*/
void util::delete_charstar(char*& c) {
  delete[] c;
}

/*--------------------------------------------------------
char compare
----------------------------------------------------------*/
int util::charcompare(const char& c1, const char& c2) {
  if (c1 == c2) {
    return 0;
  }
  if (c1 > c2) {
    return 1;
  }
  return -1;
}

/*--------------------------------------------------------
char print
----------------------------------------------------------*/
void util::print_char(char& c) {
  cout << c << " ";
}

/*--------------------------------------------------------
string print
----------------------------------------------------------*/
void util::print_string(char*& c) {
  cout << c << " ";
}

/*--------------------------------------------------------
Delete c which is allocated by new []
----------------------------------------------------------*/
void util::free_string(char*& c) {
  delete[] c;
}

/*--------------------------------------------------------
henry  zoo  is in descending order:  -1
tom   idiot is in decending order:    1
----------------------------------------------------------*/
int util::string_descending_order(char* const& c1, char* const& c2) {
  int x = strcmp(c1, c2);
  return x;
}

/*--------------------------------------------------------
henry  zoo  is in ascending order:  -1   1
tom   idiot is in ascending order:   1  -1
----------------------------------------------------------*/
int util::string_ascending_order(char* const& c1, char* const& c2) {
  int x = string_descending_order(c1, c2);
  return -x;
}


/*----------------------------------------------------------------
test
-----------------------------------------------------------------*/
void test1() {
  int m = 100;
  int* a = new int[m];
  util u;
  u.generate_random_numbers(m, a, -m, m);
  u.print_array_indices_and_contents(a, m, 4);
  delete[] a;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main1() {
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  test1();
  return 0;
}


//EOF
