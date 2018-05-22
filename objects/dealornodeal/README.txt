Download the game. Play and then write the code.
All the inputs like 
1. Number of suitcases
2. Money in suitcase
3. The number of rounds 
must be programmable.

Implement the above game in four flavors:
1. Single interactive game
2. Single computer game (Use Random numbers)
3. Non-Interactive: Play until you become a millionaire
4. Non-Interactive: Play until you become a bankrupt (1 cent)

You should report how many games you became a  millionaire?

You should report how many games you became a   bankrupt? (1 cent)

You can use the random class below:

/*--------------------------------------------------------
class random number generator
----------------------------------------------------------*/
class Random {
public:
  Random() {srand((unsigned)time(0)); }
  int get_random_number(int a = 0, int b = 10000) const {
    int upper_bound, lower_bound;
    if(a < b) {
      upper_bound = b - a; lower_bound = a;
    }
    else if(a >= b) {
      upper_bound = a - b; lower_bound = b;
    }
    return(lower_bound + rand() % upper_bound);
  }

private:
  /* no body can copy random or equal random */
  Random(const Random& x) = delete ;
  Random& operator=(const Random& x) = delete ;
};