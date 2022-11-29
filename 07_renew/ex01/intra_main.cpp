#include "iter.hpp"

#include <iostream>

class Awesome
{
public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

#include <vector>

int main() {
    std::vector<int> int_vec;

    for (std::vector<int>::iterator it = int_vec.begin(); it != int_vec.end(); ++it)
    {

    }

    int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    Awesome tab2[5];

    iter( tab, 5, print<int> );
    iter( tab2, 5, print<Awesome> );

    return 0;
}