#ifndef LUTIN_ARGS_HPP
#define LUTIN_ARGS_HPP

enum LutinArgs // TODO smaller int type
{
	TRANSFORMATION = 1, 	// b00000001
	ANALYSE_STATIQUE = 2, 	// b00000010
	AFFICHAGE = 4, 			// b00000100
	EXECUTION = 8 			// b00001000
};

inline LutinArgs operator | (LutinArgs a, LutinArgs b)
{
	return static_cast<LutinArgs>(static_cast<int>(a) | static_cast<int>(b));
}

#endif // LUTIN_ARGS_HPP
