#include "whatever.hpp"

class Awesome
{
public:
Awesome(void) : n(0) {}
Awesome( int n ) : n( n ) {}
Awesome & operator= (Awesome & a) { n = a.n; return *this; }
bool operator==( Awesome const & rhs ) const { return (this->n == rhs.n); }
bool operator!=( Awesome const & rhs ) const{ return (this->n != rhs.n); }
bool operator>( Awesome const & rhs ) const { return (this->n > rhs.n); }
bool operator<( Awesome const & rhs ) const { return (this->n < rhs.n); }
bool operator>=( Awesome const & rhs ) const { return (this->n >= rhs.n); }
bool operator<=( Awesome const & rhs ) const { return (this->n <= rhs.n); }
int getn() const { return n; }
private:
int n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.getn(); return o; }

int main(void)
{
Awesome a(2), b(4);

swap(a, b);
std::cout << a << " " << b << std::endl;
std::cout << max(a, b) << std::endl;
std::cout << min(a, b) << std::endl;
return (0);
}