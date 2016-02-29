#ifndef E0.HPP
#define E0.HPP
#include <Etat.hpp>
#include <Symbole.hpp>

class E0 : public class Etat {
	public :
		bool transition(Automate & automate, Symbole * s);
};

#endif //E0.HPP
